/*
 * function: func_021B9670
 * address:  0x021B9670
 * packet:   pkt_ov099_021B9670
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5F30  0x021C5F30  thumb  ov127
 *   func_021B9DB0  0x021B9DB0  thumb  ov099
 *   func_021BA648  0x021BA648  thumb  ov099
 *   func_021B9B80  0x021B9B80  thumb  ov099
 *   func_021B9D5C  0x021B9D5C  thumb  ov099
 *   func_021C48C0  0x021C48C0  thumb  ov127
 *   func_021C47E4  0x021C47E4  thumb  ov127
 *   func_021B9DD4  0x021B9DD4  thumb  ov099
 *   func_021B9E08  0x021B9E08  thumb  ov099
 *   func_02082BCC  0x02082BCC  arm
 */

extern void func_021C5F30(int);
extern void func_021B9DB0(char *p);
extern void func_021BA648(char *p, char *q);
extern void func_021B9B80(char *p);
extern void func_021B9D5C(char *p);
extern void func_021C48C0(int);
extern void func_021C47E4(int);
extern void func_021B9DD4(char *p);
extern void func_021B9E08(int);
extern void func_02082BCC(void *p, int v, int n);

void func_021B9670(char *p)
{
    func_021C5F30(*(int *)(p + 0x59c));
    func_021B9DB0(p);
    func_021BA648(p, p + 0x574);
    func_021B9B80(p);
    func_021B9D5C(p);
    func_021C48C0(*(int *)(p + 0x58c));
    func_021C47E4(*(int *)(p + 0x588));
    func_021B9DD4(p + 0x14);
    func_021B9E08(*(int *)(p + 0x10));
    func_02082BCC(p, 0, 0x5a0);
}
