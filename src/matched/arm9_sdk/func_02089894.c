/*
 * function: func_02089894
 * address:  0x02089894
 * packet:   pkt_02089880
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02086078    0x02086078  arm
 *   s_data_02151454  0x02151454  data
 */

extern void func_02086078(void *arg);
extern void *s_data_02151454;

void func_02089894(void)
{
    func_02086078(&s_data_02151454);
}
