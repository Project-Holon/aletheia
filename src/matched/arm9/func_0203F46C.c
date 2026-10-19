/*
 * unit:     no
 * function: GF_STANDARD_RequestRtc
 * address:  0x0203F46C
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GF_STANDARD_RtcReadDone  0x0203F42C  arm
 *   RTC_GetDateTimeAsync  0x02088944  arm
 *
 * TU: gf_standard.c.
 *
 * Start an asynchronous RTC read into the staging date and time at
 * +0x2c/+0x3c, with GF_STANDARD_RtcReadDone as the completion callback and the block
 * itself as its argument.  The busy flag at +0x04 is raised before the call
 * and the request's return code is parked in +0x0c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_RequestRtc.c \
 *       --func GF_STANDARD_RequestRtc --addr 0x0203F46C --cc 1.1p1 --arm
 */

typedef unsigned int u32;
typedef signed int   s32;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

struct RtcTime {
    u32 hour;
    u32 minute;
    u32 second;
};

struct RtcRequest {
    u32            unk_00;
    u32            unk_04;
    s32            unk_08;
    u32            result;
    struct RtcDate date;
    struct RtcTime time;
    struct RtcDate stagedDate;
    struct RtcTime stagedTime;
};

extern void GF_STANDARD_RtcReadDone(u32 result, struct RtcRequest *req);
extern u32  RTC_GetDateTimeAsync(struct RtcDate *date, struct RtcTime *time,
                          void (*done)(u32, struct RtcRequest *),
                          struct RtcRequest *arg);

void GF_STANDARD_RequestRtc(struct RtcRequest *req)
{
    req->unk_04 = 1;
    req->result = RTC_GetDateTimeAsync(&req->stagedDate, &req->stagedTime,
                                GF_STANDARD_RtcReadDone, req);
}
