/*
 * function: func_0216F40C
 * address:  0x0216F40C
 * packet:   pkt_ov010_0216F40C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Fills a 0x674-byte profile record from the save (name, flags, two RTC
 * dates, seven capped counters, a 0x600-byte blob). Byte-correct: 944/944,
 * every concrete byte right.
 *
 * Levers: the fifth (stack) parameter is `volatile u16`, which is what makes
 * the image re-read it from its stack home at both uses (0x0216F66C and
 * 0x0216F760); held in a register it takes r6 and the constant 1 that the
 * image keeps in r7 from 0x0216F608 to the fl0 insert at 0x0216F6E2 is
 * rematerialised instead. `out->f08 = 0` is written before `out->kind`.
 *
 * Blocker (MATCH, two sites): 0x02010F7C and 0x02010F8C are unlabelled ARM9
 * Thumb thunks whose only caller is this function, so neither call has a
 * witness. 0x02010F7C is `ldr r3, =0x02048F61; adds r2, r0, #0; movs r0,
 * #0x26; movs r1, #0; bx r3` (a heap-id forwarder, `return
 * func_02048F60(0x26, 0, heap);`), 0x02010F8C is `ldr r3, =0x020307B1;
 * bx r3` (`func_020307B0(p);`). Matching either thunk (ARM9 territory)
 * closes that site.
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_020089C0  0x020089C0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F08  0x02012F08  thumb
 *   func_02008B14  0x02008B14  thumb
 *   func_02008C58  0x02008C58  thumb
 *   func_0200E6E8  0x0200E6E8  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_020084BC  0x020084BC  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200C274  0x0200C274  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_02008554  0x02008554  thumb
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008A0C  0x02008A0C  thumb
 *   func_02008A28  0x02008A28  thumb
 *   func_0200E6FC  0x0200E6FC  thumb
 *   func_0200C1DC  0x0200C1DC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   func_020127B8  0x020127B8  thumb
 *   func_02010F8C  0x02010F8C  thumb
 *   func_0200C184  0x0200C184  thumb
 *   func_02008EA0  0x02008EA0  thumb
 *   func_02008E78  0x02008E78  thumb
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_02008DFC  0x02008DFC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_020089D0  0x020089D0  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_0216F830  0x0216F830  thumb  ov010
 *   func_0216F3D4  0x0216F3D4  thumb  ov010
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   func_02045A98  0x02045A98  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;

typedef struct RTCDate {
    u32 year;
    u32 month;
    u32 day;
    u32 week;
} RTCDate;

typedef struct RTCTime {
    u32 hour;
    u32 minute;
    u32 second;
} RTCTime;

typedef struct Profile {
    u8 kind;            /* 0x00 */
    u8 pad01[2];
    u8 f03;             /* 0x03 */
    u8 b0 : 1;          /* 0x04 */
    u8 b1 : 1;
    u8 b2 : 1;
    u8 b3 : 1;
    u8 b4 : 1;
    u8 b5 : 1;
    u8 b6 : 1;
    u8 pad05;
    u8 f06;             /* 0x06 */
    u8 pad07;
    u16 f08;            /* 0x08 */
    u16 name[8];        /* 0x0A */
    u8 pad1A[2];
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u16 f28;            /* 0x28 */
    u16 f2a;            /* 0x2A */
    u16 hour2;          /* 0x2C */
    u8 f2e;             /* 0x2E */
    u8 year1;           /* 0x2F */
    u8 month1;          /* 0x30 */
    u8 day1;            /* 0x31 */
    u8 year2;           /* 0x32 */
    u8 month2;          /* 0x33 */
    u8 day2;            /* 0x34 */
    u8 minute2;         /* 0x35 */
    u8 pad36[2];
    u32 f38;            /* 0x38 */
    u32 f3c;            /* 0x3C */
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
    u32 f50;            /* 0x50 */
    u32 f54;            /* 0x54 */
    u32 f58;            /* 0x58 */
    u16 f5c;            /* 0x5C */
    u16 f5e;            /* 0x5E */
    u16 f60;            /* 0x60 */
    u16 f62;            /* 0x62 */
    u16 f64;            /* 0x64 */
    u16 f66;            /* 0x66 */
    u32 fl0 : 1;        /* 0x68 */
    u32 fl1 : 1;
    u32 fl2 : 1;
    u32 fl3 : 1;
    u32 fl4 : 1;
    u8 f6c[8];          /* 0x6C */
    u8 f74[0x600];      /* 0x74 */
} Profile;

typedef struct Clock {
    u8 pad[0x24];
    s64 sec1;           /* 0x24 */
    s64 sec2;           /* 0x2C */
} Clock;

