/*
 * function: func_021DA03C
 * address:  0x021DA03C
 * packet:   pkt_021DA03C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   WIPE_SYS_EndCheck  0x020221A4  thumb
 *   func_021DA034  0x021DA034  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern void func_021DA034(char *, int, int);

void func_021DA03C(char *p)
{
    if (WIPE_SYS_EndCheck() != 0)
        func_021DA034(p, 0, 0xd5);
}
