/*
 * function: func_021DFE28
 * address:  0x021DFE28
 * packet:   pkt_ov093_021DFE28
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021E85F8  0x021E85F8  thumb  ov093
 *   func_021C8374  0x021C8374  thumb  ov093
 *   func_021C83D4  0x021C83D4  thumb  ov093
 *   func_021C830C  0x021C830C  thumb  ov093
 *   func_021C7F24  0x021C7F24  thumb  ov093
 *   func_021C7F4C  0x021C7F4C  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 */
extern int func_021D775C(int key);
extern int func_021E85F8(int id);
extern int func_021C8374(void *w, int i);
extern int func_021C83D4(void *p);
extern int func_021C830C(void *p);
extern int func_021C7F24(void *p, int k);
extern int func_021C7F4C(void *p);
extern void func_021DD044(int a, int b, int c);

void func_021DFE28(int a, void *b, int c)
{
    if (func_021E85F8(c) != 0 && func_021D775C(0x4d) == 0 && func_021C8374(b, c) == 0
        && func_021C83D4(b) == 0 && func_021C830C(b) == 0 && func_021C7F24(b, c) != 0
        && func_021C7F4C(b) != 0) {
        func_021DD044(a, (int)b, c);
    }
}
