/*
 * function: func_0219707C
 * address:  0x0219707C
 * packet:   pkt_ov021_0219707C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02197058  0x02197058  thumb  ov021
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 *   d_021D3FC8     0x021D3FC8  data  ov021  a1
 *   d_021D3FB0     0x021D3FB0  data  ov021  a1
 *   d_021D3FA8     0x021D3FA8  data  ov021  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { u8 v[5]; } B5;
typedef struct { u16 x; u16 y; u16 z; u8 a; u8 b; } Pos;

extern void func_02197058(u8 *p);
extern u32 func_0204B294(u32, u32, u32, u32, Pos *, u32, u32);
extern void func_0204B92C(u32 obj, int v);
extern void func_0204B3DC(u32 obj, int on);
extern void func_0204B688(u32 obj, u32 on);
extern B5 d_021D3FC8;
extern B5 d_021D3FB0;
extern B5 d_021D3FA8;

void func_0219707C(u8 *p)
{
    B5 xs = d_021D3FC8;
    B5 ys = d_021D3FB0;
    B5 zs = d_021D3FA8;
    Pos pos;
    int i;

    func_02197058(p);
    for (i = 0; i < 5; i++) {
        pos.x = xs.v[i];
        pos.y = ys.v[i];
        pos.z = zs.v[i];
        pos.a = 0;
        pos.b = 1;
        *(u32 *)(p + i * 4 + 0x294) = func_0204B294(*(u32 *)(p + 0x26C), *(u32 *)(p + 0x27C),
            *(u32 *)(p + 0x274), *(u32 *)(p + 0x284), &pos, 1, *(u16 *)(p + 0x10));
        func_0204B92C(*(u32 *)(p + i * 4 + 0x294), 0);
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x294), 1);
        func_0204B688(*(u32 *)(p + i * 4 + 0x294), 1);
    }
}
