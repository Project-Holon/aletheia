/*
 * function: func_021F8A44
 * address:  0x021F8A44
 * packet:   pkt_ov135_021F8A44
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x28];
    u32 x28;
    u16 x2C;
    u16 x2E;
    u16 x30;
    u8 pad32[0xEB2 - 0x32];
    u16 xEB2;
} Work;

extern void GFL_USE_CancelChangeAndPlayBgm(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);

int func_021F8A44(Work *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x486, 0xFFFF);
    p->x28 = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    func_021F4EC0((u8 *)p, 1, 0);
    return 2;
}
