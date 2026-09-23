/*
 * unit:     no
 * function: func_0206775C
 * address:  0x0206775C
 * packet:   pkt_02066740
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0207D8E0   0x0207D8E0  arm
 *   func_02067B50   0x02067B50  arm
 *   func_02067B64   0x02067B64  arm
 *   func_02066E30   0x02066E30  arm
 *   g_02148B48      0x02148B48  data
 *   tbl_020A17F0    0x020A17F0  data
 *   tbl_020A17D8    0x020A17D8  data
 *
 * NitroSystem g2d renderer core, the 3D (software sprite) per-OAM draw:
 * load the instance's 3D matrix (func_0207D8E0 on rig +0x40), and when the
 * rig's flip flag (+0x24) is set, mirror x/y about the sprite's own extent
 * (func_02067B50 / func_02067B64 are IsFlipH / IsFlipV), write the combined
 * flip bits back into the OAM, then draw it through func_02066E30 with
 * z = -1, &imageProxy->attr (rig +0x08, +0xc) and the two VRAM bases at
 * rig +0x14 / +0x18.  Sibling of func_02067340 (the 2D path).
 *
 * FRONT END: a ../2.0/sp2 pin row (sp2p2 gives the same bytes; 1.1p1 is
 * 556 bytes).  Levers, each measured against the wave-10 572/95 source:
 *   - the mirrored positions come from two inlines RETURNING u16, bound
 *     to s16 locals: that is the image's (s16)(u16) pair at each join and
 *     the deferred sign extension of y at the call (95 -> 65);
 *   - inside each inline the OAM coordinate is first read into its own
 *     local, then the table extent is added, which gives `add r0, x, w`
 *     rather than `add r0, w, x` (65 -> 61);
 *   - the flip write-back is FOUR compound statements, clear-H, or-H,
 *     clear-V, or-V (61 -> EXACT).  The front end drops the store between
 *     each pair and keeps two, the first already carrying the cleared V
 *     bit; every two- or three-statement spelling leaves the value in a
 *     different register and moves the y argument's first shift.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef int            s32;

typedef enum { GX_OAM_SHAPE_8x8 = 0 } GXOamShape;
typedef union {
    u32 attr01;
    struct {
        u32 y:8; u32 rsMode:2; u32 objMode:2; u32 mosaic:1; u32 colorMode:1; u32 shape:2;
        u32 x:9; u32 rsParam:5; u32 size:2;
    } b;
    struct { u32 _0:28; u32 flipH:1; u32 flipV:1; u32 _1:2; } f;
} Attr01;
typedef struct { Attr01 a; u16 attr2; u16 _3; } GXOamAttr;

struct Rig {
    u32 pad_00[2];
    u32 f08;        /* +0x08 */
    u32 pad_0c[2];
    u32 f14;        /* +0x14 */
    u32 f18;        /* +0x18 */
    u32 pad_1c[2];
    u32 f24;        /* +0x24 */
    u32 pad_28[6];
    u32 mtx[12];    /* +0x40 */
};

extern struct Rig *g_02148B48;
extern const u16 tbl_020A17F0[3][4];
extern const u16 tbl_020A17D8[3][4];
extern void func_0207D8E0(const void *m);
extern u32 func_02067B50(const struct Rig *r);
extern u32 func_02067B64(const struct Rig *r);
extern void func_02066E30(int x, int y, int z, const GXOamAttr *oam, u32 a4, u32 a5, u32 a6);

static inline GXOamShape G2_GetOBJShape(const GXOamAttr *oam)
{
    return (GXOamShape)(oam->a.attr01 & (0x0000c000 | 0xc0000000));
}

static inline int OamX(const GXOamAttr *oam)
{
    int x = oam->a.b.x;
    if (x > 0xff)
        x = (s16)(x | 0xff00);
    return x;
}

static inline int OamY(const GXOamAttr *oam)
{
    int y = oam->a.b.y;
    if (y > 0x7f)
        y = (s16)(y | 0xff00);
    return y;
}

static inline u16 PosX_(const GXOamAttr *oam, GXOamShape shape)
{
    if (func_02067B50(g_02148B48)) {
        int x = OamX(oam);
        return -(x + *(u16 *)((u8 *)tbl_020A17F0 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamX(oam);
}
static inline u16 PosY_(const GXOamAttr *oam, GXOamShape shape)
{
    if (func_02067B64(g_02148B48)) {
        int y = OamY(oam);
        return -(y + *(u16 *)((u8 *)tbl_020A17D8 + ((shape & 0x0000c000) >> 14) * 8 + ((shape & 0xc0000000) >> 30) * 2));
    } else
        return OamY(oam);
}
void func_0206775C(GXOamAttr *oam)
{
    func_0207D8E0(g_02148B48->mtx);
    if (g_02148B48->f24 != 0) {
        GXOamShape shape = G2_GetOBJShape(oam);
        s16 x = PosX_(oam, shape);
        s16 y = PosY_(oam, shape);
        int hf; u32 vf;
        hf = oam->a.f.flipH;
        hf = func_02067B50(g_02148B48) ^ hf;
        vf = oam->a.f.flipV;
        vf = func_02067B64(g_02148B48) ^ vf;
        oam->a.attr01 &= ~0x10000000;
        oam->a.attr01 |= hf << 28;
        oam->a.attr01 &= ~0x20000000;
        oam->a.attr01 |= vf << 29;
        func_02066E30(x, y, -1, oam, g_02148B48->f08 + 0xc, g_02148B48->f14, g_02148B48->f18);
    } else {
        func_02066E30(OamX(oam), OamY(oam), -1, oam, g_02148B48->f08 + 0xc, g_02148B48->f14, g_02148B48->f18);
    }
}
