/*
 * function: sciReportSetPlayerGameResult
 * address:  0x021DFFC8
 * packet:   pkt_021DFFC8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sciSerializeInt32  0x021E054C  arm
 *
 * Submit the `i`-th word of the +0x124 block's dynamic area (base 0x44 plus
 * the +0x2c and +0x30 sizes) with the caller's value.
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u8 *sciSerializeInt32(u8 *dst, u32 v);

int sciReportSetPlayerGameResult(char *obj, int i, int v)
{
    char *ip = *(char **)(obj + 0x124);
    int off = *(int *)(ip + 0x2c) + 0x44 + *(int *)(ip + 0x30) + i * 4;

    sciSerializeInt32((u8 *)(ip + off), v);
    return 0;
}

