/*
 * function: MANUAL_COMMON_ResetTouchbar
 * address: 0x021BA644
 * packet: pkt_ov225_021BA644
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: a separate local m = z - 1 (z = 0 declared first) keeps the zero live in r3 and emits subs r1,r3,#1.
 */
typedef unsigned char u8;

void MANUAL_COMMON_ResetTouchbar(char *p)
{
    int z = 0;
    int m = z - 1;
    *(int *)(p + 0x20) = z;
    *(int *)(p + 0x24) = m;
    *(int *)(p + 0x28) = m;
    *(u8 *)(p + 0x40) = 0xFF;
    *(int *)(p + 0x44) = z;
}
