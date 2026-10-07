/*
 * file:     report.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFF34, func_021EFF5C, func_021EFFB4, func_021F0044, func_021F0058, func_021F009C, func_021F00BC, func_021F00F0, func_021F0108, func_021F0114, func_021F01F8, func_021F0228, func_021F0284, func_021F0700, func_021F0724, func_021F0930
 * address:  0x021EFEC0
 * region:   ov034
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0B20    0x021F0B20 data ov034 a1
 *   func_0203D34C 0x0203D34C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F09BC 0x021F09BC thumb ov034
 *   func_02030EAC 0x02030EAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0201C6B4 0x0201C6B4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012934 0x02012934 thumb
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0204B3DC 0x0204B3DC arm
 *   func_02040588 0x02040588 arm
 *   func_02045374 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_02045334 0x02045334 arm
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200723C 0x0200723C thumb
 *   _s32_div_f    0x0209C2B0 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_020456F8 0x020456F8 arm
 *   func_02045730 0x02045730 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020409B4 0x020409B4 arm
 *   d_021F0AA0 0x021F0AA0 data ov034 a4
 *   d_021F0AC0 0x021F0AC0 data ov034 a4
 *   d_021F0AE0 0x021F0AE0 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02040EBC 0x02040EBC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049238 0x02049238 arm
 *   func_0201C440 0x0201C440 thumb
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0201F02C 0x0201F02C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   func_0201F158 0x0201F158 thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C258 0x0200C258 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_020142E8 0x020142E8 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_0200D0AC 0x0200D0AC thumb
 *   func_02012FCC 0x02012FCC thumb
 *   func_0200864C 0x0200864C thumb
 *   func_02008650 0x02008650 thumb
 *   func_020071F0 0x020071F0 thumb
 *   func_020071EC 0x020071EC thumb
 *   func_02008748 0x02008748 thumb
 *   func_020086C8 0x020086C8 thumb
 *   func_020086D0 0x020086D0 thumb
 *   func_020086D8 0x020086D8 thumb
 *   func_020086E0 0x020086E0 thumb
 *   func_020086E8 0x020086E8 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045B38 0x02045B38 arm
 *   func_020457B0 0x020457B0 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045808 0x02045808 arm
 *   func_02088864 0x02088864 arm
 *   func_0208890C 0x0208890C arm
 *   func_02045C04 0x02045C04 arm
 *   d_021F0A70 0x021F0A70 data a1
 *   func_0201D83C 0x0201D83C thumb
 *   func_020452E8 0x020452E8 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0204B100 0x0204B100 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_0201BC40 0x0201BC40 thumb
 *   func_0201BCB4 0x0201BCB4 thumb
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0A60    0x021F0A60 data a2
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../../matched/include/Obj00166.h"
#include "../../matched/include/Obj20477.h"
#include "../../matched/include/Obj07644.h"
#include "../../matched/include/Obj04314.h"
#include "../../matched/include/Obj13074.h"
#include "../../matched/include/Obj13075.h"
#include "../../matched/include/Obj09806.h"
#include "../../matched/include/Obj13076.h"
#include "../../matched/include/Obj13077.h"

struct Node;
struct Ctx;
struct PrintSys;
struct BigObj;
struct Obj;
struct Cfg;
struct Descriptor;
struct Big;
struct Blk34;
struct CharBuf;
struct GfFont;
struct MsgBank;
struct PlayTime;
struct RTCDate;
struct RTCTime;
struct Rec;
struct Rec44;
struct Sub020071E4Ctrl;
struct U16Vec;
struct WordSet;
struct Blk37;
struct Bank;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char  u8;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef signed short   s16;

typedef struct {
    s16 x;
    s16 y;
    u16 c;
    u16 d;
} Rect;

typedef signed int     s32;

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0203D34C(u32 a, u32 b);
extern int func_020056A0(void *, void *, int);
extern void func_021F09BC(void *task, char *p);
extern void func_02030EAC(struct Node *n);
extern u32 func_020307B0(void *p);
extern u32 func_0201C6B4(const struct PrintSys *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012934(const struct BigObj *p);
extern unsigned int func_0201AA18(void *);
extern void func_0204B3DC(struct Obj *, unsigned int);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_02045374(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern void *func_02045770(struct Descriptor *);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
extern void func_02045334(struct Descriptor *);
extern void *func_02012EBC(struct Big *p);
extern void func_0200723C(int, void *, void *);
extern void func_020456F8(struct Descriptor *d);
extern u8 func_02045730(struct Descriptor *p);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020409B4(u32 layer);
extern void func_020403F4(u32 i);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049B68(void *, int, int, int, int, int);
extern void func_02040EBC(u32 a0, u32 a1);
extern void func_02049658(void *, int, int, int, int, int, int);
extern void func_020498F4(void *, int, int, int, int, int, int);
extern void func_02049238(void *);
extern u32 func_0201C440(void *p);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u8 *func_02012944(void *p);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_02045808(struct U16Vec *vec);
extern int func_02088864(struct RTCDate *date);
extern int func_0208890C(struct RTCTime *time);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 *func_020120F8(const struct Ctx *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern u32 func_02013E4C(u32);
extern void func_0201F158(struct WordSet *p, u32 i, u32 v);
extern void *func_02012F08(int *p);
extern u32 func_0200C258(struct Blk34 *p);
extern u32 func_0201296C(const struct BigObj *p);
extern u32 func_020142E8(void *,int);
extern void *func_0200CA1C(void *);
extern u32 func_0200D0AC(struct Blk37 *p, u32 heap);
extern int func_02012FCC(int p0);
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern int func_020071F0(struct Sub020071E4Ctrl *ctrl);
extern u8 func_020071EC(const struct Sub020071E4Ctrl *);
extern struct PlayTime *func_02008748(void *sys);
extern u32 func_020086C8(const struct PlayTime *p);
extern u32 func_020086D0(const struct PlayTime *p);
extern u32 func_020086D8(const struct PlayTime *p);
extern u32 func_020086E0(const struct PlayTime *p);
extern u32 func_020086E8(const struct PlayTime *p);
extern u32 func_0201ED04(struct WordSet *p);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_0201C4C0(struct PrintSys *p);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_0201AB28(void *list, u32 i);
extern void *func_020185F4(void *a);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_02043598(u32 mask, u32 enable);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
void *func_021EFEC0(int a0, int a1);
void func_021EFF34(char *p);
void func_021EFF5C(int *p);
void func_021EFFB4(int *p);
int func_021F0044(int *p);
void func_021F0058(char *p);
unsigned func_021F009C(char *p);
void func_021F00BC(int *p);
int func_021F00F0(char *p);
void func_021F0108(int *p);
void func_021F0114(u32 heapId);
void func_021F01F8(void);
void func_021F0228(int a);
void func_021F0284(u8 *p);
void func_021F0700(char *p);
void func_021F0724(int *p);
void func_021F0930(int *p);
extern char d_021F0B20[];
extern struct BgTemplate d_021F0AA0;
extern struct BgTemplate d_021F0AC0;
extern struct BgTemplate d_021F0AE0;
extern const u8 d_021F0A70[];
extern const Rect d_021F0A60[2];


void *func_021EFEC0(int a0, int a1)
{
    char *p = (char *)func_02030734(a1, 0x130, 0, d_021F0B20, 0x114);
    *(int *)&((struct Obj00166 *)p)->f0 = a0;
    ((struct Obj00166 *)p)->f12C = a1;
    ((struct Obj00166 *)p)->f110 = 0;
    ((struct Obj00166 *)p)->f128 = 0;
    func_021F0114(((struct Obj00166 *)p)->f12C);
    func_021F0228(((struct Obj00166 *)p)->f12C);
    func_021F0724((int *)p);
    func_021F0284((u8 *)p);
    func_0203D34C(0, a1);
    ((struct Obj00166 *)p)->f10C = func_020056A0(func_021F09BC, p, 0);
    return p;
}

void func_021EFF34(char *p) { func_02030EAC((struct Node *)(((struct Obj20477 *)p)->f10C)); func_021F0700(p); func_021F0930((int *)p); func_021F01F8(); func_020307B0(p); }


void func_021EFF5C(int *p)
{
    unsigned int i;
    void *n;

    if (!(p[0x4A] & 1) && func_0201C6B4((const struct PrintSys *)p[2]) == 1) {
        n = func_02012934(func_020120F4((const struct Ctx *)p[0]));
        for (i = 0; i < func_0201AA18(n); i++)
            func_0204B3DC((struct Obj *)p[0x15 + i], 1);
        p[0x4A] |= 1;
    }
}


/*
 * note:     `h = p[2]` must be assigned before `s` in the second loop; the
 *           other order swaps p and the second counter between r5 and r6.
 *           EXACT* for the unlabelled follower at 0x021F0044.
 */
