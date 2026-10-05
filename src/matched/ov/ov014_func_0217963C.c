/*
 * function: func_0217963C
 * address:  0x0217963C
 * packet:   pkt_ov014_0217963C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: the unlabelled ov014 setter that func_020103E4
 * (+001A) and sub_02010360 (+0056) call: store v into word +0x1E88 of the
 * object behind the pointer at g_021797A8.
 *
 * symbols:
 *   g_021797A8   0x021797A8  data  ov014  a4
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021797A8;

void func_0217963C(u32 v)
{
    *(u32 *)(g_021797A8 + 0x1E88) = v;
}
