/*
 * function: func_021C64A8
 * address:  0x021C64A8
 * packet:   pkt_ov136_021C64A8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note 2026-10-02: DIFF. Everything matches except two points.
 *   1) Second loop: original keeps 0x1F0 in r7 and re-emits movs r1,#1 in the loop;
 *      ours hoists the constant 1 into r7 (shared with the tail 'k = 1') and rebuilds 0x1F0.
 *   2) Tail: original loads *(p+8) once for the v<=10 test and reuses r0 on the else path
 *      (reload only after the call in the then arm); ours reloads r0 after the k test.
 *   Tried: struct array field, local q, u8/u16 param, v local, ||/&& ternary tail.
 *
 * symbols:
 *   func_020434DC   0x020434DC  arm
 *   func_02043598   0x02043598  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_021C65A8 0x021C65A8 thumb
 *   func_021C660C 0x021C660C thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C6738 0x021C6738 thumb
 *   func_021C675C 0x021C675C thumb
 *   func_021C67D4 0x021C67D4 thumb
 *   d_021C7BBC 0x021C7BBC data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u8 d_021C7BBC[];
extern void func_020434DC(u32, u32);
extern void func_02043598(u32, u32);
extern void func_021C6738(u8 *);
extern void func_021C65A8(u8 *);
extern void func_021C67D4(u8 *);
extern void func_021C675C(u8 *);
extern void *func_021C660C(u8 *, const u8 *);
extern void func_0204B92C(void *, int);
extern void func_021C66B8(u8 *, int, u32);
void func_021C64A8(u8 *p)
{
    u32 i;
    u32 k;
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    for (i = 0; i < 8; i++) {
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x210) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x230) = 0;
        *(u32 *)(*(u8 **)(p + 8) + i * 4 + 0x250) = 0;
    }
    func_021C6738(*(u8 **)(p + 8));
    func_021C65A8(*(u8 **)(p + 8));
    func_021C67D4(*(u8 **)(p + 8));
    func_021C675C(*(u8 **)(p + 8));
    for (i = 0; i < 8; i++) {
        *(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0) = func_021C660C(*(u8 **)(p + 8), d_021C7BBC + i * 0x34);
        func_0204B92C(*(void **)(*(u8 **)(p + 8) + i * 4 + 0x1F0), 1);
    }
    if (*(u16 *)(*(u8 **)(p + 8) + 0x2FC) <= 10) {
        func_021C66B8(*(u8 **)(p + 8), 0, 0);
        k = 1;
    } else {
        k = (*(u16 *)(p + 0x1C) == 0) ? 0 : 1;
    }
    func_021C66B8(*(u8 **)(p + 8), k, 0);
    func_021C66B8(*(u8 **)(p + 8), 4, 0);
    func_021C66B8(*(u8 **)(p + 8), 5, 0);
    func_021C66B8(*(u8 **)(p + 8), 6, 0);
}
