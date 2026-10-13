/*
 * function: P_STA_RIBBON_SelectRow
 * address: 0x021D8ED0
 * packet: pkt_ov131_021D8ED0
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   P_STA_RIBBON_GetRowY 0x021D9440 thumb ov131
 *   P_STA_RIBBON_GetRowOwnedIndex 0x021D9428 thumb ov131
 *   func_0204B404 0x0204B404 arm
 */
#include "../include/Obj00091.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef struct { u16 x; u16 y; } Point;
extern s16 P_STA_RIBBON_GetRowY(u8 *,u32);
extern unsigned int P_STA_RIBBON_GetRowOwnedIndex(unsigned char *p, unsigned int target);
struct Obj;
struct Vec2;
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
void P_STA_RIBBON_SelectRow(u8 *a,u8 *p,u8 n)
{
    Point pt;
    pt.x=8;
    pt.y=P_STA_RIBBON_GetRowY(p,n);
    func_0204B404(((struct Obj00091 *)p)->f54,(const struct Vec2 *)(&pt),0);
    p[0x58]=n;
    *(int *)&((struct Obj00091 *)p)->f68=1;
    p[0x59]=P_STA_RIBBON_GetRowOwnedIndex(p,n);
}
