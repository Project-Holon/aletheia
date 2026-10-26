#ifndef GAME_OV208_ZUKAN_DETAIL_MAIN_H
#define GAME_OV208_ZUKAN_DETAIL_MAIN_H

/* BEGIN mkheaders: generated region, rewritten by tools/mkheaders.py, keep hand-written code outside it */
/* Public functions of zukan_detail_main.c, prototypes copied from their definitions. */

struct Ov208Args;
struct Ov208Main;

int ZUKAN_DETAIL_MAIN_Init(void *owner, int unused, struct Ov208Args *args);
int ZUKAN_DETAIL_MAIN_Exit(void *owner,int seq,int args,char *p);
int ZUKAN_DETAIL_MAIN_Main(void *unused, int *cnt, struct Ov208Args *args, struct Ov208Main *work);
void ZUKAN_DETAIL_MAIN_NoOp(struct TcbTask * unused0, void * unused1);
/* END mkheaders: generated region */

#endif
