/*
 * function: func_0220549C
 * address:  0x0220549C
 * packet:   pkt_0220549C
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 */

struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern unsigned char func_02045730(int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
extern void func_0201CE48(int);
extern void func_02045808(int);

void func_0220549C(char *a, int b)
{
    int p;

    func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)(a + 0x6c)), b);
    p = *(int *)(a + 0x6c);
    func_02045334(p);
    func_02045374(p);
    func_02041B6C(func_02045730(p));
    if (*(int *)(a + 0x64) != 0)
        func_0201CE48(*(int *)(a + 0x64));
    if (*(int *)(a + 0x80) != 0)
        func_02045808(*(int *)(a + 0x80));
    *(int *)(a + 0x64) = 0;
    *(int *)(a + 0x80) = 0;
}
