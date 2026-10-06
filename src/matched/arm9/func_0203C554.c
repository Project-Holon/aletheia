/*
 * function: func_0203C554
 * address:  0x0203C554
 * packet:   pkt_0203C494
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
 *   python tools/match.py one --src src/matched/func_0203C554.c \
 *       --func func_0203C554 --addr 0x0203C554 --cc 1.1p1 --arm
 */

typedef signed char   s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int  u32;

extern u8 *g_021469DC;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern u16 func_02039338(void);
extern void func_0203C494(u8 *p);

void func_0203C554(u32 a)
{
    u8 *p = g_021469DC;

    if (p == 0)
        return;

    if (a != 0) {
        if (func_02039338() == 0)
            g_021469DC[0x4B] = 0;
        else
            g_021469DC[0x4B] = 1;
    } else {
        p[0x4B] = 0;
    }

    func_0203AD80((struct NetState *)g_021469DC, (void *)0x0203C494, 0, 0x671);
    func_0203C494((u8 *)((u32)g_021469DC));
}
