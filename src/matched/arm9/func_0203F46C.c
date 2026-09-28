/*
 * unit:     no
 * function: func_0203F46C
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
 *   func_0203F42C  0x0203F42C  arm
 *   func_02088944  0x02088944  arm
 *
 * TU: gf_standard.c.
 *
 * Start an asynchronous RTC read into the staging date and time at
 * +0x2c/+0x3c, with func_0203F42C as the completion callback and the block
 * itself as its argument.  The busy flag at +0x04 is raised before the call
 * and the request's return code is parked in +0x0c.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203F46C.c \
 *       --func func_0203F46C --addr 0x0203F46C --cc 1.1p1 --arm
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

extern void func_0203F42C(u32 result, struct RtcRequest *req);
extern u32  func_02088944(struct RtcDate *date, struct RtcTime *time,
                          void (*done)(u32, struct RtcRequest *),
                          struct RtcRequest *arg);

void func_0203F46C(struct RtcRequest *req)
{
    req->unk_04 = 1;
    req->result = func_02088944(&req->stagedDate, &req->stagedTime,
                                func_0203F42C, req);
}
