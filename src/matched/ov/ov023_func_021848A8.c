/*
 * function: func_021848A8
 * address: 0x021848A8
 * packet: pkt_ov023_021848A8
 * region: ov023
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_02186860 0x02186860 thumb ov023
 *   func_021866C4 0x021866C4 thumb ov023
 * Extent follower 0x021848CC is already matched separately.
 */
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 func_02039338(void);
extern void func_02186860(char *p, int x, int y);
extern void func_021866C4(u32 *p);
void func_021848A8(int a, int unused, char *p)
{
    if (func_02039338() == 0)
        func_02186860(p, 0x2903, a);
    func_021866C4((u32 *)p);
}
