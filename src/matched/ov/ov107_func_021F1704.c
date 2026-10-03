/*
 * function: func_021F1704
 * address:  0x021F1704
 * packet:   pkt_ov107_021F1704
 * region:   ov107
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201CE48  0x0201CE48  thumb
 *   func_0202F038  0x0202F038  thumb
 *   func_02045808  0x02045808  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_020457B0  0x020457B0  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_02194A24  0x02194A24  thumb
 *   func_0201F73C  0x0201F73C  thumb
 *   func_02028470  0x02028470  thumb
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
void func_0202F038(u8 *p);
void func_02045808(struct U16Vec *vec);
void *func_02045770(struct Descriptor *p);
void func_02043B5C(struct CharBuf *buf, u8 value);
void *func_02045EC0(struct MsgBank *bank, u32 index);
struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
void func_0201F250(struct WordSet *ws, void *dst, void *src);
int func_02194A24(void *, void *, int);
void func_0201F73C(void *, int, int, int);
void *func_0201CCE4(void *, int, int, void *, void *, int, void *, int, int, int);
void func_02028470(u8 *p, u32 v);

void func_021F1704(Ov107Ctx *p, int a, int b)
{
    void *s;

    if (p->f18 != 0) {
        func_0201CE48(p->f18);
        p->f18 = 0;
    }
    if (p->f5C != 0) {
        func_0202F038(p->f5C);
        p->f5C = 0;
    }
    p->f38 = 0;
    p->f58 = 0;
    if (p->f20 != 0) {
        func_02045808(p->f20);
        p->f20 = 0;
    }
    func_02043B5C(func_02045770(p->f10), 0xF);
    p->f20 = func_02045EC0(p->f1C, a);
    if (p->f24 != 0) {
        s = func_020457B0(0x17B, p->f00);
        func_0201F250(p->f24, s, p->f20);
        func_02045808(p->f20);
        p->f20 = s;
    }
    p->f18 = func_0201CCE4(p->f10, 0, 0, p->f20, p->f14, b, p->f0C, 2, p->f00, 0xF);
    if (p->f04 == 8) {
        func_02194A24(p->f54, p->f10, 0);
    } else {
        func_0201F73C(p->f10, 1, 1, 0xD);
    }
    if (p->f08 == 1) {
        func_02028470(p->f28, 6);
    } else {
        func_02028470(p->f28, 4);
    }
}
