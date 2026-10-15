/*
 * function: UNION_SUBDISP_DrawChatLine
 * address:  0x021F07AC
 * packet:   pkt_ov031_021F07AC
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note: 2026-10-05 (wave P6 U7b) closed from 28 B. The palette row offset is a byte
 * offset written (k * 0xE0) << 1 (the 0x1C0 byte length is the same row size), and the
 * flag helper tests e[0x20] == 0 first. The offset form fixed the k/c register swap
 * and the early shift; the helper polarity fixed bne vs beq.
 * symbols:
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   PMS_DRAW_IsActive  0x0202DCC4  thumb
 *   PMS_DRAW_Clear  0x0202DC9C  thumb
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_TransferChars  0x02045334  arm
 *   PMS_DRAW_PrintOffset  0x0202DC60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   BMP_WIN_MakeScreen  0x02045374  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_SetString  0x02045924  arm
 *   sUnionSubdispChatTextOffset     0x021F1040  data  ov031  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct { int a, b; } Pair;

struct Slot {
    u32 h;
    u8  f;
    u8  pad[3];
};

struct Obj {
    u32 w0;
    char pad0[0x40 - 4];
    u32 w40;
    u32 w44;
    u32 w48;
    u32 a[3];
    u32 b[3];
    struct Slot s[3];
    u32 w7c;
};

struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Obj0202DC98;
struct Obj0202DCC4;
struct Strbuf;
struct U16Vec;
extern u32 BG_SYS_GetBuf(int channel);
extern void MI_CpuCopy8(void *src, void *dst, int n);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32 bit);
extern u32 PMS_DRAW_IsActive(const struct Obj0202DCC4 *p, u32 i);
extern void PMS_DRAW_Clear(struct Obj0202DC98 *o, int i, u32 a1);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void PMS_DRAW_PrintOffset(struct Obj *p, u32 a, void *w, u32 i, u32 e);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void STRBUF_SetString(struct Strbuf *o, const u16 *src);
extern const Pair sUnionSubdispChatTextOffset;
static inline int paletteFlag(const u8 *e)
{
    if (e[0x20] == 0) return 0;
    return 2;
}

void UNION_SUBDISP_DrawChatLine(struct Obj *p, const u8 *e, u8 k)
{
    u16 *pal;
    int c;
    Pair t;
    void *x;
    void *buf;
    u32 q;
    int off;

    pal = (u16 *)BG_SYS_GetBuf(6);
    off = (k * 0xE0) << 1;
    c = paletteFlag(e);
    MI_CpuCopy8(pal, (u8 *)pal + off, 0x1C0);
    func_020413B0(6, 0, k * 7, 0x20, 7, c);
    func_02041B6C(6);
    t = sUnionSubdispChatTextOffset;
    if (p->b[k] == 0) {
        if (PMS_DRAW_IsActive((const struct Obj0202DCC4 *)p->w7c, k) == 1)
            PMS_DRAW_Clear((struct Obj0202DC98 *)p->w7c, k, 1);
    } else if (p->b[k] == 1) {
        BMP_Clear(BMP_WIN_GetBmp((struct Descriptor *)p->a[k]), 0);
        BMP_WIN_TransferChars((struct Descriptor *)p->a[k]);
    }
    if (e[0x21] == 0) {
        PMS_DRAW_PrintOffset((struct Obj *)p->w7c, p->a[k], (void *)(e + 0x10), k, (u32)(&t));
        p->b[k] = 0;
    } else {
        switch (e[0x21]) {
        case 1:
            x = func_02045EC0((struct MsgBank *)p->w48, 6);
            break;
        case 2:
            x = func_02045EC0((struct MsgBank *)p->w48, 0);
            break;
        case 3:
            x = func_02045EC0((struct MsgBank *)p->w48, 1);
            break;
        case 4:
            x = func_02045EC0((struct MsgBank *)p->w48, 2);
            break;
        case 5:
            x = func_02045EC0((struct MsgBank *)p->w48, 3);
            break;
        case 0:
            return;
        default:
            return;
        }
        BMP_WIN_MakeScreen((struct Cfg *)p->a[k]);
        func_02041B6C(BMP_WIN_GetBgLayer((struct Descriptor *)p->a[k]));
        q = p->w40;
        PRINTSYS_PrintQueColor((void *)q, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->s[k].h), (s16)0, (s16)t.b, (u32)x, p->w44, (u32)0x440);
        p->s[k].f = 1;
        STRBUF_Delete(x);
        p->b[k] = 1;
    }
    buf = STRBUF_Create(8, 0x15);
    STRBUF_SetString(buf, (const u16 *)e);
    PRINTSYS_PrintQueColor((void *)p->w40, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->a[k]), (s16)0, (s16)0, (u32)buf, p->w44, (u32)0x440);
    STRBUF_Delete(buf);
    if (e[0x22] != 0) {
        buf = func_02045EC0((struct MsgBank *)p->w48, (e[0x22] == 1) ? 4 : 5);
        PRINTSYS_PrintQueColor((void *)p->w40, (u32)BMP_WIN_GetBmp((struct Descriptor *)p->a[k]), (s16)0x74, (s16)0, (u32)buf, p->w44, (u32)0x440);
        STRBUF_Delete(buf);
    }
}
