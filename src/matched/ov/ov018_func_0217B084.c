/*
 * function: INTRUDE_FIELD_TaskEdgeBlock
 * address:  0x0217B084
 * packet:   pkt_ov018_0217B084
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckPossibleAcmd  0x0216D3CC  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_CheckEndAcmd  0x0216D454  thumb  ov010
 *   FLDMMDL_EndAcmd  0x0216D480  thumb  ov010
 *   FLDMMDL_SysPauseMove  0x0216D9A0  thumb  ov010
 *   FLDMMDL_SysResumeMove  0x0216D9E4  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FIELDMAP_GetMsgBg  0x02188C54  thumb  ov021
 *   FIELD_MSGBG_CreateMsgData  0x021904B0  thumb  ov021
 *   FIELD_MSGBG_CreateBottomMsgWin  0x021907A8  thumb  ov021
 *   FIELD_MSGBG_IsMsgWinTransDone  0x0219077C  thumb  ov021
 *   FIELD_MSGBG_ClearMsgWin  0x02190788  thumb  ov021
 *   FIELD_MSGBG_MsgWinPrintMsg  0x02190740  thumb  ov021
 *   FIELD_MSGBG_DeleteMsgWin  0x02190728  thumb  ov021
 *   func_020362DC  0x020362DC  arm
 *   MSGDATA_Delete  0x02045C04  arm
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    unsigned char *f0;
    int f4;
    int f8;
    int fc;
    int f10;
    u16 f14;
} Obj;

typedef unsigned char  u8;
extern int FLDMMDL_CheckPossibleAcmd(int a0);
struct Rec;
extern u16 FLDMMDL_GetDirDisp(void *p);
extern void FLDMMDL_SetAcmd(void *a0, u16 a1);
extern int FLDMMDL_CheckEndAcmd(int a0, u32 a1, u32 a2, u32 a3);
extern int FLDMMDL_EndAcmd(char *p);
extern void FLDMMDL_SysPauseMove(void *map);
extern u32 *FLDMMDL_SysResumeMove(void *c);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern u32 FIELDMAP_GetMsgBg(u8 *p);
extern int FIELD_MSGBG_CreateMsgData(u32 a, u32 b);
extern int FIELD_MSGBG_CreateBottomMsgWin();
extern int FIELD_MSGBG_IsMsgWinTransDone(u8 *p);
extern void FIELD_MSGBG_ClearMsgWin(u8 *p);
extern int FIELD_MSGBG_MsgWinPrintMsg(u32 a, u32 b, u32 c, u32 d);
extern int FIELD_MSGBG_DeleteMsgWin(void *a);
extern u32 func_020362DC(void);
extern u32 MSGDATA_Delete(struct Rec *rec);

int INTRUDE_FIELD_TaskEdgeBlock(int a0, int *state, Obj *o, u32 a3)
{
    u16 m;
    int t;
    int h;

    switch (*state) {
    case 0:
        if (FLDMMDL_CheckPossibleAcmd(o->f4) == 1) {
            if (o->f14 == 3)
                t = 3;
            else
                t = 2;
            m = t;
            if (o->f14 != FLDMMDL_GetDirDisp((void *)o->f4)) {
                FLDMMDL_SetAcmd((void *)o->f4, m);
                *state += 1;
            } else {
                *state = 2;
            }
        }
        break;
    case 1:
        if (FLDMMDL_CheckEndAcmd(o->f4, (u32)state, (u32)o, a3) == 1) {
            FLDMMDL_EndAcmd((char *)o->f4);
            *state += 1;
        }
        break;
    case 2:
        FLDMMDL_SysPauseMove(FIELDMAP_GetMmdlSys(o->f0));
        h = FIELDMAP_GetMsgBg(o->f0);
        o->f8 = FIELD_MSGBG_CreateMsgData(h, 0x2D);
        o->fc = FIELD_MSGBG_CreateBottomMsgWin(h, o->f8);
        FIELD_MSGBG_MsgWinPrintMsg(o->fc, 0, 0, o->f10 == 0 ? 0x52 : 0x4F);
        *state += 1;
        break;
    case 3:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 4:
        if (o->f10 == 0) {
            if (func_020362DC() & 3)
                *state += 1;
        } else {
            if (func_020362DC() & 0xF3)
                *state = 8;
        }
        break;
    case 5:
        FIELD_MSGBG_ClearMsgWin((u8 *)o->fc);
        FIELD_MSGBG_MsgWinPrintMsg(o->fc, 0, 0, 0x53);
        *state += 1;
        break;
    case 6:
        if (FIELD_MSGBG_IsMsgWinTransDone((u8 *)o->fc) == 1)
            *state += 1;
        break;
    case 7:
        if (func_020362DC() & 0xF3)
            *state += 1;
        break;
    case 8:
        FIELD_MSGBG_DeleteMsgWin((void *)o->fc);
        MSGDATA_Delete((struct Rec *)o->f8);
        *state += 1;
        break;
    case 9:
        if (FLDMMDL_CheckPossibleAcmd(o->f4) == 1) {
            FLDMMDL_SetAcmd((void *)o->f4, (u16)(o->f14 == 3 ? 10 : 11));
            *state += 1;
        }
        break;
    case 10:
        if (FLDMMDL_CheckEndAcmd(o->f4, (u32)state, (u32)o, a3) == 1) {
            FLDMMDL_EndAcmd((char *)o->f4);
            FLDMMDL_SysResumeMove(FIELDMAP_GetMmdlSys(o->f0));
            return 1;
        }
        break;
    }
    return 0;
}
