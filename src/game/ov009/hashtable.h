#ifndef GAME_OV009_HASHTABLE_H
#define GAME_OV009_HASHTABLE_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of hashtable.c, prototypes copied from their definitions. */

struct HashImplementation;

struct HashImplementation *TableNew(int elemSize, int nBuckets, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
struct HashImplementation *TableNew2(int elemSize, int nBuckets, int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *), void (*freeFn)(void *));
void TableFree(struct HashImplementation *table);
int TableCount(struct HashImplementation *table);
void TableEnter(struct HashImplementation *table, void *newElem);
int TableRemove(struct HashImplementation *table, void *delElem);
void *TableLookup(struct HashImplementation *table, void *elemKey);
void TableMapSafe(struct HashImplementation *table, void (*fn)(void *, void *), void *clientData);
void *TableMapSafe2(struct HashImplementation *table, int (*fn)(void *, void *), void *clientData);
/* END mkheaders: generated region */

#endif
