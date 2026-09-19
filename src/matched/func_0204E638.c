/*
 * function: func_0204E638
 * address:  0x0204E638
 * packet:   pkt_0204E638
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146A7C     0x02146A7C  data
 *   func_0204E824  0x0204E824  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

typedef struct S0204E638 {
    u32 f00;
    u8 pad04[4];
    s32 f08;
    s32 f0c;
    s32 f10;
    s32 f14;
    s32 f18;
} S0204E638;

extern S0204E638 *g_02146A7C;
extern void func_0204E824(void);

void func_0204E638(void)
{
    if (g_02146A7C == 0) {
        return;
    }
    if ((g_02146A7C->f00 & 0xf) == 0) {
        return;
    }
    if (g_02146A7C->f10 != 0) {
        g_02146A7C->f10 = g_02146A7C->f10 - 1;
        return;
    }
    g_02146A7C->f10 = g_02146A7C->f14;
    g_02146A7C->f08 = g_02146A7C->f08 + g_02146A7C->f18;
    if ((g_02146A7C->f08 >= g_02146A7C->f0c && g_02146A7C->f18 > 0) ||
        (g_02146A7C->f08 <= g_02146A7C->f0c && g_02146A7C->f18 < 0)) {
        g_02146A7C->f08 = g_02146A7C->f0c;
    }
    func_0204E824();
    if (g_02146A7C->f08 == g_02146A7C->f0c) {
        g_02146A7C->f00 = 0;
    }
}
