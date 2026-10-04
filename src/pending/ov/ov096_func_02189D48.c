/*
 * function: func_02189D48
 * address: 0x02189D48
 * packet: pkt_ov096_02189D48
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-04 (wave D2 lane 08): first draft, DIFF (8 bytes, size 294 vs 296). Control flow, slots and registers match; only the argument-register order of the two func_021C7E14 calls differs: image 'adds r1,r4' (x) before the field load and 'ldr r2,[sp,#0x10]' (y) last, ours loads y first. Stack slots follow declaration order t,g,j,sel,y,best,n. Tried u32/u8 types for x and y and swapped declaration order.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021B8DE4 0x021B8DE4 thumb ov093
 *   func_021B9AF8 0x021B9AF8 thumb ov093
 *   func_021B99B8 0x021B99B8 thumb ov093
 *   func_021B9C98 0x021B9C98 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D5448 0x021D5448 thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D5B7C 0x021D5B7C thumb ov093
 *   func_021C7E14 0x021C7E14 thumb ov093
 *   func_0218A308 0x0218A308 thumb ov096
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_0201134C(int);
extern u8 func_021B8DE4(u8 *, int);
extern u8 *func_021B9AF8(u8 *, int);
extern int func_021B99B8(u8 *, u32);
extern int func_021B9C98(u8 *, u8 *);
extern u8 func_021D5440(u8 *);
extern int func_021D5448(void *);
extern u16 func_021D54C0(u8 *, u8);
extern int func_021D5B7C(void *);
extern u16 func_021C7E14(u8 *p, int a, int b, u32 c, int e0, int e1);
extern u8 *func_0218A308(void *, u8);
u32 func_02189D48(int a, u8 *p)
{
    int t, k, x, z;
    u8 *g;
    int j, sel, y;
    u32 best;
    int n;
    t = func_0201134C(a);
    k = func_021B8DE4(*(u8 **)(p + 0xB0), p[0x94]);
    g = func_021B9AF8(*(u8 **)(p + 0xB8), k);
    n = func_021B99B8(*(u8 **)(p + 0xB0), k);
    sel = func_021B9C98(g, *(u8 **)(p + 0xBC));
    x = func_021D5440(*(u8 **)(p + 0xBC));
    y = func_021D5440(*(u8 **)(p + 0xC0));
    best = func_021C7E14(*(u8 **)(p + 0xB4), x, y, *(u16 *)(p + 2), 1, t);
    if (sel < 0 || best == 0) {
        *(u32 *)(p + 0x38) = 0;
        return *(u32 *)(p + 0xC4);
    }
    for (j = 0; j < n; j++) {
        u8 *m = func_0218A308(g, j);
        z = func_021D5440(m);
        if (func_021D5B7C(m) != 0 && j != sel) {
            int i;
            *(u32 *)(p + 0x38) = 2;
            for (i = 0; i < func_021D5448(m); i++) {
                u16 c = func_021D54C0(m, i);
                if (i != p[1]) {
                    u32 r = func_021C7E14(*(u8 **)(p + 0xB4), z, y, c, 1, t);
                    if (r > best) {
                        *(u32 *)(p + 0x38) = 1;
                        break;
                    }
                }
            }
        }
    }
    return *(u32 *)(p + 0xC4);
}
