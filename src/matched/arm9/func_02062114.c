/*
 * function: func_02062114
 * address:  0x02062114
 * packet:   pkt_02061D0C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Closed 2026-09-22 (wave 7, pseudo-family pkt_02061D0C).  The two sites that
 * blocked it are both resolved now: func_0206216C was filed EXACT this lane
 * (../2.0/sp2) and the PC24 to func_02062270 carries on sole-ref/code, the
 * class widened 2026-09-21.  The two callback globals 0x020A8140 / 0x020A8144
 * were simply missing from the symbols: block and resolve as literal x20 each.
 *
 * Register-argument save hook: park r0-r3 in the 0x02146B94 block, run the
 * real body func_02062270 (which is handed the same four values), and when
 * the fifth (stack) argument is non-zero also install the two callbacks in
 * the clact.c handler slots 0x020A8140 / 0x020A8144.
 *
 * The 0x02146B94 block is written through its own address - a plain global
 * struct, not a pointer variable - so there is exactly one pool word for it.
 * The fifth argument is read at [sp, #8], the caller's first stack slot, past
 * the 8-byte {r3, lr} frame.
 *
 * symbols:
 *   g_02146B94   0x02146B94  data
 *   g_020A8140   0x020A8140  data
 *   g_020A8144   0x020A8144  data
 *   func_02062270   0x02062270  arm
 *   func_0206216C   0x0206216C  arm
 *   func_020621FC   0x020621FC  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Save {
    u8  pad_00[0xc];
    u32 f0c;    /* 0x0c */
    u32 f10;    /* 0x10 */
    u32 f14;    /* 0x14 */
    u32 f18;    /* 0x18 */
};

extern struct Save g_02146B94;

extern void (*g_020A8140)(void);
extern void (*g_020A8144)(void);

extern void func_02062270(u32 a, u32 b, u32 c, u32 d);
extern u32 func_0206216C(u32 size, u32 flag);
extern u32 func_020621FC(u32 h);

void func_02062114(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_02146B94.f0c = a;
    g_02146B94.f10 = b;
    g_02146B94.f14 = c;
    g_02146B94.f18 = d;

    func_02062270(a, b, c, d);

    if (e != 0) {
        g_020A8140 = (void (*)(void))func_0206216C;
        g_020A8144 = (void (*)(void))func_020621FC;
    }
}
