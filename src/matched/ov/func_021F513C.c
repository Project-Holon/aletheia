/*
 * function: func_021F513C
 * address:  0x021F513C
 * packet:   pkt_021F513C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0200F7C0   0x0200F7C0  thumb
 *
 * Shape: mode query pair, then the 0x29 command byte.  0x0200F7C0 is a
 * thumb leaf whose EXACT arm9 entry attests the call once the symbols line
 * declares the true ISA.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012E08(char *p);
extern void func_0200F7C0(u32 c);

void func_021F513C(u8 *p)
{
    func_02012E08(func_020120F4((const struct Ctx *)(*(u32 *)(*(u32 *)p + 0x40))));
    func_0200F7C0(0x29);
}
