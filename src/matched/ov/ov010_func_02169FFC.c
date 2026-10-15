/*
 * function: REPORT_EVENT_QueueMessage
 * address:  0x02169FFC
 * packet:   pkt_ov010_02169FFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   FIELD_MSGBG_GetFont  0x021904AC  thumb  ov021
 *   PRINTSYS_PrintQue  0x0201C6FC  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
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

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 FIELD_MSGBG_GetFont(u8 *p);
struct PrintSys;
extern void PRINTSYS_PrintQue(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);

void REPORT_EVENT_QueueMessage(Work *w, u32 msg)
{
    void *str;
    u32 a;
    Slot *s;
    void *t;
    void *p;

    BMP_Clear(BMP_WIN_GetBmp(w->f18->f08), 15);
    BMP_MENUWORK_DrawWindow(w->f18->f08, 2, 1, 13);
    str = func_02045EC0(w->f18->f04, msg);
    a = FIELD_MSGBG_GetFont(w->f0C);
    s = (Slot *)&w->f18->f08;
    t = w->f18->f14;
    PRINTSYS_PrintQue(t, (u32)BMP_WIN_GetBmp(s->f00), 0, 0, str, a);
    s->f04 = 1;
    STRBUF_Delete(str);
    p = w->f18->f08;
    BMP_WIN_TransferChars(p);
    BMP_WIN_MakeScreen(p);
    func_02041B6C(BMP_WIN_GetBgLayer(p));
}
