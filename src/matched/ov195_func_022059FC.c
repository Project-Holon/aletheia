/*
 * function: func_022059FC
 * address:  0x022059FC
 * packet:   pkt_022059FC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02205BC8 0x02205BC8 thumb
 *   func_02205B60 0x02205B60 thumb
 */

extern void func_02205BC8(void *);
extern void func_02205B60(void *);

void func_022059FC(char *a)
{
    func_02205BC8(a + 4);
    func_02205B60(a);
}