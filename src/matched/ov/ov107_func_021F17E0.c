/*
 * function: func_021F17E0
 * address:  0x021F17E0
 * packet:   pkt_ov107_021F17E0
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   TIME_ICON_Delete  0x0202F038  thumb
 *   STRBUF_Delete  0x02045808  arm
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   STRBUF_Create  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201C6FC  0x0201C6FC  thumb
 *   TALKMSGWIN_DrawWindowFrame  0x02194A24  thumb
 *   func_020409B4  0x020409B4  arm
 *   func_0201F73C  0x0201F73C  thumb
 */

typedef struct {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    int f04;
    int f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28[8];
    void *f30;
    int f34;
    int f38;
    unsigned char pad3C[0x18];
    void *f54;
    int f58;
    void *f5C;
} Ov107Ctx;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
void func_0201CE48(struct Rec3 *p);
void TIME_ICON_Delete(u8 *p);
void STRBUF_Delete(struct U16Vec *vec);
void *func_02045770(struct Descriptor *p);
void BMP_Clear(struct CharBuf *buf, u8 value);
void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
int TALKMSGWIN_DrawWindowFrame(void *, void *, int);
void func_0201F73C(void *, int, int, int);
struct PrintSys;
void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_020409B4(u32 index);

void func_021F17E0(Ov107Ctx *p, int a)
{
    void *s;

    if (p->f18 != 0) {
        func_0201CE48(p->f18);
        p->f18 = 0;
    }
    if (p->f5C != 0) {
        TIME_ICON_Delete(p->f5C);
        p->f5C = 0;
    }
    if (p->f20 != 0) {
        STRBUF_Delete(p->f20);
        p->f20 = 0;
    }
    BMP_Clear(func_02045770(p->f10), 0xF);
    p->f20 = func_02045EC0(p->f1C, a);
    if (p->f24 != 0) {
        s = STRBUF_Create(0x17B, p->f00);
        func_0201F250(p->f24, s, p->f20);
        STRBUF_Delete(p->f20);
        p->f20 = s;
    }
    func_0201C6FC(p->f30, (u32)func_02045770(p->f10), 0, 0, p->f20, (u32)p->f14);
    p->f34 = 1;
    if (p->f04 == 8) {
        TALKMSGWIN_DrawWindowFrame(p->f54, p->f10, 0);
        func_020409B4(p->f02);
    } else {
        func_0201F73C(p->f10, 1, 1, 0xD);
    }
}
