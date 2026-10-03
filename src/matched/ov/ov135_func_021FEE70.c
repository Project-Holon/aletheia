/*
 * function: func_021FEE70
 * address: 0x021FEE70
 * packet: pkt_ov135_021FEE70
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F99F0 0x021F99F0 thumb ov135
 *   func_021FF570 0x021FF570 thumb ov135
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_02045334 0x02045334 arm
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021F882C 0x021F882C thumb ov135
 *   func_021F8154 0x021F8154 thumb ov135
 */
typedef unsigned short u16;
extern int func_021F99F0(void *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern void func_021FF570(u32 v);
extern void func_0201F7A8(void *, unsigned);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 index);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_021F882C(void *, int, int);
extern void func_021F8154(void *, void *, int, unsigned, unsigned, u16, int, void *);
int func_021FEE70(char *p)
{
    unsigned r = func_021F99F0(*(void **)(p + 0xde4));
    switch (r) {
    case 11:
    case -2:
        func_021FF570(0);
        *(int *)(p + 0x28) = 0;
        break;
    case -1: break;
    default:
        func_021FF570(0);
        func_021F882C(p + 0xb56, r, 1);
        *(int *)(p + 0x28) = 0;
        func_02043B5C(func_02045770(*(void **)(p + 0xda4)), 0);
        func_021F8154(*(void **)(p + 0xda4), *(void **)(p + 0xb6c), r, 0, 0, 0x3c40, 1, p + 0xfa0);
        break;
    }
    return 2;
}
