/*
 * file:     trcard_sys_p07.c
 * unit:     yes
 * function: func_0216F378, func_0216F3B0, func_0216F3D4, func_0216F40C, func_0216F7BC
 * address:  0x0216F378
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02031324 0x02031324 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_02031348 0x02031348 arm
 *   d_021C892C 0x021C892C data a4 ov111
 *   ov110_id 0x0000006E data a1
 *   func_0216F088 0x0216F088 thumb ov010
 *   func_02008DFC  0x02008DFC  thumb
 *   d_02172620     0x02172620  data  a2
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
 *   func_0201296C  0x0201296C  thumb
 *   func_020142E8  0x020142E8  thumb
 *   func_0200D0AC  0x0200D0AC  thumb
 *   func_020089D0  0x020089D0  thumb
 *   func_020089CC  0x020089CC  thumb
 *   func_0216F830  0x0216F830  thumb  ov010
 *   func_0216FEAC  0x0216FEAC  thumb  ov010
 *   MIi_CpuCopy16  0x02082A60  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   RTC_ConvertSecondToDateTime  0x020891E0  arm
 *   func_02045A98  0x02045A98  arm
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   d_02172B64 0x02172B64 data ov010 a1
 */
#include "../../matched/include/Obj01640.h"
#include "../../matched/include/Obj19156.h"

struct Big;
struct Sub02008C20Obj;
struct BigObj;
struct Blk34;
struct PlayTime;
struct Rec0200E6FC;
struct Rec1B0;
struct Sub0200852CObj;
struct Sub020089A8Obj;
struct Sub02008AECSession;
struct Sub020090B0Obj;
struct Sub02009210Obj;
struct Blk37;
typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char u8;

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

typedef struct { void *f00; void *f04; void *f08; u32 f0c; u32 f10; u32 f14; } Record;

extern void *func_02031324(int a0);
extern void *func_02012EBC(struct Big *p);
extern void func_02031348(void *,u32,const void *,void *);
extern int func_0216F088(int a0);
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern struct Sub020089A8Obj *func_020089C0(void *sys);
extern u8 *func_02012944(void *p);
extern void *func_02012F08(int *p);
extern struct Sub02008AECSession *func_02008B14(void *sys);
extern struct Sub02008C20Obj *func_02008C58(void *sys);
extern void *func_0200E6E8(u32 a);
extern void *func_0200CA1C(void *save);
extern int func_020084BC(const u16 *values);
extern const void *func_020084F4(const void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u32 func_0200C274(struct Blk34 *p);
extern u32 func_0200C234(struct Blk34 *p, u32 bit);
extern int func_02012FCC(int p0);
extern u8 func_02008554(const struct Sub0200852CObj *obj);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u16 func_02008A0C(const struct Sub020089A8Obj *obj);
extern u8 func_02008A28(const struct Sub020089A8Obj *obj);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 func_0200C1DC(struct Blk34 *p);
extern u16 *func_0200BE48(void *sys);
extern void *func_02010F7C(u32 heap);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);
extern void *func_020127B8(void *save);
extern void func_02010F8C(void *p);
extern u32 func_0200C184(struct Blk34 *p);
extern u32 func_02008EA0(struct Sub02008C20Obj *obj);
extern u8 func_02008E78(struct Sub02008C20Obj *obj);
extern struct Sub02009210Obj *func_0200921C(void *p);
extern u8 func_020090E0(const struct Sub020090B0Obj *obj);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *bitmap, int id);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern int func_020089D0(const struct Sub020089A8Obj *obj);
extern void *func_020089CC(void *p);
extern int func_0216F830(void *save);
extern int func_0216FEAC(void *tbl, void *pos, u8 *flags);
extern void MIi_CpuCopy16(const void *src, void *dst, u32 size);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void RTC_ConvertSecondToDateTime(RTCDate *date, RTCTime *time, s64 sec);
extern u16 func_02045A98(void);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
int func_0216F378(char *p);
int func_0216F3B0(char *p);
u32 func_0216F3D4(void *p, int idx, u32 cap);
void func_0216F40C(Profile *out, void *save, int mode, int flag, volatile u16 heap);
Record *func_0216F7BC(void *a,u32 heap,void *b);
extern const u32 d_021C892C[];
extern char ov110_id[];
extern u16 d_02172620[][7];
extern char d_02172B64[];

