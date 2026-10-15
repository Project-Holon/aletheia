/*
 * function: ENTRANCE_CAMERA_SetupArriveByDir
 * address:  0x021BDEB4
 * packet:   pkt_ov021_021BDEB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENTRANCE_CAMERA_GetCamera  0x021BE17C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   ENTRANCE_CAMERA_AimsAtEntrance  0x021BE1B0  thumb  ov021
 *   FIELD_GROUND_ANIME_GetEntryPos  0x021A7B08  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   ENTRANCE_CAMERA_AimAtTarget  0x021BE158  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 *   FIELD_CAMERA_ANIME_ApplyStartParam  0x0218FEC0  thumb  ov021
 *
 * Same object layout as ENTRANCE_CAMERA_SetupArriveByRecord. The first switch's arms are laid
 * out in source order, cases 1-3 ahead of case 0 (its table entry for 0 is
 * the later block); the identical arms of the second switch are separate
 * blocks cross-jumped into the case-3 store.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 f04;
    u16 f06;
    int f08;
    Vec pos;
    Vec rot;
} In;

typedef struct {
    u32 f00;
    In  in;
    u8  sub[0x20];
    int f44;
    int f48;
} S;

typedef struct {
    u32 obj;
    u32 f04;
    S   s;
    u32 f54;
    u32 pad58[4];
    u32 f68;
    u32 f6C;
} A;

extern u32 ENTRANCE_CAMERA_GetCamera(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern int ENTRANCE_CAMERA_AimsAtEntrance(u32 a);
struct V3;
extern void FIELD_GROUND_ANIME_GetEntryPos(int a, struct V3 *b);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *t, struct VecFx32 *v);
extern int ENTRANCE_CAMERA_AimAtTarget(u32 a, u32 b);
extern void FIELD_CAMERA_ANIME_Setup(u32 p);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(u32 p, void *sub);
extern void FIELD_CAMERA_ANIME_ApplyStartParam(u8 *o);

void ENTRANCE_CAMERA_SetupArriveByDir(A *a)
{
    Vec v;
    u32 h;
    void *t;
    int m;
    S *s = &a->s;
    u8 *sub = s->sub;

    h = ENTRANCE_CAMERA_GetCamera((u8 *)a);
    t = FIELDMAP_GetFieldPlayer((struct Obj00020 *)a->obj);
    m = FIELD_PLAYER_GetDirDisp(t);
    switch (m) {
    case 1:
    case 2:
    case 3:
        a->f68 = 0;
        a->f6C = 1;
        break;
    case 0:
        a->f68 = 0;
        a->f6C = 0;
        break;
    }
    if (a->f6C == 0)
        return;
    s->f48 = 0;
    s->f44 = 0;
    if (ENTRANCE_CAMERA_AimsAtEntrance((u32)a) != 0)
        FIELD_GROUND_ANIME_GetEntryPos(a->obj, (struct V3 *)(&v));
    else
        FIELD_PLAYER_GetPos(t, (struct VecFx32 *)&v);
    switch (m) {
    case 0:
        s->f00 = 0;
        break;
    case 1:
        s->f00 = 10;
        break;
    case 2:
        s->f00 = 10;
        break;
    case 3:
        s->f00 = 10;
        break;
    }
    if (ENTRANCE_CAMERA_AimsAtEntrance((u32)a) != 0)
        ENTRANCE_CAMERA_AimAtTarget(h, (u32)(&v));
    FIELD_CAMERA_ANIME_Setup(a->f54);
    FIELD_CAMERA_ANIME_GetCurrentParam(a->f04, &s->in);
    switch (m) {
    case 0:
        break;
    case 1:
        s->in.f08 = 0xB4000;
        break;
    case 2:
        s->in.f06 = 0xF5F7;
        break;
    case 3:
        s->in.f06 = 0xA09;
        break;
    }
    FIELD_CAMERA_ANIME_GetCurrentParam(a->f04, sub);
    if (a->f6C != 0)
        FIELD_CAMERA_ANIME_ApplyStartParam((u8 *)a->f54);
}
