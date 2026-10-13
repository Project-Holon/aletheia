/*
 * function: RAIL_SLIPDOWN_Create
 * address:  0x021F36C0
 * packet:   pkt_ov063_021F36C0
 * region:   ov063
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetNogridMapper  0x02188C5C  thumb  ov021
 *   FLDMMDL_RAIL_GetRailWork  0x0219E348  thumb  ov021
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_ResetMoveWork  0x021A2F6C  thumb  ov021
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetStatusBitAttrGetOff  0x0216DC98  thumb  ov010
 *   FLDMMDL_SetStatusBitFellowHit  0x0216DAE0  thumb  ov010
 *   FLDMMDL_OnMoveBitMovePause  0x0216DAF8  thumb  ov010
 *   FIELDMAP_GetTcblSys  0x02188D30  thumb  ov021
 *   func_02030734  0x02030734  arm
 *   func_02030DA8  0x02030DA8  arm
 *   RAIL_SLIPDOWN_TaskMain  0x021F377C  thumb  ov063
 *   d_021F3D80     0x021F3D80  data  a1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    int f0;
    int f4;
    int f8;
    void *fC;
    int f10;
    int f14;
    int f18;
    u8 pad[0x64];
    int f80;
} W;

extern const char d_021F3D80[];

extern unsigned short FIELDMAP_GetHeapId(u8 *p);
extern u32 FIELDMAP_GetNogridMapper(u8 *p);
extern void *FLDMMDL_RAIL_GetRailWork(void *a);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void *FIELDMAP_GetCamera(void *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
typedef unsigned short u16;
extern void FIELD_PLAYER_ResetMoveWork(u32 *p);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FLDMMDL_SetStatusBitAttrGetOff(void *a0, int a1);
extern void FLDMMDL_SetStatusBitFellowHit(unsigned int *p, unsigned int v);
extern void FLDMMDL_OnMoveBitMovePause(void *a0);
extern u32 FIELDMAP_GetTcblSys(u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern int func_02030DA8(u32 owner, void *cb, void *arg, u32 n);
extern void RAIL_SLIPDOWN_TaskMain(void);

W *RAIL_SLIPDOWN_Create(int unused, u8 *sys, int c, int d)
{
    W *p;

    p = func_02030734(FIELDMAP_GetHeapId(sys), 0x84, 1, d_021F3D80, 0x80);
    p->f4 = FIELDMAP_GetNogridMapper((u8 *)sys);
    p->f10 = c;
    p->f8 = (int)FLDMMDL_RAIL_GetRailWork((void *)c);
    p->f14 = FIELDMAP_GetEffect((u8 *)sys);
    p->f18 = (int)FIELDMAP_GetCamera((void *)sys);
    if (d != 0) {
        p->fC = FIELDMAP_GetFieldPlayer((void *)sys);
        FIELD_PLAYER_ResetMoveWork(p->fC);
    } else {
        p->fC = 0;
    }
    FLDMMDL_SetStatusBitHeightGetOff((void *)p->f10, 1);
    FLDMMDL_SetStatusBitAttrGetOff((void *)p->f10, 1);
    FLDMMDL_SetStatusBitFellowHit((unsigned int *)p->f10, 0);
    FLDMMDL_OnMoveBitMovePause((void *)p->f10);
    p->f80 = func_02030DA8(FIELDMAP_GetTcblSys((u8 *)sys), (void *)RAIL_SLIPDOWN_TaskMain, p, 0);
    return p;
}
