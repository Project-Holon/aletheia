/*
 * function: func_021B75AC
 * address: 0x021B75AC
 * packet: pkt_ov172_021B75AC
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BDFDC 0x021BDFDC thumb ov172
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021BE078 0x021BE078 thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021BE0AC 0x021BE0AC thumb ov172
 *   func_021BE054 0x021BE054 thumb ov172
 *   func_021BE0B4 0x021BE0B4 thumb ov172
 *   MIi_CpuCopy32 0x02082A90 arm
 *   func_02034714 0x02034714 arm
 *   func_021BE0F8 0x021BE0F8 thumb ov172
 *   func_021BE0FC 0x021BE0FC thumb ov172
 *   d_021C71F0 0x021C71F0 data a4
 */
#include "../include/Obj06552.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BDFDC(void *p);
extern int func_021BE05C(void *p);
extern u32 func_021BE078(void *p);
extern u32 func_021BE0A4(void *p);
extern u32 func_021BE0AC(void *p);
extern u8 func_021BE054(void *p);
extern u32 func_021BE0B4(void *p);
extern void MIi_CpuCopy32(const void *srcp, void *destp, unsigned long size);
extern const char d_021C71F0[];
extern void func_02034714(const char *file, u32 line, const char *msg);
extern u32 func_021BE0F8(void *p);
extern void func_021BE0FC(void *p, u32 v);
void func_021B75AC(char *src, void *p)
{
    char *base;
    int sub;
    u32 wide;
    int x;
    u32 me;
    u32 n;
    u16 y;
    int w;
    u16 h;
    int i;
    base = (char *)func_021BDFDC(p);
    sub = func_021BE05C(p);
    wide = func_021BE078(p);
    me = func_021BE0A4(p);
    if (func_021BE0AC(p) == 1 || func_021BE054(p) < 2)
        return;
    if (((struct Obj06552 *)base)->f10 & (1 << me))
        return;
    if (func_021BE0B4(p) == 0) {
        for (i = 0; i < 0xc0; i++)
            MIi_CpuCopy32(src + i * 0x200 + 0x80, *(char * *)&((struct Obj06552 *)base)->fB0 + i * 0x100, 0x100);
    }
    if (sub == 0) {
        func_02034714(d_021C71F0, 0, d_021C71F0);
        return;
    }
    n = me;
    if (sub == 1 && me > 1)
        n = 1;
    if (wide == 0) {
        x = 0;
        y = (sub == 1) ? 0 : 0x30;
        w = 0x80;
        h = (sub == 1) ? 0xc0 : 0x60;
    } else {
        x = 0x20;
        y = (sub == 1) ? 0x30 : 0x50;
        w = 0x40;
        h = (sub == 1) ? 0x60 : 0x30;
    }
    if (func_021BE0F8(p) != 0)
        return;
    func_021BE0FC(p, 1);
    for (i = 0; i < h; i++)
        MIi_CpuCopy32((void *)(*(u32 *)&((struct Obj06552 *)base)->fB0 + (y + i) * 0x100 + x * 2),
                      (void *)(((struct Obj06552 *)base)->f4 + w * h * 2 * n + w * i * 2), w * 2);
    func_021BE0FC(p, 0);
    ((struct Obj06552 *)base)->f10 |= (u8)(1 << me);
}
