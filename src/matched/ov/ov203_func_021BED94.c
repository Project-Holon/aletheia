/*
 * function: DEMO3D_DATA_UpdateSeFade
 * address: 0x021BED94
 * packet: pkt_ov203_021BED94
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   DEMO3D_DATA_ApplySeFade 0x021BEDCC thumb ov203
 *   TCBL_DeleteTask 0x02031194 arm
 */
#include "../include/Obj02919.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Owner;struct TcblNode;
typedef struct Config {unsigned words[11];} Config;
extern void DEMO3D_DATA_ApplySeFade(int,int,int);
extern void TCBL_DeleteTask(struct TcblNode *);
void DEMO3D_DATA_UpdateSeFade(struct TcblNode *p,char *q) { int old;old=((struct Obj02919 *)q)->f8;((struct Obj02919 *)q)->f8=old-1;if(old>0){DEMO3D_DATA_ApplySeFade(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f14>>12);((struct Obj02919 *)q)->f14+=((struct Obj02919 *)q)->f18;}else {DEMO3D_DATA_ApplySeFade(((struct Obj02919 *)q)->f5,((struct Obj02919 *)q)->f6,((struct Obj02919 *)q)->f10);TCBL_DeleteTask(p);} }
