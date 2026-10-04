/*
 * function: func_021BAF7C
 * address: 0x021BAF7C
 * packet: pkt_ov206_021BAF7C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern int func_0201C6C4(int, int);
extern void func_02045334(int);
extern void func_02045374(int);
extern int func_02045730(int);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void func_021BAF7C(char *p)
{
    int i;
    for (i = 0; i < 4; i++) {
        char *slot = p + i * 4;
        if (*(int *)(slot + 0x7c) == 0 && func_0201C6C4(*(int *)(p + 0x2c), (int)func_02045770((struct Descriptor *)*(int *)(slot + 0x6c))) == 0) {
            int window = *(int *)(slot + 0x6c);
            func_02045334(window);
            func_02045374(window);
            func_02041B6C(func_02045730(window));
            *(int *)(slot + 0x7c) = 1;
        }
    }
}
