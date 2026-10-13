/*
 * function: SCRCMD_WORK_CmdGetSaveStatus
 * address:  0x0215ACC8
 * packet:   pkt_ov010_0215ACC8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_020071EC  0x020071EC  thumb
 *   func_020071E4  0x020071E4  thumb
 *   func_0200723C  0x0200723C  thumb
 */

extern void *SCRCMD_WORK_GetGameData(void *a0);
typedef unsigned char  u8;
struct Big;
struct Sub020071E4Ctrl;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern unsigned short *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
struct Sub020071E4Ctrl;
extern unsigned char func_020071EC(const struct Sub020071E4Ctrl *ctrl);
extern u8 func_020071E4(const struct Sub020071E4Ctrl *ctrl);
extern void func_0200723C(int, unsigned *, unsigned *);

int SCRCMD_WORK_CmdGetSaveStatus(int a, int b)
{
    int r4;
    unsigned short *r7;
    unsigned short *m;
    unsigned short *r5;
    unsigned s2;
    unsigned s1;

    r4 = (int)GAME_DATA_GetSaveControl(SCRCMD_WORK_GetGameData((void *)b));
    r7 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    m = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    r5 = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    s2 = 0;
    s1 = 0;
    *r7 = func_020071EC((const struct Sub020071E4Ctrl *)r4);
    *m = func_020071E4((const struct Sub020071E4Ctrl *)r4);
    func_0200723C(r4, &s1, &s2);
    if (s1 * 3 < s2) {
        *r5 = 0;
    } else {
        *r5 = 1;
    }
    return 0;
}
