/*
 * function: func_0203B6EC
 * address:  0x0203B6EC
 * packet:   pkt_0203B6EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B6EC.c \
 *       --func func_0203B6EC --addr 0x0203B6EC --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;

extern u8 *func_0203D788(void);
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern u32 func_02037894(u32 a, u32 b, u32 c, u32 d);
extern int func_0203B6B4(int a0, int a1, int a2, int a3);
extern int func_0203B688(int a0, int a1, int a2, int a3);

void func_0203B6EC(u8 *p)
{
    if ((*(u32 (**)(void))(*(u32 *)(func_0203D788() + 0x340) + 0x78))() == 0)
        return;
    if (func_02037894(0, 0x200, 0, (u32)func_0203B6B4) == 0)
        return;

    p[0x4C] = 0;
    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)func_0203B688, 0x1E, 0x2FC);
}
