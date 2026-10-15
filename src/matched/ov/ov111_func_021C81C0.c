/*
 * function: func_021C81C0
 * address:  0x021C81C0
 * packet:   pkt_ov111_021C81C0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GF_STANDARD_CopyCachedRtc  0x0203F49C  arm
 *   sub_02008A34  0x02008A34  thumb
 *   sub_02008ADC  0x02008ADC  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work;

typedef struct { u32 year, month, day, week; } RTCDate;
typedef struct { u32 hour, minute, second; } RTCTime;

struct RtcDate;
struct RtcTime;
extern void GF_STANDARD_CopyCachedRtc(struct RtcDate *date, struct RtcTime *time);
extern s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
struct Sub020089A8Obj;
extern void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi);
extern void sub_02008ADC(struct Sub020089A8Obj *obj, int i, int value);

void func_021C81C0(Work *p)
{
    RTCDate date;
    RTCTime time;
    s64 sec;
    int i;

    GF_STANDARD_CopyCachedRtc((struct RtcDate *)(&date), (struct RtcTime *)(&time));
    sec = RTC_ConvertDateTimeToSecond(&date, &time);
    sub_02008A34(p->f184, (u32)sec, (u32)(sec >> 32));
    for (i = 0; i < 8; i++) {
        sub_02008ADC(p->f184, i, p->f188[i]);
    }
}
