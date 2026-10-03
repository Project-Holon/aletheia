/*
 * function: func_02159FA8
 * address: 0x02159FA8
 * packet: pkt_ov010_02159FA8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: followed by independently matched ov010_func_02159FE0.c.
 * lever: const table declarations hoist the second table load before the stack argument.
 * prototype: fifth input stays word-wide; u16 adds an absent redundant truncation.
 * symbols:
 *   func_0215A064 0x0215A064 thumb ov010
 *   func_0215A048 0x0215A048 thumb ov010
 *   d_02170FEC 0x02170FEC data
 *   d_02170FF0 0x02170FF0 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Ent {
    u16 f00;
    u16 f02_0 : 1;
    u16 f02_rest : 15;
    u16 f04;
    u16 f06;
    u8 pad[12];
} Ent;
extern int func_0215A064(int);
extern void func_0215A048(void *, int, int, unsigned, int);
extern const Ent d_02170FEC[];
extern const Ent d_02170FF0[];
void func_02159FA8(int a, int b)
{
    int i = func_0215A064(a);
    const Ent *e = &d_02170FEC[i];
    u16 v = e->f06;
    u32 w = d_02170FF0[i].f00;
    u32 hi = ((u32)v << 16) >> 24;
    func_0215A048((void *)b, w, 0, ((u32)v << 24) >> 24, hi);
}
