/*
 * function: func_021C49D0
 * address:  0x021C49D0
 * packet:   pkt_ov136_021C49D0
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02028218 0x02028218 thumb
 *   func_0202822C 0x0202822C thumb
 *   func_02028230 0x02028230 thumb
 *   func_020282A4 0x020282A4 thumb
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02027974 0x02027974 thumb
 *   func_0201F7A8 0x0201F7A8 thumb
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02021FD8 0x02021FD8 thumb
 *   func_02028454 0x02028454 thumb
 *   func_021C47C4 0x021C47C4 thumb ov136
 *   func_021C44FC 0x021C44FC thumb ov136
 *   func_021C48FC 0x021C48FC thumb ov136
 *   func_021C4998 0x021C4998 thumb ov136
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02028218(void *obj, u32 a);
extern void func_0202822C(void *p, int v);
extern int func_02028230(void *p);
extern void func_020282A4(void *p);
extern u32 func_0201CE30(void *h);
extern void func_0201CE48(void *h);
extern void func_02027974(void *p);
extern void func_0201F7A8(void *p, u32 a);
extern int func_020456F8(void *p);
extern int func_02045730(void *p);
extern void func_020409B4(u32 index);
extern void func_02021FD8(void *p, u32 idx, u32 c, u32 count, u32 e, u32 f);
extern void func_02028454(void *p);
extern void func_021C47C4(u8 *p, int n);
extern void func_021C44FC(u8 *p);
extern void func_021C48FC(u8 *p);
extern int func_021C4998(u8 *p);

int func_021C49D0(u8 *p)
{
    int r;
    void *w;

    switch (*(u16 *)(p + 8)) {
    case 0:
        func_02028218(*(void **)(p + 0x128), 0);
        func_0202822C(*(void **)(p + 0x12C), 1);
        break;
    case 1:
        if (func_02028230(*(void **)(p + 0x12C))) {
            func_020282A4(*(void **)(p + 0x12C));
            func_02028218(*(void **)(p + 0x12C), 1);
            *(int *)(p + 0x10) = 1;
            func_021C47C4(p, 3);
            func_021C44FC(p);
            p[0x1B] = p[0x1A];
            break;
        }
        return 0;
    case 2:
        if (func_0201CE30(*(void **)(p + 0x9C)) == 2) {
            func_0201CE48(*(void **)(p + 0x9C));
            func_021C48FC(p);
            *(u16 *)(p + 8) = 3;
        }
        return 0;
    case 3:
        func_02027974(*(void **)(p + 0x10C));
        r = func_021C4998(p);
        if (r < 0)
            return 0;
        func_0201F7A8(*(void **)(p + 0x5C), 2);
        w = *(void **)(p + 0x5C);
        func_020456F8(w);
        func_020409B4(func_02045730(w));
        *(u16 *)(p + 8) = 0;
        if (r == 0) {
            **(u16 **)(p + 0x1C) = 0xFFFF;
            p[0xB] = p[0xC];
            return 1;
        }
        *(int *)(p + 0x10) = 0;
        p[0xB] = p[0xC];
        func_02021FD8(*(void **)(p + 0x38), 0, 0, 0x30, 0, 0);
        func_02028454(*(void **)(p + 0x128));
        func_02028454(*(void **)(p + 0x12C));
        return 0;
    }
    (*(u16 *)(p + 8))++;
    return 0;
}
