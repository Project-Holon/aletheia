/*
 * file:     input.c
 * unit:     yes
 * function: DWCi_IPTlInit, DWCi_IPTlEnd, DWCi_IPTlUpdate, readKey, readTouch, DWCi_IPTlCheckTrigger, DWCi_IPTlCheckRepeat, DWCi_IPTlCheckRelease, DWCi_TPlCheck, DWCi_TPlCheckTrigger, DWCi_TPlCheckRepeat, DWCi_TPlCheckRelease, DWCi_TPlCheckATrigger, DWCi_TPlGet, DWCi_IPTlCheckFold
 * address:  0x021D64B8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Call readKey, readTouch.
 * Addresses are Black-image addresses.
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_IPTlUpdate.c \
 *       --func DWCi_IPTlUpdate --addr 0x021D656C --region ov016 --cc dsi/1.1p1 --arm
 *
 * symbols:
 *   TP_RequestAutoSamplingStopAsync 0x0208AD14  arm  arm9
 *   DWCi_HEAPlFree_                0x021D6438  arm  ov016
 *   DWCi_HEAPlAllocEx  0x021D6414  arm
 *   TP_GetUserInfo  0x0208A998  arm
 *   OS_Terminate  0x02088234  arm
 *   TP_SetCalibrateParam  0x0208AA2C  arm
 *   TP_RequestAutoSamplingStartAsync  0x0208AC0C  arm
 *   TP_WaitBusy  0x0208B220  arm
 *   TP_CheckError  0x0208B238  arm
 *   gInputStatics     0x021DE688  data
 *   _ZZ7readKeyvE5count 0x021DE690 data
 *   TP_GetLatestIndexInAuto  0x0208AF08  arm
 *   TP_GetCalibratedPoint  0x0208B104  arm
 *   DWCi_InputCoord  0x021D5FE8  arm  ov016
 *   FX_ModS32  0x0207C994  arm
 *   PM_SetLCDPower 0x0208C64C  arm
 *   OS_WaitVBlankIntr  0x02087AE4  arm
 *   GX_DispOn  0x0207D46C  arm
 *   GX_DispOff  0x0207D42C  arm
 */
struct TPCalibrateParam;
struct TPData;
typedef struct {
    unsigned short x;
    unsigned short y;
    unsigned short touch;
    unsigned short validity;
} TPData;

typedef struct tagCOORD {
    unsigned short x;
    unsigned short y;
} COORD;

typedef struct {
    TPData tp[5];
    COORD coord;
    COORD last;
    unsigned short cont;
    unsigned short trg;
    unsigned short repeat;
    unsigned short release;
    unsigned char touch : 1;
    unsigned char trig : 1;
    unsigned char repeatTp : 1;
    unsigned char releaseTp : 1;
} InputWork;

typedef struct {
    unsigned char fold;
    unsigned char cnt;
    unsigned char pad2[2];
    InputWork *work;
} InputStatics;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef long           s32;

typedef _Bool bool;

typedef struct {
    unsigned char touch : 1;
    unsigned char trigger : 1;
    unsigned char repeat : 1;
    unsigned char release : 1;
    unsigned char f4 : 1;
    unsigned char f5 : 1;
    unsigned char f6 : 1;
    unsigned char f7 : 1;
} ByteBits;

typedef struct tagAREA { unsigned short x, y, w, h; } AREA;

typedef struct tagRECT { unsigned short l, t, r, b; } RECT;

extern void *DWCi_HEAPlAllocEx(unsigned long size, int alignment);
extern int TP_GetUserInfo(struct TPCalibrateParam *calibrate);
extern void  OS_Terminate(void);
extern void TP_SetCalibrateParam(const struct TPCalibrateParam *param);
extern void  TP_RequestAutoSamplingStartAsync(int a, int b, void *c, int d);
extern void TP_WaitBusy(unsigned int command_flgs);
extern unsigned int TP_CheckError(unsigned int command_flgs);
extern void TP_RequestAutoSamplingStopAsync(void);
extern void DWCi_HEAPlFree_(void **mem);
extern u16 TP_GetLatestIndexInAuto(void);
extern void TP_GetCalibratedPoint(struct TPData *disp, const struct TPData *raw);
extern void DWCi_InputCoord(int a, int b, unsigned short *p);
extern s32 FX_ModS32(s32 a, s32 b);
extern int PM_SetLCDPower(int sw);
extern void OS_WaitVBlankIntr(void);
extern void GX_DispOn(void);
extern void GX_DispOff(void);
void DWCi_IPTlInit(void);
void DWCi_IPTlEnd(void);
void DWCi_IPTlUpdate(void);
int DWCi_IPTlCheckTrigger(unsigned int f);
int DWCi_IPTlCheckRepeat(unsigned int f);
int DWCi_IPTlCheckRelease(unsigned int f);
int DWCi_TPlCheck(u16 *a);
int DWCi_TPlCheckTrigger(u16 *a);
int DWCi_TPlCheckRepeat(u16 *a);
int DWCi_TPlCheckRelease(u16 *a);
int DWCi_TPlCheckATrigger(const AREA *a);
int DWCi_TPlGet(COORD *c);
void DWCi_IPTlCheckFold(void);
extern InputStatics gInputStatics;

