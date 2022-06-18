#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STRING_LENGTH 6

struct package
{
	char* id;
	int weight;
};

typedef struct package package;

struct post_office
{
	int min_weight;
	int max_weight;
	package* packages;
	int packages_count;
};

typedef struct post_office post_office;

struct town
{
	char* name;
	post_office* offices;
	int offices_count;
};

typedef struct town town;





void print_all_packages(town t) {
    printf("%s:\n", t.name);

    for(int i=0 ; i< t.offices_count ; i++)
    {
        printf("\t%d:\n", i); // the i th office
        
        for(int j=0 ; j<t.offices[i].packages_count ; j++)
        {
            printf("\t\t%s\n",t.offices[i].packages[j].id);
        }
    }
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {
    package* updated_source = NULL;
    package* updated_target = NULL;
    
    
    int out_weight  = 0;
    int new_source_size;
    int new_target_size;
    int source_no_pack = (*source).offices[source_office_index].packages_count ;
    int target_no_pack = (*target).offices[target_office_index].packages_count ;

    int *arr_of_trans_index = malloc(source_no_pack * sizeof(int));
    /*Save the weight restrication of targetted post office*/
    int max_weight = (*target).offices[target_office_index].max_weight;
    int min_weight = (*target).offices[target_office_index].min_weight;
    
    /*Check what is going to be successfully transactioned*/
    /*for every package in source town*/
    int trans_count = 0;
    int j = 0;
    for(int i=0 ; i< source_no_pack ; i++ )
    {
        out_weight = (*source).offices[source_office_index].packages[i].weight;
        if((out_weight >= min_weight) && (out_weight <= max_weight))
        {
            arr_of_trans_index[j] = i;
            j++;
            trans_count++;
        }
    }
    new_source_size = (*source).offices[source_office_index].packages_count - trans_count;
    (*source).offices[source_office_index].packages_count = new_source_size;
    updated_source = (package*) malloc(new_source_size*sizeof(package));
    
    new_target_size = (*target).offices[target_office_index].packages_count + trans_count;
    (*target).offices[target_office_index].packages_count = new_target_size;
    updated_target = (package*) malloc(new_target_size*sizeof(package));
    
    /*Fill the copy array updated source */
    j=0;
    int k=0;
    for (int i=0 ; i< new_source_size; i++) {
        /*check if the package is ought to be transported*/
        if(arr_of_trans_index[j] != i) //Not transported
        {
            updated_source[i] = (*source).offices[source_office_index].packages[k];
            k++;
        }else { //Transported
            i--;
            j++;
            k++;//Recently added
        }
    }
    
    /*fill the copy array updated_target with old packages*/
    for (int i=0; i< target_no_pack ; i++) {
        updated_target[i] = (*target).offices[target_office_index].packages[i];
    }
    //4
    /*add the tranported packages to the list*/
    int m=0;
    for (int i=0; i< trans_count ; i++) {
        m = arr_of_trans_index[i];
        updated_target[i+target_no_pack] = (*source).offices[source_office_index].packages[m];
    }
    
    /*update source and target offices with new package arrays*/
    free((*source).offices[source_office_index].packages);
    free((*target).offices[target_office_index].packages);
    (*source).offices[source_office_index].packages = updated_source;
    (*target).offices[target_office_index].packages = updated_target;
    
}

town town_with_most_packages(town* towns, int towns_count) {
    int * each_towns_total = calloc(towns_count,sizeof(int)) ;
    for (int i=0 ; i<towns_count; i++) {
        /*for each office in each town*/
        for (int j=0; j< towns[i].offices_count ; j++) {
            each_towns_total[i] += towns[i].offices[j].packages_count;
        }
    }
    int most = 0;
    for (int i=1 ; i<towns_count; i++) {
        if(each_towns_total[i] >= each_towns_total[most])
        {
            most = i;
        }
    }
    return towns[most];    
}

town* find_town(town* towns, int towns_count, char* name) {
    int match = 0;
    // town* ret;

    for(int i=0 ; i<towns_count ; i++)
    {
        if(strcmp(name , towns[i].name ) == 0)
        {
            match=i;
        }    
    }
    return towns+match;
}

int main()
{
	int towns_count;
	scanf("%d", &towns_count);
	town* towns = malloc(sizeof(town)*towns_count);
	for (int i = 0; i < towns_count; i++) {
		towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
		scanf("%s", towns[i].name);
		scanf("%d", &towns[i].offices_count);
		towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
		for (int j = 0; j < towns[i].offices_count; j++) {
			scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
			towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
			for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
				towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
				scanf("%s", towns[i].offices[j].packages[k].id);
				scanf("%d", &towns[i].offices[j].packages[k].weight);
			}
		}
	}
	int queries;
	scanf("%d", &queries);
        
	char town_name[MAX_STRING_LENGTH];
	while (queries--) {
		int type;
		scanf("%d", &type);
		switch (type) {
		case 1:
			scanf("%s", town_name);            
			town* t = find_town(towns, towns_count, town_name);
			print_all_packages(*t);
			break;
		case 2:
			scanf("%s", town_name);
			town* source = find_town(towns, towns_count, town_name);
			int source_index;
			scanf("%d", &source_index);
			scanf("%s", town_name);
			town* target = find_town(towns, towns_count, town_name);
			int target_index;
			scanf("%d", &target_index);
			send_all_acceptable_packages(source, source_index, target, target_index);
			break;
		case 3:
			printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
			break;
		}
	}
	return 0;
}
