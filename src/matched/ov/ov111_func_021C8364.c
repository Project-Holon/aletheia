/*
 * function: VIEWER_ACTOR_RefreshRows
 * address:  0x021C8364
 * packet:   pkt_ov111_021C8364
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VIEWER_ACTOR_LoadPalette  0x021C829C  thumb
 *   VIEWER_ACTOR_LoadTexture  0x021C82C0  thumb
 *   VIEWER_ACTOR_SetRowActorDrawEnable  0x021C832C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern void VIEWER_ACTOR_LoadPalette(Work *p, int idx, int k);
extern void VIEWER_ACTOR_LoadTexture(Work *p, int idx, int k);
extern void VIEWER_ACTOR_SetRowActorDrawEnable(Work *p, int row, int n);

void VIEWER_ACTOR_RefreshRows(Work *p)
{
    int i;

    for (i = 0; i < 8; i++) {
        p->f1A8[i] = p->f188[i] / 0x60;
        if (p->f1A8[i] > 5) {
            p->f1A8[i] = 5;
        }
        if (p->f1A8[i] != p->f1B0[i]) {
            VIEWER_ACTOR_LoadPalette(p, i, p->f1A8[i]);
            VIEWER_ACTOR_LoadTexture(p, i, p->f1A8[i]);
            VIEWER_ACTOR_SetRowActorDrawEnable(p, i, p->f1A8[i]);
        }
        p->f1B0[i] = p->f1A8[i];
    }
}
