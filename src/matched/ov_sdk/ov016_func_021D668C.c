/*
 * function: readTouch
 * address:  0x021D668C
 * packet:   pkt_ov016_021D668C
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      readTouch (libdwcutil.TWL.HYB.a(input.o))
 *
 * symbols:
 *   TP_GetLatestIndexInAuto  0x0208AF08  arm
 *   TP_GetCalibratedPoint  0x0208B104  arm
 *   DWCi_InputCoord  0x021D5FE8  arm  ov016
 *   FX_ModS32  0x0207C994  arm
 *   gInputStatics     0x021DE688  data
 *
 * input.o's statics sit in one block; the vendor reaches them through one
 * pool word anchored at 0x021DE688 (DWCi_IPTlCheckFold's local static fold),
 * so the block is a struct overlay named by offset.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef long           s32;
typedef _Bool bool;

typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;

typedef struct tagCOORD {
    u16 x;
    u16 y;
} COORD;

typedef struct {
    TPData tp[5];
    COORD coord;
    COORD last;
    u8 pad30[8];
    u8 touch : 1;
    u8 trig : 1;
    u8 repeat : 1;
    u8 release : 1;
} InputWork;

typedef struct {
    u8 fold;
    u8 cnt;
    u8 pad2[2];
    InputWork *work;
} InputStatics;

extern u16 TP_GetLatestIndexInAuto(void);
struct TPData;
extern void TP_GetCalibratedPoint(struct TPData *disp, const struct TPData *raw);
extern void DWCi_InputCoord(int a, int b, unsigned short *p);
extern s32 FX_ModS32(s32 a, s32 b);
extern InputStatics gInputStatics;

void readTouch(void)
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
    gInputStatics.work->release = last & (touch ^ last);
    gInputStatics.work->touch = touch;
    gInputStatics.work->repeat = gInputStatics.work->trig;
    if (!touch) {
        gInputStatics.cnt = 0;
        return;
    }
    if (++gInputStatics.cnt == 40) {
        gInputStatics.work->repeat = 1;
        return;
    }
    if (gInputStatics.cnt == 47) {
        gInputStatics.work->repeat = 1;
        gInputStatics.cnt = 40;
    }
}