static void readKey(void);
static void readTouch(void);


void DWCi_IPTlInit(void)
{
    char buf[8];

    gInputStatics.work = DWCi_HEAPlAllocEx(0x3a, 4);
    if (TP_GetUserInfo((struct TPCalibrateParam *)buf) == 0)
        OS_Terminate();
    TP_SetCalibrateParam((const struct TPCalibrateParam *)buf);
    TP_RequestAutoSamplingStartAsync(0, 4, gInputStatics.work, 5);
    TP_WaitBusy(2);
    if (TP_CheckError(2) != 0)
        OS_Terminate();
    DWCi_IPTlUpdate();
}


/*
 * Drain the channel-4 queue, then post the event at 0x021DE68C.
 * Addresses are Black-image addresses.
 */
void DWCi_IPTlEnd(void)
{
    int v = 4;

    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(v);
    } while (TP_CheckError(v) != 0);
    DWCi_HEAPlFree_((void *)0x021DE68C);
}


void DWCi_IPTlUpdate(void)
{
    readKey();
    readTouch();
}


static void readKey(void)
{
    static unsigned char count[14];
    unsigned short *input;
    int i;
    unsigned short bit;

    input = (unsigned short *)0x04000130;
    bit = ((*input | *(unsigned short *)0x02FFFFA8) ^ 0x2FFF) & 0x2FFF;
    input = &gInputStatics.work->cont;
    bit = bit & ~((bit & 0x40) << 1) & ~((bit & 0x20) >> 1);
    gInputStatics.work->trg = (*input ^ bit) & bit;
    gInputStatics.work->release = (*input ^ bit) & *input;
    gInputStatics.work->cont = bit;
    gInputStatics.work->repeat = gInputStatics.work->trg;
    for (i = 0; i < 14; i++) {
        if (!(bit & (unsigned short)(1 << i))) {
            count[i] = 0;
        } else {
            count[i]++;
            if (count[i] == 40) {
                gInputStatics.work->repeat |= (unsigned short)(1 << i);
            } else if (count[i] == 47) {
                gInputStatics.work->repeat |= (unsigned short)(1 << i);
                count[i] = 40;
            }
        }
    }
}


/*
 * sdk:      readTouch (libdwcutil.TWL.HYB.a(input.o))
 *
 * input.o's statics sit in one block; the vendor reaches them through one
 * pool word anchored at 0x021DE688 (DWCi_IPTlCheckFold's local static fold),
 * so the block is a struct overlay named by offset.
 */
static void readTouch(void)
{
    TPData p;
    int idx;
    int lastIdx;
    int i;
    bool last;
    bool touch;

    last = gInputStatics.work->touch;
    touch = 0;
    idx = TP_GetLatestIndexInAuto();
    gInputStatics.work->last = gInputStatics.work->coord;
    for (i = 0; i < 4; i++, idx = FX_ModS32(idx + 4, 5)) {
        if (gInputStatics.work->tp[idx].touch == 1 && gInputStatics.work->tp[idx].validity == 0) {
            touch = 1;
            TP_GetCalibratedPoint((struct TPData *)(&p), (const struct TPData *)(&gInputStatics.work->tp[idx]));
            DWCi_InputCoord(p.x, p.y, (short unsigned int *)(&gInputStatics.work->coord));
            break;
        }
    }
    gInputStatics.work->trig = touch & (touch ^ last);
    gInputStatics.work->releaseTp = last & (touch ^ last);
    gInputStatics.work->touch = touch;
    gInputStatics.work->repeatTp = gInputStatics.work->trig;
    if (!touch) {
        gInputStatics.cnt = 0;
        return;
    }
    if (++gInputStatics.cnt == 40) {
        gInputStatics.work->repeatTp = 1;
        return;
    }
    if (gInputStatics.cnt == 47) {
        gInputStatics.work->repeatTp = 1;
        gInputStatics.cnt = 40;
    }
}


