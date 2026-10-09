/*
 * file:     unit_0220BC70_p01.c
 * unit:     yes
 * function: func_0220BC70, func_0220BD34, func_0220BD84, func_0220BDA0, func_0220BDD4, func_0220BE04, func_0220BE2C, func_0220BEB8
 * address:  0x0220BC70
 * region:   ov198
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020450F0 0x020450F0 arm
 *   d_02211BDA 0x02211BDA data a1
 *   d_02211B80 0x02211B80 data a1
 *   d_02211CB0 0x02211CB0 data a1
 *   d_02211BFE 0x02211BFE data a1
 *   d_02211C24 0x02211C24 data a1
 *   d_02211B98 0x02211B98 data a1
 *   d_02211BB6 0x02211BB6 data a1
 *   d_02211C68 0x02211C68 data a1
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_020452E8 0x020452E8 arm
 *   func_0220C60C  0x0220C60C  thumb  ov198
 *   func_0220D884  0x0220D884  thumb  ov198
 *   func_0220D9B4  0x0220D9B4  thumb  ov198
 *   func_0220DCA8  0x0220DCA8  thumb  ov198
 *   func_0220DC04  0x0220DC04  thumb  ov198
 *   func_0220DD78  0x0220DD78  thumb  ov198
 *   func_0220DE4C  0x0220DE4C  thumb  ov198
 *   func_0220DF20  0x0220DF20  thumb  ov198
 *   func_0220E088  0x0220E088  thumb  ov198
 *   func_02045778 0x02045778 arm
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EEF4 0x0201EEF4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045738 0x02045738 arm
 *   func_0201D304 0x0201D304 thumb
 *   d_02211B68 0x02211B68 data ov198 a4
 */
#include "../../matched/include/Obj25130.h"
#include "../../matched/include/Obj14554.h"
#include "../../matched/include/Obj25132.h"
#include "../../matched/include/Obj00507.h"

#define P ((struct Ov198P *)p)
struct Descriptor;
struct CharBuf;
struct MsgBank;
struct StrObj;
struct U16Vec;
struct WordSet;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Item { u8 a,b,c,d,e,f; } Item;

typedef struct Bits { unsigned char low:5; unsigned char high:3; } Bits;

typedef unsigned short u16;

typedef signed short   s16;

typedef signed char    s8;

struct R {
    u8 pad[0x16];
    u8 a0 : 7;
    u8 a1 : 1;
    u8 b0 : 3;
    u8 b1 : 4;
    u8 b2 : 1;
};

struct Ov198Hdr { char pad[0xC]; u32 font; u16 f10; };

struct Ov198P { struct Ov198Hdr *hdr; char pad[0x1E9C]; void *f1EA0; void *f1EA4; void *pad8; u32 f1EAC; };

extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern u32 func_020452E8(struct Descriptor *d);
extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *,u8);
extern int func_0220C60C(char *, int);
extern void func_0220D884(u8 *p);
extern int func_0220D9B4(char *);
extern int func_0220DCA8(char *);
extern int func_0220DC04(char *);
extern int func_0220DD78(char *);
extern int func_0220DE4C(char *);
extern int func_0220DF20(char *);
extern int func_0220E088(char *);
extern u8 func_02045778(struct Descriptor *p);
extern int func_022110D4(u8 *, int);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(u32, u32, s16, s16, void *, u32, u32);
extern void func_02045808(struct U16Vec *vec);
extern u8 func_02045738(struct Descriptor *p);
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
void func_0220BC70(u8 *p,u32 state);
void func_0220BD34(u8 *p);
void func_0220BD84(u8 *p);
void func_0220BDA0(u8 *p);
void func_0220BDD4(char *p);
void func_0220BE04(u8 *p);
int func_0220BE2C(char *a, int idx);
void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra);
extern Item d_02211BDA[],d_02211B80[],d_02211CB0[],d_02211BFE[],d_02211C24[],d_02211B98[],d_02211BB6[],d_02211C68[];
extern u32 d_02211B68[];



/*
 * precondition: game callers supply state 0..8; every case initializes s.
 * evidence: C88's nine callers pass constants0..8; F4E0 dominates BC24
 * with state-byte2180 stores0/4/6. C88 stores its bounded state at2177+9.
 * Domain and decoded-call audit: Wave30 S26/BC70-domain-review.md.
 */
void func_0220BC70(u8 *p,u32 state)
{
    Item *s;
    u32 i;
    func_0220BD84(p);
    func_0220BD34(p);
    switch(state) {
    case 0: case 8: s=d_02211BDA; p[0x2174]=6; break;
    case 1: s=d_02211B80; p[0x2174]=4; break;
    case 2: s=d_02211CB0; p[0x2174]=22; break;
    case 3: s=d_02211BFE; p[0x2174]=6; break;
    case 4: s=d_02211C24; p[0x2174]=11; break;
    case 5: s=d_02211B98; p[0x2174]=5; break;
    case 6: s=d_02211BB6; p[0x2174]=6; break;
    case 7: s=d_02211C68; p[0x2174]=12; break;
    }
    for(i=0;i<p[0x2174];i++,s++)
        *(void **)(p+i*8+0x1F70)=(void *)func_020450F0(s->a,s->b,s->c,s->d,s->e,s->f,1);
}



void func_0220BD34(u8 *p)
{
    if (((Bits *)(p+0x2175))->low == 1)
        ((struct Obj25130 *)p)->f2170=(void *)func_020450F0(5,0,0,32,16,0,1);
    ((Bits *)(p+0x2175))->low ^= 1;
}




/*
 * Addresses are Black-image addresses.
 */
