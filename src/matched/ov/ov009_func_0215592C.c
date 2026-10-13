/*
 * function: DWC_RAP_RunStateMachine
 * address:  0x0215592C
 * packet:   pkt_ov009_0215592C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_RAP_SendPendingAck  0x02155B68  thumb  ov009
 *   DWC_RAP_StepLogin  0x021554C8  thumb  ov009
 *   DWC_RAP_SetState  0x02155374  thumb  ov009
 *   DWC_CloseAllConnectionsHard  0x0216B65C  arm
 *   DWC_RAP_EndCancel  0x02155904  thumb  ov009
 *   func_0203D798  0x0203D798  arm
 *   DWC_RAP_StartVchat  0x02156344  thumb  ov009
 *   DWC_RAP_HandleError  0x02155F58  thumb  ov009
 *   DWC_RAP_StepSession  0x021561C0  thumb  ov009
 */
#include "../include/Obj18649.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x32c];
    u8 kind[0x754 - 0x32c];  /* 0x32c */
    int state;          /* 0x754 */
    int err;            /* 0x758 */
    int mode;           /* 0x75c */
    int f760;           /* 0x760 */
    char pad1[0x76c - 0x764];
    int f76c;           /* 0x76c */
    int idx;            /* 0x770 */
    int f774;           /* 0x774 */
    char pad2[0x782 - 0x778];
    short s782;         /* 0x782 */
    char pad3[0x794 - 0x784];
    u16 h794;           /* 0x794 */
} G;

extern G *_pRapWork;
void DWC_RAP_SendPendingAck(void);
int DWC_RAP_StepLogin(void);
void DWC_RAP_SetState(int);
int DWC_CloseAllConnectionsHard(void);
void DWC_RAP_EndCancel(void);
void *func_0203D798(void);
void DWC_RAP_StartVchat(void *a);
int DWC_RAP_HandleError(void);
int DWC_RAP_StepSession(void);

static inline int SetErr(int e)
{
    _pRapWork->err = e;
    return e;
}

int DWC_RAP_RunStateMachine(int a)
{
    DWC_RAP_SendPendingAck();
    switch (_pRapWork->state) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
        return DWC_RAP_StepLogin();
    case 7:
        if (a != 0)
            DWC_RAP_SetState(8);
        if (_pRapWork->mode == 2 && _pRapWork->idx >= 0
            && _pRapWork->kind[_pRapWork->idx] != 6)
            DWC_RAP_SetState(12);
        break;
    case 8:
    case 12:
        DWC_CloseAllConnectionsHard();
        DWC_RAP_EndCancel();
        break;
    case 9: {
        u8 *p = func_0203D798();
        if (_pRapWork->s782 != 0)
            DWC_RAP_StartVchat((void *)(((struct Obj18649 *)p)->f56));
        _pRapWork->h794 = 0;
        DWC_RAP_SetState(10);
        return SetErr(1000);
    }
    case 11:
        DWC_RAP_SetState(6);
        _pRapWork->f760 = 0;
        _pRapWork->f774 = -1;
        return SetErr(0x3e9);
    case 13:
        DWC_RAP_SetState(6);
        _pRapWork->f760 = 0;
        _pRapWork->f774 = -1;
        return SetErr(0x3ea);
    case 14:
        return DWC_RAP_HandleError();
    case 18:
        if (_pRapWork->f76c == 0) {
            DWC_CloseAllConnectionsHard();
            DWC_RAP_SetState(0x13);
            break;
        }
    case 6: {
        int r = DWC_RAP_StepSession();
        if (r == 0)
            return SetErr(0x3ef);
        return r;
    }
    }
    return DWC_RAP_StepSession();
}
