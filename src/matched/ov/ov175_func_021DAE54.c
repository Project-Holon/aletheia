/*
 * function: WIFIBATTLEMATCH_NET_SubmitReport
 * address:  0x021DAE54
 * packet:   pkt_021DAE54
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_ScCreateReport  0x021DF23C  arm
 *   DWC_ScReportBeginGlobalData  0x021DF298  arm
 *   DWC_ScReportBeginPlayerData  0x021DF2C8  arm
 *   DWC_ScReportBeginTeamData  0x021DF2F8  arm
 *   DWC_ScReportBeginNewPlayer  0x021DF328  arm
 *   DWC_ScReportSetPlayerData  0x021DF358  arm
 *   DWC_ScReportEnd  0x021DF3B0  arm
 *   func_02034714  0x02034714  arm
 *   d_021E2EF8     0x021E2EF8  data
 *
 * One exchange round: bails with the first nonzero status of the four session checks, sends the local record (mode from the peer kind), runs the callback, optionally sends the peer's record back and runs the callback again, then closes with the flag.
 */
#include "../include/Obj02887.h"
#include "../include/Obj14337.h"
#include "../include/Obj24332.h"

typedef unsigned long u32;

typedef int (*RoundFn)(char *ctx, char *peer, int dir, int flag);

typedef signed int     s32;
extern int DWC_ScCreateReport(u32 a0, u32 a1, u32 a2, u32 a3);
typedef unsigned char  u8;
extern int DWC_ScReportBeginGlobalData(u32 *a0);
extern int DWC_ScReportBeginPlayerData(u32 *a0);
extern int DWC_ScReportBeginTeamData(u32 *a0);
extern int DWC_ScReportBeginNewPlayer(u8 *a0);
extern s32 DWC_ScReportSetPlayerData(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, char *a5, s32 a6);
extern int DWC_ScReportEnd(u32 h, u32 a, int flag);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];

int WIFIBATTLEMATCH_NET_SubmitReport(char *ctx, char *other, char *peer, u32 a3, RoundFn cb, int flag, int have, int twoway)
{
    int r;
    int mode;
    int mode2;

    if ((r = DWC_ScCreateReport(1, 2, 0, (u32)(ctx + 4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginGlobalData((u32 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginPlayerData((u32 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if ((r = DWC_ScReportBeginNewPlayer((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (flag != 0 || have == 0) {
        mode = 5;
    } else {
        switch (((struct Obj14337 *)peer)->f4) {
        case 1:
        case 4:
            mode = 0;
            break;
        case 0:
        case 3:
            mode = 1;
            break;
        case 2:
            mode = 2;
            break;
        default:
            func_02034714(d_021E2EF8, 0, d_021E2EF8);
            break;
        }
    }
    if ((r = DWC_ScReportSetPlayerData(((struct Obj02887 *)ctx)->f4, 0, (s32)(ctx + 0x30), 0, mode, (char *)(((struct Obj02887 *)ctx)->f0), (s32)(ctx + 0x58))) != 0)
        return r;
    if ((r = cb(ctx, peer, 1, flag)) != 0)
        return r;
    if ((r = DWC_ScReportBeginNewPlayer((u8 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;

    if (twoway == 1) {
        if (have == 0) {
            mode2 = 5;
        } else if (flag != 0) {
            mode2 = 3;
        } else {
            switch (((struct Obj14337 *)peer)->f4) {
            case 1:
            case 4:
                mode2 = 1;
                break;
            case 0:
            case 3:
                mode2 = 0;
                break;
            case 2:
                mode2 = 2;
                break;
            default:
                func_02034714(d_021E2EF8, 0, d_021E2EF8);
                break;
            }
        }
        if ((r = DWC_ScReportSetPlayerData(((struct Obj02887 *)ctx)->f4, 1, (s32)(other + 0x30), 0, mode2, (char *)(((struct Obj24332 *)other)->f0), (s32)(other + 0x58))) != 0)
            return r;
        if ((r = cb(ctx, peer, 0, flag)) != 0)
            return r;
    }
    if ((r = DWC_ScReportBeginTeamData((u32 *)(((struct Obj02887 *)ctx)->f4))) != 0)
        return r;
    if (flag != 0)
        return DWC_ScReportEnd(((struct Obj02887 *)ctx)->f4, a3, 1);
    return DWC_ScReportEnd(((struct Obj02887 *)ctx)->f4, a3, 0);
}
