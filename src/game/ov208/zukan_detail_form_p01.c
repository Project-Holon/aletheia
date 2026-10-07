/*
 * file:     zukan_detail_form_p01.c
 * unit:     yes
 * function: func_021C31CC, func_021C3208, func_021C3218, func_021C3268, func_021C3280, func_021C32FC, func_021C3318, func_021C3354, func_021C3374, func_021C3378, func_021C337C, func_021C3380, func_021C3480, func_021C34A4, func_021C3514, func_021C35DC, func_021C3638, func_021C3650, func_021C3678, func_021C36CC, func_021C3840, func_021C3A24, func_021C3AA8, func_021C3B14
 * address:  0x021C31CC
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02049B90 0x02049B90 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045334 0x02045334 arm
 *   func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201D304 0x0201D304 thumb
 *   func_02045770 0x02045770 arm
 *   func_020437DC 0x020437DC arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   data_020A7370 0x020A7370 data a4
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045730 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_020870D0 0x020870D0 arm
 *   _ll_udiv 0x0209C00C arm
 *   _s32_div_f 0x0209C0A4 arm
 *   ov208_func_021C3208 0x021C3208 thumb ov208
 *   ov208_func_021C337C 0x021C337C thumb ov208
 *   ov208_func_021C3378 0x021C3378 thumb ov208
 *   ov208_func_021C2DE0 0x021C2DE0 thumb ov208
 *   func_02006650  0x02006650  thumb
 *   func_020065D8  0x020065D8  thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021C2FEC 0x021C2FEC thumb ov208
 *   func_021C2E6C 0x021C2E6C thumb ov208
 *   func_020362DC 0x020362DC arm
 *   func_020355D8 0x020355D8 arm
 *   func_02035D20 0x02035D20 arm
 *   ov208_func_021BC3A4 0x021BC3A4 thumb ov208
 *   func_0200CA1C 0x0200CA1C thumb
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   func_0200CC40 0x0200CC40 thumb
 *   func_02006984 0x02006984 thumb
 *   ov208_func_021C31CC 0x021C31CC thumb ov208
 *   func_02030734 0x02030734 arm
 *   func_02043678 0x02043678 arm
 *   data_021C8E28 0x021C8E28 data ov208 a1
 *   func_021C36CC 0x021C36CC thumb ov208
 *   func_02043AF4 0x02043AF4 arm
 *   func_020439A0 0x020439A0 arm
 *   ov208_func_021C3A24 0x021C3A24 thumb ov208
 *   func_02006B5C 0x02006B5C thumb
 *   func_02006B94 0x02006B94 thumb
 *   func_02006B3C 0x02006B3C thumb
 *   func_02006B78 0x02006B78 thumb
 *   func_02006B20 0x02006B20 thumb
 *   _ffltu 0x0209BE04 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _fadd 0x0209C95C arm
 *   _fmul 0x0209C77C arm
 *   _ffixu 0x0209C4C8 arm
 *   func_02045768 0x02045768 arm
 *   func_02041090 0x02041090 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_021BC518 0x021BC518 thumb ov208
 */
#include "../../matched/include/Obj09208.h"
#include "../../matched/include/Obj00146.h"
#include "../../matched/include/Obj09209.h"
#include "../../matched/include/Obj02256.h"
#include "../../matched/include/Obj06684.h"
#include "../../matched/include/Obj09210.h"
#include "../../matched/include/Obj01010.h"
#include "../../matched/include/Obj06685.h"

struct Obj;
struct Vec2;
struct Pair;
struct Descriptor;
struct PrintSys;
struct MsgBank;
struct StrObj;
struct Bmp;
struct U16Vec;
struct Key;
struct CharBuf;
struct Cfg;
struct S;
struct Obj020437AC;
struct Actor;
typedef unsigned int   u32;

typedef struct {
    char pad[0x60];
    unsigned int state;
} S;

typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned long long u64;

struct Ov208Scroll {
    u8 pad0[0x18];
    s16 a;
    s16 b;
    u8 pad1c[0x20 - 0x1c];
    struct Descriptor *desc;
    u8 pad24[0x2c - 0x24];
    struct Bmp *dst;
    s16 c;
    s16 d;
};

typedef signed char    s8;

extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_0204B5AC(struct Obj *dst, struct Pair *src);
extern void func_02049B90(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045334(struct Descriptor *);
extern void func_0201C6EC(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern u16 func_021BC3C0(struct Key *key);
extern void *func_02045EC0(struct MsgBank *bank,u32 index);
extern u32 func_0201D304(struct StrObj *s,u32 a,u32 b);
extern void *func_02045770(struct Descriptor *p);
extern u16 func_020437DC(const struct Bmp *p);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *s);
extern void func_02043B5C(struct CharBuf *p, u8 v);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern u64 func_020870D0(void);
extern void ov208_func_021C3208(u16 *heap, u8 *p, int key);
extern void ov208_func_021C337C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C3378(u16 *heap, u8 *p, int key, int first, u16 second);
extern void ov208_func_021C2DE0(u16 *heap, u8 *p, int key, int first, u16 second);
extern int func_02006650(void);
extern void func_020065D8(void);
extern void func_0204B3DC(struct Obj *p,u32 v);
extern void func_021C2FEC(void *unused, struct S *p, u32 unused2, u32 i);
extern void func_021C2E6C(u16 *heap, u8 *p, int key, u32 slot);
extern u32 func_020362DC(void);
extern void func_020355D8(u8 v);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern int ov208_func_021BC3A4(int key);
extern void *func_0200CA1C(void *a);
extern u16 ov208_func_021BC3C0(int key);
extern void func_0200CC40(u8 *p, u16 id, u32 *out1, u32 *out2, u32 *outForm, u16 a5);
extern u32 func_02006984(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern void ov208_func_021C31CC(u16 *heap, u8 *p, int key);
extern void *func_02030734(u32 heap,u32 size,int clear,const char *file,u16 line);
extern struct Bmp *func_02043678(u32 width, u32 height, u32 depth, u16 heap);
extern void func_020437AC(struct Obj020437AC *p);
extern u32 func_020307B0(void *p);
extern void func_021C36CC(u16 *heap, u8 *p, int key);
extern void func_02043AF4(struct Bmp *p,u32 a,u32 b,u32 c,u32 d,u32 e);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y,
                          int sx, int sy, u32 w, u32 h, u32 key);
extern void ov208_func_021C3A24(u16 *heap, u8 *p, int key);
extern u32 func_02006B5C(u32 i);
extern u32 func_02006B94(u32 i);
extern u32 func_02006B3C(u32 i);
extern u32 func_02006B78(u32 i);
extern s8 func_02006B20(u32 i);
extern u16 func_02045768(struct Descriptor *p);
extern void func_02041090(u32 index,u32 a,u32 b,u32 c,u8 d,u8 e);
extern void func_0204B688(struct Actor *p,u32 value);
extern void func_0207D63C(u32 reg,int p1,int p2,int ev1,int ev2);
extern void func_021BC518(int *p);
void func_021C31CC(int unused, char *q);
void func_021C3208(int unused, S *p);
void func_021C3218(u16 *heap,u8 *p,int key);
void func_021C3268(void *unused, char *p, void *a2);
void func_021C3280(u16 *heap,u8 *p,struct Key *key);
void func_021C32FC(u16 *heap, u8 *p, int key);
void func_021C3318(u16 *heap, u8 *p, int key);
void func_021C3354(unsigned short *p, void *a1, int a2);
void func_021C3374(void *a0, void *st, void *a2);
void func_021C3378(void *a0, void *a1, int a2, int a3, int a4);
void func_021C337C(void *a0, void *st, void *a2);
void ov208_func_021C3380(u16 *heap, u8 *p, int key);
void func_021C3480(int unused, char *p, int key);
void func_021C34A4(u16 *heap,u8 *p,int key);
void ov208_func_021C3514(u16 *heap, u8 *p, int key);
void func_021C35DC(u16 *heap,u8 *p,int key);
void func_021C3638(void *unused, char *p, void *a2);
void func_021C3650(u16 *heap, u8 *p, int key);
void func_021C3678(u16 *heap,u8 *p,int key);
void ov208_func_021C36CC(u16 *heap, struct Ov208Scroll *p, int key);
void ov208_func_021C3840(u16 *heap, u8 *p, int key, u16 a, u16 b);
void func_021C3A24(u16 *heap,u8 *p,int key);
void func_021C3AA8(void *unused, u8 *p, int a2);
void func_021C3B14(void *unused, u8 *p, int a2);
void func_021C3B68(u16 *p, u32 value);
extern struct MsgBank *data_020A7370;
extern const char data_021C8E28[];


/*
 * Hands the element at +0x5C a 0x80 pair and a 0x1000 pair and marks +0x60.
 *
 * Blocker resolved: 0x0204B5AC was matched in arm9 (src/matched/
 * func_0204B5AC.c, shard pkt_0204B5AC), so the call at +0x30 attests as
 * `matched`.  All 58 concrete bytes equal (the 60-byte listing extent is 58
 * plus two padding bytes); the extent ran two bytes long because the follower
 * has no func_ label.
 */
void func_021C31CC(int unused, char *q)
{
    struct {
        unsigned int w[2];
        unsigned short h[2];
    } buf;

    buf.h[0] = 0x80;
    buf.h[1] = 0x80;
    buf.w[0] = 0x1000;
    buf.w[1] = 0x1000;
    func_0204B404((struct Obj *)(*(int *)(q + ((struct Obj09208 *)q)->f5C * 4 + 0x54)), (const struct Vec2 *)buf.h, 1);
    func_0204B5AC((struct Obj *)(*(int *)(q + ((struct Obj09208 *)q)->f5C * 4 + 0x54)), (struct Pair *)buf.w);
    ((struct Obj09208 *)q)->f60 = 1;
}


/*
 * Writes 3 to +0x60 when the word there, less one, is 0 or 1.
 */
void func_021C3208(int unused, S *p)
{
    unsigned int v = p->state;

    v -= 1;
    if (v <= 1)
        p->state = 3;
}

void func_021C3218(u16 *heap,u8 *p,int key)
{
    func_02049B90(23,5,4,0,0,32,*heap);
    *(u32 *)&((struct Obj00146 *)p)->fC=func_020450F0(6,10,5,12,4,0,1);
    ((struct Obj00146 *)p)->f10=0;
    func_021C32FC(heap,p,key);
    func_02045334((struct Descriptor *)*(u32 *)&((struct Obj00146 *)p)->fC);
}


/*
 * Clears +0x10 and releases the two handles at +8 and +0xC.
 */
void func_021C3268(void *unused, char *p, void *a2)
{
    ((struct Obj09209 *)p)->f10 = 0;
    func_0201C6EC((struct PrintSys *)(((struct Obj09209 *)p)->f8));
    func_020452E8((struct Descriptor *)(((struct Obj09209 *)p)->fC));
}

void func_021C3280(u16 *heap,u8 *p,struct Key *key)
{
    struct StrObj *text;
    u16 width;
    u16 available;
    text=func_02045EC0(data_020A7370,func_021BC3C0(key));
    width=func_0201D304(text,((struct Obj00146 *)p)->f4,0);
    available=func_020437DC(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC));
    func_0201C724(((struct Obj00146 *)p)->f8,(u32)func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC),(s16)((u16)((available-width)/2)),(s16)1,(u32)text,((struct Obj00146 *)p)->f4,0x3c40);
    func_02045808((struct U16Vec *)text);
    ((struct Obj00146 *)p)->f10=1;
    func_021C3318(heap,p,(int)key);
}

