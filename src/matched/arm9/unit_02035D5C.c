/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: TOUCHPANEL_RequestAutoSamplingStop, TOUCHPANEL_AutoSamplingRestartSys, TOUCHPANEL_AutoSamplingRestart, TOUCHPANEL_AutoSamplingStopSys,
 *           TOUCHPANEL_AutoSamplingStop, TOUCHPANEL_RequestAutoSamplingStart
 * address:  0x02035D5C
 * packet:   pkt_02035C60
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02035224  0x02035224  arm
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *   TP_RequestAutoSamplingStartAsync  0x0208AC0C  arm
 *   TP_RequestAutoSamplingStopAsync  0x0208AD14  arm
 *   TP_WaitBusy  0x0208B220  arm
 *   TP_CheckError  0x0208B238  arm
 *
 * The open/close pair of the 0x02035000 block's link layer, plus their
 * no-context wrappers.  TOUCHPANEL_AutoSamplingStopSys brings the link up (state word at +0x5a
 * goes to 1) and TOUCHPANEL_AutoSamplingRestartSys takes it down (state word goes back to 0);
 * both refuse to act unless the handle at +0x58 is live and the state is not
 * already where they would leave it.
 *
 * The four workers are kept in one unit deliberately: TOUCHPANEL_RequestAutoSamplingStop,
 * TOUCHPANEL_AutoSamplingRestartSys, TOUCHPANEL_AutoSamplingStopSys and TOUCHPANEL_RequestAutoSamplingStart are each reached by exactly
 * one branch in the image, the one in this same file, so as separate files
 * every wrapper would cap at MATCH.  Inside one range each site is `local`.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02035D5C.c \
 *       --addr 0x02035D5C --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Sio {
    u8 pad_00[0x0c];
    u8 buf[0x4c];
    u16 unk58;
    u16 unk5a;
    u8 pad_5c[0x19];
    u8 unk75;
};

struct UiCtx;
extern struct UiCtx *func_02035224(void);
extern int TOUCHPANEL_GetWork(void);
extern void TP_RequestAutoSamplingStartAsync(u32 a, u32 b, void *c, u32 d);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void TP_WaitBusy(u32 slot);
extern u32 TP_CheckError(u32 slot);

u32 TOUCHPANEL_RequestAutoSamplingStop(struct Sio *p);
u32 TOUCHPANEL_RequestAutoSamplingStart(struct Sio *p);
void TOUCHPANEL_AutoSamplingRestartSys(struct Sio *p);
void TOUCHPANEL_AutoSamplingStopSys(struct Sio *p);

u32 TOUCHPANEL_RequestAutoSamplingStop(struct Sio *p)
{
    if (p->unk58 == 0) {
        return 1;
    }
    TP_RequestAutoSamplingStopAsync();
    TP_WaitBusy(4);
    if (TP_CheckError(4) != 0) {
        return 2;
    }
    return 1;
}

void TOUCHPANEL_AutoSamplingRestartSys(struct Sio *p)
{
    struct Sio *sio = (struct Sio *)TOUCHPANEL_GetWork();

    if (sio != 0 && sio->unk5a != 0 && sio->unk58 != 0) {
        TOUCHPANEL_RequestAutoSamplingStart(sio);
        sio->unk5a = 0;
    }
}

void TOUCHPANEL_AutoSamplingRestart(void)
{
    TOUCHPANEL_AutoSamplingRestartSys((struct Sio *)func_02035224());
}

void TOUCHPANEL_AutoSamplingStopSys(struct Sio *p)
{
    struct Sio *sio = (struct Sio *)TOUCHPANEL_GetWork();

    if (sio != 0 && sio->unk5a != 1 && sio->unk58 != 0) {
        TOUCHPANEL_RequestAutoSamplingStop(sio);
        sio->unk5a = 1;
    }
}

void TOUCHPANEL_AutoSamplingStop(void)
{
    TOUCHPANEL_AutoSamplingStopSys((struct Sio *)func_02035224());
}

u32 TOUCHPANEL_RequestAutoSamplingStart(struct Sio *p)
{
    u32 ret;

    TP_RequestAutoSamplingStartAsync(0, p->unk75, p->buf, 9);
    ret = 2;
    TP_WaitBusy(2);
    if (TP_CheckError(2) == 0) {
        ret = 1;
    }
    return ret;
}
