/*
 * function: func_027022F8
 * address:  0x027022F8
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0209C0A4  0x0209C0A4  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned long long u64;

extern u64 func_0209C0A4(u32, u32);

u32 func_027022F8(u32 a0, u32 a1) {
    u32 r4 = (u32)func_0209C0A4(0x400, a0);
    if ((s32)r4 > 0x10) r4 = 0x10;
    if ((s32)r4 > 1) {
        do {
            u64 res = func_0209C0A4(a1, r4);
            if ((u32)(res >> 32) == 0) return r4;
            r4--;
        } while ((s32)r4 > 1);
    }
    return 1;
}
