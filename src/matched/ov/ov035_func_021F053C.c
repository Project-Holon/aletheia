/*
 * function: func_021F053C
 * address:  0x021F053C
 * packet:   pkt_ov035_021F053C
 * region:   ov035
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F053C 0x021F053C thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045788 0x02045788 arm
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_021F0254 0x021F0254 thumb ov035
 *   func_020221A4 0x020221A4 thumb
 *   func_02035C60 0x02035C60 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Cfg;
struct Descriptor;
extern void func_020456F8(struct Descriptor *d);
extern void func_02045788(struct Descriptor *p, u8 v);
struct Descriptor;
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern void func_021F0254(char *p, int a1, int a2);
extern u32 func_020221A4(void);
extern u32 func_02035C60(void);

int func_021F053C(char *p)
{
    switch (*(u16 *)(p + 0x4A)) {
    case 0:
        func_020456F8((struct Descriptor *)(*(int *)(p + 0x18)));
        func_020456F8((struct Descriptor *)(*(int *)(p + 0x1C)));
        func_02045788((struct Descriptor *)(*(int *)(p + 0x1C)), 6);
        func_02045334((struct Descriptor *)*(int *)(p + 0x1C));
        func_02045374((struct Cfg *)(*(int *)(p + 0x1C)));
        func_021F0254(p, *(int *)(p + 0x1C), 4);
        (*(u16 *)(p + 0x4A))++;
        break;
    case 1:
        if (func_020221A4() == 1)
            (*(u16 *)(p + 0x4A))++;
        break;
    case 2:
        if (func_02035C60() != 0)
            (*(u16 *)(p + 0x4A))++;
        break;
    case 3:
        return 1;
    }
    return 0;
}
