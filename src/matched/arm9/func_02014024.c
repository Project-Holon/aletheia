/*
 * function: func_02014024
 * address:  0x02014024
 * packet:   pkt_02014024
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02013B10  0x02013B10  thumb
 *   d_0209DFD2     0x0209DFD2  data
 */

typedef unsigned int u32;

typedef signed int     s32;
typedef unsigned short u16;
extern u32 func_02013B10(u32 id, const u16 *table, s32 count);
extern const char d_0209DFD2[];

int func_02014024(u32 a)
{
    return func_02013B10(a, (const u16 *)d_0209DFD2, 5);
}
