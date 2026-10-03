/*
 * function: func_021B90B8
 * address:  0x021B90B8
 * packet:   pkt_ov067_021B90B8
 * region:   ov067
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CF84  0x0202CF84  thumb
 *   func_0202CF8C  0x0202CF8C  thumb
 *   func_020410D0  0x020410D0  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
    u8 f4;
    u8 f5;
    u8 _6[0x3c - 6];
    void *f3c;
};

struct WinMgr;
extern u32 func_0202CF84(struct WinMgr *mgr, u32 idx);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern void func_020410D0(u8 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_02041B6C(u8 id);

void func_021B90B8(struct S *p, u32 a1, s8 a2)
{
    u32 t;
    u32 id;
    u16 j;

    t = func_0202CF84(p->f3c, a1);
    id = func_0202CF8C(p->f3c, a1);
    for (j = 0; j < p->f5; j++) {
        if (a2 < 0)
            a2 += 0x20;
        else if (a2 >= 0x20)
            a2 -= 0x20;
        func_020410D0(id, p->f2, (u8)a2, p->f4, 1, t, 0, j, p->f4, p->f5);
        a2++;
    }
    func_02041B6C(id);
}
