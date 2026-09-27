/*
 * function: func_021B98B8
 * address:  0x021B98B8
 * packet:   pkt_ov217_021B98B8
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker:  byte-correct; caps at MATCH because 0x021C2E30 (and 0x021C2E60
 *           under the contested ov217 hint) are data targets whose only
 *           pool word image-wide is the one inside this range, so no
 *           outside witness exists (sole-ref/data has no start there either).
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02040588  0x02040588  arm
 *   d_021C2E30     0x021C2E30  data  ov217  a4
 *   d_021C2E60     0x021C2E60  data  ov217  a4
 *   d_021C2E40     0x021C2E40  data  ov217  a4
 *   d_021C2E80     0x021C2E80  data  ov217  a4
 */

extern void func_0203F8F4(void);
extern void func_0203FC28(void *);
extern void func_0203FCA0(int, void *, int);
extern void func_02040588(int, int);
extern int d_021C2E30;
extern int d_021C2E60;
extern int d_021C2E40;
extern int d_021C2E80;

void func_021B98B8(void)
{
    func_0203F8F4();
    func_0203FC28(&d_021C2E30);
    func_0203FCA0(4, &d_021C2E60, 0);
    func_0203FCA0(5, &d_021C2E40, 0);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_0203FCA0(1, &d_021C2E80, 0);
    func_02040588(1, 1);
}