/*
 * function: ov208_func_021C625C
 * address:  0x021C625C
 * packet:   pkt_ov208_021C625C
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021C87A0  0x021C87A0  data
 *   func_020490F4  0x020490F4  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204AF28  0x0204AF28  arm
 *   func_02049238  0x02049238  arm
 *   func_02082BCC  0x02082BCC  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B688  0x0204B688  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

struct Ov208CellHdr {
    s16 x;
    s16 y;
    s16 z;
    u8  a;
    u8  b;
};

extern const u8 data_021C87A0[4][8];

extern void *func_020490F4(unsigned int id, u16 heap);
typedef signed int     s32;
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern void func_02049238(void *h);
extern void func_02082BCC(void *p, int v, int n);
struct Obj;
extern struct Obj *func_0204B294(void *sys, unsigned int chr, unsigned int pal, unsigned int cell, const void *hdr, u16 a,
                                u16 heap);
extern void func_0204B92C(struct Obj *obj, u32 on);
extern void func_0204B3DC(u32 obj, int v);
extern void func_0204B688(u32 obj, u32 on);

#define W(o) (*(u32 *)(p + (o)))
#define RES(k) (*(u32 *)(p + (k) * 4 + 0x5c0))

void ov208_func_021C625C(u16 *heap, u8 *p, int key)
{
    struct Ov208CellHdr hdr[2];
    void *h;
    u8 i;
    const u8 *t;
    u8 *e;

    h = func_020490F4(0x9f, *heap);
    W(0x5c4) = func_0204AC18(h, 3, 0, 0, 0, 3, *heap);
    W(0x5c0) = func_0204A6C8(h, 0xd, 0, 0, *heap);
    W(0x5c8) = func_0204AF28(h, 0x1b, 0x2c, *heap);
    W(0x5d0) = func_0204AC18(h, 0, 0, 0x60, 0, 1, *heap);
    W(0x5cc) = func_0204A6C8(h, 0xa, 0, 0, *heap);
    W(0x5d4) = func_0204AF28(h, 0x1a, 0x2b, *heap);
    W(0x5dc) = func_0204AC18(h, 6, 0, 0x80, 0, 2, *heap);
    W(0x5d8) = func_0204A6C8(h, 0x10, 0, 0, *heap);
    W(0x5e0) = func_0204AF28(h, 0x1d, 0x2e, *heap);
    func_02049238(h);
    for (i = 0; i < 4; i++) {
        func_02082BCC(&hdr[1], 0, 8);
        t = data_021C87A0[i];
        hdr[1].x = t[0];
        hdr[1].y = t[1];
        hdr[1].z = t[2];
        hdr[1].a = t[3];
        hdr[1].b = t[4];
        *(u32 *)(p + i * 4 + 0x5e4) = (u32)func_0204B294((void *)W(0), RES(t[5]), RES(t[6]), RES(t[7]), &hdr[1], 0, *heap);
        func_0204B92C((struct Obj *)*(u32 *)(p + i * 4 + 0x5e4), 1);
        func_0204B3DC(*(u32 *)(p + i * 4 + 0x5e4), 0);
        func_0204B688(*(u32 *)(p + i * 4 + 0x5e4), 1);
    }
    *(u16 *)(p + 0x5f4) = 0x40;
    *(u16 *)(p + 0x5f6) = 0x98;
    *(u32 *)(p + 0x5f8) = 0x0;
    *(u32 *)(p + 0x5fc) = 0x1;
    *(u32 *)(p + 0x600) = 0x2;
    *(u8 *)(p + 0x604) = 0x40;
    *(u8 *)(p + 0x605) = 0x98;
    *(u8 *)(p + 0x606) = 0x40;
    *(u8 *)(p + 0x607) = 0x10;
    *(u8 *)(p + 0x608) = 0x18;
    *(u8 *)(p + 0x609) = 0x1a;
    *(u32 *)(p + 0x60c) = 0x4;
    *(u32 *)(p + 0x610) = 0x54c;
    *(u32 *)(p + 0x614) = 0x0;
    *(u32 *)(p + 0x618) = 0x0;
    *(u16 *)(p + 0x61c) = 0x80;
    *(u16 *)(p + 0x61e) = 0x98;
    *(u32 *)(p + 0x620) = 0x0;
    *(u32 *)(p + 0x624) = 0x1;
    *(u32 *)(p + 0x628) = 0x2;
    *(u8 *)(p + 0x62c) = 0x80;
    *(u8 *)(p + 0x62d) = 0x98;
    *(u8 *)(p + 0x62e) = 0x40;
    *(u8 *)(p + 0x62f) = 0x10;
    *(u8 *)(p + 0x630) = 0x17;
    *(u8 *)(p + 0x631) = 0x19;
    *(u32 *)(p + 0x634) = 0x8;
    *(u32 *)(p + 0x638) = 0x54c;
    *(u32 *)(p + 0x63c) = 0x0;
    *(u32 *)(p + 0x640) = 0x0;
    *(u16 *)(p + 0x644) = 0x80;
    *(u16 *)(p + 0x646) = 0x60;
    *(u32 *)(p + 0x648) = 0x6;
    *(u32 *)(p + 0x64c) = 0x7;
    *(u32 *)(p + 0x650) = 0x8;
    *(u8 *)(p + 0x654) = 0x0;
    *(u8 *)(p + 0x655) = 0x0;
    *(u8 *)(p + 0x656) = 0x18;
    *(u8 *)(p + 0x657) = 0x10;
    *(u8 *)(p + 0x658) = 0x4;
    *(u8 *)(p + 0x659) = 0x5;
    *(u32 *)(p + 0x65c) = 0x200;
    *(u32 *)(p + 0x660) = 0x54a;
    *(u32 *)(p + 0x664) = 0x0;
    *(u32 *)(p + 0x668) = 0x0;
    *(u16 *)(p + 0x66c) = 0xe4;
    *(u16 *)(p + 0x66e) = 0x60;
    *(u32 *)(p + 0x670) = 0x6;
    *(u32 *)(p + 0x674) = 0x7;
    *(u32 *)(p + 0x678) = 0x8;
    *(u8 *)(p + 0x67c) = 0xe8;
    *(u8 *)(p + 0x67d) = 0x0;
    *(u8 *)(p + 0x67e) = 0x18;
    *(u8 *)(p + 0x67f) = 0x10;
    *(u8 *)(p + 0x680) = 0x2;
    *(u8 *)(p + 0x681) = 0x3;
    *(u32 *)(p + 0x684) = 0x100;
    *(u32 *)(p + 0x688) = 0x54a;
    *(u32 *)(p + 0x68c) = 0x0;
    *(u32 *)(p + 0x690) = 0x0;
    for (i = 0; i < 4; i++) {
        func_02082BCC(&hdr[0], 0, 8);
        e = p + i * 0x28;
        hdr[0].x = *(s16 *)(e + 0x5f4);
        hdr[0].y = *(s16 *)(e + 0x5f6);
        hdr[0].z = *(u8 *)(e + 0x608);
        hdr[0].a = 0;
        hdr[0].b = 3;
        *(u32 *)(e + 0x618) = (u32)func_0204B294((void *)W(0), RES(*(u32 *)(e + 0x5f8)), RES(*(u32 *)(e + 0x5fc)),
                                            RES(*(u32 *)(e + 0x600)), &hdr[0], 0, *heap);
        func_0204B92C((struct Obj *)*(u32 *)(e + 0x618), 1);
        func_0204B688(*(u32 *)(e + 0x618), 1);
    }
    W(0x694) = 5;
}
