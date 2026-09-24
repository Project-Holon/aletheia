/*
 * function: func_0219B030
 * address:  0x0219B030
 * packet:   pkt_0219B030
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   func_02197EDC  0x02197EDC  thumb  ov021
 *   func_0216DA50  0x0216DA50  thumb
 *   func_0219B358  0x0219B358  thumb  ov021
 *   func_0219B404  0x0219B404  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_0216DA50(u32);
extern u32 func_02197EDC(u32, u32, u32, u32);
extern u32 func_0219B358(u32);
extern u32 func_0219B404(u32, u32);

int func_0219B030(u32 a, u32 b, u32 c, u32 d)
{
if (func_02197EDC(a, b, c, d) == 1) {
    func_0216DA50(a);
    if (func_0219B358(a) == 1) {
        func_0219B404(a, (b + 8));
    }
    *(u8 *)((u8 *)(b)) = 0;
}
return 0;
}

