#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct package {
    char* id;
    int weight;
};

typedef struct package package;

struct post_office {
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town {
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;

// Prints all packages in a town following the precise tab formatting rules
void print_all_packages(town t) {
    printf("%s:\n", t.name);
    for (int i = 0; i < t.offices_count; i++) {
        printf("\t%d:\n", i);
        for (int j = 0; j < t.offices[i].packages_count; j++) {
            printf("\t\t%s\n", t.offices[i].packages[j].id);
        }
    }
}

// Executes a transaction between two post offices across towns
void send_all_packages(town* source, int source_office_index, town* target, int target_office_index) {
    post_office* src = &source->offices[source_office_index];
    post_office* tgt = &target->offices[target_office_index];

    // Arrays to temporarily sort accepted and rejected packages
    package* accepted = malloc(src->packages_count * sizeof(package));
    package* rejected = malloc(src->packages_count * sizeof(package));
    int acc_cnt = 0;
    int rej_cnt = 0;

    for (int i = 0; i < src->packages_count; i++) {
        int w = src->packages[i].weight;
        if (w >= tgt->min_weight && w <= tgt->max_weight) {
            accepted[acc_cnt++] = src->packages[i];
        } else {
            rejected[rej_cnt++] = src->packages[i];
        }
    }

    // Append accepted packages to the tail of the target office queue
    if (acc_cnt > 0) {
        tgt->packages = realloc(tgt->packages, (tgt->packages_count + acc_cnt) * sizeof(package));
        for (int i = 0; i < acc_cnt; i++) {
            tgt->packages[tgt->packages_count + i] = accepted[i];
        }
        tgt->packages_count += acc_cnt;
    }

    // Retain rejected packages inside the source office in their original order
    free(src->packages);
    if (rej_cnt > 0) {
        src->packages = malloc(rej_cnt * sizeof(package));
        for (int i = 0; i < rej_cnt; i++) {
            src->packages[i] = rejected[i];
        }
        src->packages_count = rej_cnt;
    } else {
        src->packages = NULL;
        src->packages_count = 0;
    }

    free(accepted);
    free(rejected);
}

// Finds the town containing the highest aggregate sum of packages across all its offices
town town_with_most_packages(town* towns, int towns_count) {
    town max_town = towns[0];
    int max_pkgs = -1;

    for (int i = 0; i < towns_count; i++) {
        int current_town_pkgs = 0;
        for (int j = 0; j < towns[i].offices_count; j++) {
            current_town_pkgs += towns[i].offices[j].packages_count;
        }
        if (current_town_pkgs > max_pkgs) {
            max_pkgs = current_town_pkgs;
            max_town = towns[i];
        }
    }
    return max_town;
}

// Finds and returns a reference to the town matching the requested string identifier
town* find_town(town* towns, int towns_count, char* name) {
    for (int i = 0; i < towns_count; i++) {
        if (strcmp(towns[i].name, name) == 0) {
            return &towns[i];
        }
    }
    return NULL;
}

int main() {
    int towns_count;
    if (scanf("%d", &towns_count) != 1) return 0;
    town* towns = malloc(towns_count * sizeof(town));
    
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * 51);
        if (scanf("%s", towns[i].name) != 1) return 0;
        if (scanf("%d", &towns[i].offices_count) != 1) return 0;
        towns[i].offices = malloc(towns[i].offices_count * sizeof(post_office));
        
        for (int j = 0; j < towns[i].offices_count; j++) {
            if (scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight) != 3) return 0;
            towns[i].offices[j].packages = malloc(towns[i].offices[j].packages_count * sizeof(package));
            
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * 51);
                if (scanf("%s", towns[i].offices[j].packages[k].id) != 1) return 0;
                if (scanf("%d", &towns[i].offices[j].packages[k].weight) != 1) return 0;
            }
        }
    }
    
    int queries_count;
    if (scanf("%d", &queries_count) != 1) return 0;
    
    while (queries_count--) {
        int type;
        if (scanf("%d", &type) != 1) return 0;
        if (type == 1) {
            char town_name[51];
            if (scanf("%s", town_name) != 1) return 0;
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
        } else if (type == 2) {
            char source_name[51];
            char target_name[51];
            int source_office_index, target_office_index;
            if (scanf("%s%d%s%d", source_name, &source_office_index, target_name, &target_office_index) != 4) return 0;
            town* source = find_town(towns, towns_count, source_name);
            town* target = find_town(towns, towns_count, target_name);
            send_all_packages(source, source_office_index, target, target_office_index);
        } else if (type == 3) {
            town t = town_with_most_packages(towns, towns_count);
            printf("Town with the most number of packages is %s\n", t.name);
        }
    }
    
    // Free allocated memory
    for (int i = 0; i < towns_count; i++) {
        for (int j = 0; j < towns[i].offices_count; j++) {
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                free(towns[i].offices[j].packages[k].id);
            }
            free(towns[i].offices[j].packages);
        }
        free(towns[i].offices);
        free(towns[i].name);
    }
    free(towns);
    
    return 0;
}
