/*
 * function: func_0218F114
 * address:  0x0218F114
 * packet:   pkt_ov021_0218F114
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Copies 0x18 * count bytes (count = *(int *)(arg1)) from arg0+0x88 to
 * arg1+4, then stores the low byte of count at arg0+0xe8.  Callee of
 * func_0218F14C.  EXACT* (unlabelled follower 0x0218F134).
 *
 * symbols:
 *   func_02082D44   0x02082D44  arm
 */

extern void func_02082D44(void *, void *, int);

void func_0218F114(char *arg0, char *arg1)
{
    func_02082D44(arg1 + 4, arg0 + 0x88, 0x18 * *(int *)arg1);
    *(unsigned char *)(arg0 + 0xe8) = *(int *)arg1;
}
