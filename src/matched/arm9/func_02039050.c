/*
 * function: func_02039050
 * address:  0x02039050
 * packet:   pkt_02038D68
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469DC     0x021469DC  data
 *   g_021469D0     0x021469D0  data
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02039050.c \
 *       --func func_02039050 --addr 0x02039050 --cc 1.1p1 --arm
 */
#include "../include/Obj15938.h"
#include "../include/G_LinkState.h"

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct LinkState *g_021469D0;
extern void func_0203666C(u32 a);
struct Src;
struct St;
extern int func_020365E8(char *p);
extern u32 func_02037258(void);
extern void func_02038DF0(struct Src *src, u32 a1, u8 *buf, struct St *st, u32 n);

void func_02039050(void)
{
    int i;
    u8 *p;

    if (((u8 *)g_021469D0) == 0)
        return;

    func_0203666C((u32)(((u8 *)g_021469D0) + 0x2C));

    for (i = 0; i < 4; i++) {
        if ((int)func_020365E8((char *)((u32)(((u8 *)g_021469D0) + 0x2C))) <= 0)
            return;

        p = ((u8 *)g_021469D0);
        func_02038DF0((struct Src *)((u32)(p + 0x2C)), 0xFF, (u8 *)(((struct Obj15938 *)p)->f18),
                      (struct St *)((u32)(p + 0x19C)), func_02037258());
    }
}
