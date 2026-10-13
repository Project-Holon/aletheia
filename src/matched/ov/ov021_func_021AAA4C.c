/*
 * function: EFFECT_ENCOUNT_GetSpotDistance
 * address:  0x021AAA4C
 * packet:   pkt_ov021_021AAA4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 */

typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Ent {
    unsigned short id;
    short x;
    short y;
    short z;
    unsigned long w;
    unsigned char b;
    unsigned char flags : 4;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
} Self;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_GetGridNowPos(void *p, Vec3s *out);

int EFFECT_ENCOUNT_GetSpotDistance(Self *self, short *out)
{
    Ent *e = (Ent *)(GAME_DATA_GetFieldGimmick(self->obj) + 0x10);
    Vec3s v;
    int a, b;

    if (e->flags == 0) {
        *out = 0;
        return 0;
    }
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(self->ctx)), &v);
    a = (short)(e->x - v.x);
    if (a < 0)
        a = a * 0xffffffff;
    b = (short)(e->z - v.z);
    if (b < 0)
        b = b * 0xffffffff;
    if (a > b)
        *out = a;
    else
        *out = b;
    return 1;
}
