/*
 * function: func_020227CC
 * address:  0x020227CC
 * packet:   pkt_0202271C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * blocker:  0209F568 label
 * blocker:  020A73F8 literal
 *
 * symbols:
 *   func_020222A8  0x020222A8  thumb
 *   func_020238B4  0x020238B4  thumb
 *   func_0202390C  0x0202390C  thumb
 *   func_0209F568  0x0209F568  arm
 *   func_0209F56C  0x0209F56C  arm
 *   func_0209F570  0x0209F570  arm
 *   func_0209F574  0x0209F574  arm
 *   g_020A73D0     0x020A73D0  data
 *   g_020A73E0     0x020A73E0  data
 *   g_020A73F0     0x020A73F0  data
 *   g_020A73F8     0x020A73F8  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


struct T {
    u8  pad00[0xc];
    u32 f0c;
    u8  pad10[0x14];
    u16 f24;
    u8  pad26[2];
    u32 f28;
    u32 f2c;
};

struct G {
    u32 f00;
    u8  pad04[0xc];
    u32 f10;
    u8  pad14[0xc];
    u32 f20;
    u32 pad24;
    u32 f28;
};

extern void func_020222A8(u32 v);
extern void func_020238B4(struct T *p, void *g);
extern void func_0202390C(struct T *p);
extern void func_0209F568(void);
extern void func_0209F56C(void);
extern void func_0209F570(void);
extern void func_0209F574(void);
extern struct G g_020A73D0;
extern char g_020A73E0[];
extern char g_020A73F0[];
extern char g_020A73F8[];

void func_020227CC(struct T *p)
{
    if (p->f0c == 0) {
        g_020A73D0.f28 = (u32)func_0209F568;
        func_020222A8(p->f24);
        func_020238B4(p, g_020A73F8);
        p->f28 = 0;
        p->f2c = 0;
    } else {
        func_0202390C(p);
    }
}
