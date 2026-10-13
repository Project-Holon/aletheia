/*
 * function: PMS_SELECT_GRAPHIC_DeleteRows
 * address: 0x021C0C18
 * packet: pkt_ov110_021C0C18
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 */
#include "../include/Obj22409.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Descriptor;
struct Obj;
extern void PMS_DRAW_Delete(struct Obj *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
void PMS_SELECT_GRAPHIC_DeleteRows(u8 *p) { int i; PMS_DRAW_Delete(((struct Obj22409 *)p)->f8C); for(i=0;i<4;i++) BMP_WIN_Delete(*(void **)(p+0x6c+i*4)); }
