/*
 * function: func_021B6C90
 * address:  0x021B6C90
 * packet:   pkt_ov098_021B6C90
 * region:   ov098
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char u8;

struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(int, int);
extern void func_02045334(struct Descriptor *);

void func_021B6C90(char *p, int flag)
{
    if ((u8)(*(u8 *)(p + 0x14) + 0xff) <= 1) {
        if (flag == 0) {
            func_02043B5C((int)func_02045770((struct Descriptor *)*(int *)p), 0xc);
            func_02045334((struct Descriptor *)*(int *)p);
        }
        *(int *)(p + 4) = 0;
        *(int *)(p + 8) = 0x10000;
        *(int *)(p + 0xc) = 0x52AA;
        *(int *)(p + 0x10) = -0x1800;
        *(u8 *)(p + 0x15) = 6;
        *(u8 *)(p + 0x14) = 4;
    }
}
