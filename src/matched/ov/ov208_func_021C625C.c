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
#include "../include/Obj00124.h"
#include "../include/Obj03367.h"

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

extern void *func_020490F4(u32 id, u32 heap);
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
extern void func_0204B3DC(struct Obj *p, unsigned int v);
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);

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
        func_0204B3DC((struct Obj *)*(u32 *)(p + i * 4 + 0x5e4), 0);
        func_0204B688((struct Actor *)(*(u32 *)(p + i * 4 + 0x5e4)), 1);
    }
    ((struct Obj00124 *)p)->f5F4 = 0x40;
    ((struct Obj00124 *)p)->f5F6 = 0x98;
    ((struct Obj00124 *)p)->f5F8 = 0x0;
    ((struct Obj00124 *)p)->f5FC = 0x1;
    ((struct Obj00124 *)p)->f600 = 0x2;
    ((struct Obj00124 *)p)->f604 = 0x40;
    ((struct Obj00124 *)p)->f605 = 0x98;
    ((struct Obj00124 *)p)->f606 = 0x40;
    ((struct Obj00124 *)p)->f607 = 0x10;
    ((struct Obj00124 *)p)->f608 = 0x18;
    ((struct Obj00124 *)p)->f609 = 0x1a;
    ((struct Obj00124 *)p)->f60C = 0x4;
    ((struct Obj00124 *)p)->f610 = 0x54c;
    ((struct Obj00124 *)p)->f614 = 0x0;
    ((struct Obj00124 *)p)->f618 = 0x0;
    ((struct Obj00124 *)p)->f61C = 0x80;
    ((struct Obj00124 *)p)->f61E = 0x98;
    ((struct Obj00124 *)p)->f620 = 0x0;
    ((struct Obj00124 *)p)->f624 = 0x1;
    ((struct Obj00124 *)p)->f628 = 0x2;
    ((struct Obj00124 *)p)->f62C = 0x80;
    ((struct Obj00124 *)p)->f62D = 0x98;
    ((struct Obj00124 *)p)->f62E = 0x40;
    ((struct Obj00124 *)p)->f62F = 0x10;
    ((struct Obj00124 *)p)->f630 = 0x17;
    ((struct Obj00124 *)p)->f631 = 0x19;
    ((struct Obj00124 *)p)->f634 = 0x8;
    ((struct Obj00124 *)p)->f638 = 0x54c;
    ((struct Obj00124 *)p)->f63C = 0x0;
    ((struct Obj00124 *)p)->f640 = 0x0;
    ((struct Obj00124 *)p)->f644 = 0x80;
    ((struct Obj00124 *)p)->f646 = 0x60;
    ((struct Obj00124 *)p)->f648 = 0x6;
    ((struct Obj00124 *)p)->f64C = 0x7;
    ((struct Obj00124 *)p)->f650 = 0x8;
    ((struct Obj00124 *)p)->f654 = 0x0;
    ((struct Obj00124 *)p)->f655 = 0x0;
    ((struct Obj00124 *)p)->f656 = 0x18;
    ((struct Obj00124 *)p)->f657 = 0x10;
    ((struct Obj00124 *)p)->f658 = 0x4;
    ((struct Obj00124 *)p)->f659 = 0x5;
    ((struct Obj00124 *)p)->f65C = 0x200;
    ((struct Obj00124 *)p)->f660 = 0x54a;
    ((struct Obj00124 *)p)->f664 = 0x0;
    ((struct Obj00124 *)p)->f668 = 0x0;
    ((struct Obj00124 *)p)->f66C = 0xe4;
    ((struct Obj00124 *)p)->f66E = 0x60;
    ((struct Obj00124 *)p)->f670 = 0x6;
    ((struct Obj00124 *)p)->f674 = 0x7;
    ((struct Obj00124 *)p)->f678 = 0x8;
    ((struct Obj00124 *)p)->f67C = 0xe8;
    ((struct Obj00124 *)p)->f67D = 0x0;
    ((struct Obj00124 *)p)->f67E = 0x18;
    ((struct Obj00124 *)p)->f67F = 0x10;
    ((struct Obj00124 *)p)->f680 = 0x2;
    ((struct Obj00124 *)p)->f681 = 0x3;
    ((struct Obj00124 *)p)->f684 = 0x100;
    ((struct Obj00124 *)p)->f688 = 0x54a;
    ((struct Obj00124 *)p)->f68C = 0x0;
    ((struct Obj00124 *)p)->f690 = 0x0;
    for (i = 0; i < 4; i++) {
        func_02082BCC(&hdr[0], 0, 8);
        e = p + i * 0x28;
        hdr[0].x = ((struct Obj03367 *)e)->f5F4;
        hdr[0].y = ((struct Obj03367 *)e)->f5F6;
        hdr[0].z = ((struct Obj03367 *)e)->f608;
        hdr[0].a = 0;
        hdr[0].b = 3;
        ((struct Obj03367 *)e)->f618 = (u32)func_0204B294((void *)W(0), RES(((struct Obj03367 *)e)->f5F8), RES(((struct Obj03367 *)e)->f5FC),
                                            RES(((struct Obj03367 *)e)->f600), &hdr[0], 0, *heap);
        func_0204B92C((struct Obj *)((struct Obj03367 *)e)->f618, 1);
        func_0204B688((struct Actor *)(((struct Obj03367 *)e)->f618), 1);
    }
    W(0x694) = 5;
}
