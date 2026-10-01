/*
 * function: func_021BFF00
 * address: 0x021BFF00
 * packet: pkt_ov217_021BFF00
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: p + i * 4 + 0x2d4 keeps the indexed base before the call; p + 0x2d4 + i * 4 differed by 23 bytes.
 * symbols:
 *   func_021BF9F0 0x021BF9F0 thumb ov217
 *   func_021BF9FC 0x021BF9FC thumb ov217
 *   func_021C26E8 0x021C26E8 thumb ov217
 *   func_021C2740 0x021C2740 thumb ov217
 */
typedef unsigned int u32;
typedef unsigned short u16;
struct Params { u32 handles[3]; u16 a, b, c; };
extern u32 func_021BF9F0(void *, u32);
extern u32 func_021BF9FC(void *, u32);
extern u32 func_021C26E8(u32, u32, u32);
extern void func_021C2740(u32, u32);
void func_021BFF00(char *p)
{
    struct Params args;
    int i;
    args.handles[0] = func_021BF9F0(p, 0);
    args.handles[1] = func_021BF9F0(p, 1);
    args.handles[2] = func_021BF9F0(p, 2);
    args.a = 0;
    args.b = 12;
    args.c = 13;
    for (i = 0; i < 10; i++) {
        *(u32 *)(p + i * 4 + 0x2d4) = func_021C26E8(*(u16 *)(p + 4), (u32)&args, func_021BF9FC(p, 3));
        func_021C2740(*(u32 *)(p + i * 4 + 0x2d4), 0);
    }
}
