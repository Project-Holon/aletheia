/*
 * function: func_021C3FC8
 * address:  0x021C3FC8
 * packet:   pkt_ov136_021C3FC8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status: EXACT*
 *
 * note:     2026-10-02 only unresolved arm9 Thumb leaf witnesses (02024104, 02024108, 02024450 unmanifested); C is complete
 *
 * symbols:
 *   func_021C3FC8 0x021C3FC8 thumb
 *   func_0202428C 0x0202428C thumb
 *   func_02024044 0x02024044 thumb
 *   func_02024104 0x02024104 thumb
 *   func_02024570 0x02024570 thumb
 *   func_02024450 0x02024450 thumb
 *   func_020242A4 0x020242A4 thumb
 *   func_02024108 0x02024108 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0202428C(void *p);
struct Obj;
extern struct Obj *func_02024044(u32 kind, u32 a1, void *src, u32 flag, void *sys, u32 hh);
extern void func_02024104(u16 *p, u16 v);
extern void func_02024570(void *dst, const void *src);
extern int func_02024450(const u16 *p);
extern void func_020242A4(void *obj, u32 id);
extern void func_02024108(void *o, void *src);
void func_021C3FC8(u8 *ctx, u8 *arg)
{
    u8 *p = *(u8 **)(ctx + 0x10);
    u32 k = p[2];
    if (k == 3) {
        func_0202428C(ctx + 0x14);
        *(u16 *)(ctx + 0x14) = 6;
        *(u16 *)(ctx + 0x16) = 0;
        *(u16 *)(ctx + 0x18) = *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32);
        *(void **)(ctx + 8) = func_02024044(0, 0, 0, 1, *(void **)(arg + 0x10), *(u32 *)ctx);
        func_02024104(*(void **)(ctx + 8), *(u16 *)(*(u8 **)(ctx + 0x10) + 0x32));
    } else if (*(p + k + 0x2e) == 1) {
        func_02024570(ctx + 0x14, p + 0x16 + k * 8);
        *(void **)(ctx + 8) = func_02024044(2, 0, ctx + 0x14, 1, *(void **)(arg + 0x10), *(u32 *)ctx);
    } else {
        *(void **)(ctx + 8) = func_02024044(2, 0, 0, 1, *(void **)(arg + 0x10), *(u32 *)ctx);
        if (func_02024450((u16 *)(*(u8 **)(ctx + 0x10) + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8)))
            func_02024570(ctx + 0x14, *(u8 **)(ctx + 0x10) + 0x16 + (*(u8 **)(ctx + 0x10))[2] * 8);
        else
            func_020242A4(ctx + 0x14, 0);
        func_02024108(*(void **)(ctx + 8), ctx + 0x14);
    }
}