void func_021EFFB4(int *p)
{
    unsigned int i;
    char *s;
    int h;

    if (!(p[0x4A] & 2) && func_0201C6B4((const struct PrintSys *)p[2]) == 1) {
        func_02040588(4, 1);
        func_02040588(5, 1);
        func_02040588(6, 1);
        for (i = 0; i < 8; i++)
            func_02045374((struct Cfg *)p[3 + i * 2]);
        func_02041B6C(5);
        p[0x4A] |= 2;
    }
    func_0201C4E4((struct PrintSys *)p[2]);
    for (i = 0; i < 8; i++) {
        h = p[2];
        s = (char *)p + i * 8;
        if (((struct Obj07644 *)s)->f10) {
            if (func_0201C6C4((struct PrintSys *)h, (void *)func_02045770((struct Descriptor *)((struct Obj07644 *)s)->fC)) == 0) {
                func_02045334((struct Descriptor *)((struct Obj07644 *)s)->fC);
                ((struct Obj07644 *)s)->f10 = 0;
            }
        }
    }
}

/*
 * True when the state word at +0x128 is 3.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int func_021F0044(int *p)
{
    if (p[0x4A] == 3) {
        return 1;
    }
    return 0;
}


void func_021F0058(char *p)
{
    int v;
    int r;

    r = (int)func_02012EBC(func_020120F4((const struct Ctx *)(((struct Obj04314 *)p)->f0)));
    ((struct Obj04314 *)p)->f4 = r;
    func_0200723C(r, p + 0x114, p + 0x118);
    v = (((struct Obj04314 *)p)->f114 << 9) / 10;
    ((struct Obj04314 *)p)->f120 = v;
    ((struct Obj04314 *)p)->f11C = v;
    ((struct Obj04314 *)p)->f124 = 0;
    ((struct Obj04314 *)p)->f126 = 0;
}

unsigned func_021F009C(char *p) { return ((struct Obj13074 *)p)->f114 >= ((struct Obj13074 *)p)->f118/3; }


void func_021F00BC(int *p)
{
    int h = p[0x11];
    unsigned int i;

    func_020456F8((struct Descriptor *)h);
    func_02041B6C(func_02045730((struct Descriptor *)h));
    for (i = 6; i <= 15; i++)
        func_0204B3DC((struct Obj *)p[0x15 + i], 1);
    p[0x44] = 1;
}


/*
 * When the halfword counter at +0x124 reaches 10, clears the flag at +0x110
 * (set by func_021F00BC) and returns true.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
int func_021F00F0(char *p)
{
    if (((struct Obj13075 *)p)->f124 == 10) {
        ((struct Obj13075 *)p)->f110 = 0;
        return 1;
    }
    return 0;
}

/*
 * Clears the flag at +0x110 that func_021F00BC sets.
 * Region ov034: of the ten overlays mapped here, ov034 holds a Thumb leaf at
 * this address inside the same work struct as its matched neighbours
 * func_021F0058 / func_021F00BC, and the ov021 wrapper family at
 * 0x021A1500..0x021A15F4 already resolves its other callees to ov034
 * (wave A1 witness).
 * Addresses are Black-image addresses.
 */