void func_0220BD84(u8 *p)
{
    u32 t = ((struct Obj14554 *)p)->f2170;

    if (t != 0) {
        func_020452E8((struct Descriptor *)t);
        ((struct Obj14554 *)p)->f2170 = 0;
    }
}



void func_0220BDA0(u8 *p){u32 i;for(i=0;i<p[0x2174];i++)func_02043B5C(func_02045770(*(struct Descriptor **)(p+i*8+0x1f70)),0);}




void func_0220BDD4(char *p)
{
    unsigned int i;
    for (i = 0; i < ((struct Obj25132 *)p)->f2174; i++)
    {
        func_020452E8(*(void **)(p + 0x1f70 + i * 8));
    }
}



void func_0220BE04(u8 *p){u32 i;func_0220BDD4((char *)p);for(i=0;i<2;i++)func_020452E8(*(struct Descriptor **)(p+i*8+0x1f60));func_0220BD84(p);}




int func_0220BE2C(char *a, int idx)
{
    switch (idx) {
    case 0: {
        unsigned char c;
        func_0220D884((u8 *)a);
        c = *(unsigned char *)(*(int *)&((struct Obj00507 *)a)->f0 + 0x1f);
        if (c == 3)
            return func_0220C60C(a, 7);
        if (c == 2)
            return func_0220C60C(a, 9);
        return func_0220C60C(a, 6);
    }
    case 8:
        func_0220D884((u8 *)a);
        return func_0220C60C(a, 0xa);
    case 1:
        return func_0220D9B4(a);
    case 2:
        return func_0220DCA8(a);
    case 3:
        return func_0220DC04(a);
    case 4:
        return func_0220DD78(a);
    case 5:
        return func_0220E088(a);
    case 6:
        return func_0220DE4C(a);
    case 7:
        return func_0220DF20(a);
    }
}


/*
 * lever: rec is passed as `*(void **)rec` (a real variable, not a CSE temp); ex is an s16 local (the callee's
 *   parameter type) set in each head arm; a2 is u16 (the caller passes `(u16)i`); tail colour depends on b0
 * 2026-10-05 (wD9r lane121): 45 -> EXACT. Fixes: (1) the 0201EEF4 argument written `*(void **)rec`, so rec is a
 *   declared variable with its own slot (the `base + off` form made it a CSE temp in the lowest slot); (2) lane 94's
 *   declaration order (w2, w, off, handle, rec, vec, msg, x, k, c90, cn0, c91, cn1, ex, m3, m2, x2) with the four
 *   tail ctx values as function-scope locals; (3) ex as s16 (the 0201C724 parameter type), assigned in each head
 *   arm: a u8 copy coalesced with the stack parameter; (4) logic fix: the tail colour is 0x2960 for b0 == 0 and
 *   0x31A0 for b0 == 1 in both k arms (the draft had it per k); (5) a2 as u16 (the matched caller passes
 *   `(u16)i`), which puts the a2 spill store first at entry.
 */
void func_0220BEB8(u8 *p, int slot, u16 a2, u8 a3, u8 extra)
{
    u32 w2;
    u32 w;
    u32 off;
    void *handle;
    struct R *rec;
    void *vec;
    void *msg;
    u32 x;
    u32 k;
    u32 c90;
    u32 cn0;
    u32 c91;
    u32 cn1;
    s16 ex;
    void *m3;
    void *m2;
    u32 x2;
    int n;
    u8 *base;
    u8 *tab;

    slot = slot * 8;
    tab = p + 0x1F70;
    handle = *(void **)(tab + slot);
    k = func_02045778(handle);
    n = func_022110D4(p, a2);
    base = p + 4;
    off = n * 0x4C;
    rec = (struct R *)(base + off);
    vec = func_020457B0(12, P->hdr->f10);
    msg = func_02045EC0(P->f1EA0, d_02211B68[a2]);
    func_0201EEF4(P->f1EA4, 0, *(void **)rec);
    func_0201F250(P->f1EA4, vec, msg);
    if (k == 9) {
        u32 h9 = P->f1EAC;
        ex = extra;
        func_0201C724(h9, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    } else {
        u32 hn = P->f1EAC;
        ex = extra;
        func_0201C724(hn, (u32)func_02045770(*(void **)(tab + slot)), a3, ex, vec, P->hdr->font, 0x3DC0);
        *(p + 0x1F74 + slot) = 1;
    }
    func_02045808(msg);
    func_02045808(vec);
    if (rec->a1 || rec->b2)
        return;
    if (rec->b0 == 0) {
        m2 = func_02045EC0(P->f1EA0, 0x16);
        w = func_02045738(handle);
        x = (u16)((w << 3) - func_0201D304(m2, P->hdr->font, 0));
        if (k == 9) {
            c90 = P->f1EAC;
            func_0201C724(c90, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn0 = P->f1EAC;
            func_0201C724(cn0, (u32)func_02045770(*(void **)(tab + slot)), x, ex, m2, P->hdr->font, 0x2960);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m2);
    } else if (rec->b0 == 1) {
        m3 = func_02045EC0(P->f1EA0, 0x17);
        w2 = func_02045738(handle);
        x2 = (u16)((w2 << 3) - func_0201D304(m3, P->hdr->font, 0));
        if (k == 9) {
            c91 = P->f1EAC;
            func_0201C724(c91, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        } else {
            cn1 = P->f1EAC;
            func_0201C724(cn1, (u32)func_02045770(*(void **)(tab + slot)), x2, ex, m3, P->hdr->font, 0x31A0);
            *(p + 0x1F74 + slot) = 1;
        }
        func_02045808(m3);
    }
}
