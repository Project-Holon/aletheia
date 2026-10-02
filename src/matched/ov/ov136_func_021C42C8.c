/*
 * function: func_021C42C8
 * address:  0x021C42C8
 * packet:   pkt_ov136_021C42C8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C4AF8 0x021C4AF8 thumb ov136
 *   func_021C4BFC 0x021C4BFC thumb ov136
 *   func_021C4B5C 0x021C4B5C thumb ov136
 *   func_021C4D14 0x021C4D14 thumb ov136
 *   data_021C7774 0x021C7774 data
 *   func_0202223C 0x0202223C thumb
 *   func_02022224 0x02022224 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_020434DC 0x020434DC arm
 *   func_02022230 0x02022230 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_020056BC 0x020056BC thumb
 *   func_0202173C 0x0202173C thumb
 *   func_02021ED8 0x02021ED8 thumb
 *   func_0202DBC4 0x0202DBC4 thumb
 *   func_02028178 0x02028178 thumb
 *   func_02030EAC 0x02030EAC arm
 *   func_0204A600 0x0204A600 arm
 *   func_02030D28 0x02030D28 arm
 *   func_020310C4 0x020310C4 arm
 *   func_0201C4E4 0x0201C4E4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int (*Step021C42C8)(u8 *p);
extern void func_021C4AF8(void);
extern int func_021C4BFC(u8 *p);
extern void func_021C4B5C(void *a, u32 *p);
extern int func_021C4D14(u8 *p);
extern Step021C42C8 data_021C7774[];
extern void func_0202223C(u32 a, u32 b);
extern void func_02022224(u32 a);
extern void *func_020056A0(void *callback, void *ctx, int a2);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02022230(u32 a);
extern void func_0207D63C(void *reg, int a, int b, int c, int d);
extern u32 func_020056BC(void);
extern void func_0202173C(void *p, int a, int b, int c, int d, int e, int f, u32 g);
extern int func_02021ED8(void *p);
extern void func_0202DBC4(void *p);
extern void func_02028178(void *p);
extern void func_02030EAC(void *p);
extern void func_0204A600(void *p);
extern void func_02030D28(void *p);
extern void func_020310C4(void *p);
extern void func_0201C4E4(void *p);

int func_021C42C8(u8 *p)
{
    int r = 0;
    u32 t;

    switch (*(u32 *)(p + 4)) {
    case 0:
        func_021C4AF8();
        func_0202223C(0, 0);
        func_0202223C(1, 0);
        func_02022224(0);
        func_02022224(1);
        (*(u32 *)(p + 4))++;
        break;
    case 1:
        if (func_021C4BFC(p)) {
            *(void **)(p + 0x104) = func_020056A0((void *)func_021C4B5C, p, 0x10);
            func_020434DC(0x10, 1);
            func_02022230(0);
            func_0207D63C((void *)0x04000050, 4, 8, 0x1C, 4);
            t = func_020056BC();
            func_0202173C(*(void **)(p + 0x38), 5, 0xFFFF, -1, 0x10, 0, 0, t);
            (*(u32 *)(p + 4))++;
        }
        break;
    case 2:
        if (!func_02021ED8(*(void **)(p + 0x38)))
            (*(u32 *)(p + 4))++;
        func_0202DBC4(*(void **)(p + 0x148));
        break;
    case 3:
        if (data_021C7774[p[0xB]](p) == 1) {
            (*(u32 *)(p + 4))++;
            t = func_020056BC();
            func_0202173C(*(void **)(p + 0x38), 5, 0xFFFF, -1, 0, 0x10, 0, t);
        }
        func_0202DBC4(*(void **)(p + 0x148));
        if (*(void **)(p + 0x128)) {
            func_02028178(*(void **)(p + 0x128));
            func_02028178(*(void **)(p + 0x12C));
        }
        break;
    case 4:
        if (!func_02021ED8(*(void **)(p + 0x38))) {
            func_0202223C(0, 0);
            func_0202223C(1, 0);
            func_02030EAC(*(void **)(p + 0x104));
            func_021C4AF8();
            (*(u32 *)(p + 4))++;
        }
        func_0202DBC4(*(void **)(p + 0x148));
        break;
    case 5:
        if (func_021C4D14(p))
            r = 1;
        break;
    }
    if (*(void **)(p + 0xA0))
        func_0204A600(*(void **)(p + 0xA0));
    if (*(void **)(p + 0xF8))
        func_02030D28(*(void **)(p + 0xF8));
    if (*(void **)(p + 0x100))
        func_020310C4(*(void **)(p + 0x100));
    if (*(void **)(p + 0x98))
        func_0201C4E4(*(void **)(p + 0x98));
    if (*(void **)(p + 0x158))
        func_0201C4E4(*(void **)(p + 0x158));
    return r;
}