void func_021C32FC(u16 *heap, u8 *p, int key)
{
    ((struct Obj00146 *)p)->f10 = 0;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8);
    func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC), 0);
}

void func_021C3318(u16 *heap, u8 *p, int key)
{
    struct Descriptor *d;
    if (((struct Obj00146 *)p)->f10 != 0) {
        if (func_0201C6C4(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8, func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC)) == 0) {
            d = *(struct Descriptor * *)&((struct Obj00146 *)p)->fC;
            func_02045334(d);
            func_02045374((struct Cfg *)d);
            func_02041B6C(func_02045730(d));
            ((struct Obj00146 *)p)->f10 = 0;
        }
    }
}


/*
 * Posts message 0x17 with the halfword at +0 as its last argument.
 */
void func_021C3354(unsigned short *p, void *a1, int a2)
{
    func_02049B90(0x17, 5, 0, 0, 0x20, 0x20, *p);
}

/*
 * Empty stub; the listing pads it with two zero bytes.
 */
void func_021C3374(void *a0, void *st, void *a2)
{
}

void func_021C3378(void *a0, void *a1, int a2, int a3, int a4)
{
}

void func_021C337C(void *a0, void *st, void *a2)
{
}


void ov208_func_021C3380(u16 *heap, u8 *p, int key)
{
    u64 now;
    u64 start;
    u64 diff;
    u64 ms;
    u16 cur;
    u16 secs;
    u16 rem;
    u16 hund;
    if (((struct Obj02256 *)p)->f68 != 0) {
        now = func_020870D0();
        start = *(u64 *)(p + 0x6c);
        if (now >= start)
            diff = now - start;
        else
            diff = now + (0xFFFFFFFFFFFFFFFFULL - start);
        ms = (diff * 64) / 33514;
        if (ms > 9990)
            ms = 9990;
        ((struct Obj02256 *)p)->f74 = (u16)ms;
        if (((struct Obj02256 *)p)->f74 >= ((struct Obj02256 *)p)->f38) {
            ((struct Obj02256 *)p)->f74 = ((struct Obj02256 *)p)->f38;
            ((struct Obj02256 *)p)->f68 = 0;
            ov208_func_021C3208(heap, p, key);
        }
    }
    cur = ((struct Obj02256 *)p)->f74;
    if (cur != ((struct Obj02256 *)p)->f76) {
        secs = cur / 1000;
        rem = cur % 1000;
        hund = rem / 10 + ((rem % 10) >= 5 ? 1 : 0);
        ov208_func_021C337C(heap, p, key);
        ov208_func_021C3378(heap, p, key, secs, hund);
        ov208_func_021C2DE0(heap, p, key, secs, hund);
        ((struct Obj02256 *)p)->f76 = ((struct Obj02256 *)p)->f74;
    }
}


