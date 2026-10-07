/*
 * file:     unit_021C75E4_p05.c
 * unit:     yes
 * function: func_021C81C0, func_021C8208, func_021C829C
 * address:  0x021C81C0
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F49C  0x0203F49C  arm
 *   sub_02008A34  0x02008A34  thumb
 *   sub_02008ADC  0x02008ADC  thumb
 *   sub_02008A44  0x02008A44  thumb
 *   sub_02008ACC  0x02008ACC  thumb
 *   RTC_ConvertDateTimeToSecond  0x02089004  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   _ll_sdiv  0x0209BE5C  arm
 *   func_0207E51C  0x0207E51C  arm
 */
struct RtcDate;
struct RtcTime;
struct Sub020089A8Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef long long s64;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res_021C81C0;

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
    Res_021C81C0 *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C81C0;

typedef struct { u32 year, month, day, week; } RTCDate;

typedef struct { u32 hour, minute, second; } RTCTime;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res_021C8208;

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
    Res_021C8208 *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C8208;

typedef struct {
    unsigned char pad0[0xC];
    unsigned char *fC;
} Res_021C829C;

typedef struct {
    unsigned char pad0[0x158];
    Res_021C829C *res[3];
} Work_021C829C;

extern void func_0203F49C(struct RtcDate *date, struct RtcTime *time);
extern s64 RTC_ConvertDateTimeToSecond(const RTCDate *date, const RTCTime *time);
extern void sub_02008A34(struct Sub020089A8Obj *obj, u32 lo, u32 hi);
extern void sub_02008ADC(struct Sub020089A8Obj *obj, int i, int value);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern unsigned long long sub_02008A44(const struct Sub020089A8Obj *obj);
extern u16 sub_02008ACC(const struct Sub020089A8Obj *obj, u32 i);
extern void func_0207E51C(const void *src, int ofs, int size);
void func_021C81C0(Work_021C81C0 *p);
void func_021C8208(Work_021C8208 *p);
void func_021C829C(Work_021C829C *p, int idx, int k);


/*
 * Addresses are Black-image addresses.
 */
void func_021C81C0(Work_021C81C0 *p)
{
    RTCDate date;
    RTCTime time;
    s64 sec;
    int i;

    func_0203F49C((struct RtcDate *)(&date), (struct RtcTime *)(&time));
    sec = RTC_ConvertDateTimeToSecond(&date, &time);
    sub_02008A34(p->f184, (u32)sec, (u32)(sec >> 32));
    for (i = 0; i < 8; i++) {
        sub_02008ADC(p->f184, i, p->f188[i]);
    }
}


void func_021C8208(Work_021C8208 *p)
{
    RTCDate date;
    RTCDate date2;
    RTCTime time;
    RTCTime time2;
    s64 saved;
    s64 hours;
    int i;

    saved = sub_02008A44(p->f184);
    RTC_ConvertSecondToDateTime(&date2, &time2, saved);
    func_0203F49C((struct RtcDate *)(&date), (struct RtcTime *)(&time));
    hours = (RTC_ConvertDateTimeToSecond(&date, &time) - saved) / 3600;
    if (hours < 0) {
        hours = 0;
    }
    for (i = 0; i < 8; i++) {
        p->f188[i] = sub_02008ACC(p->f184, i);
        p->f188[i] -= hours * 2;
        if (p->f188[i] < 0) {
            p->f188[i] = 0;
        }
    }
    for (i = 0; i < 8; i++) {
        p->f1B0[i] = 0xFF;
    }
}


void func_021C829C(Work_021C829C *p, int idx, int k)
{
    if (k > 2) {
        k = 2;
    }
    func_0207E51C((unsigned short *)p->res[k]->fC + idx * 16, idx * 32, 32);
}
