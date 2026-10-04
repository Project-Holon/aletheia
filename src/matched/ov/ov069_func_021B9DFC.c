/*
 * function: func_021B9DFC
 * address:  0x021B9DFC
 * packet:   pkt_ov069_021B9DFC
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045770  0x02045770  arm
 *   func_02045334  0x02045334  arm
 */

extern void func_0201C4E4(int);
extern int func_0201C6C4(int, int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02045334(int);

void func_021B9DFC(unsigned char *p)
{
    int i;
    int h;

    func_0201C4E4(*(int *)(p + 0xE8));
    for (i = 0; i < 18; i++) {
        h = *(int *)(p + 0xE8);
        if (p[i * 8 + 0x5C] != 0) {
            if (func_0201C6C4(h, (int)func_02045770((struct Descriptor *)*(int *)(p + i * 8 + 0x58))) == 0) {
                func_02045334(*(int *)(p + i * 8 + 0x58));
                p[i * 8 + 0x5C] = 0;
            }
        }
    }
}
