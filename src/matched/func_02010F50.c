/*
 * function: func_02010F50
 * address:  0x02010F50
 * packet:   pkt_02010EEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_0214621C  0x0214621C  data
 *   g_02146228  0x02146228  data
 *   g_021461E8  0x021461E8  data
 *
 * Clears slot `idx` of the same thirteen-entry counter table and marks the byte
 * table g_0214621C; if the slot was the selected one (g_02146228[0x1c]) the
 * selection is reset to 0xd.  The bound test is SIGNED (`bge`, not `bhs`): the
 * index is an int.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010F50.c \
 *       --func func_02010F50 --addr 0x02010F50 --cc 1.1p1 --thumb
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern u8 g_0214621C[];
extern u8 g_02146228[];
extern u32 g_021461E8[];

void func_02010F50(int idx)
{
    if (idx >= 0xd) {
        return;
    }
    g_0214621C[idx] = 0x30;
    g_021461E8[idx] = 0;
    if (g_02146228[0x1c] == idx) {
        g_02146228[0x1c] = 0xd;
    }
}
