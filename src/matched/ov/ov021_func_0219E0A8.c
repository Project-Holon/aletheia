/*
 * function: FLDMMDL_RAIL_MOVE_AcJump1
 * address:  0x0219E0A8
 * packet:   pkt_ov021_0219E0A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMoveCmdWork  0x0216D6D4  thumb  ov010
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FLDMMDL_RAIL_UpdateRailWork  0x0219E354  thumb  ov021
 *   FIELD_RAIL_WORK_GetPos  0x021B8028  thumb  ov021
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_RAIL_SetMoveRequest  0x0219E370  thumb  ov021
 *   FLDMMDL_RAIL_SetGridPosByDir  0x0219E6C8  thumb  ov021
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FIELD_RAIL_WORK_IsMoving  0x021B8040  thumb  ov021
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 *   d_021DDD94     0x021DDD94  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

typedef struct {
    s32 x, y, z;
} V3;

typedef struct {
    s32 speed;
    s32 acc;
    u16 step;
    u16 pos;
    s8 id;
    s8 count;
    s8 f0e;
    s8 table;
} E;

extern void *FLDMMDL_GetMoveCmdWork(void *p);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern void FLDMMDL_RAIL_UpdateRailWork(u32);
extern void FIELD_RAIL_WORK_GetPos(u32, void *);
extern void FLDMMDL_SetPos(u32, void *);
extern void FLDMMDL_RAIL_SetMoveRequest(u32 a, u32 b, u32 c);
extern void FLDMMDL_RAIL_SetGridPosByDir(u32 o, u16 id);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void FLDMMDL_SetDrawOffset(u32, V3 *);
extern u8 FIELD_RAIL_WORK_IsMoving(u8 *p);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u8 *p);
extern void func_020061E4(u32);

extern s32 *d_021DDD94[];

int FLDMMDL_RAIL_MOVE_AcJump1(u32 o)
{
    E *e;
    u32 a;
    s32 t;
    s32 k;
    u8 buf[12];
    V3 v;
    s32 z[3];

    e = FLDMMDL_GetMoveCmdWork((void *)o);
    e->count--;
    if (e->speed != 0) {
        a = (u32)FLDMMDL_RAIL_GetRailWork((void *)o);
        FLDMMDL_RAIL_UpdateRailWork(o);
        FIELD_RAIL_WORK_GetPos(a, buf);
        FLDMMDL_SetPos(o, buf);
        if (e->acc >= 0x10000 && e->count > 0) {
            e->acc = 0;
            FLDMMDL_RAIL_SetMoveRequest(o, e->id, 8);
            FLDMMDL_RAIL_SetGridPosByDir(o, e->id);
            FLDMMDL_SetMoveBit((void *)o, 0x20);
        }
        t = e->speed;
        if (t < 0) {
            t = -t;
        }
        e->acc += t;
    }
    e->pos += e->step;
    if (e->pos > 0xF00) {
        e->pos = 0xF00;
    }
    t = (u16)(e->pos / 256);
    k = e->table;
    v.x = 0;
    v.y = d_021DDD94[k][t];
    v.z = 0;
    FLDMMDL_SetDrawOffset(o, &v);
    if (e->count > 0 || FIELD_RAIL_WORK_IsMoving((u8 *)a)) {
        return 0;
    }
    {
        V3 *pv = (V3 *)z;
        pv->x = 0;
        pv->y = 0;
        pv->z = 0;
        FLDMMDL_SetDrawOffset(o, pv);
    }
    FLDMMDL_SetMoveBit((void *)o, 0x540);
    FLDMMDL_MOVE_UpdateOldGridPos(o);
    FLDMMDL_SetDrawStatus((void *)o, 0);
    FLDMMDL_IncAcmdSeq((u8 *)o);
    func_020061E4(0x67B);
    return 1;
}
