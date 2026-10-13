/*
 * function: EFFECT_ENCOUNT_TriggerSpot
 * address:  0x021AA944
 * packet:   pkt_ov021_021AA944
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAME_DATA_GetFieldGimmick  0x02012A38  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 *   func_02005728  0x02005728  thumb
 *   EFFECT_ENCOUNT_PickItemKind7  0x021AB070  thumb  ov021
 *   EFFECT_ENCOUNT_StartItemEvent  0x021AB0AC  thumb  ov021
 *   EFFECT_ENCOUNT_PickItemKind4  0x021AB018  thumb  ov021
 *   FIELD_ENCOUNT_CheckWildEncount  0x021A9F40  thumb  ov021
 *   EFFECT_ENCOUNT_ClearSpot  0x021AAFA0  thumb  ov021
 *   EFFECT_ENCOUNT_SetEffectFlag  0x021AAB1C  thumb  ov021
 *   FIELD_PLAYER_CheckGridMoving  0x021A3624  thumb  ov021
 *   FIELD_PLAYER_FinishGridMove  0x021A3644  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

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
    unsigned char mid : 2;
    unsigned char top : 2;
} Ent;

typedef struct Self {
    void *ctx;
    char pad04[4];
    void *obj;
    char pad0C[4];
    void *f10;
} Self;

struct BigObj;
extern u32 GAME_DATA_GetFieldGimmick(const struct BigObj *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void FLDMMDL_GetGridNowPos(void *p, Vec3s *out);
extern u32 func_02005728(u32 v);
extern u16 EFFECT_ENCOUNT_PickItemKind7(void);
extern int EFFECT_ENCOUNT_StartItemEvent(Self *self, u16 v);
extern u16 EFFECT_ENCOUNT_PickItemKind4(void);
struct Ctx;
extern int FIELD_ENCOUNT_CheckWildEncount(struct Ctx *ctx, int mode);
extern void EFFECT_ENCOUNT_ClearSpot(Self *self, void *p);
extern void EFFECT_ENCOUNT_SetEffectFlag(Self *self, int v);
extern int FIELD_PLAYER_CheckGridMoving(void *p);
extern void FIELD_PLAYER_FinishGridMove(void **p);

static inline int same_pos(Ent *e, Vec3s *v)
{
    if (e->x != v->x || e->z != v->z || e->y != v->y)
        return 0;
    return 1;
}

int EFFECT_ENCOUNT_TriggerSpot(Self *self)
{
    void *arg = self->f10;
    char *base = (char *)GAME_DATA_GetFieldGimmick(self->obj);
    Ent *e = (Ent *)(base + 0x10);
    int flag = 0;
    Vec3s v;
    u16 r;
    int x;
    void *o;

    if (((Ent *)(base + 0x10))->flags == 0)
        return flag;
    FLDMMDL_GetGridNowPos(FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(self->ctx)), &v);
    if (!same_pos(e, &v))
        return 0;
    r = func_02005728(1000);
    if (e->b == 7) {
        if (r < 200) {
            x = FIELD_ENCOUNT_CheckWildEncount((struct Ctx *)self, 1);
        } else {
            x = EFFECT_ENCOUNT_StartItemEvent(self, EFFECT_ENCOUNT_PickItemKind7());
            flag = 1;
        }
    } else if (e->b == 4) {
        if (r < 400) {
            x = FIELD_ENCOUNT_CheckWildEncount((struct Ctx *)self, 1);
        } else {
            x = EFFECT_ENCOUNT_StartItemEvent(self, EFFECT_ENCOUNT_PickItemKind4());
            flag = 1;
        }
    } else {
        x = FIELD_ENCOUNT_CheckWildEncount((struct Ctx *)self, 1);
    }
    if (x == 0) {
        EFFECT_ENCOUNT_ClearSpot(self, arg);
        return 0;
    }
    if (flag) {
        EFFECT_ENCOUNT_ClearSpot(self, arg);
    } else {
        if (e->b == 5 || e->b == 6)
            EFFECT_ENCOUNT_SetEffectFlag(self, 1);
        e->top = 1;
        o = FIELDMAP_GetFieldPlayer(self->ctx);
        if (FIELD_PLAYER_CheckGridMoving(o))
            FIELD_PLAYER_FinishGridMove(o);
    }
    return x;
}
