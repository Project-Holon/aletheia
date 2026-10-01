/*
 * function: func_021A2BD4
 * address:  0x021A2BD4
 * packet:   pkt_ov021_021A2BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: only scheduling differs: original moves q into r4 before
 * loading the u16 stack arg; draft loads the stack arg first.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204BA20  0x0204BA20  arm
 *   data_021D88E0  0x021D88E0  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 data_021D88E0[];

u32 func_0204B294(int a, u16 b, u16 c, u16 d, u32 *e, int f, u16 g);
void func_0204B3DC(u32 h, int v);
void func_0204BA20(u32 h, int v);

void func_021A2BD4(u32 *p, u32 a, u16 *q, int b, u16 e)
{
    p[0] = a;
    p[1] = func_0204B294(b, q[1], q[2], q[3], data_021D88E0, 0, e);
    func_0204B3DC(p[1], 0);
    func_0204BA20(p[1], 0);
}
