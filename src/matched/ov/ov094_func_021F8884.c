/*
 * function: func_021F8884
 * address:  0x021F8884
 * packet:   pkt_ov094_021F8884
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Stores the low 8 bits of the argument in bits 18..25 of the word at 0x1ec of the global work block.
 *
 * symbols:
 *   d_0220AF20  0x0220AF20  data  ov094
 */
typedef struct {
    char pad[0x1ec];
    unsigned lo : 18;
    unsigned v : 8;
} Work;

extern Work *d_0220AF20;

void func_021F8884(int a)
{
    d_0220AF20->v = a;
}
