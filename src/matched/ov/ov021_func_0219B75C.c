/*
 * function: FLDMMDL_MOVE_TurnSpin
 * address:  0x0219B75C
 * packet:   pkt_ov021_0219B75C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gSpinDirTable     0x021D5258  data   ov021  a4
 *   FLDMMDL_GetMoveSubProcWork  0x0216D6B8  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   FLDMMDL_MOVE_IsButtonBHeld  0x0219B8A8  thumb  ov021
 *   FLDMMDL_MOVE_IsNearPlayer  0x02164168  thumb  ov010
 *   FLDMMDL_SetDirDispCheckPause  0x0216D5E0  thumb  ov010
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct Tbl24 { u32 w[2][4]; } Tbl24;

typedef struct St {
    u8 f0;
    u8 state;
    u8 f2;
    u8 f3;
    s8 f4;
    s8 f5;
    s8 f6;
    s8 f7;
    s8 f8;
} St;

extern Tbl24 gSpinDirTable;

extern void *FLDMMDL_GetMoveSubProcWork(void *p);
extern u16 FLDMMDL_GetDirDisp(void *p);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);
extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern u16 FLDMMDL_GetEventType(u8 *p);
extern int FLDMMDL_MOVE_IsButtonBHeld(void);
extern int FLDMMDL_MOVE_IsNearPlayer(int a);
extern void FLDMMDL_SetDirDispCheckPause(int a0, int a1);

int FLDMMDL_MOVE_TurnSpin(char *a)
{
    Tbl24 t = gSpinDirTable;
    St *p;
    int lim;
    int i;
    u16 v;
    u16 k;

    p = FLDMMDL_GetMoveSubProcWork((void *)a);
    switch (p->state) {
    case 0:
        v = FLDMMDL_GetDirDisp((void *)a);
        for (i = 0; i < 4 && v != t.w[p->f5][i]; i++) {
        }
        i++;
        p->f4 = v;
        p->f6 = i % 4;
        p->state++;
    case 1:
        FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)t.w[p->f5][p->f6], (u16)0)));
        p->state++;
    case 2:
        if (FLDMMDL_ACMD_Update((u8 *)a) == 0) {
            return 1;
        }
        p->state++;
    case 3:
        lim = 8;
        k = FLDMMDL_GetEventType((u8 *)a);
        if ((k == 15 || k == 16) && FLDMMDL_MOVE_IsButtonBHeld() == 1 && FLDMMDL_MOVE_IsNearPlayer((int)a) == 1) {
            lim = 4;
        }
        if (++p->f8 < lim) {
            return 1;
        }
        p->f8 = 0;
        if (++p->f7 < 4) {
            p->f6 = (p->f6 + 1) % 4;
            p->state = 1;
            return 1;
        }
        FLDMMDL_SetDirDispCheckPause((int)a, p->f4);
        p->state++;
        p->f7 = 0;
        p->f0 = 0;
    }
    return 0;
}
