/*
 * function: func_021F3D38
 * address: 0x021F3D38
 * packet: pkt_ov051_021F3D38
 * region: ov051
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Scalar stack slots reproduce the In3 aggregate: 0216CE84/8A/8E
 *       read only low halfwords at incoming +0/+4/+8; padding is unread.
 *       The fourth outgoing word feeds x at 0216CE90; 0216CE60 forwards
 *       only the constructed Big record, never the original padding.
 * symbols:
 *   func_02188C7C 0x02188C7C thumb ov021
 *   func_02188C9C 0x02188C9C thumb ov021
 *   func_0216CE6C 0x0216CE6C thumb ov010
 */

extern void *func_02188C7C(int);
extern int func_02188C9C(int);
extern void *func_0216CE6C(void *, int, int, unsigned short, unsigned, unsigned, unsigned, unsigned);

void *func_021F3D38(int a, int x, int y)
{
    void *p = func_02188C7C(a);
    int n = func_02188C9C(a);
    return func_0216CE6C(p, (short)x, (short)y, 0, 0xfd, 0, 0, n);
}
