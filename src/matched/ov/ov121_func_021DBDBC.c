/*
 * function: func_021DBDBC
 * address: 0x021DBDBC
 * packet: pkt_ov121_021DBDBC
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: Declare the index before the count, but initialise count first; this places index in r4 and count in r5.
 * prototype: MYSTERY_DATA_GetCardSlotNum returns the value used by the bound. Its forwarding target 0200A400 reads only r0, so legacy trailing arguments are omitted.
 * symbols:
 *   MYSTERY_DATA_GetCardSlotNum 0x0200A348 thumb
 *   func_021DBF04 0x021DBF04 thumb ov121
 */
#include "../include/Obj22900.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern u32 MYSTERY_DATA_GetCardSlotNum(struct Obj *); extern int func_021DBF04(int *);
u32 func_021DBDBC(u32 p) { u32 i; u32 count=0; for (i=0;i<MYSTERY_DATA_GetCardSlotNum(((struct Obj22900 *)p)->fC);i++) { if (func_021DBF04((int *)(p+40+i*220))) count++; } return count; }
