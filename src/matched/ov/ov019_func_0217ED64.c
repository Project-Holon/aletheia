/*
 * function: func_0217ED64
 * address:  0x0217ED64
 * packet:   pkt_ov019_0217ED64
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   d_02180390     0x02180390  data  a2
 *
 * Two-column u16 table indexed by func_020056EC(4); same shape as
 * func_0217ED48 (table 0x02180360). The 204 bytes after the pool are
 * seventeen unlabelled u16-table leaves, each filed on its own.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_020056EC(u32 v);
extern const u16 d_02180390[][2];

u16 func_0217ED64(int i)
{
    return d_02180390[func_020056EC(4)][i];
}
