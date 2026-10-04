/*
 * function: func_021B8688
 * address:  0x021B8688
 * packet:   pkt_ov070_021B8688
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  
 *
 * symbols:
 *   func_020221A4  0x020221A4  thumb
 *   func_021BB690  0x021BB690  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_021B8AF4  0x021B8AF4  thumb  ov070
 */

extern int func_020221A4();
extern int func_021BB690();
struct Obj;
extern void func_0204B92C(struct Obj *, unsigned int);
extern void func_021B8AF4();

void func_021B8688(int p)
{
    int a = func_020221A4(p);
    int b = func_021BB690(p);
    if (a == 1 && b == 0) {
        func_0204B92C((struct Obj *)*(int *)((char *)p + 0x6A8), 1);
        func_021B8AF4(p);
    }
}
