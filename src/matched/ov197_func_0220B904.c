/*
 * function: func_0220B904
 * address:  0x0220B904
 * packet:   pkt_0220B904
 * region:   ov197
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0220B928 0x0220B928 thumb
 */

extern void func_0201F73C(void *, int, int, int);
extern int func_02045770(void *);
extern void func_02043B5C(int, int);
extern void func_0220B928(void *);

void func_0220B904(char *p)
{
    func_0201F73C(*(void **)(p + 0x24), 2, 1, 0xb);
    func_02043B5C(func_02045770(*(void **)(p + 0x24)), 0xf);
    func_0220B928(p);
}
