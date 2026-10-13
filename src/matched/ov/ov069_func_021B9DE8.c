/*
 * function: BSUBWAY_RECORD_LIST_ExitText
 * address: 0x021B9DE8
 * packet: pkt_ov069_021B9DE8
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C4C0 0x0201C4C0 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj01132.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern void func_0201C4C0(struct PrintSys *p);
extern u32 GF_FONT_Delete(void *ptr);
void BSUBWAY_RECORD_LIST_ExitText(u8 *p) { func_0201C4C0(((struct Obj01132 *)p)->fE8); GF_FONT_Delete(((struct Obj01132 *)p)->fC); }