void func_021F0108(int *p)
{
    p[0x44] = 0;
}


void func_021F0114(u32 heapId)
{
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    {
        struct BgTemplate t = d_021F0AE0;

        func_0203FCA0(4, &t, 0);
    }
    func_020414EC(4);
    func_02040B94(4, 0x20, 0, heapId);
    func_020409B4(4);
    {
        struct BgTemplate t = d_021F0AC0;

        func_0203FCA0(5, &t, 0);
    }
    func_020414EC(5);
    func_02040B94(5, 0x20, 0, heapId);
    func_020409B4(5);
    {
        struct BgTemplate t = d_021F0AA0;

        func_0203FCA0(6, &t, 0);
    }
    func_020414EC(6);
    func_02040B94(6, 0x20, 0, heapId);
    func_020409B4(6);
}

void func_021F01F8(void) { func_02040588(6,0); func_02040588(5,0); func_02040588(4,0); func_020403F4(6); func_020403F4(5); func_020403F4(4); }


void func_021F0228(int a)
{
    void *h = func_020490F4(0xC4, a);

    func_02049B68(h, 2, 4, 0, 0x60, a);
    func_02040EBC(4, 0);
    func_02049658(h, 1, 4, 0, 0, 1, a);
    func_020498F4(h, 0, 4, 0, 0, 1, a);
    func_02049238(h);
}