/*
 * BLOCKED.  Unverifiable: func_020065D8 resolves only through the `matched` class and layout/matched/ov093 holds func_021B911C in two shards, which aborts every manifest load.
 */
void func_021C3480(int unused, char *p, int key)
{
    int v;

    if (((struct Obj00146 *)p)->f68 != 0) {
        v = func_02006650();
        if (v != 0)
            func_020065D8();
        ((struct Obj00146 *)p)->f68 = 0;
    }
    ((struct Obj00146 *)p)->f74 = 0;
}

void func_021C34A4(u16 *heap,u8 *p,int key)
{
    if(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54))
        func_0204B3DC(*(struct Obj **)(p+((struct Obj00146 *)p)->f5C*4+0x54),0);
    ((struct Obj00146 *)p)->f5C=(((struct Obj00146 *)p)->f5C+1)%2;
    func_021C32FC(heap,p,key);
    func_021C2FEC(heap,(struct S *)p,key,((struct Obj00146 *)p)->f5C);
    func_021C2E6C(heap,p,key,((struct Obj00146 *)p)->f5C);
    func_021C3280(heap,p,(struct Key *)key);
    func_021C3480((int)heap,(char *)p,key);
    func_021C3678(heap,p,key);
}


void ov208_func_021C3514(u16 *heap, u8 *p, int key)
{
    u32 hit;
    u16 species;
    u32 x;
    u32 y;
    u32 form;
    u32 o1;
    u32 o2;
    void *pd;
    hit = 0;
    if (((struct Obj06684 *)p)->fD0 != 0) {
        if (func_020362DC() & 1) {
            func_020355D8(0);
            hit = 1;
        } else if (func_02035D20(&x, &y) != 0) {
            if (x < 0x100 && y < 0xa8) {
                hit = 1;
                func_020355D8(1);
            }
        }
    }
    if (hit != 0) {
        pd = func_0200CA1C((void *)ov208_func_021BC3A4(key));
        species = ov208_func_021BC3C0(key);
        func_0200CC40(pd, species, &o1, &o2, &form, *heap);
        ((struct Obj06684 *)p)->f64 = func_02006984(species, form, 0x40, 0, 0, 0, 0, 0);
        ((struct Obj06684 *)p)->f74 = 0;
        *(u64 *)(p + 0x6c) = func_020870D0();
        ((struct Obj06684 *)p)->f68 = 1;
        ov208_func_021C3840(heap, p, key, species, form);
        ov208_func_021C31CC(heap, p, key);
    }
}

