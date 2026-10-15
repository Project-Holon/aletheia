/*
 * function: ENTRANCE_CAMERA_SetupLeaveByDir
 * address:  0x021BDDC0
 * packet:   pkt_ov021_021BDDC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The unused `zero` vector is a dead initialised local: an initialiser keeps
 * its three stores (plain assignments are eliminated), and declaring it in an
 * inner block schedules them between the two FIELD_CAMERA_ANIME_GetCurrentParam calls.  The
 * rotation halfword is u16 (pool word 0x0000F5F7, not 0xFFFFF5F7).
 *
 * symbols:
 *   ENTRANCE_CAMERA_GetCamera  0x021BE17C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetDirDisp  0x021A3050  thumb  ov021
 *   ENTRANCE_CAMERA_AimsAtEntrance  0x021BE1B0  thumb  ov021
 *   FIELD_GROUND_ANIME_GetEntryPos  0x021A7B08  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_CAMERA_ANIME_Setup  0x0218FEA4  thumb  ov021
 *   FIELD_CAMERA_ANIME_GetCurrentParam  0x0218FE78  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

typedef struct {
    u16 f0;
    u16 f2;
    int f4;
} Rot;

typedef struct {
    int f0;
    int f4;
    u8 pad8[0x24 - 0x8];
    Rot t;
    u8 pad2C[0x44 - 0x2C];
    int f44;
    int f48;
} Sub;

typedef struct {
    u32 f0;
    u32 f4;
    Sub s;
    u32 f54;
    u8 pad58[0x68 - 0x58];
    int f68;
    int f6C;
} Obj;

extern u32 ENTRANCE_CAMERA_GetCamera(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern u16 FIELD_PLAYER_GetDirDisp(u8 *p);
extern int ENTRANCE_CAMERA_AimsAtEntrance(u32 a);
struct V3;
extern void FIELD_GROUND_ANIME_GetEntryPos(int a, struct V3 *b);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *out);
extern void FIELD_CAMERA_ANIME_Setup(u32 a);
extern void FIELD_CAMERA_ANIME_GetCurrentParam(u32 a, void *dst);

void ENTRANCE_CAMERA_SetupLeaveByDir(Obj *p)
{
    Sub *s = &p->s;
    Rot *t = &s->t;
    Vec out;
    void *h;
    int mode;

    ENTRANCE_CAMERA_GetCamera((u8 *)p);
    h = FIELDMAP_GetFieldPlayer((struct Obj00020 *)p->f0);
    mode = FIELD_PLAYER_GetDirDisp(h);
    switch (mode) {
    case 2:
    case 3:
        p->f68 = 1;
        p->f6C = 0;
        break;
    case 0:
    case 1:
        p->f68 = 0;
        p->f6C = 0;
        break;
    }
    if (p->f68 == 0) {
        return;
    }
    s->f48 = 0;
    s->f44 = 0;
    if (ENTRANCE_CAMERA_AimsAtEntrance((u32)p)) {
        FIELD_GROUND_ANIME_GetEntryPos(p->f0, (struct V3 *)(&out));
    } else {
        FIELD_PLAYER_GetPos(h, (struct VecFx32 *)&out);
    }
    FIELD_CAMERA_ANIME_Setup(p->f54);
    FIELD_CAMERA_ANIME_GetCurrentParam(p->f4, &s->f4);
    {
        Vec zero = {0, 0, 0};
        FIELD_CAMERA_ANIME_GetCurrentParam(p->f4, t);
    }
    switch (mode) {
    case 0:
        t->f4 = 0xB4000;
        break;
    case 1:
        break;
    case 2:
        t->f2 = 0xA09;
        break;
    case 3:
        t->f2 = -0xA09;
        break;
    }
    switch (mode) {
    case 0:
        s->f0 = 0;
        break;
    case 1:
        s->f0 = 0;
        break;
    case 2:
        s->f0 = 10;
        break;
    case 3:
        s->f0 = 10;
        break;
    }
}
