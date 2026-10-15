/*
 * function: BR_PROC_SYS_UpdateRecord
 * address: 0x021F97EC
 * packet: pkt_ov186_021F97EC
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BR_PROC_SYS_LoadRecords 0x021F98F8 thumb ov186
 */
#include "../include/Obj14449.h"
#include "../include/Obj24794.h"
#include "../include/Obj24795.h"
#include "../include/Obj24796.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void BR_PROC_SYS_LoadRecords(char *p, int skip, void *sys, int heap);
void BR_PROC_SYS_UpdateRecord(char *p,char *q) { char *s;if(((struct Obj24794 *)p)->f1C){s=*(char * *)&((struct Obj24795 *)q)->f18;BR_PROC_SYS_LoadRecords((char *)(((struct Obj14449 *)s)->f8+0x1748),0,(void *)(((struct Obj24796 *)(*(char * *)&((struct Obj14449 *)s)->fC))->f4),90);} }
