/*
 * function: REPORT_EVENT_UpdateMessageQueue
 * address:  0x0216A07C
 * packet:   pkt_ov010_0216A07C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   PRINTSYS_QUE_IsExistTarget  0x0201C6C4  thumb
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   PRINTSYS_QUE_IsFinished  0x0201C6B4  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u8 pad0C[0x10 - 0x0C];
    void *f10;          /* 0x10 */
    void *f14;          /* 0x14 */
    void *f18;          /* 0x18 */
    void *f1C;          /* 0x1C */
    u32 f20;            /* 0x20 */
    void *f24;          /* 0x24 */
    u16 f28;            /* 0x28 */
    u32 f2C;            /* 0x2C */
    void *f30;          /* 0x30 */
    u16 f34;            /* 0x34 */
    u32 f38;            /* 0x38 */
    void *f3C;          /* 0x3C */
    void *f40;          /* 0x40 */
} Res;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 *f08;            /* 0x08 */
    void *f0C;          /* 0x0C */
    u16 f10;            /* 0x10 */
    u8 pad12[0x18 - 0x12];
    Res *f18;           /* 0x18 */
} Work;

typedef struct Slot {
    void *f00;
    u8 f04;
} Slot;

struct Descriptor;
struct PrintSys;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern u32 PRINTSYS_QUE_IsExistTarget(struct PrintSys *p, void *v);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u32 PRINTSYS_QUE_IsFinished(const struct PrintSys *p);

int REPORT_EVENT_UpdateMessageQueue(Work *w)
{
    Slot *s;
    void *t;

    PRINTSYS_QUE_Main(w->f18->f14);
    t = w->f18->f14;
    s = (Slot *)&w->f18->f08;
    if (s->f04 != 0 && PRINTSYS_QUE_IsExistTarget(t, BMP_WIN_GetBmp(s->f00)) == 0) {
        BMP_WIN_TransferChars(s->f00);
        s->f04 = 0;
    }
    return PRINTSYS_QUE_IsFinished(w->f18->f14);
}
