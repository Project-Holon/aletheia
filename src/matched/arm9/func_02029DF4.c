/*
 * function: func_02029DF4
 * address:  0x02029DF4
 * packet:   pkt_02029DF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02029EB4  0x02029EB4  thumb
 *
 * Plain forwarder to func_02029EB4 (ldr r3, =target; bx r3).  Seeded in
 * layout/function_starts.txt from the bl sites in ov020 and ov021
 * (w6_fix18).
 */

extern unsigned int func_02029EB4(void *a, unsigned int id, unsigned int which);

unsigned int func_02029DF4(void *a, unsigned int id, unsigned int which)
{
    return func_02029EB4(a, id, which);
}
