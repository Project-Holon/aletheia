/*
 * function: func_021B69FC
 * address:  0x021B69FC
 * packet:   pkt_ov093_021B69FC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9E38  0x021B9E38  thumb  ov093
 *   func_021B9E7C  0x021B9E7C  thumb  ov093
 *   func_021B6954  0x021B6954  thumb  ov093
 */

struct A;
struct B;
extern void func_021B9E38(char *p, int a, int b);
extern void func_021B9E7C(struct A *p, struct B *src);
extern void func_021B6954(int, int);

void func_021B69FC(int a, char *b)
{
    if (*(unsigned char *)(b + 0x23) == 0) {
        func_021B9E38((char *)(a + 0x20), *(unsigned short *)((char *)a + 0x468), *(int *)((char *)a + 0xc0));
        func_021B9E7C((struct A *)(a + 0x48), (struct B *)(*(int *)(b + 0x4c)));
    } else {
        func_021B6954(a, 0);
        func_021B6954(a, 1);
    }
}
