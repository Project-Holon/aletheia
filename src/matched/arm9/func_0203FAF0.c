/*
 * function: BG_SYS_CheckFAF0
 * address:  0x0203FAF0
 * packet:   pkt_0203FA08
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_02146A44    0x02146A44  data
 *   BG_SYS_GetField17 0x020416B8  arm
 *   func_020341F0 0x020341F0  arm
 *   _u32_div_f    0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *g_02146A44;
extern u8 BG_SYS_GetField17(int channel);
typedef signed int     s32;
struct AreaMan;
extern s32 func_020341F0(struct AreaMan *p, u32 start, u32 len);

u32 BG_SYS_CheckFAF0(u32 a, u32 b, u32 c)
{
    u32 d = BG_SYS_GetField17(a & 0xff);

    d = *(u32 *)(g_02146A44 + 0x170 + a * 4) / d;
    return func_020341F0((struct AreaMan *)((a < 4) ? *(u32 *)(g_02146A44 + 0x168) : *(u32 *)(g_02146A44 + 0x16c)),
                  d + b, c);
}
