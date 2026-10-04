/*
 * function: func_021B9AE4
 * address:  0x021B9AE4
 * packet:   pkt_ov218_021B9AE4
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * note (2026-10-04): DIFF, 81 bytes. Structure and calls match. Original has push {r4-r7,lr}, sub sp,#0x1c, loads d first (ldr r7,[sp,#0x30]) and spills t=0x83-d to [sp,#0x18], reloaded as the 3rd arg of func_0201EFA4, with a and b spilled to [sp,#0x10]/[sp,#0x14]. Compiled keeps t in r7 and pushes r3 (frame 0x18). Need t spilled while d stays in r7. Tried r/t declaration order and int d.
 *
 * note (2026-10-04, wD2 lane07): also tried no t variable (0x83 - d written twice, compiler CSEs it identically): same output.
 *   The compiler gives r7 to t and reloads d from [sp,#0x30]; the original keeps d in r7 and spills t to [sp,#0x18].
 *
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021B6AE4 0x021B6AE4 thumb ov067
 *   func_0201D2C8 0x0201D2C8 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_02045CAC(void *bank, u32 index, void *dest);
extern void func_0201EFA4(void *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(void *ws, void *dst, void *src);
extern void func_021B6AE4(u8 *p, u32 a, u16 b, u16 c, u32 s0, u32 s1, u16 s2, u32 s3);
extern u32 func_0201D2C8(u32 v);
void func_021B9AE4(u8 *p, u8 *a, u32 b, u32 c, u32 d)
{
    u32 t = 0x83 - d;
    u32 r = 12;
    func_02045CAC(*(void **)(p + 8), (t == 2) ? 0xF0 : 0xED, *(void **)(p + 0x18));
    func_0201EFA4(*(void **)(p + 0x14), 2, t, 3, 0, 1);
    func_0201F250(*(void **)(p + 0x14), *(void **)(p + 0x1C), *(void **)(p + 0x18));
    func_021B6AE4(a, b, 0, 12, *(u32 *)(p + 0x1C), c, 0x39E0, 0);
    p += 0x2C;
    if (func_0201D2C8(*(u32 *)(p + d * 4)) > 1) r = 4;
    func_021B6AE4(a, b, 0x1E, r, *(u32 *)(p + d * 4), c, 0x39E0, 0);
}
