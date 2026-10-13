/*
 * function: EFFECT_ENCOUNT_IsTileOccupied
 * address:  0x021AAEC0
 * packet:   pkt_ov021_021AAEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchUseMmdl  0x0216DD1C  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_GetObjCodeParam  0x0216E3C4  thumb  ov010
 *   FLDMMDL_GetGridNowPos  0x0216D828  thumb  ov010
 */

typedef struct Vec3s {
    short x, y, z;
} Vec3s;

typedef struct Self {
    void *ctx;
} Self;

typedef unsigned char  u8;
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
typedef unsigned int   u32;
struct Ctx;
struct Rec;
extern int FLDMMDL_SysSearchUseMmdl(struct Ctx *c, struct Rec **out, u32 *iter);
extern int FLDMMDL_CheckEndAcmd(void *rec);
extern void *FLDMMDL_GetObjCodeParam(void *p);
extern void FLDMMDL_GetGridNowPos(void *rec, Vec3s *out);

int EFFECT_ENCOUNT_IsTileOccupied(Self *self, int x, short y2, int z, int skip)
{
    Vec3s v;
    void *rec;
    unsigned long it = 0;
    void *list;
    void *cur;
    unsigned char *info;

    cur = FIELD_PLAYER_GetMmdl(FIELDMAP_GetFieldPlayer(self->ctx));
    list = FIELDMAP_GetMmdlSys(self->ctx);
    for (;;) {
        if (!FLDMMDL_SysSearchUseMmdl(list, (struct Rec **)(&rec), (u32 *)(&it)))
            break;
        if (!FLDMMDL_CheckEndAcmd(rec))
            continue;
        if (rec == cur && skip)
            continue;
        info = FLDMMDL_GetObjCodeParam(rec);
        FLDMMDL_GetGridNowPos(rec, &v);
        if (y2 != v.y)
            continue;
        if (x < v.x || x >= v.x + info[0xb])
            continue;
        if (z > v.z || z <= v.z - info[0xc])
            continue;
        return 1;
    }
    return 0;
}
