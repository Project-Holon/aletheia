/*
 * function: GFL_NET_WM_ICON_Draw
 * address:  0x02036CA8
 * packet:   pkt_02036CA8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_WM_ICON_GetEngine  0x02036D64  arm
 *   GFL_NET_WM_ICON_GetCharName  0x02036DC8  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_WM_ICON_Draw.c  *       --func GFL_NET_WM_ICON_Draw --addr 0x02036CA8 --cc 1.1p1 --arm
 *
 * wm_icon.c: write the wireless icon's two 16x16 OAM entries into main
 * (0x07000000) or sub (0x07000400) OAM, and hide the pair at the previous
 * location when the engine changed.  Every store is the NitroSDK
 * G2_SetOBJAttr inline (attr01 = y | mode<<10 | mosaic<<12 | effect |
 * color<<13 | shape | x<<16 | rs<<25, attr2 = name | prio<<10 | cparam<<12):
 * entry 0 is an OBJ-window sprite (mode 2) or a NODISPLAY blank (effect
 * 0x200), entry 1 the normal sprite, palette 14.  Written through the
 * inline, the shift scheduling of docs/notes/pkt_02036CA8.c.txt (31 bytes,
 * hand-expanded) disappears.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

typedef struct {
    union {
        u32 attr01;
        struct { u16 attr0; u16 attr1; };
    };
    u16 attr2;
    u16 _3;
} GXOamAttr;

static inline void G2_SetOBJAttr(GXOamAttr *oam, int x, int y, int priority,
                                 int mode, BOOL mosaic, int effect, int shape,
                                 int color, int charName, int cParam, int rsParam)
{
    oam->attr01 = (u32)(((y & 0xff) << 0) |
                        (mode << 10) |
                        (mosaic << 12) |
                        effect |
                        (color << 13) |
                        shape |
                        ((x & 0x1ff) << 16) |
                        (rsParam << 25));
    oam->attr2 = (u16)((charName << 0) | (priority << 10) | (cParam << 12));
}

struct Icon {
    u32 f00;
    u16 f04;
    u16 f06;
    u8  pad08[7];
    u8  f0f;
    GXOamAttr *f10;
};

extern u32 GFL_NET_WM_ICON_GetEngine(u8 *p);
extern u32 GFL_NET_WM_ICON_GetCharName(u32 engine, u32 b);

void GFL_NET_WM_ICON_Draw(struct Icon *c)
{
    u32 mode;
    u32 name;
    GXOamAttr *oam;

    mode = GFL_NET_WM_ICON_GetEngine((u8 *)c);
    name = GFL_NET_WM_ICON_GetCharName(mode, c->f00);
    if (mode == 1) {
        oam = (GXOamAttr *)0x07000000;
    } else {
        oam = (GXOamAttr *)0x07000400;
    }
    if (c->f0f == 1) {
        G2_SetOBJAttr(&oam[0], c->f04, c->f06, 0, 2, 0, 0, 0x40000000, 0, name, 14, 0);
    } else {
        G2_SetOBJAttr(&oam[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
    }
    G2_SetOBJAttr(&oam[1], c->f04, c->f06, 0, 0, 0, 0, 0x40000000, 0, name, 14, 0);
    if (oam != c->f10) {
        G2_SetOBJAttr(&c->f10[0], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        G2_SetOBJAttr(&c->f10[1], 0, 0, 0, 0, 0, 0x200, 0x40000000, 0, 0, 0, 0);
        c->f10 = oam;
    }
}
