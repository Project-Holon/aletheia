/*
 * function: func_021DAE00
 * address:  0x021DAE00
 * packet:   pkt_021DAE00
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   (none)
 *
 * Competition-server completion callback: records a nonzero result at +0x15c and drops the pending-request count at +0x134 (unlabelled; its address is a code pointer in func_021DA6B8's pool).
 */

void func_021DAE00(int result, char *obj)
{
    if (result != 0)
        *(int *)(obj + 0x15c) = result;
    (*(int *)(obj + 0x134))--;
}
