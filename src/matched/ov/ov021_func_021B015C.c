/*
 * function: SCRCMD_MSGWIN_MenuEventMain
 * address:  0x021B015C
 * packet:   pkt_ov021_021B015C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_SetWaitCount  0x0215A684  thumb  ov010
 *   SCRCMD_WORK_CountDownWait  0x0215A690  thumb  ov010
 *   SCRCMD_WORK_StartMenu  0x0215A864  thumb  ov010
 *   SCRCMD_WORK_WaitMenuOrCancel  0x0215A990  thumb  ov010
 *   SCRCMD_WORK_WaitMenu  0x0215A954  thumb  ov010
 */

typedef struct {
    int h;
    int flag;
} Ctx;

typedef unsigned char  u8;
extern void SCRCMD_WORK_SetWaitCount(int *p, unsigned short v);
extern int SCRCMD_WORK_CountDownWait(char *a0);
extern void SCRCMD_WORK_StartMenu(int *p);
extern int SCRCMD_WORK_WaitMenuOrCancel(u8 *a);
extern int SCRCMD_WORK_WaitMenu(u8 *a);

int SCRCMD_MSGWIN_MenuEventMain(int a0, int *st, Ctx *c)
{
    int r;

    switch (*st) {
    case 0:
        SCRCMD_WORK_SetWaitCount((int *)c->h, 8);
        (*st)++;
    case 1:
        if (SCRCMD_WORK_CountDownWait((char *)c->h) == 1) {
            SCRCMD_WORK_StartMenu((int *)c->h);
            (*st)++;
        }
        break;
    case 2:
        if (c->flag != 0)
            r = SCRCMD_WORK_WaitMenuOrCancel((u8 *)c->h);
        else
            r = SCRCMD_WORK_WaitMenu((u8 *)c->h);
        if (r == 1)
            return 1;
        break;
    }
    return 0;
}
