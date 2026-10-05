/*
 * function: func_0202ACCC
 * address:  0x0202ACCC
 * packet:   pkt_0202ACCC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Dispatches on the state word returned by func_0202ABF8 over a three-way
 * state machine.  One `switch` on the call result is what puts the result
 * straight into r0 for all three `cmp`s: a named local would have stored it.
 *
 * symbols:
 *   func_0202ABF8  0x0202ABF8  thumb
 *   func_0202ACFC  0x0202ACFC  thumb
 *   func_0202AD10  0x0202AD10  thumb
 *   func_0202AD44  0x0202AD44  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202ACCC.c \
 *       --func func_0202ACCC --addr 0x0202ACCC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0202ABF8(void *obj);
extern void func_0202ACFC(u8 *p);
extern void func_0202AD10(void *obj);
extern void func_0202AD44(void *obj);

void func_0202ACCC(u8 *p)
{
    switch (func_0202ABF8(p)) {
    case 0:
        func_0202ACFC(p);
        break;
    case 1:
        func_0202AD10(p);
        break;
    case 2:
        func_0202AD44(p);
        break;
    }
}