extern void *func_02012EBC(void *save);
extern void *func_020089C0(void *p);
extern void *func_02012944(void *save);
extern void *func_02012F08(void *save);
extern Clock *func_02008B14(void *p);
extern void *func_02008C58(void *p);
extern void *func_0200E6E8(void *p);
extern void *func_0200CA1C(void *save);
extern int func_020084BC(void *player);
extern u16 *func_020084F4(void *player);
extern u32 func_02008550(void *player);
extern u32 func_02008530(void *player);
extern u32 func_0200C274(void *p);
extern u32 func_0200C234(void *p, u32 i);
extern void *func_02012FCC(void *save);
extern u32 func_02008554(void *player);
extern u32 func_0200864C(void *p);
extern u32 func_02008650(void *p);
extern u32 func_02008A0C(void *p);
extern u32 func_02008A28(void *p);
extern void func_0200E6FC(void *p, u32 a, void *out);
extern u32 func_0200C1DC(void *p);
extern void *func_0200BE48(void *p);
extern void *func_02010F7C(u32 heap);
extern void func_0200BF54(void *p, void *out, u32 n);
extern void *func_020127B8(void *save);
extern void func_02010F8C(void *p);
extern u32 func_0200C184(void *p);
extern u32 func_02008EA0(void *p);
extern u32 func_02008E78(void *p);
extern void *func_0200921C(void *save);
extern u32 func_020090E0(void *p);
extern u64 func_0200BF94(void *p);
extern u32 func_02008DFC(void *p, u16 v);
extern void *func_0201296C(void *save);
extern u32 func_020142E8(void *bitmap, int id);
extern u32 func_0200D0AC(void *p, u32 heap);
extern u32 func_020089D0(void *p);
extern void *func_020089CC(void *p);
extern u32 func_0216F830(void *save);
extern u32 func_0216F3D4(void *p, int idx, u32 cap);
extern int func_0216FEAC(void *tbl, void *pos, u8 *flags);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern u16 func_02045A98(void);

void func_0216F40C(Profile *out, void *save, int mode, int flag, volatile u16 heap)
{
    RTCDate date;
    RTCTime time;
    u8 work[4];
    void *x28;
    void *x24;
    void *player;
    void *x1c;
    Clock *clock;
    void *x14;
    void *x10;
    void *x0c;
    void *p;
    void *q;
    u8 i;
    u8 bit;

    x28 = func_02012EBC(save);
    x24 = func_020089C0(x28);
    player = func_02012944(save);
    x1c = func_02012F08(save);
    clock = func_02008B14(x28);
    x14 = func_02008C58(x28);
    x10 = func_0200E6E8(x28);
    x0c = func_0200CA1C(save);

    if (func_020084BC(player) == 0) {
        MIi_CpuCopy16(func_020084F4(player), out->name, 16);
    } else {
        out->name[0] = 'N';
        out->name[1] = 'o';
        out->name[2] = 'N';
        out->name[3] = 'a';
        out->name[4] = 'm';
        out->name[5] = 'e';
        out->name[6] = func_02045A98();
    }
    out->f03 = func_0216F830(save);
    out->b1 = func_02008550(player);
    out->f28 = func_02008530(player);
    out->f20 = func_0200C274(x1c);
    out->f08 = 0;
    out->kind = 0x15;
    for (i = 0, bit = 1; i < 8; i++) {
        if (func_0200C234(x1c, i) == 1)
            out->f08 |= bit;
        bit <<= 1;
    }

    if (mode == 1) {
        p = func_02012FCC(save);
        out->f06 = func_02008554(player);
        out->b0 = 0;
        out->f1c = 0;
        out->f2a = func_0200864C(p);
        out->f2e = func_02008650(p);
    } else {
        out->f06 = func_02008554(player);
        out->b0 = 1;
        out->f1c = (u32)func_02012FCC(save);
    }
    out->f48 = func_02008A0C(x24);
    out->b4 = func_02008A28(x24);
    func_0200E6FC(x10, 0, out->f6c);

    RTC_ConvertSecondToDateTime(&date, &time, clock->sec1);
    out->year1 = date.year;
    out->month1 = date.month;
    out->day1 = date.day;
    if (clock->sec2 == 0) {
        out->year2 = 0;
        out->month2 = 0;
        out->day2 = 0;
        out->hour2 = 0;
        out->minute2 = 0;
    } else {
        RTC_ConvertSecondToDateTime(&date, &time, clock->sec2);
        out->year2 = date.year;
        out->month2 = date.month;
        out->day2 = date.day;
        out->hour2 = time.hour;
        out->minute2 = time.minute;
    }

    out->f38 = func_0216F3D4(x14, 0, 999999999);
    out->f3c = func_0216F3D4(x14, 1, 999999999);
    out->f40 = func_0216F3D4(x14, 2, 999999999);
    out->f44 = func_0216F3D4(x14, 3, 999999999);
    out->f4c = func_0216F3D4(x14, 4, 999999999);
    out->f50 = func_0216F3D4(x14, 5, 999999999);
    out->f54 = func_0216F3D4(x14, 6, 999999999);
    out->f58 = func_0200C1DC(x1c);
    out->f5c = func_0216F3D4(x14, 7, 9999);

    q = func_0200BE48(x28);
    p = func_02010F7C(heap);
    func_0200BF54(q, work, 2);
    out->f5e = func_0216FEAC(p, func_020127B8(save), work);
    func_02010F8C(p);

    out->f60 = func_0216F3D4(x14, 8, 9999);
    out->f62 = func_0200C184(x1c);
    out->f64 = func_02008EA0(x14);
    out->f66 = func_02008E78(x14);
    out->fl0 = func_020090E0(func_0200921C(save));
    if (func_0200BF94(func_0200BE48(x28)) != 0)
        out->fl1 = 1;
    if (out->f60 != 0)
        out->fl2 = 1;
    if (func_02008DFC(x14, 0x78))
        out->fl3 = 1;
    if (func_02008DFC(x14, 0x79))
        out->fl4 = 1;
    if (func_020142E8(func_0201296C(save), 2402) == 1)
        out->b2 = 1;
    else
        out->b2 = 0;
    out->f24 = func_0200D0AC(x0c, heap);
    out->b3 = func_020089D0(x24);
    MI_CpuCopy8(func_020089CC(x24), out->f74, 0x600);
    out->b6 = flag;
}
