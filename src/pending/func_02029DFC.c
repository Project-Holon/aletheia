/*
 * function: func_02029DFC
 * address:  0x02029DFC
 * packet:   pkt_02029DFC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 *
 * Parked: every concrete byte is right; the only unresolved relocation site(s)
 * target 02028900, which has no witness outside this range (no outside branch names it,
 * not a manifest entry, not in layout/runtime_arm9.txt).
 * status:   MATCH

 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02012A30(void);
extern void func_02028900(void);

void func_02029DFC(void)
{
    func_02012A30();
    func_02028900();
}
