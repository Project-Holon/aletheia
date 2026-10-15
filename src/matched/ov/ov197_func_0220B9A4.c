/*
 * function: B_BAG_MAIN_CheckKeyItem
 * address: 0x0220B9A4
 * packet: pkt_ov197_0220B9A4
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   MYITEM_SAVEDATA_HasItem 0x02007F68 thumb
 */
#include "../include/Obj06648.h"
#include "../include/Obj14544.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 MYITEM_SAVEDATA_HasItem(u8 *,u16,u16,u16);
int B_BAG_MAIN_CheckKeyItem(char *p) { char *q; if(((struct Obj06648 *)p)->f540==0) return 0; q=*(char * *)&((struct Obj06648 *)p)->f0; if(MYITEM_SAVEDATA_HasItem(*(u8 * *)&((struct Obj14544 *)q)->f0,((struct Obj06648 *)p)->f540,1,((struct Obj14544 *)q)->fC)==0) { ((struct Obj06648 *)p)->f540=0; ((struct Obj06648 *)p)->f542=0; return 0; } return 1; }
