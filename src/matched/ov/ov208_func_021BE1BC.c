/*
 * function: ov208_func_021BE1BC
 * address:  0x021BE1BC
 * packet:   pkt_ov208_021BE1BC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BD3C0  0x021BD3C0  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208ActDesc {
    int f0;
    s16 x;
    s16 y;
    u16 h8;
    u16 ha;
    u16 hc;
    u16 he;
    u16 h10;
    u16 h12;
    u16 h14;
    u16 h16;
    u32 f18;
    u32 f1c;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    u32 count;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
};

struct Ov208ActSrc {
    int id;
    u16 x;
    u16 y;
    u16 h8;
    u16 pad;
    u32 fc;
    u32 f10;
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    u32 obj;
};

struct Ov208Scene {
    u16 heap;
    u16 pad2;
    u32 f4;
    u32 f8;
    u32 fc;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u32 mgr;
    u32 f34;
    u32 f38;
    u32 f3c;
    u32 f40;
    u32 f44;
    u32 f48;
    u32 f4c;
    u32 f50;
    u32 f54;
    u32 f58;
    u32 f5c;
    u32 f60;
    u32 f64;
    u8  count;
    u8  pad69[3];
    struct Ov208Slot slots[10];
};

struct Obj;
extern int func_021BD3C0(void *mgr, int key);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void ov208_func_021BE1BC(struct Ov208Scene *p)
{
    int slot = 9;

    switch (p->f1c) {
    case 0:
        slot = 6;
        break;
    case 1:
        slot = 5;
        break;
    case 2:
        slot = 4;
        break;
    case 3:
        slot = 3;
        break;
    }
    if (slot != 9) {
        CLACT_SetActorPaletteOffset((struct Obj *)func_021BD3C0((void *)p->mgr, p->slots[slot].src->id), 0, 0);
        p->f1c = 4;
    }
}
