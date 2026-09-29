/*
 * function: func_021F88BC
 * address:  0x021F88BC
 * packet:   pkt_ov094_021F88BC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf, filed for the caller ov093 func_021D284C (lane S16).
 * Sets bit 26 of the word at 0x1EC of the work object at d_0220AF20.
 *
 * symbols:
 *   d_0220AF20     0x0220AF20  data   ov094
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    char pad[0x1EC];
    u32 lo : 26;
    u32 flag : 1;
    u32 hi : 5;
} Work;

extern Work *d_0220AF20;

void func_021F88BC(u32 v)
{
    d_0220AF20->flag = v;
}
