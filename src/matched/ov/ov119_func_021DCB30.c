/*
 * function: POKETRADE_PROC_StartRequest3
 * address: 0x021DCB30
 * packet: pkt_ov119_021DCB30
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   POKETRADE_PROC_AllocTradeWork 0x021DC854 thumb ov119
 *   POKETRADE_PROC_InitTradeWork 0x021DC894 thumb ov119
 */
#include "../include/Obj04478.h"
#include "../include/Obj08060.h"
#include "../include/Obj22735.h"
extern void *POKETRADE_PROC_AllocTradeWork(void *a, int t);extern void POKETRADE_PROC_InitTradeWork(void *,int,void *,void *,int);
void POKETRADE_PROC_StartRequest3(void *a,int b,char *c) {const char *q=*(char * *)&((struct Obj04478 *)c)->f18;char *p=POKETRADE_PROC_AllocTradeWork(a,0xc6000);if(q) {if(((struct Obj22735 *)q)->f1B0==2) {int i;for(i=0;i<2;i++) {const int *s=(const int *)(q+i*8);char *d=p+i*4;((struct Obj08060 *)d)->f1048=s[2];((struct Obj08060 *)d)->f1050=s[1];}} else {int j;for(j=0;j<2;j++){char *d=p+j*4;((struct Obj08060 *)d)->f1048=-1;((struct Obj08060 *)d)->f1050=-1;}}}POKETRADE_PROC_InitTradeWork(a,b,c,p,3);}
