/*
 * function: BTL_REC_SEL_DrawCounter
 * address:  0x021BA794
 * packet:   pkt_ov214_021BA794
 * region:   ov214
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb
 *   PRINTSYS_PrintQueColor  0x0201C724  thumb
 *   WORDSET_CreateDefault  0x0201EC64  thumb
 *   WORDSET_DeleteStrbufED04  0x0201ED04  thumb
 *   WORDSET_SetSlotNumber  0x0201EFA4  thumb
 *   WORDSET_CopyTaggedText  0x0201F250  thumb
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   STRBUF_Create  0x020457B0  arm
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045EC0  0x02045EC0  arm
 *   BTL_REC_SEL_ShowWindows  0x021BA4E8  thumb  ov214
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    unsigned short f00;
    unsigned short pad02;
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    char pad1c[0x58 - 0x1c];
    int f58;
    char pad5c[0x94 - 0x5c];
    int f94;
    int f98;
    char pad9c[0xa4 - 0x9c];
    int fA4;
    int fA8;
    char padAC[0xbc - 0xac];
    int fBC;
    unsigned short fC0;
} Ent;

typedef struct {
    int f00;
    int f04;
    int f08;
} Obj;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct PrintSys;
struct U16Vec;
struct WordSet;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void STRBUF_Delete(struct U16Vec *vec);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_PrintQueColor(int, int, int, int, int, int, int);
extern struct WordSet *WORDSET_CreateDefault(u32 heap);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
struct S;
extern void BTL_REC_SEL_ShowWindows(void *unused, struct S *p);

void BTL_REC_SEL_DrawCounter(Obj *obj, Ent *e, unsigned int v)
{
    int state;
    int flag;
    int tmp;
    int h;
    int p;
    int x;
    int h2;
    int p2;
    int q;

    if (obj->f08 == 0)
        return;

    if (v > 0xa) {
        flag = 0x440;
        state = 1;
    } else {
        flag = 0xc80;
        state = 2;
    }

    if (state != e->fBC) {
        tmp = (int)BMP_WIN_GetBmp((struct Descriptor *)e->f94);
        BMP_Clear((struct CharBuf *)tmp, 0);
        tmp = (int)BMP_WIN_GetBmp((struct Descriptor *)e->f98);
        BMP_Clear((struct CharBuf *)tmp, 0);
    } else if (v != e->fC0) {
        tmp = (int)BMP_WIN_GetBmp((struct Descriptor *)e->f98);
        BMP_Clear((struct CharBuf *)tmp, 0);
    }

    if (state != e->fBC) {
        PRINTSYS_QUE_Clear((struct PrintSys *)e->f14);
        h = (int)func_02045EC0((struct MsgBank *)e->f58, 0x10);
        p = (int)BMP_WIN_GetBmp((struct Descriptor *)e->f94);
        PRINTSYS_PrintQueColor(e->f14, p, 4, 1, h, e->f08, flag);
        e->fA4 = 0;
        STRBUF_Delete((struct U16Vec *)h);
    }

    if (state != e->fBC || v != e->fC0) {
        x = (int)WORDSET_CreateDefault(e->f00);
        h2 = (int)func_02045EC0((struct MsgBank *)e->f58, 0x12);
        p2 = (int)STRBUF_Create(8, e->f00);
        PRINTSYS_QUE_Clear((struct PrintSys *)e->f18);
        WORDSET_SetSlotNumber((struct WordSet *)x, 1, v, 2, 2, 1);
        WORDSET_CopyTaggedText((struct WordSet *)x, (void *)p2, (void *)h2);
        q = (int)BMP_WIN_GetBmp((struct Descriptor *)e->f98);
        PRINTSYS_PrintQueColor(e->f18, q, 2, 2, p2, e->f08, flag);
        e->fA8 = 0;
        STRBUF_Delete((struct U16Vec *)p2);
        STRBUF_Delete((struct U16Vec *)h2);
        WORDSET_DeleteStrbufED04((struct WordSet *)x);
    }

    e->fBC = state;
    e->fC0 = v;
    BTL_REC_SEL_ShowWindows(obj, (struct S *)e);
}
