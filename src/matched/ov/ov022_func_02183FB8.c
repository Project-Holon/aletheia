/*
 * function: func_02183FB8
 * address:  0x02183FB8
 * packet:   pkt_ov022_02183FB8
 * region:   ov022
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02008550  0x02008550  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct { u32 w[10]; } Blk;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_0203D1A4(struct Link *p);
extern u32 func_02008550(const Blk *p);
extern u32 func_02008554(const Blk *p);
extern int func_0217357C(u8 *self, const u8 *mac, u32 a2, u32 a3);

typedef struct { u8 pad[0x14]; u8 tab[1]; } Inner;


void func_02183FB8(u8 *self, u8 *peer, u32 idx, const Blk *src)
{
    Inner *in = (Inner *)&peer[0x2830];
    *(Blk *)(self + 0x2c + idx * 0x28) = *src;
    self[0xe] |= (u8)(1 << idx);
    if (idx != func_0203D1A4((struct Link *)func_020399A8())) {
        u32 a = func_02008554(src);
        u32 b = func_02008550(src);
        func_0217357C(in->tab, (const u8 *)src + 0x20, a, (u8)b);
    }
}