static inline void print_record(u8 *p,u32 index,void *dst,void *s,u32 y,u16 color,u32 one)
{
    u32 owner=((struct Obj09806 *)p)->f8;
    func_0201C724((void *)owner,(u32)func_02045770((struct Descriptor *)*(u32 *)(p+12+index*8)),0,y,(u32)dst,(u32)(((struct Obj09806 *)p)->f4C),color);
    p[16+index*8]=one;
    func_02045808(s);
}

/*
 * lever: inline print_record binds owner before the bitmap getter; named one
 * remains live across the repeated blocks and pins their distinct spill slots.
 */
void func_021F0284(u8 *p)
{
    u32 i,one=1;
    void *bank,*ws,*dst,*ctx,*ctrl,*s0,*s1,*s2,*s3,*s4,*s5,*s6,*s7,*time,*t;
    u32 date[4],clock[3];
    ((struct Obj00166 *)p)->f8=func_0201C440((void *)(((struct Obj00166 *)p)->f12C));
    for(i=0;i<8;i++) {
        const u8 *r=d_021F0A70+i*6;
        u8 *entry=p+i*8;
        ((struct Obj13076 *)entry)->fC=func_020450F0(r[0],r[1],r[2],r[3],r[4],r[5],one);
        func_02043B5C(func_02045770((struct Descriptor *)((struct Obj13076 *)entry)->fC),0);
    }
    ((struct Obj00166 *)p)->f4C=func_0201D7EC(23,0,0,0,((struct Obj00166 *)p)->f12C);
    bank=func_02045B38(0,2,168,((struct Obj00166 *)p)->f12C);
    ws=func_0201EC64(((struct Obj00166 *)p)->f12C);
    dst=func_020457B0(256,((struct Obj00166 *)p)->f12C);
    ctx=func_020120F4(((struct Obj00166 *)p)->f0);
    ctrl=func_02012EBC(ctx);
    s0=func_02045EC0(bank,0);
    func_0201F02C(ws,0,func_02012944(ctx));
    func_0201F250(ws,dst,s0);
    print_record(p,0,dst,s0,4,0x3580,one);
    s1=func_02045EC0(bank,1);
    func_02088864((struct RTCDate *)date);
    func_0201EFA4(ws,0,date[0],2,2,one);
    func_0201EFA4(ws,one,date[1],2,0,one);
    func_0201EFA4(ws,2,date[2],2,0,one);
    func_0201F250(ws,dst,s1);
    print_record(p,1,dst,s1,0,0x3DC0,one);
    s2=func_02045EC0(bank,2);
    func_0208890C((struct RTCTime *)clock);
    func_0201EFA4(ws,0,clock[0],2,0,one);
    func_0201EFA4(ws,one,clock[1],2,2,one);
    func_0201F250(ws,dst,s2);
    print_record(p,2,dst,s2,0,0x3DC0,one);
    s3=func_02045EC0(bank,3);
    func_0201F158(ws,0,func_02013E4C(func_02012AC8((const struct Rec44 *)func_020120F8(((struct Obj00166 *)p)->f0))));
    func_0201F250(ws,dst,s3);
    print_record(p,3,dst,s3,0,0x3DC0,one);
    s4=func_02045EC0(bank,4);
    func_0201EFA4(ws,0,func_0200C258(func_02012F08(ctx)),2,0,1);
    func_0201F250(ws,dst,s4);
    print_record(p,4,dst,s4,0,0x3DC0,one);
    if(func_020142E8((void *)func_0201296C(func_020120F4(((struct Obj00166 *)p)->f0)),0x962)==1) {
        s5=func_02045EC0(bank,5);
        func_0201EFA4(ws,0,func_0200D0AC(func_0200CA1C(ctx),((struct Obj00166 *)p)->f12C),3,0,1);
        func_0201F250(ws,dst,s5);
        print_record(p,5,dst,s5,0,0x3DC0,one);
    }
    s6=func_02045EC0(bank,6);
    time=(void *)func_02012FCC((u32)ctx);
    func_0201EFA4(ws,0,func_0200864C(time),3,0,1);
    func_0201EFA4(ws,1,func_02008650(time),2,2,1);
    func_0201F250(ws,dst,s6);
    print_record(p,6,dst,s6,0,0x3DC0,one);
    if(func_020071F0(ctrl)==0 && func_020071EC(ctrl)==1) {
        t=func_02008748(ctrl);
        s7=func_02045EC0(bank,7);
        func_0201EFA4(ws,0,func_020086C8(t),2,2,1);
        func_0201EFA4(ws,1,func_020086D0(t),2,0,1);
        func_0201EFA4(ws,2,func_020086D8(t),2,0,1);
        func_0201EFA4(ws,3,func_020086E0(t),2,0,1);
        func_0201EFA4(ws,4,func_020086E8(t),2,2,1);
        func_0201F250(ws,dst,s7);
        print_record(p,7,dst,s7,4,0x3580,one);
    } else func_02045334((struct Descriptor *)((struct Obj00166 *)p)->f44);
    func_02045808(dst);
    func_0201ED04(ws);
    func_02045C04(bank);
}

