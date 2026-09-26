/*
 * function: func_021B6B8C
 * address:  0x021B6B8C
 * packet:   pkt_ov098_021B6B8C
 * region:   ov098
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  codegen only, 14 of 168 bytes; a pure callee-saved colouring swap
 *   plus one schedule swap.  The second parameter b and the `x` flag are the
 *   two live-across-call temporaries; the image keeps b in r4 and x in r7
 *   (later `strb r7,[a+0x38]`, `adds r0,r7,#0`), mwcc keeps b in r6 and x in
 *   r4.  The only other difference is at +0x9E: the original issues
 *   `strh r1,[a+0x42]; adds r5,#0x3a` where mwcc does `adds r5,#0x3a` first.
 *   Everything else, all 10 resolved relocations included, is byte-exact.
 *   Ceiling is MATCH anyway: func_0201CE0C's only reference image-wide is the
 *   call inside this range, so that site stays wildcarded.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02040588  0x02040588  arm
 *   func_02045374  0x02045374  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02045334  0x02045334  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201CE0C  0x0201CE0C  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 */

typedef unsigned short u16;

extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_02040588(int, int);
extern void func_02045374(int);
extern void func_020409B4(int);
extern void func_02045334(int);
extern void func_0201DD78(int, int, int);
extern int func_0201CCE4(int, int, int, int, int, int, int, int, int, int);
extern void func_0201CE0C(void);
extern void func_0201C7A4(int, int, int, int, int);

void func_021B6B8C(int a, int b)
{
    int x;

    func_02043B5C(func_02045770(*(int *)(a + 0x1c)), 0xc);
    func_0201DD78(1, 9, 0xc);
    func_02040588(1, 1);
    x = 1;
    if (b != 0) {
        *(int *)a = func_0201CCE4(*(int *)(a + 0x1c), 0, 0,
                                  *(int *)(a + 0x2c), *(int *)(a + 0x24),
                                  *(int *)(a + 0x34), *(int *)(a + 0x28), 0,
                                  *(u16 *)(a + 0x44), 0xc);
        func_0201CE0C();
        x = 0;
    } else {
        func_0201C7A4(func_02045770(*(int *)(a + 0x1c)), 0, 0,
                      *(int *)(a + 0x2c), *(int *)(a + 0x24));
        func_02045374(*(int *)(a + 0x1c));
        func_020409B4(1);
        func_02045334(*(int *)(a + 0x1c));
    }
    *(char *)(a + 0x38) = x;
    *(char *)(a + 0x39) = 0;
    *(u16 *)(a + 0x40) = b;
    *(u16 *)(a + 0x42) = b;
    *(char *)(a + 0x3a) = 0;
}
