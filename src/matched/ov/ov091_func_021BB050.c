/*
 * function: func_021BB050
 * address:  0x021BB050
 * packet:   pkt_ov091_021BB050
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Three explicit calls to func_020413B0 (last argument 4 / 7 / k), which the
 * compiler cross-jumps at the table load; a shared `v` local set per arm
 * compiles to one call and is 20 bytes short.
 *
 * symbols:
 *   func_021BB554  0x021BB554  thumb  ov091
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   d_021BEC74     0x021BEC74  data  ov091  a1
 *   d_021BEC75     0x021BEC75  data  ov091  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021BB554(u32 p);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 id);
extern const u8 d_021BEC74[];
extern const u8 d_021BEC75[];

void func_021BB050(int unused, u8 *s, int k)
{
    if (k == 3 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 4);
    else if (k == 6 && func_021BB554((u32)s) == 3)
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, 7);
    else
        func_020413B0(2, d_021BEC74[s[4] * 2] + 0x10, d_021BEC75[s[4] * 2], 0x10, 6, k);
    func_02041B6C(2);
}