void func_021C35DC(u16 *heap,u8 *p,int key)
{
    ((struct Obj00146 *)p)->f14=func_02030734(*heap,0x3a2,1,data_021C8E28,0x8a1);
    *(u32 *)&((struct Obj00146 *)p)->f20=func_020450F0(3,1,2,31,15,1,1);
    func_021C3678(heap,p,key);
    *(struct Bmp * *)&((struct Obj00146 *)p)->f2C=func_02043678(121,15,32,*heap);
}


/*
 * Releases the three handles at +0x2C, +0x20 and +0x14.
 */
void func_021C3638(void *unused, char *p, void *a2)
{
    func_020437AC((struct Obj020437AC *)(((struct Obj09210 *)p)->f2C));
    func_020452E8((struct Descriptor *)(((struct Obj09210 *)p)->f20));
    func_020307B0((void *)(((struct Obj09210 *)p)->f14));
}

void func_021C3650(u16 *heap, u8 *p, int key)
{
    if (p[0x24] != 0) {
        p[0x24]--;
        return;
    }
    func_021C36CC(heap, p, key);
    p[0x24] = 0;
}

void func_021C3678(u16 *heap,u8 *p,int key)
{
    struct Bmp *bmp;
    p[0x24] = 0;
    ((struct Obj00146 *)p)->f18 = 0;
    ((struct Obj00146 *)p)->f1A = 0;
    ((struct Obj00146 *)p)->f26 = 0;
    ((struct Obj00146 *)p)->f28 = 0;
    ((struct Obj00146 *)p)->f30 = 0;
    ((struct Obj00146 *)p)->f32 = *(s16 *)&((struct Obj00146 *)p)->f30;
    ((struct Obj00146 *)p)->f38 = 0;
    bmp = func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->f20);
    func_02043B5C((struct CharBuf *)bmp,0);
    func_02043AF4(bmp,0,0x37,0xee,1,0xf);
    func_021C3A24(heap,p,key);
}


void ov208_func_021C36CC(u16 *heap, struct Ov208Scroll *p, int key)
{
    s16 *qd;
    struct Bmp *bmp;
    s16 x;
    s16 *qa;
    s16 n;
    bmp = func_02045770(p->desc);
    x = (s16)(((s16)(p->a + (p->b << 3)) + 0xee) % 0xf8);
    n = 0;
    qa = &p->a;
    p->a = *qa + 2;
    while (p->a >= 8) {
        func_02043AF4(bmp, (s16)(p->b << 3), 0, 8, 0x78, 0);
        p->b = (p->b + 1) % 0x1f;
        *qa = *qa - 8;
    }
    if (p->a > 0)
        func_02043AF4(bmp, (s16)(p->b << 3), 0, (u16)p->a, 0x78, 0);
    qd = &p->d;
    while (n < 2) {
        s16 end;
        s16 d;
        int w;
        d = p->c - p->d;
        end = (s16)(x + 2 - n);
        if (d <= 0)
            break;
        if (end > 0xf8)
            end = 0xf8;
        if (end - x > d)
            end = (s16)(x + d);
        w = end - x;
        func_020439A0(p->dst, bmp, p->d, 0, x, 0, w, 0x78, 0xffff);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
        *qd = *qd + n;
    }
    while (n < 2) {
        s16 end;
        int w;
        end = (s16)(x + 2 - n);
        if (end > 0xf8)
            end = 0xf8;
        w = end - x;
        func_02043AF4(bmp, x, 0x37, (u16)w, 1, 0xf);
        n = (s16)(n + (s16)w);
        x = (s16)(end % 0xf8);
    }
    ov208_func_021C3A24(heap, (u8 *)p, key);
}


