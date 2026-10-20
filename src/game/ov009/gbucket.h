#ifndef GAME_OV009_GBUCKET_H
#define GAME_OV009_GBUCKET_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of gbucket.c, prototypes copied from their definitions. */

struct bucketset_s;
struct bucket_s;

void *BucketNew(struct bucketset_s *set, char *name, int type, void *initialvalue);
void *BucketSet(struct bucketset_s *set, char *name, void *value);
void *BucketAdd(struct bucketset_s *set, char *name, void *value);
void *BucketSub(struct bucketset_s *set, char *name, void *value);
void *BucketMult(struct bucketset_s *set, char *name, void *value);
void *BucketDiv(struct bucketset_s *set, char *name, void *value);
void *BucketConcat(struct bucketset_s *set, char *name, void *value);
void *BucketAvg(struct bucketset_s *set, char *name, void *value);
char *bint(int v);
void *bfloat(double d);
char *stripchars(char *s);
void *DoSet(struct bucket_s *pbucket, void *value);
char *DoGet(char *p);
struct bucket_s *DoFind(struct bucketset_s *set, char *name);
/* END mkheaders: generated region */

#endif
