/*
 * function: ov208_func_021BE9CC
 * address:  0x021BE9CC
 * packet:   pkt_ov208_021BE9CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_020437D4  0x020437D4  arm
 *   func_02040B1C  0x02040B1C  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Icon {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    int fc;
    u32 pad10[2];
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 f30;
};

extern int  func_0201C6C4(u32 a, u32 b);
extern u32  func_020437D4(u32 a);
extern void func_02040B1C(u32 layer, u32 src, u32 a, u32 b);
extern void func_02041B6C(u32 layer);

void ov208_func_021BE9CC(struct Ov208Icon *p)
{
    if (p->f30 != 0 && func_0201C6C4(p->f2c, p->f18) == 0) {
        func_02040B1C(5, func_020437D4(p->f18), p->f20, p->f1c);
        func_02041B6C(5);
        p->f30 = 0;
    }
}
