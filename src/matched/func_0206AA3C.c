/*
 * function: func_0206AA3C
 * address:  0x0206AA3C
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148BCC       0x02148BCC  data
 * Packs three 10-bit fields (each taken from a signed value shifted right by
 * three) plus the slot index at bits 30..31 into one word of g_02148BCC.
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA3C.c \
 *       --func func_0206AA3C --addr 0x0206AA3C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_02148BCC[];

void func_0206AA3C(int idx, int a, int b, int c)
{
    g_02148BCC[idx] = (u32)(((a >> 3) & 0x3FF) | (((b >> 3) & 0x3FF) << 10)
                            | (((c >> 3) & 0x3FF) << 20) | (idx << 30));
}
