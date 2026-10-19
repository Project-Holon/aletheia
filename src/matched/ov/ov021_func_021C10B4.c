/*
 * function: FIELD_PLAYER_GRID_EVENT_HopTask
 * address:  0x021C10B4
 * packet:   pkt_ov021_021C10B4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb  ov010
 *   FLDMMDL_MOVE_AddDirVector  0x02164208  thumb  ov010
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb  ov010
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FLDEFF_NAMIPOKE_Start  0x021ACB38  thumb  ov021
 *   FIELD_PLAYER_SetRideEffect  0x021A2F8C  thumb  ov021
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_IsSpotAt  0x021AA900  thumb  ov021
 *   EFFECT_ENCOUNT_SetEffectFlag  0x021AAB1C  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FIELD_PLAYER_GetRideEffect  0x021A2F98  thumb  ov021
 *   FLDEFF_NAMIPOKE_SetFollowMode  0x021ACBB8  thumb  ov021
 *   FIELD_PLAYER_StartFormChange  0x021A2F48  thumb  ov021
 *   FIELD_PLAYER_StepFormChange  0x021A2F54  thumb  ov021
 *   FIELD_PLAYER_SetGridHopLanded  0x021A35A0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct { int x, y, z; } Vec;

typedef struct {
    u16 state;
    s16 count;
    u16 f4;
    u16 f6;
    u16 f8;
    u16 padA;
    u32 fC;
    u8 *f10;
    u32 f14;
} Work;

extern void *FIELD_PLAYER_GetMmdl(unsigned char *p);
extern u16 FLDMMDL_GetDirDisp(void *obj);
extern int FLDMMDL_GetGridNowX(void *obj);
extern int FLDMMDL_GetGridNowZ(void *obj);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern void FLDMMDL_MOVE_AddDirVector(int dir, int *p, int amt);
extern int FLDMMDL_MOVE_GetMapHeight(void *obj, Vec *v, int *h);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern u32 FLDEFF_NAMIPOKE_Start(u32, u32, Vec *, void *, int);
extern void FIELD_PLAYER_SetRideEffect(u8 *a, u32 b);
extern u32 FIELDMAP_GetEncount(u8 *p);
struct Self;
extern int EFFECT_ENCOUNT_IsSpotAt(struct Self *self, short *pos);
extern void EFFECT_ENCOUNT_SetEffectFlag(void *p, int b);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(void *obj, u32 a);
extern int FLDMMDL_CheckEndAcmd(void *obj);
extern int FLDMMDL_EndAcmd(char *p);
extern u32 FIELD_PLAYER_GetRideEffect(u8 *a);
extern void FLDEFF_NAMIPOKE_SetFollowMode(u32 a, u8 v);
extern void FIELD_PLAYER_StartFormChange(u8 *p, u32 a1);
extern int FIELD_PLAYER_StepFormChange(u8 *a);
extern void FIELD_PLAYER_SetGridHopLanded(u32 *p, int a);

void FIELD_PLAYER_GRID_EVENT_HopTask(u32 task, Work *w)
{
    void *obj;
    u16 dir;
    u32 r;
    int x;
    int y;
    Vec v;
    int h;
    s16 pos[3];
    void *q;
    int step;

    obj = FIELD_PLAYER_GetMmdl(w->f10);
    switch (w->state) {
    case 0:
        dir = FLDMMDL_GetDirDisp(obj);
        x = FLDMMDL_GetGridNowX(obj);
        y = FLDMMDL_GetGridNowZ(obj);
        FLDMMDL_GetPos(obj, (struct VecFx32 *)&v);
        FLDMMDL_MOVE_GridToVectorPos(x, y, (int *)(&v));
        step = 0x10000;
        if (w->f8 == 1)
            step = 0x20000;
        FLDMMDL_MOVE_AddDirVector(dir, (int *)(&v), step);
        h = 0;
        FLDMMDL_MOVE_GetMapHeight(obj, &v, &h);
        v.y = h;
        FIELD_PLAYER_SetRideEffect(w->f10, FLDEFF_NAMIPOKE_Start(FIELDMAP_GetEffect((u8 *)w->fC), dir, &v, obj, 0));
        q = (void *)FIELDMAP_GetEncount((u8 *)w->fC);
        pos[0] = (v.x >> 4) / 0x1000;
        pos[1] = (v.y >> 4) / 0x1000;
        pos[2] = (v.z >> 4) / 0x1000;
        if (EFFECT_ENCOUNT_IsSpotAt(q, pos))
            EFFECT_ENCOUNT_SetEffectFlag(q, 1);
        w->state++;
        break;
    case 1:
        w->count++;
        if (w->count > 15)
            w->state++;
        break;
    case 2:
        dir = FLDMMDL_GetDirDisp(obj);
        r = FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x34);
        if (w->f8 == 1)
            r = FLDMMDL_ACMD_ConvertCodeByDir(dir, 0x38);
        FLDMMDL_SetAcmd(obj, r);
        w->state++;
        break;
    case 3:
        if (FLDMMDL_CheckEndAcmd(obj) == 0)
            break;
        FLDMMDL_EndAcmd(obj);
        FLDEFF_NAMIPOKE_SetFollowMode(FIELD_PLAYER_GetRideEffect(w->f10), 1);
        FIELD_PLAYER_StartFormChange(w->f10, 4);
        w->state++;
    case 4:
        if (FIELD_PLAYER_StepFormChange(w->f10) == 1) {
            FIELD_PLAYER_SetGridHopLanded((u32 *)w->f10, 1);
            w->f4 = 1;
            w->state++;
        }
        break;
    case 5:
        break;
    }
}
