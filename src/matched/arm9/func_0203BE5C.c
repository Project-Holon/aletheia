/*
 * function: func_0203BE5C
 * address:  0x0203BE5C
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
 *   python tools/match.py one --src src/matched/func_0203BE5C.c \
 *       --func func_0203BE5C --addr 0x0203BE5C --cc 1.1p1 --arm
 */

#include "../include/G_Sys.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern struct Sys *g_021469DC;

struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
struct Entry;
extern u16 func_02039338(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);

void func_0203BE5C(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    func_0203D3A8((void *)a4, 2, 0, 0);

    if (func_02039338() != 0)
        return;

    func_0203AD80((struct NetState *)((u8 *)g_021469DC), (void *)0x0203BDEC, 0, 0x46C);
}
