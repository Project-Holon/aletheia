/*
 * function: ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind
 * address:  0x021BDBB8
 * packet:   pkt_ov208_021BDBB8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight  0x021BE1BC  thumb
 *   func_021BE170  0x021BE170  thumb
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

extern void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(struct Ov208Scene *p);
extern void func_021BE170(struct Ov208Scene *p);

void ZUKAN_DETAIL_TOUCHBAR_SetPaletteForKind(struct Ov208Scene *p, u32 kind)
{
    u32 saved;
    int restore;

    if (p->f10 == 0) {
        restore = 0;
        p->f14 = p->f18;
        p->f18 = kind;
        if (kind == p->f1c) {
            saved = p->f1c;
            restore = 1;
            p->f1c = 4;
        }
        ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteRight(p);
        func_021BE170(p);
        if (restore)
            p->f1c = saved;
    }
}
