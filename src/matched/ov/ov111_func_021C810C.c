/*
 * function: VIEWER_ACTOR_UpdateRowVisibility
 * address:  0x021C810C
 * packet:   pkt_ov111_021C810C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetMiscSave  0x02012F08  thumb
 *   BEACON_GetFlag  0x0200C234  thumb
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *   VIEWER_ACTOR_SetRowDrawEnable  0x021C80E8  thumb
 *   GAME_DATA_CheckSaveFlag  0x02012BF8  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
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
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
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

struct Blk34;
struct Obj;
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_GetFlag(struct Blk34 *p, u32 bit);
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void VIEWER_ACTOR_SetRowDrawEnable(Work *p, int row, int v);
extern int GAME_DATA_CheckSaveFlag(int a0, int a1);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void VIEWER_ACTOR_UpdateRowVisibility(Work *p, int a, int b)
{
    void *obj;
    int i;

    obj = GAME_DATA_GetMiscSave(p->f108->f4);
    for (i = 0; i < 8; i++) {
        if (BEACON_GetFlag(obj, i)) {
            CLACT_SetActorDrawEnable(p->f5C[i], 1);
            VIEWER_ACTOR_SetRowDrawEnable(p, i, 1);
            p->f17C[i] = 1;
        } else {
            CLACT_SetActorDrawEnable(p->f5C[i], 0);
            VIEWER_ACTOR_SetRowDrawEnable(p, i, 0);
            p->f17C[i] = 0;
        }
    }
    CLACT_SetActorAnimSeq(p->f58, GAME_DATA_CheckSaveFlag((int)p->f108->f4, 0x17) + 6);
}
