/*
 * function: func_021A2BD4
 * address:  0x021A2BD4
 * packet:   pkt_ov021_021A2BD4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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

struct Obj;
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
void func_0204B3DC(u32 h, int v);
void func_0204BA20(u32 h, int v);

typedef struct { u16 id; u16 x, y, z; } Q;
void func_021A2BD4(u32 *p, u32 a, const Q *q, int b, u16 e)
{
    p[0] = a;
    p[1] = (u32)func_0204B294((void *)b, q->x, q->y, q->z, data_021D88E0, 0, e);
    func_0204B3DC(p[1], 0);
    func_0204BA20(p[1], 0);
}
