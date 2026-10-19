/*
 * unit:     no
 * function: GF_STANDARD_RtcReadDone
 * address:  0x0203F42C
 * packet:   pkt_0203EF5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * TU: gf_standard.c.
 *
 * Completion callback for the asynchronous RTC read started by
 * GF_STANDARD_GetRtc: publish the result code, mark the block busy, promote the
 * staging date and time at +0x2c/+0x3c into the live copies at +0x10/+0x20,
 * then clear the busy flag.  Both promotions are whole-structure
 * assignments, so each is one inlined ldm/stm pair.
 *
 * Its address reaches the image only as the pool word at 0x0203F498 inside
 * GF_STANDARD_GetRtc, never as a branch target, so this file's manifest entry is
 * the only thing that can attest that relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GF_STANDARD_RtcReadDone.c \
 *       --func GF_STANDARD_RtcReadDone --addr 0x0203F42C --cc 1.1p1 --arm
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

void GF_STANDARD_RtcReadDone(u32 result, struct RtcRequest *req)
{
    req->result = result;
    req->unk_00 = 1;
    req->date = req->stagedDate;
    req->time = req->stagedTime;
    req->unk_04 = 0;
}
