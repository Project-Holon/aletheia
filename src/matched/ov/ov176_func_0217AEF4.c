/*
 * function: func_0217AEF4
 * address:  0x0217AEF4
 * packet:   pkt_0217AEF4
 * region:   ov176
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E5440  0x021E5440  thumb  ov177
 */

extern int *func_021E5440(unsigned swap, int heap);

void func_0217AEF4(int *p)
{
    *(int *)((char *)p + 0x24) = (int)func_021E5440(1, *(unsigned short *)p);
}
