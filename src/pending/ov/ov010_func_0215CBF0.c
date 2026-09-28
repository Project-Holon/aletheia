/*
 * function: func_0215CBF0
 * address:  0x0215CBF0
 * packet:   pkt_ov010_0215CBF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * MATCH, bytes exact. Blockers: ov223_id (0xDF) and d_021BC8C4 have no witness.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   func_0215C63C  0x0215C63C  thumb  ov010
 *   d_021728F0     0x021728F0  data  a1
 *   ov223_id       0x000000DF  data
 *   d_021BC8C4     0x021BC8C4  data  a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_02159AE8(void *c, void *vm);
extern void *func_02030734(u32 heap, u32 size, u32 flags, const char *file, u32 line);
extern void func_0215C63C(void *c, void *vm, u32 ovId, const void *proc, void *work, u32 arg0, u32 arg1);
extern const char d_021728F0[];
extern const u8 d_021BC8C4[];
extern u8 ov223_id[];

int func_0215CBF0(void *c, void *vm)
{
    u32 v;
    u32 *w;

    v = func_02159AE8(c, vm);
    w = func_02030734(4, 8, 1, d_021728F0, 0x254);
    w[0] = v;
    func_0215C63C(c, vm, (u32)ov223_id, d_021BC8C4, w, 0, 0);
    return 1;
}
