/*
 * function: func_021C85A4
 * address: 0x021C85A4
 * packet: pkt_ov128_021C85A4
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WF2DMAP_TOUCH_SetActorAnimSeq 0x021CA40C thumb ov128
 *   func_021C88C0 0x021C88C0 thumb ov128
 *   func_021C899C 0x021C899C thumb ov128
 *   WF2DMAP_TOUCH_UpdateItemBar 0x021CA2DC thumb ov128
 */
#include "../include/Obj00179.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
extern void WF2DMAP_TOUCH_SetActorAnimSeq(char *p, int n);
extern void func_021C88C0(s16 *, void *, u8 *);
extern void func_021C899C(char *p, char *q, void *r, void *s, int t, char *table, int page, u16 heap);
extern void WF2DMAP_TOUCH_UpdateItemBar(char *p);
void func_021C85A4(u8 *p, u8 *a, u8 *b, int x, int y, int n, u16 c)
{
    int offset;
    u8 *base;
    if (n == 0) {
        ((struct Obj00179 *)p)->f0 = x;
        ((struct Obj00179 *)p)->f4 = y;
        WF2DMAP_TOUCH_SetActorAnimSeq((char *)p, x);
    }
    offset = n * 0x4c;
    base = p + 12;
    func_021C88C0((s16 *)(base + offset), b, b + 0x16c);
    func_021C899C((char *)(base + offset), (char *)a, b, ((struct Obj00179 *)p)->f104, (int)(b + 0x16c), (char *)(a + 16), x, c);
    WF2DMAP_TOUCH_UpdateItemBar((char *)p);
}
