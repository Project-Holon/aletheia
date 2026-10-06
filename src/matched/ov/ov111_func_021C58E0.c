/*
 * function: func_021C58E0
 * address:  0x021C58E0
 * packet:   pkt_ov111_021C58E0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02040B1C  0x02040B1C  arm
 *   func_020410D0  0x020410D0  arm
 *   func_020409B4  0x020409B4  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x10];
    u32 size;
    void *data;
} CharData;

typedef struct {
    u16 w;
    u16 h;
} ScrnData;

typedef struct {
    u8 pad0[0x3030];
    CharData *chr;
    u8 pad3034[0x31DC - 0x3034];
    ScrnData *scrn;
} Work;

extern void func_02040B1C(int index, const void *src, u32 size, u32 tile);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_020409B4(u32 layer);

void func_021C58E0(Work *p)
{
    ScrnData *s;

    func_02040B1C(7, p->chr->data, p->chr->size, 0);
    s = p->scrn;
    func_020410D0(7, 0x15, 2, 10, 11, (u32)s + 0xC, 0x15, 2, s->w >> 3, s->h >> 3);
    func_020409B4(7);
}
