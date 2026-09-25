/*
 * function: func_021B71A0
 * address:  0x021B71A0
 * packet:   pkt_021B71A0
 * region:   ov174
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082A90  0x02082A90  arm
 */

extern void func_02082A90(int, int, int);

void func_021B71A0(int a, int *b, int c, int d, int e)
{
    func_02082A90(*(int *)((char *)(*(int *)((char *)b + 0xc)) + 0x14) + c,
                  d + 0x06000000, e);
}
