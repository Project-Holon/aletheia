/*
 * function: func_0203DC04
 * address:  0x0203DC04
 * packet:   pkt_0203DAC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Verified EXACT* - every byte compares equal; the extent runs long only
 * because the follower at 0x0203DC48 carries no `func_` label (it saves no
 * lr and disasm.py does not auto-label it).  That follower is for the
 * integrator's layout/function_starts.txt, not for this file.
 *
 * symbols:
 *   g_021469F0     0x021469F0  data
 *   func_02039338  0x02039338  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct S0203DC04 {
    u8 pad00[0x102];
    u8 f102;
    u8 pad103;
    u8 pad104;
    u8 f105;
    u8 f106;
};

extern struct S0203DC04 *g_021469F0;
typedef unsigned short u16;
extern u16 func_02039338(void);

void func_0203DC04(void)
{
    if (g_021469F0 == 0)
        return;
    g_021469F0->f102 = 1;
    if (g_021469F0->f106 != 0) {
        g_021469F0->f105 = g_021469F0->f106 - 1;
    } else {
        g_021469F0->f105 = func_02039338();
    }
}
