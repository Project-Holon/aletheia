/*
 * function: func_021BA330
 * address:  0x021BA330
 * packet:   pkt_ov213_021BA330
 * region:   ov213
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  8 bytes short (84 vs 92). Original keeps a live zero in r6
 *           (push {r6}) reused for the 3rd argument of two calls and
 *           materialises the 5/6 vs 3/4 branch as separate arms; the natural
 *           C here puts the zero in an immediate and cross-jumps the arms.
 *           Call sequence and relocations all resolve; near miss.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0201DD78  0x0201DD78  thumb
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

extern int func_02045770(int);
extern void func_02043B5C(int, int);
extern void func_0201DD78(int, int, int);
extern void func_0201C7A4(int, int, int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern int func_02045730(int);
extern void func_02041B6C(int);

void func_021BA330(void *p, int a)
{
    int v;
    int x;
    int z = 0;

    func_02043B5C(func_02045770(*(int *)((char *)p + 0x1c)), z);
    if (*(int *)((char *)p + 0x14) == 0) {
        v = 5;
        x = 6;
    } else {
        v = 3;
        x = 4;
    }
    func_0201DD78(v, x, z);
    func_02045770(*(int *)((char *)p + 0x1c));
    func_0201C7A4(*(int *)((char *)p + 0x18), 1, 1, a);
    {
        int q = *(int *)((char *)p + 0x1c);
        func_02045334(q);
        func_02045374(q);
        func_02041B6C(func_02045730(q));
    }
}