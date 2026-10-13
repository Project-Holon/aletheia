/*
 * function: REPORT_ExitWindows
 * address: 0x021F0700
 * packet: pkt_ov034_021F0700
 * region: ov034
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_FONT_Delete 0x0201D83C thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 */
#include "../include/Obj13077.h"
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
struct Descriptor;
struct PrintSys;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
void REPORT_ExitWindows(char *p) { unsigned i; GF_FONT_Delete(((struct Obj13077 *)p)->f4C); for(i=0;i<8;i++) BMP_WIN_Delete(*(void **)(p+i*8+0xc)); PRINTSYS_QUE_Delete(((struct Obj13077 *)p)->f8); }
