/*
 * function: func_022050F0
 * address:  0x022050F0
 * packet:   pkt_ov094_022050F0
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GF_FONT_GetTextColor  0x0201DE00  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EC64  0x0201EC64  thumb
 *   func_0201DD78  0x0201DD78  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0201EEF4  0x0201EEF4  thumb
 *   func_0201F250  0x0201F250  thumb
 *   func_02204C98  0x02204C98  thumb  ov094
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02049F34  0x02049F34  arm
 *   PALANM_CopyToSlot  0x020215BC  thumb
 *   func_020307B0  0x020307B0  arm
 *   d_0220A7FC     0x0220A7FC  data
 *   d_0220A94C     0x0220A94C  data
 */
#include "../include/Obj01909.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Entry {
    u8 kind : 2;
    u8 flag : 1;
    u8 pad0 : 5;
    u8 pad1[3];
    short show;
    short pad6;
    void *text;
} Entry;

typedef struct Info {
    Entry e[6];
    u8 b48;
    u8 b49;
} Info;

typedef struct Bits6C {
    u32 lo : 2;
    u32 x : 8;
    u32 hi : 22;
} Bits6C;

typedef struct Out {
    u32 pad[3];
    int fc;
} Out;

typedef struct Res {
    u32 pad[3];
    u16 *fc;
} Res;

extern void GF_FONT_GetTextColor(u8 *, u8 *, u8 *);
struct MsgBank;
struct U16Vec;
struct WordSet;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
typedef signed short   s16;
struct PalAnmSlot;
extern struct WordSet *func_0201EC64(u32 heap);
extern void func_0201DD78(u32, u32, u32);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct StrObj;
extern void func_02204C98(struct StrObj *a, int b, int *outn, int *outq);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_0201ED04(struct WordSet *p);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void PALANM_CopyToSlot(struct PalAnmSlot *slots, const void *src, u32 idx, u32 off, u16 size);
extern u32 func_020307B0(void *p);

extern const int d_0220A7FC[2][6][2];
extern const int d_0220A94C[2][3][15];

void func_022050F0(char *s, Out *out, const Info *p)
{
    int n;
    int k;
    int i;
    int m;
    int idx;
    void *v;
    int h;
    void *w;
    void *r;
    int ww;
    int hh;
    Res *res;
    u8 c[3];

    n = (((struct Obj01909 *)s)->f50 == 2) ? 6 : 4;
    k = (((struct Obj01909 *)s)->f50 == 2) ? 1 : 0;
    GF_FONT_GetTextColor(&c[2], &c[1], &c[0]);
    v = func_020457B0(12, (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    h = (int)func_0201EC64((u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
    func_0201DD78(1, 2, 0);
    for (i = 0; i < n; i++) {
        if (p->e[i].show != 0) {
            w = func_02045EC0(((struct Obj01909 *)s)->f5C, p->e[i].kind + 3);
            func_0201EEF4((void *)h, 0, p->e[i].text);
            func_0201F250((struct WordSet *)h, v, w);
            func_02204C98((struct StrObj *)v, ((struct Obj01909 *)s)->f224, &ww, &hh);
            func_0201C7A4((void *)(((struct Obj01909 *)s)->f22C), d_0220A7FC[k][i][0] - ww / 2, d_0220A7FC[k][i][1], v, (void *)(((struct Obj01909 *)s)->f224));
            func_02045808(w);
        }
        (s + i)[0x25a] = p->e[i].flag;
    }
    (s + i)[0x25a] = 1;
    func_0201DD78(c[2], c[1], c[0]);
    func_0201ED04((struct WordSet *)h);
    func_02045808(v);
    idx = (p->b48 - 2) / 2;
    ((Bits6C *)(s + 0x6c))->x = p->b49;
    out->fc = d_0220A94C[k][idx][p->b49];
    m = 3;
    if (((struct Obj01909 *)s)->f50 != 2)
        m = 2;
    for (i = 0; i < m; i++) {
        r = func_02049F34(11, 0xd3, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
    for (m *= 2; i < m; i++) {
        r = func_02049F34(11, 0xd4, (u32)(&res), (u16)((((struct Obj01909 *)s)->f240 & 0x7fff) | 0x8000));
        PALANM_CopyToSlot((struct PalAnmSlot *)(((struct Obj01909 *)s)->f64), res->fc, 1, (u16)(i * 16 + 0x70), 0x20);
        func_020307B0(r);
    }
}
