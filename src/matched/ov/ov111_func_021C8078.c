/*
 * function: VIEWER_ACTOR_ToggleFavorite
 * address:  0x021C8078
 * packet:   pkt_ov111_021C8078
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_ContainsRecentId  0x02012BF8  thumb
 *   GAME_DATA_SetRecentId  0x02012BE0  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
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
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

extern int GAME_DATA_ContainsRecentId(int a0, int a1);
struct Obj;
extern void GAME_DATA_SetRecentId(void *p, u32 a, u32 b);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);

void VIEWER_ACTOR_ToggleFavorite(Work *p)
{
    int v = GAME_DATA_ContainsRecentId((int)p->f108->f4, 0x17) ^ 1;

    CLACT_SetActorAnimSeq(p->f58, v + 6);
    GAME_DATA_SetRecentId(p->f108->f4, 0x17, v);
    GFL_USE_PlaySeDefaultVolume(0x646);
}
