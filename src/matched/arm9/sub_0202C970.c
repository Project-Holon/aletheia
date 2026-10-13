/*
 * function: func_0202C970
 * address:  0x0202C970
 * packet:   pkt_0202C860
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   ZONEDATA_IsRawZone176Or17A   0x02014044  thumb
 *   func_0203F4E4  0x0203F4E4  arm
 *   sub_0202EB60   0x0202EB60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct RtcDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
};

extern u32 ZONEDATA_IsRawZone176Or17A(u32 id);
extern void func_0203F4E4(struct RtcDate *date);
extern void sub_0202EB60(u8 *out1, u8 *out2);

u32 func_0202C970(void *a, void *b, u32 c)
{
    u8 buf[2];
    struct RtcDate date;

    if (!ZONEDATA_IsRawZone176Or17A((u16)c)) {
        goto fail;
    }
    func_0203F4E4(&date);
    sub_0202EB60(&buf[1], &buf[0]);
    if (date.month != buf[1]) {
        goto fail;
    }
    if (date.day != buf[0]) {
        goto fail;
    }
    return 0;

fail:
    return 0xFFFF;
}
