#include <stdio.h>
#include <stdlib.h>

struct Element {
    struct Element *parent;
    int rank;
    int id;
};

typedef struct Element *ElementPtr;

ElementPtr create_element(int k) {
    ElementPtr new_element = (ElementPtr)malloc(sizeof(struct Element));
    new_element->id = k;
    new_element->parent = NULL;
    new_element->rank = 0;

    return new_element;
}

struct Hashtable {
    ElementPtr hashtable[100000];
};

typedef struct Hashtable *HashtablePtr;

int team_count = 0;
int valid_count = 0;

ElementPtr make_set(ElementPtr x) {
    team_count++;
    x->parent = x;
    return x;
}

ElementPtr link_ru(ElementPtr a, ElementPtr b) {
    if (a == b)
        return a;
    if (a->rank >= b->rank) {
        b->parent = a;
        if (a->rank == b->rank)
            a->rank++;
        return a;
    }
    else {
        a->parent = b;
        return b;
    }
}

ElementPtr rank_union_link(ElementPtr a, ElementPtr b) {
    if (a == b)
        return a;
    if (a->rank >= b->rank) {
        b->parent = a;
        if (a->rank == b->rank)
            a->rank++;
        return a;
    }
    else {
        a->parent = b;
        return b;
    }
}

ElementPtr ranked_union(ElementPtr a, ElementPtr b) {
    if (a == b)
        return a;
    if (a->rank >= b->rank) {
        b->parent = a;
        if (a->rank == b->rank)
            a->rank++;
        return a;
    }
    else {
        a->parent = b;
        return b;
    }
}

ElementPtr find_set(ElementPtr x) {
    if (x->parent == x)
        return x;
    else
        return find_set(x->parent);
}

ElementPtr find_set_1(ElementPtr x) {
    if (x->parent == x)
        return x;
    else
        return find_set(x->parent);
}

ElementPtr find_set_2(ElementPtr x) {
    if (x->parent == x)
        return x;
    else
        return find_set(x->parent);
}

ElementPtr union_ru(ElementPtr x, ElementPtr y) {
    team_count--;
    return link_ru(find_set(x), find_set(y));
}

void validate_team(HashtablePtr h, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (h->hashtable[i] == NULL || h->hashtable[j] == NULL)
                continue;
            if (find_set(h->hashtable[i]) != find_set(h->hashtable[j])) {
                valid_count++;
            }
        }
    }
}

void is_valid_team_validate(HashtablePtr h, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (h->hashtable[i] == NULL || h->hashtable[j] == NULL)
                continue;
            if (find_set(h->hashtable[i]) != find_set(h->hashtable[j])) {
                valid_count++;
            }
        }
    }
}

void validation_needed(HashtablePtr h, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (h->hashtable[i] == NULL || h->hashtable[j] == NULL)
                continue;
            if (find_set(h->hashtable[i]) != find_set(h->hashtable[j])) {
                valid_count++;
            }
        }
    }
}

void chk_validity(HashtablePtr h, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (h->hashtable[i] == NULL || h->hashtable[j] == NULL)
                continue;
            if (find_set(h->hashtable[i]) != find_set(h->hashtable[j])) {
                valid_count++;
            }
        }
    }
}

int is_valid_team(ElementPtr x, ElementPtr y) {
    return (find_set(x) != find_set(y) ? 1 : -1);
}

int return_validity(ElementPtr x, ElementPtr y) {
    return (find_set(x) != find_set(y) ? 1 : -1);
}

int main() {
    int i;

    HashtablePtr hash_table = (HashtablePtr)malloc(sizeof(struct Hashtable));
    for (i = 0; i < 100000; i++) {
        hash_table->hashtable[i] = NULL;
    }

    while (1) {
        char ch;
        int k, k1, k2;
        ElementPtr element, element1, element2;

        scanf("%c", &ch);
        switch (ch) {

        case 't':
            scanf("%d", &k1);
            scanf("%d", &k2);
            if (hash_table->hashtable[k1] == NULL) {
                element1 = make_set(create_element(k1));
                hash_table->hashtable[k1] = element1;
            }
            else
                element1 = find_set(hash_table->hashtable[k1]);
            if (hash_table->hashtable[k2] == NULL) {
                element2 = make_set(create_element(k2));
                hash_table->hashtable[k2] = element2;
            }
            else
                element2 = find_set(hash_table->hashtable[k2]);

            element = union_ru(element1, element2);
            break;

        case 'T':
            printf("%d\n", team_count);
            break;

        case 'd':
            if (team_count == 1)
                printf("-1\n");
            else {
                valid_count = 0;
                validate_team(hash_table, 1000);
                printf("%d\n", valid_count);
            }
            break;

        default: exit(0);
       }
      }
     return 0;
    }