void ov208_func_021C3840(u16 *heap, u8 *p, int key, u16 a, u16 b)
{
    u32 ca;
    u32 cb;
    u32 k;
    u32 i;
    u32 end;
    int lo;
    int hi;
    int v;
    s16 w;
    int t;
    *(s8 * *)&((struct Obj01010 *)p)->f34 = (s8 *)func_02006B5C(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f32 = 0;
    if (a == ((struct Obj01010 *)p)->f26 && b == ((struct Obj01010 *)p)->f28)
        return;
    ((struct Obj01010 *)p)->f26 = a;
    ((struct Obj01010 *)p)->f28 = b;
    ca = func_02006B94(((struct Obj01010 *)p)->f64);
    cb = func_02006B3C(((struct Obj01010 *)p)->f64);
    ((struct Obj01010 *)p)->f38 = (u32)(1000.0f * (32768.0f * (float)func_02006B78(((struct Obj01010 *)p)->f64)
                                           / (float)(int)ca
                                           / (float)(int)cb) + 0.5f);
    func_02043B5C((struct CharBuf *)(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C), 0);
    k = 0;
    i = 0;
    while (i < func_02006B78(((struct Obj01010 *)p)->f64)) {
        cb = func_02006B3C(((struct Obj01010 *)p)->f64);
        ca = func_02006B94(((struct Obj01010 *)p)->f64);
        end = (u32)((float)(k + 1) * ((float)(int)ca * (float)(int)cb / 32768.0f / 60.0f / 2.0f));
        if (end > func_02006B78(((struct Obj01010 *)p)->f64))
            end = func_02006B78(((struct Obj01010 *)p)->f64);
        if (k < 0x3c0) {
            lo = 500;
            hi = -500;
            for (; i < end; i++) {
                t = (*(s8 **)(p + 0x34))[i] * 0x2f * func_02006B20(((struct Obj01010 *)p)->f64) / 128;
                v = (s16)(t / 128);
                if (v > 500)
                    v = 500;
                else if (v < -500)
                    v = -500;
                w = v;
                if (w < lo)
                    lo = w;
                if (w > hi)
                    hi = w;
            }
            if (lo <= hi) {
                if (lo < -55)
                    lo = -55;
                if (hi > 0x37)
                    hi = 0x37;
                func_02043AF4(*(struct Bmp * *)&((struct Obj01010 *)p)->f2C, (s16)k, (s16)(0x37 - hi), 1, (u16)(hi - lo + 1), 0xf);
            }
        }
        k++;
        i = end + 1;
    }
    if (k > 0x3c0)
        k = 0x3c0;
    ((struct Obj01010 *)p)->f30 = k;
}

void func_021C3A24(u16 *heap,u8 *p,int key)
{
    u16 tile;
    u16 row;
    u16 index;
    u16 col;
    int base;
    tile=func_02045768(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
    index=0;
    for(row=0;row<15;row++) {
        base=tile+row*31;
        for(col=0;col<31;col++) {
            (*(u16 **)(p+0x14))[index]=(u16)(base+(col+((struct Obj06685 *)p)->f1A)%31)|0x1000;
            index++;
        }
    }
    func_02041090(3,((struct Obj06685 *)p)->f14,1,2,31,15);
    ((struct Obj06685 *)p)->f1C=1;
    func_02045334(*(struct Descriptor * *)&((struct Obj06685 *)p)->f20);
}

void func_021C3AA8(void *unused, u8 *p, int a2)
{
    u8 i;
    for(i=0;i<2;i++) {
        if(*(struct Actor **)(p+i*4+0x54))
            func_0204B688(*(struct Actor **)(p+i*4+0x54),0);
    }
    for(i=0;i<6;i++)
        func_0204B688(*(struct Actor **)(p+i*4+0x9c),0);
    func_0207D63C(0x04000050,4,0x3f,0x10,8);
    func_0207D63C(0x04001050,0,0x3f,0xc,4);
}

void func_021C3B14(void *unused, u8 *p, int a2)
{
    u8 i;
    for (i = 0; i < 2; i++) {
        if (*(struct Actor **)(p + i * 4 + 0x54))
            func_0204B688(*(struct Actor **)(p + i * 4 + 0x54), 1);
    }
    for (i = 0; i < 6; i++)
        func_0204B688(*(struct Actor **)(p + i * 4 + 0x9c), 1);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC0);
    func_021BC518(*(int * *)&((struct Obj00146 *)p)->fC4);
}

void func_021C3B68(u16 *p, u32 value)
{
    *p = value;
}
