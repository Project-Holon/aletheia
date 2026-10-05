/*
 * function: func_021FC4E8
 * address:  0x021FC4E8
 * packet:   pkt_021FC4E8
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021FC598  0x021FC598  thumb  ov186
 *   func_021FC604  0x021FC604  thumb  ov186
 */

extern void func_021FC598(void *);
extern void func_021FC604(void *);

void func_021FC4E8(int a0, char *p)
{
    func_021FC598(p);
    func_021FC604(p + 4);
}