void func_021F0700(char *p) { unsigned i; func_0201D83C(((struct Obj13077 *)p)->f4C); for(i=0;i<8;i++) func_020452E8(*(void **)(p+i*8+0xc)); func_0201C4C0(((struct Obj13077 *)p)->f8); }


void func_021F0724(int *p)
{
    void *list;
    unsigned int n;
    unsigned int i;
    void *h;
    u32 t;
    void *e;
    Rect r;

    list = func_02012934(func_020120F4((const struct Ctx *)p[0]));
    n = func_0201AA18(list);
    p[0x14] = (int)func_0204B100(0x10, 0, ((struct Obj00166 *)p)->f12C);
    h = func_020490F4(7, ((struct Obj00166 *)p)->f12C);
    for (i = 0; i < n; i++)
        p[0x25 + i] = func_0204A6C8(h, func_0201BA68(func_020185F4(func_0201AB28(list, i))), 0, 1,
                                    ((struct Obj00166 *)p)->f12C);
    p[0x34] = func_0204ACEC(h, func_0201BC3C(), 1, 0, ((struct Obj00166 *)p)->f12C);
    t = func_0201BC40();
    p[0x41] = func_0204AF28(h, t, func_0201BCB4(), ((struct Obj00166 *)p)->f12C);
    func_02049238(h);
    h = func_020490F4(0xC4, ((struct Obj00166 *)p)->f12C);
    p[0x2B] = func_0204A6C8(h, 3, 1, 1, ((struct Obj00166 *)p)->f12C);
    p[0x35] = func_0204AC18(h, 4, 1, 0x60, 0, 1, ((struct Obj00166 *)p)->f12C);
    p[0x42] = func_0204AF28(h, 5, 6, ((struct Obj00166 *)p)->f12C);
    func_02049238(h);
    r = d_021F0A60[0];
    for (i = 0; i < n; i++) {
        e = func_0201AB28(list, i);
        p[0x15 + i] = (int)func_0204B294((void *)p[0x14], p[0x25 + i], p[0x34], p[0x41], &r, 1,
                                    ((struct Obj00166 *)p)->f12C);
        func_0204B3DC((struct Obj *)p[0x15 + i], 0);
        r.x += 0x20;
        func_0204B6F4((struct Obj *)p[0x15 + i], func_0201BBE8(func_020185F4(e)), 1);
    }
    r = d_021F0A60[1];
    for (i = 6; i <= 15; i++) {
        p[0x15 + i] = (int)func_0204B294((void *)p[0x14], p[0x2B], p[0x35], p[0x42], &r, 1,
                                    ((struct Obj00166 *)p)->f12C);
        func_0204B3DC((struct Obj *)p[0x15 + i], 0);
        r.x += 0xC;
    }
    func_02043598(0x10, 1);
}


void func_021F0930(int *p)
{
    unsigned int i;
    void *n;

    n = func_02012934(func_020120F4((const struct Ctx *)p[0]));
    for (i = 0; i < func_0201AA18(n); i++) {
        func_0204B3B4((struct Obj *)p[0x15 + i]);
        func_0204A8D4(p[0x25 + i]);
    }
    for (i = 6; i <= 15; i++)
        func_0204B3B4((struct Obj *)p[0x15 + i]);
    func_0204A8D4(p[0x2B]);
    func_0204ADA4(p[0x34]);
    func_0204ADA4(p[0x35]);
    func_0204AFD8(p[0x41]);
    func_0204AFD8(p[0x42]);
    func_0204B1CC((struct Bank *)p[0x14]);
    func_02043598(0x10, 0);
}