int DWCi_IPTlCheckTrigger(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x32)) == f;
}


/*
 * Gate on the hardware bit, then test the flag word at +0x34 for the whole mask.
 * Addresses are Black-image addresses.
 */
int DWCi_IPTlCheckRepeat(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x34)) == f;
}


/*
 * Gate on the hardware bit, then test the flag word at +0x36 for the whole mask.
 * Addresses are Black-image addresses.
 */
int DWCi_IPTlCheckRelease(unsigned int f)
{
    int *g = (int *)0x021DE688;
    unsigned short v = *(unsigned short *)0x02FFFFA8;

    if ((v & 0x8000) >> 0xf)
        return 0;
    return (f & *(unsigned short *)(g[1] + 0x36)) == f;
}


/*
 * Validity test for a records window: bails out unless the shared flag word
 * (0x02FFFFA8 bit 0x8000) and bit 0 of the current record's +0x38 byte are
 * set, then checks a[0]/a[2] against the +0x28 bound and a[1]/a[3] against the
 * +0x2a bound. Addresses are Black-image addresses.
 */
int DWCi_TPlCheck(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->touch == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}


int DWCi_TPlCheckTrigger(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->trigger == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}


int DWCi_TPlCheckRepeat(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->repeat == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}


/*
 * Validity test for a records window: bails out unless the shared flag word
 * (0x02FFFFA8 bit 0x8000) and bit 3 of the current record's +0x38 byte are
 * set, then checks a[0]/a[2] against the +0x28 bound and a[1]/a[3] against the
 * +0x2a bound. Addresses are Black-image addresses.
 */
int DWCi_TPlCheckRelease(u16 *a)
{
    u8 *g = (u8 *)0x021DE688;
    u8 *p;

    if (((*(volatile u16 *)0x02FFFFA8 & 0x8000) >> 15) != 0)
        return 0;

    p = *(u8 **)(g + 4);

    if (((ByteBits *)(p + 0x38))->release == 0)
        return 0;

    if (a[0] > *(u16 *)(p + 0x28))
        return 0;
    if (a[2] < *(u16 *)(p + 0x28))
        return 0;
    if (a[1] > *(u16 *)(p + 0x2a))
        return 0;
    return a[3] >= *(u16 *)(p + 0x2a);
}


/*
 * sdk:      DWCi_TPlCheckATrigger (libdwcutil.TWL.HYB.a input.o)
 *
 * notes:    const input lets all four halfwords load before the first store.
 *           The fold test reads the shared word at 0x02FFFFA8 through a
 *           volatile u16 cast (a fixed address, no variable, so the vendor
 *           DWARF has nothing to say about it either way).
 */
int DWCi_TPlCheckATrigger(const AREA *a)
{
    RECT r;

    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    r.l = a->x;
    r.t = a->y;
    r.r = a->x + a->w;
    r.b = a->y + a->h;
    return DWCi_TPlCheckTrigger((u16 *)(&r));
}


/*
 * sdk:      DWCi_TPlGet (libdwcutil.TWL.HYB.a input.o)
 */
int DWCi_TPlGet(COORD *c)
{
    InputWork *t;
    if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
        return 0;
    t = gInputStatics.work;
    if (!t->touch) {
        *c = t->last;
        return 0;
    }
    *c = t->coord;
    return 1;
}


/*
 * sdk:      DWCi_IPTlCheckFold (libdwcutil.TWL.HYB.a input.o)
 */
void DWCi_IPTlCheckFold(void)
{
    if (gInputStatics.fold) {
        if ((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15)
            return;
        if (PM_SetLCDPower(1)) {
            OS_WaitVBlankIntr();
            GX_DispOn();
            *(volatile unsigned int *)0x04001000 |= 0x10000;
            OS_WaitVBlankIntr();
            gInputStatics.fold = 0;
        }
    } else {
        if (!((*(volatile unsigned short *)0x02FFFFA8 & 0x8000) >> 15))
            return;
        OS_WaitVBlankIntr();
        GX_DispOff();
        *(volatile unsigned int *)0x04001000 &= ~0x10000;
        OS_WaitVBlankIntr();
        if (PM_SetLCDPower(0))
            gInputStatics.fold = 1;
    }
}