/*
 * hint. Pooled request ID is 110, so no proven ov111 loading path yet.
 * 2026-10-05: data hints now carry an overlay token that has a witness; EXACT.
 *
 * Interface: veneers preserve arguments and result as shown by their full
 * forwarding targets 02031354 and 020314F4.
 */
int func_0216F378(char *p) { if (*(void **)(p+8)==0) *(void **)(p+8)=func_02031324((u16)(*(u32 *)p)); *(void **)(p+12)=func_02012EBC(*(void **)(*(char **)(p+24)+4)); func_02031348(*(void **)(p+8),(u32)ov110_id,d_021C892C,*(void **)(p+24)); return 6; }

/*
 * Extent: two-byte zero alignment padding at 0216F3D2.
 */
int func_0216F3B0(char *p) { if (!func_0216F088((int)(p+8))) return 6; if (((struct Obj19156 *)(*(char * *)&((struct Obj01640 *)p)->f18))->fC==3) return 1; return 7; }


/*
 * Sums func_02008DFC over one seven-entry row of a u16 table (rows of 14
 * bytes at 0x02172620), stopping at the first zero entry and clamping the
 * running sum to cap.
 */
u32 func_0216F3D4(void *p, int idx, u32 cap)
{
    u32 sum;
    int i;

    sum = 0;
    for (i = 0; i < 7; i++) {
        if (d_02172620[idx][i] == 0)
            break;
        sum += func_02008DFC(p, d_02172620[idx][i]);
        if (sum > cap)
            sum = cap;
    }
    return sum;
}


/*
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
 */
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
    clock = (Clock *)func_02008B14(x28);
    x14 = func_02008C58(x28);
    x10 = func_0200E6E8((u32)x28);
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
    out->f03 = (u32)func_0216F830(save);
    out->b1 = (u32)func_02008550(player);
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
        p = (void *)func_02012FCC((int)save);
        out->f06 = (u32)func_02008554(player);
        out->b0 = 0;
        out->f1c = 0;
        out->f2a = (u32)func_0200864C(p);
        out->f2e = (u32)func_02008650(p);
    } else {
        out->f06 = (u32)func_02008554(player);
        out->b0 = 1;
        out->f1c = (u32)func_02012FCC((int)save);
    }
    out->f48 = (u32)func_02008A0C(x24);
    out->b4 = (u32)func_02008A28(x24);
    func_0200E6FC(x10, (u32)0, (struct Rec0200E6FC *)out->f6c);

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
    out->f66 = (u32)func_02008E78(x14);
    out->fl0 = (u32)func_020090E0((const struct Sub020090B0Obj *)func_0200921C(save));
    if (func_0200BF94((struct Rec1B0 *)func_0200BE48(x28)) != 0)
        out->fl1 = 1;
    if (out->f60 != 0)
        out->fl2 = 1;
    if (func_02008DFC(x14, (u16)0x78))
        out->fl3 = 1;
    if (func_02008DFC(x14, (u16)0x79))
        out->fl4 = 1;
    if (func_020142E8((void *)func_0201296C(save), 2402) == 1)
        out->b2 = 1;
    else
        out->b2 = 0;
    out->f24 = func_0200D0AC(x0c, heap);
    out->b3 = (u32)func_020089D0(x24);
    MI_CpuCopy8(func_020089CC(x24), out->f74, 0x600);
    out->b6 = flag;
}

Record *func_0216F7BC(void *a,u32 heap,void *b) { Record *p; p=func_02030734(heap,24,1,d_02172B64,0x321); func_02082BCC(p,0,24); p->f00=0; p->f04=a; p->f0c=0; p->f08=b; return p; }
