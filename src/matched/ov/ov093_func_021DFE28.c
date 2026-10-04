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
typedef unsigned char  u8;
struct Flag;
extern int func_021C8374(u8 *p, int i);
extern int func_021C83D4(u8 *p);
extern unsigned int func_021C830C(u8 *p);
extern int func_021C7F24(u8 *p, int i);
extern int func_021C7F4C(struct Flag *p);
extern void func_021DD044(void *a, void *b, int c);

void func_021DFE28(int a, void *b, int c)
{
    if (func_021E85F8(c) != 0 && func_021D775C(0x4d) == 0 && func_021C8374(b, c) == 0
        && func_021C83D4(b) == 0 && func_021C830C(b) == 0 && func_021C7F24(b, c) != 0
        && func_021C7F4C(b) != 0) {
        func_021DD044((void *)a, (void *)((int)b), c);
    }
}
