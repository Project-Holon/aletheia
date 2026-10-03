/*
 * function: func_021B8EA8
 * address:  0x021B8EA8
 * packet:   pkt_ov070_021B8EA8
 * region:   ov070
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B98C  0x0204B98C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_021B809C  0x021B809C  thumb  ov070
 *   func_0204B92C  0x0204B92C  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_021BACF0  0x021BACF0  thumb  ov070
 *   func_021BB580  0x021BB580  thumb  ov070
 *   func_021BB3F4  0x021BB3F4  thumb  ov070
 *   func_021B6100  0x021B6100  thumb  ov070
 *   func_021B8F0C  0x021B8F0C  thumb  ov070
 */

extern int func_0204B98C();
extern void func_0204B878();
extern void func_021B809C();
extern void func_0204B92C();
extern void func_02045CAC();
extern void func_021BACF0(int p, int mode);
extern void func_021BB580();
extern void func_021BB3F4(int p, int mode);
extern void func_021B6100();
extern void func_021B8F0C(int p);

void func_021B8EA8(int p)
{
    if (func_0204B98C(*(int *)((char *)p + 0x72C)) == 0) {
        func_0204B878(*(int *)((char *)p + 0x72C), 0);
        func_021B809C(p);
        func_0204B92C(*(int *)((char *)p + 0x6A8), 0);
        func_02045CAC(*(int *)((char *)p + 0x51C), 0x8A, *(int *)((char *)p + 0x528));
        func_021BACF0(p, 0);
        func_021BB580(p, 0);
        func_021BB3F4(p, 0);
        func_021B6100(p, func_021B8F0C);
    }
}
