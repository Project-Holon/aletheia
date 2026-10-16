/*
 * function: TOUCHPANEL_MainSys
 * address:  0x020358A0
 * packet:   pkt_020358A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_GetWork  0x02035750  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   TP_RequestSamplingAsync  0x0208AB1C  arm
 *   TP_WaitRawResult  0x0208ABB8  arm
 *   TP_GetLatestRawPointInAuto  0x0208ADB4  arm
 *   TP_GetCalibratedPoint  0x0208B104  arm
 *
 * The touch-panel sampling pass of the touchpanel.c family: it resolves the
 * work object, refuses to run with the lid closed, samples the panel (with a
 * bounded debounce retry), converts the raw sample, and then does the edge /
 * latch bookkeeping over the halfword block at +0x5c..+0x72.
 *
 * Bit 15 of the halfword at 0x02FFFFA8 is the lid-closed flag, the same
 * hardware address src/matched/UI_ServiceLidSleep.c reads; it is a cast constant,
 * not a relocation (docs/idioms/volatile-reread-needs-two-locals.md).  When
 * it is set the whole 0x7c-byte object is cleared and the pass returns.
 *
 * Three declaration facts carry the register allocation, and none of them is
 * visible in the control flow:
 *
 *   - The two sample buffers are laid out `raw` first and `cal` second, but
 *     the ORIGINAL passes sp+8 to the sampler and sp+0 to the converter, so
 *     `cal` is the sp+0 object: the dispatch code the function tests is
 *     `cal.t` at [sp,#6] and the state word it latches is `cal.v` at [sp,#4].
 *     Getting those two fields the wrong way round moves every stack offset
 *     in the tail.
 *   - `struct Samp` is x, y, v, t: the `v`/`t` order is what puts the tested
 *     halfword at +6 rather than +4.
 *   - The resolver's result is bound to its own local `sio` DECLARED LAST and
 *     copied into `w`.  Initialising `w` from the call directly, or declaring
 *     `sio` before `w`, swaps r4 and r5 through the whole body; the extra
 *     copy is what splits the live range so that the loop counter keeps r4.
 *     The permuter found this as `temp(tmp=TOUCHPANEL_GetWork(ctx))`.
 *
 * The `% 2 == 0` tail test compiles to the lsr/rsb/adds triple at +0x168,
 * the signed-remainder-by-two idiom on a signed char field.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/TOUCHPANEL_MainSys.c \
 *       --func TOUCHPANEL_MainSys --addr 0x020358A0 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Tp {
    u8  pad00[0x3e];
    u8  f3e;
};

struct Work {
    u8  pad00[0x5c];
    u16 f5c;
    u16 f5e;
    u16 f60;
    u16 f62;
    u16 f64;
    u16 f66;
    u16 f68;
    u16 f6a;
    u16 f6c;
    u16 f6e;
    u16 f70;
    u16 f72;
    u8  f74;
};

struct Samp {
    u16 x;
    u16 y;
    u16 v;
    u16 t;
};

extern int TOUCHPANEL_GetWork(void);
extern void MI_CpuFill8(void *dst, u32 val, u32 size);
extern void TP_RequestSamplingAsync(void);
struct TPData;
extern u32 TP_WaitRawResult(struct TPData *result);
extern void TP_GetLatestRawPointInAuto(struct TPData *result);
extern void TP_GetCalibratedPoint(struct TPData *disp, const struct TPData *raw);

void TOUCHPANEL_MainSys(struct Tp *ctx)
{
    struct Samp raw;
    struct Samp cal;
    struct Work *w;
    u32 done = 0;
    u32 n;
    struct Work *sio = (struct Work *)TOUCHPANEL_GetWork();

    w = sio;
    if (w == 0) {
        return;
    }
    if ((s32)(*(u16 *)0x02FFFFA8 & 0x8000) >> 15 != 0) {
        MI_CpuFill8(w, 0, 0x7c);
        return;
    }
    if (w->f74 == 0) {
        n = 0;
        TP_RequestSamplingAsync();
        if (TP_WaitRawResult((struct TPData *)(&raw)) != 0) {
            do {
                n = (n + 1) & 0xff;
                if (n >= 0x20) {
                    cal.t = 3;
                    done = 1;
                    break;
                }
                TP_RequestSamplingAsync();
            } while (TP_WaitRawResult((struct TPData *)(&raw)) != 0);
        }
    } else {
        TP_GetLatestRawPointInAuto((struct TPData *)(&raw));
    }
    if (done == 0) {
        TP_GetCalibratedPoint((struct TPData *)(&cal), (const struct TPData *)(&raw));
    }
    if (cal.t == 0) {
        w->f5c = cal.x;
        w->f5e = cal.y;
    } else if (w->f62 != 0) {
        if (cal.t != 1) {
            if (cal.t == 2) {
                w->f5c = cal.x;
            }
        } else {
            w->f5e = cal.y;
        }
    } else {
        cal.v = 0;
    }
    w->f60 = cal.v & (cal.v ^ w->f62);
    w->f62 = cal.v;
    w->f70 = w->f70 | w->f60;
    w->f72 = w->f72 | w->f62;
    if (w->f5e != 0) {
        w->f6e = w->f5e;
    }
    if (w->f5c != 0) {
        w->f6c = w->f5c;
    }
    if (ctx->f3e % 2 == 0) {
        w->f64 = w->f6c;
        w->f66 = w->f6e;
        w->f68 = w->f70;
        w->f6a = w->f72;
        w->f6c = 0;
        w->f6e = 0;
        w->f70 = 0;
        w->f72 = 0;
    }
}
