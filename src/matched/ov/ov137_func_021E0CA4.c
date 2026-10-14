/*
 * function: GURU2_MAIN_DropEffectStateInit
 * address: 0x021E0CA4
 * packet: pkt_ov137_021E0CA4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_ActivatePlayerRecord 0x021E078C thumb ov137
 */
#include "../include/Obj08224.h"
#include "../include/Obj08225.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void GURU2_MAIN_ActivatePlayerRecord(char *,char *);
int GURU2_MAIN_DropEffectStateInit(char *p) { char *q; q=*(char * *)&((struct Obj08224 *)p)->f10; ((struct Obj08225 *)q)->f38=4096; ((struct Obj08225 *)q)->f3C=4096; ((struct Obj08225 *)q)->f40=4096; ((struct Obj08225 *)q)->f54=0xc0000; GURU2_MAIN_ActivatePlayerRecord(*(char * *)&((struct Obj08224 *)p)->f14,q); ((struct Obj08224 *)p)->fC=0x8000; ((struct Obj08224 *)p)->f0=1; return 0; }
