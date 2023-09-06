// Online C compiler to run C program online
#include <stdio.h>
#define MAX_HASH 100

typedef struct keyVal
{
    char * key;
    int value;
    struct keyVal * next;
} keyval_t;

typedef struct hashtable
{
    keyval_t * table[MAX_HASH];
}hashtable_t;

keyval_t * createPair(const char * key_p, int val_p)
{
    keyval_t * result = NULL;
    
    result = malloc(sizeof(keyval_t));
    result->key = strdup(key_p);
    result->value = val_p;
    result->next = NULL;
    
    return result;
}

int hash(const char * key_p)
{
    int hash = 0;
    
    while( *key_p )
    {
        hash = (hash + *key_p) % MAX_HASH;
        ++key_p;
    }
    
    return hash;
}

void insert(hashtable_t *ht, const char * key_p, int value)
{
    int idx = 0;
    keyval_t * pair;
    pair = createPair(key_p, value);
    
    idx = hash(key_p);
    if (ht->table[idx] == NULL)
    {
        ht->table[idx] = pair;
    }
    else
    {
        keyval_t * temp = ht->table[idx];
        while ( temp->next != NULL )
        {
            temp = temp->next;
        }
        temp->next = pair;
    }
}

int get(hashtable_t *ht, const char * key_p)
{
    int result;
    int idx = hash(key_p);
    keyval_t * pair = ht->table[idx];
    
    if ( pair )
    {
        while( pair )
        {
            if ( !strcmp(pair->key, key_p) )
            {
                return pair->value;
            }
            pair = pair->next;
        }
        return -1;
    }
    else
    {
        return -1;
    }
    
    return result;
}

int main() {
    // Write C code here
    printf("Hello world\n");
    
    hashtable_t table;
    memset(&table, 0, sizeof(table));
    
    insert(&table, "one", 1);
    insert(&table, "two", 2);
    insert(&table, "three", 3);
    insert(&table, "eno", 4);
    
    printf("Will get values now\n");
    
    printf("value for one is %d\n", get(&table, "one"));
    printf("value for two is %d\n", get(&table, "two"));
    printf("value for three is %d\n", get(&table, "three"));
    printf("value for eno is %d\n", get(&table, "eno"));
    printf("value for four is %d\n", get(&table, "four"));

    printf("done");

    return 0;
}
