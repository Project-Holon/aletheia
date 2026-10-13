/*
 * function: INTRUDE_FIELD_MainMmdlCopyAnime
 * address:  0x0217C820
 * packet:   pkt_ov018_0217C820
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Per-frame step of the 0x18-byte record (same layout as INTRUDE_FIELD_StepPlayerSpin's).
 *
 * symbols:
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt  0x021F37B8  thumb  ov060
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLDMMDL_SetStatusBitVanish  0x0216DAC8  thumb  ov010
 *   FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive  0x021F37D8  thumb  ov060
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_DeleteMmdl  0x0216CF2C  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

typedef struct {
    void *f0;
    void *f4;
    s16 f8;
    s16 fA;
    u16 fC;
    u8 fE;
    u8 fF;
    u8 f10;
    u8 f11;
    u8 f12;
    u8 f13;
    void *f14;
} Rec;

typedef struct {
    int x;
    int y;
    int z;
} Vec;

struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern void FLDMMDL_SetAcmd(void *, u16);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *, struct VecFx32 *);
extern void FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt(int, Vec *);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void FLDMMDL_SetStatusBitVanish(unsigned int *, unsigned int);
extern int FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(void *);
extern int FLDMMDL_CheckEndAcmd(int);
extern int FLDMMDL_EndAcmd(char *p);
extern void FLDMMDL_DeleteMmdl(int);

int INTRUDE_FIELD_MainMmdlCopyAnime(Rec *r)
{
    void *fld;
    void *obj;
    u16 anim;
    Vec v;

    fld = FIELDMAP_GetFieldPlayer(r->f4);
    obj = FIELD_PLAYER_GetMmdl((void *)fld);
    switch (r->f10) {
    case 0:
        anim = r->f13 == 3 ? 7 : 6;
        FLDMMDL_SetAcmd(obj, anim);
        if (r->f14 != 0)
            FLDMMDL_SetAcmd(r->f14, anim);
        FIELD_PLAYER_GetPos(fld, (struct VecFx32 *)&v);
        if (r->f13 == 3)
            v.x += 0x8000;
        else
            v.x -= 0x8000;
        FIELD_GIMMICK_GAUGE_EFFECT_StartEffectAt((int)r->f4, &v);
        GFL_USE_PlaySeDefaultVolume(0x774);
        r->f10++;
        break;
    case 1:
        r->fA--;
        if (r->fA <= 0) {
            if (r->f14 != 0) {
                FLDMMDL_SetStatusBitVanish(obj, 0);
                FLDMMDL_SetStatusBitVanish(r->f14, 1);
            }
            r->f10++;
        }
        break;
    case 2:
        if (FIELD_GIMMICK_GAUGE_EFFECT_IsEffectActive(r->f4) == 0 && FLDMMDL_CheckEndAcmd((int)obj) == 1) {
            FLDMMDL_EndAcmd(obj);
            if (r->f14 != 0)
                FLDMMDL_EndAcmd(r->f14);
            r->f10++;
        }
        break;
    case 3:
        if (r->f14 != 0) {
            FLDMMDL_DeleteMmdl((int)r->f14);
            r->f14 = 0;
        }
        return 1;
    }
    return 0;
}
