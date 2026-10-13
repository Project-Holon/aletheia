/*
 * function: FIELD_G3DOBJ_GetAnimeFrame
 * address:  0x021C67A8
 * packet:   pkt_ov021_021C67A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   G3D_SYSTEM_GetObjectAnimeFrame  0x02047828  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 a, b, c; } V;
typedef struct {
    u32 k:2;
    u32 b2:1;
    u32 b3:1;
    u32 b4:1;
    u32 b5:1;
    u32 rest:26;
    u16 f4;
    u16 f6;
    V f8;
    u8 pad14[0x30];
    u32 f44;
    u8 pad48[0x20];
} Elem;
typedef struct { u8 pad[0x2c]; } Item;
typedef struct { u16 f0; u16 f2; u16 f4; u16 f6; Item *f8; Elem *fC; } Mgr;
typedef signed int     s32;
struct AnmCtl;
extern u32 G3D_SYSTEM_GetObjectAnimeFrame(struct AnmCtl *c, u32 idx, s32 *frame);
int FIELD_G3DOBJ_GetAnimeFrame(Mgr *m, int idx, int i)
{
    int r = 0;
    Elem *e = &m->fC[idx];
    if (e->k == 1) {
        if ((int)G3D_SYSTEM_GetObjectAnimeFrame((struct AnmCtl *)e->f44, (u16)i, &r) == 0)
            r = 0;
    }
    return r;
}
