/*
 * function: func_0206AA78
 * address:  0x0206AA78
 * packet:   pkt_0206A12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 g_02148BF4 at +0x10: the address appears in no other literal pool in the image and no outside branch reaches it
 *
 * symbols:
 *   g_02148BF4       0x02148BF4  data
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206AA78.c \
 *       --func func_0206AA78 --addr 0x0206AA78 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 g_02148BF4[];

void func_0206AA78(int idx, u32 v)
{
    g_02148BF4[idx] = v | (u32)(idx << 30);
}
