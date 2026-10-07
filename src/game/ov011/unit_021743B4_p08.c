/*
 * file:     unit_021743B4_p08.c
 * unit:     yes
 * function: func_0217537C, func_0217538C, func_021753B8, func_021753D0, func_0217544C, func_0217545C, func_0217546C, func_021754B4, func_021754E8, func_02175508, func_02175514, func_0217553C, func_02175548, func_02175598, func_02175628, func_02175648, func_021756A4, func_021756B0, func_021756D0, func_021756F0, func_02175710, func_0217574C, func_0217576C, func_021757A8, func_021757C4, func_02175894, func_021758B4, func_021758C8, func_02175914, func_02175920, func_0217592C, func_02175938, func_02175954, func_021759B0, func_021759C0, func_021759F8, func_02175A24, func_02175A34, func_02175AE8, func_02175B14, func_02175B34, func_02175B4C, func_02175B8C, func_02175BAC, func_02175BBC, func_02175BCC, func_02175BE4
 * address:  0x0217537C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_020120D8  0x020120D8  thumb
 *   func_02008530  0x02008530  thumb
 *   func_02008550  0x02008550  thumb
 *   tbl_02176A90   0x02176A90  data  ov011  a2
 *   tbl_02176A98   0x02176A98  data  ov011  a2
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203D1B4 0x0203D1B4 arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_0200BF70  0x0200BF70  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012FCC  0x02012FCC  thumb
 *   func_0200BFA4  0x0200BFA4  thumb
 *   func_0200BF94  0x0200BF94  thumb
 *   func_0200BF54  0x0200BF54  thumb
 *   d_02176B08 0x02176B08 data ov011 a2
 *   tbl_02176AD0 0x02176AD0 data ov011 a2
 *   func_020120F4  0x020120F4  thumb
 *   func_02012B8C  0x02012B8C  thumb
 *   func_02161FEC  0x02161FEC  thumb  ov010
 *   func_02175EE8 0x02175EE8 thumb ov011
 *   func_0203D378  0x0203D378  arm
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175D34  0x02175D34  thumb  ov011
 *   func_02176158  0x02176158  thumb  ov011
 *   func_02176194  0x02176194  thumb  ov011
 *   func_0203F4FC 0x0203F4FC arm
 *   func_02173DA0  0x02173DA0  thumb  ov011
 *   func_02173EEC  0x02173EEC  thumb  ov011
 *   func_021741E8  0x021741E8  thumb  ov011
 *   func_02173F74  0x02173F74  thumb  ov011
 *   func_021742EC  0x021742EC  thumb  ov011
 *   func_021742A8  0x021742A8  thumb  ov011
 *   func_02173FF4 0x02173FF4 thumb ov011
 *   func_02175DA8 0x02175DA8 thumb ov011
 */
#include "../../matched/include/Obj03548.h"
#include "../../matched/include/Obj00566.h"
#include "../../matched/include/Obj07331.h"
#include "../../matched/include/Obj07332.h"
#include "../../matched/include/Obj00269.h"
#include "../../matched/include/Obj19190.h"
#include "../../matched/include/Obj19191.h"
#include "../../matched/include/Obj00567.h"
#include "../../matched/include/Obj12430.h"
#include "../../matched/include/Obj12431.h"
#include "../../matched/include/Obj19193.h"
#include "../../matched/include/Obj09352.h"

struct Sub0200852CObj;
struct Big;
struct BigObj;
struct Rec1B0;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct F86 {
    u16 lo : 9;
    u16 x : 6;
    u16 hi : 1;
} F86;

typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags_0217545C;

typedef struct { u8 low : 4; u8 flag : 1; u8 high : 3; } Flags_021754B4;

typedef unsigned long long u64;

typedef struct Out {
    u32 f00;
    u64 f04;
    u8  f0c[2];
    u8  f0e;
} Out;

typedef struct Flags_021756F0 {
    u8 lo : 6;
    u8 f  : 1;
    u8 hi : 1;
} Flags_021756F0;

typedef struct Lo3 {
    u16 v  : 3;
    u16 hi : 13;
} Lo3;

typedef struct Flags_02175710 {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags_02175710;

typedef struct {
    u8 pad0[0xA8];
    u16 hA8;
    u16 hAA;
    u8 padAC[0xD8 - 0xAC];
    u8 bD8;
    u8 padD9[0xE3 - 0xD9];
    u8 bE3;
    u8 padE4[0x19C - 0xE4];
    u8 b19C;
    u8 pad19D[0x1A5 - 0x19D];
    u8 f0 : 1;
    u8 f1 : 1;
    u8 f2 : 1;
    u8 f3 : 1;
    u8 f4 : 1;
    u8 f5 : 3;
} Work;

typedef struct {
    u32 w0;
    u32 w4;
} Ctx;

typedef struct Flags_021758C8 {
    u8 a  : 1;
    u8 f  : 1;
    u8 hi : 6;
} Flags_021758C8;

typedef struct Rec {
    u32 lo : 15;
    u32 a  : 7;
    u32 b  : 10;
    u8  pad04[0x28];
    u8  f2c;
    u8  pad2d[7];
} Rec;

typedef struct {
    u8 pad0[0x190];
    u32 stamp;
    u8 pad194[9];
    u8 active;
    u8 pending;
} State;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Flags_02175A24;

typedef struct Fl {
    u8 lo : 2;
    u8 x  : 1;
    u8 y  : 1;
    u8 hi : 4;
} Fl;

typedef struct { u8 a:2; u8 bit:1; u8 rest:5; } Flags_02175B8C;

typedef struct { u8 a : 3; u8 b : 1; u8 c : 4; } Fb;

extern void MI_CpuFill8(void *, u8, u32);
int func_020120D8(char *a);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 func_0200FB24(void);
extern int func_0203D1B4(void);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern u32 func_0200BF70(struct Rec1B0 *p);
extern int func_02012B70(const struct BigObj *p);
extern int func_02012FCC(int p0);
extern unsigned long long func_0200BFA4(u8 *p, void *q, u32 mode);
extern unsigned long long func_0200BF94(struct Rec1B0 *p);
extern void func_0200BF54(struct Rec1B0 *p, u8 *dest, u32 n);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02012B8C(struct BigObj *p, u32 v);
extern void func_02161FEC(char *p, u16 v);
extern void func_02175EE8(u8 *);
extern u32 func_0203D378(void);
extern u32 func_02026478(void *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_02175D34(Ctx *c, Work *w, int a);
extern void func_02176158(int a, u8 *p);
extern void func_02176194(Ctx *c, Work *w);
extern u32 func_0203F4FC(void);
extern int func_02173DA0(int a, int b, int c);
extern int func_02173EEC(char *a, char *b);
extern int func_021741E8(char *a, char *b);
extern int func_02173F74(int a, u8 *b);
extern u32 func_021742EC(u32 a);
extern int func_021742A8(int a);
extern int func_02173FF4(int a, int b, int c);
extern int func_02175DA8(u8 *p);
unsigned char *func_0217537C(unsigned char *p);
void func_0217538C(u8 *p, int a);
void func_021753B8(u8 *p);
int func_021753D0(u8 *p, int i, u8 v);
void func_0217544C(u8 *p);
void func_0217545C(u8 *p);
void func_0217546C(u8 *p);
int func_021754B4(u8 *p, int *out);
void func_021754E8(u8 *p, int a, int b, int c);
void func_02175508(int a, int b, int c);
int func_02175514(u8 *p);
void func_0217553C(u8 *p);
void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3);
u16 func_02175598(u8 *o, u32 id);
int func_02175628(void);
void func_02175648(void *sv, Out *o);
u8 func_021756A4(char *p);
int func_021756B0(int value);
int func_021756D0(u32 x);
void func_021756F0(u8 *o, u32 v);
void func_02175710(u8 *o, u32 v);
void func_0217574C(u8 *o, u32 v);
void func_0217576C(u8 *p);
void func_021757A8(u8 *p);
void func_021757C4(Ctx *c, Work *w);
int func_02175894(u8 *p);
int func_021758B4(u8 *p);
int func_021758C8(u8 *o);
void func_02175914(int a, int b);
void func_02175920(int a);
void func_0217592C(int a);
void func_02175938(u8 *p, const u16 *src, int index);
int func_02175954(void *unused, u8 *o, Rec *src);
void func_021759B0(u8 *p);
void func_021759C0(State *p, u8 index);
void func_021759F8(u8 *p, int n);
int func_02175A24(u8 *p);
void func_02175A34(void *a, u8 *b);
void func_02175AE8(int ctx, u8 *p);
int func_02175B14(u8 *p);
u8 *func_02175B34(u8 *p);
void func_02175B4C(u8 *a, u8 *b);
int func_02175B8C(u8 *p);
void func_02175BAC(u8 *p);
int func_02175BBC(u8 *p);
u8 *func_02175BCC(u8 *p);
int func_02175BE4(void *a);
void func_02175C04(u8 *o, u32 bit);
extern u16 tbl_02176A90[];
extern u16 tbl_02176A98[];
extern const u16 d_02176B08[];
extern u16 tbl_02176AD0[];

/*
 * Unlabelled Thumb leaf, the follower of func_02175368 (same +0x15C field):
 * returns the field's address when its first byte is 1, else null.
 * Labelled so that func_02175368's extent ends at its own pool.
 *
 * Addresses are Black-image addresses.
 */
unsigned char *func_0217537C(unsigned char *p)
{
    if (p[0x15C] == 1) {
        return p + 0x15C;
    }
    return 0;
}

/*
 * extent: two zero alignment bytes at 0x021753B6 precede the owned 021753B8 function.
 */
void func_0217538C(u8 *p, int a)
{
    MI_CpuFill8(p + 0x154, 0, 8);
    p[0x154] = a;
    p[0x155] = 4;
    p[0x158] = 0;
    func_021753B8(p);
}

void func_021753B8(u8 *p)
{
    p[0x944]++;
    p[0x159] = p[0x944];
}


int func_021753D0(u8 *p, int i, u8 v)
{
    if (!(p[0x8FB] & (1 << i))) {
        (p + i)[0x945] = v;
        return 0;
    }
    if (((F86 *)(p + 0x86))->x == 0) {
        if (p[0x154] == 4 && p[0x158] == 0 && func_020120D8((char *)((struct Obj03548 *)p)->f0) == 0) {
            p[0x154] = i;
            p[0x156] = 1;
            p[0x158] = v;
            p[0x159] = v;
            func_0217544C(p);
            return 1;
        }
        (p + i)[0x945] = v;
    } else {
        (p + i)[0x945] = v;
    }
    return 0;
}

void func_0217544C(u8 *p) { p[0x8F8] |= 0x10; }

/*
 * lever: bitfield clear emits bics; byte mask emits ands with 0xEF.
 */
void func_0217545C(u8 *p) { ((Flags_0217545C *)(p + 0x8F8))->flag = 0; }


void func_0217546C(u8 *p)
{
    u8 buf[4];
    u8 *q;
    int i;

    if (func_021754B4(p, (int *)buf) == 1 && func_020120D8((char *)((struct Obj00566 *)p)->f0) == 1) {
        q = p + 0x945;
        i = p[0x154];
        if (q[i] == 0) {
            q[i] = p[0x158];
        }
        func_0217538C(p, 4);
        func_0217545C(p);
    }
}

int func_021754B4(u8 *p, int *out)
{
    int value;
    if (p == 0 || ((struct Obj07331 *)p)->f8 == 0) return 0;
    value = p[0x154];
    if (value != 4 && ((Flags_021754B4 *)(p + 0x8F8))->flag == 1) {
        *out = value;
        return 1;
    }
    return 0;
}

void func_021754E8(u8 *p, int a, int b, int c)
{
    if (p[0x154] == a && p[0x158] == c) {
        p[0x155] = a;
        p[0x157] = b;
    }
}


void func_02175508(int a, int b, int c)
{
    func_021754E8((u8 *)a, b, 3, c);
}


/*
 * note:     unlabelled leaf (push {r3,r4}, no lr); callers func_0218123C and
 *           func_02181584 in ov018. Its follower 0x0217553C is also an
 *           unlabelled leaf.
 */
int func_02175514(u8 *p)
{
    int r;

    if (p[0x155] != 4) {
        r = p[0x157];
        if (r != 0) {
            p[0x157] = 0;
            return r;
        }
    }
    return 0;
}


/*
 * Unlabelled leaf (no lr save): clears the byte at +0x157.
 */
void func_0217553C(u8 *p)
{
    p[0x157] = 0;
}


void func_02175548(u32 a, u16 *p1, u8 *p2, u8 *p3)
{
    u32 x;
    u32 i;
    int r;

    x = func_02008530((const struct Sub0200852CObj *)a);
    r = func_02008550((const struct Sub0200852CObj *)a);
    i = ((x >> 16) + (u16)x) & 3;
    if (r == 0) {
        *p1 = tbl_02176A90[i];
        *p2 = 3;
        *p3 = 0;
    } else {
        *p1 = tbl_02176A98[i];
        *p2 = 4;
        *p3 = 1;
    }
}


u16 func_02175598(u8 *o, u32 id)
{
    struct { u8 x; u8 y; u16 c; } s;
    u16 h;

    h = ((struct Obj07332 *)o)->f18;
    if (h == 0) {
        if (o[0x12] == 1) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 2 : 5;
        } else {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 1 : 4;
        }
    } else if (h == 0xFFFF) {
        func_02175548(id, &s.c, &s.y, &s.x);
    } else {
        s.c = h;
        if (func_021756B0(s.c) == 0) {
            s.c = (func_02008550((const struct Sub0200852CObj *)id) == 0) ? 10 : 14;
        }
    }
    if ((s.c >= 0xdf && s.c < 0x1000) || s.c >= 0x1236) {
        s.c = 10;
    }
    return s.c;
}

/*
 * extent: two zero alignment bytes at 0x02175646 precede existing 02175648 code.
 */
int func_02175628(void)
{
    if (func_0200FB24() != 0) return 0;
    if (func_0203D1B4() > 1) return 1;
    return 0;
}


void func_02175648(void *sv, Out *o)
{
    void *q;

    q = func_0200BE48(func_02012EBC(sv));
    MI_CpuFill8(o, 0, 0x10);
    o->f00 = func_0200BF70(q);
    if (func_02012B70(sv) == 1) {
        o->f04 = func_0200BFA4(q, (void *)func_02012FCC((int)sv), 2);
    } else {
        o->f04 = func_0200BF94(q);
    }
    func_0200BF54(q, o->f0c, 2);
    o->f0e = 1;
}


u8 func_021756A4(char *p)
{
    return p[0x35a];
}

/*
 * A ternary loop condition keeps the unrotated entry branch.
 */
int func_021756B0(int value)
{
    unsigned int i;
    for (i = 0; (i < 162) ? 1 : 0; i++) if (value == d_02176B08[i]) return 1;
    return 0;
}

/*
 * The 32-byte follower at 021756F0 already has its own matched shard.
 * A ternary loop condition preserves the branch to the bottom test.
 */
int func_021756D0(u32 x)
{
    u32 i;
    for (i = 0; (i < 0x1c) ? 1 : 0; i++) {
        if (x == tbl_02176AD0[i]) {
            return 1;
        }
    }
    return 0;
}


/*
 * Unlabelled leaf: sets bit 6 of the byte at +0x93f from the low bit of v.
 */
void func_021756F0(u8 *o, u32 v)
{
    ((Flags_021756F0 *)(o + 0x93f))->f = (u8)v;
}


/*
 * func_0217574C is an unlabelled leaf (bit 1 of the byte at +0x904).
 */
void func_02175710(u8 *o, u32 v)
{
    void *p;

    p = func_020120F4(((struct Obj00269 *)o)->f0);
    ((Lo3 *)(o + 0x86))->v = v;
    func_02012B8C(p, v);
    func_02161FEC((char *)(o + 0x35c), (u8)v);
}


void func_0217574C(u8 *o, u32 v)
{
    ((Flags_02175710 *)(o + 0x904))->f = (u8)v;
}

void func_0217576C(u8 *p)
{
    int i;
    MI_CpuFill8(p, 0, 0x1A8);
    p[0xA4] = 4;
    func_02175EE8(p + 0x90);
    p[0xD8] = 4;
    for (i = 0; i < 3; i++) p[0xE0 + i] = 4;
    func_021757A8(p);
}

/*
 * extent: two zero alignment bytes at 0x021757C2 precede existing 021757C4 code.
 */
void func_021757A8(u8 *p)
{
    int i;
    for (i = 0; i < 3; i++) p[i * 0x28 + 0x10] = 0;
}


void func_021757C4(Ctx *c, Work *w)
{
    int x;

    if (func_0203D378() == 1 && func_02175B14((u8 *)w) == 1) {
        if (w->bD8 == 4) {
            if (w->hA8 != 0) {
                if (w->b19C == 0 && func_02175894((u8 *)w) > w->hA8) {
                    w->b19C = 1;
                }
            } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
                x = func_02026478((void *)c->w4);
                if (w->bE3 == 0) {
                    func_02175D34(c, w, func_02012B58((const struct BigObj *)x));
                }
            }
        } else if (w->f1 == 1 && func_02175894((u8 *)w) > w->hAA) {
            w->f4 = 1;
        }
    }
    func_02176158((int)c, (u8 *)w);
    func_02176194(c, w);
    func_02175A34(c, (u8 *)w);
    func_02175AE8((int)c, (u8 *)w);
}

int func_02175894(u8 *p)
{
    u32 now = func_0203F4FC();
    u32 stamp = ((struct Obj19190 *)p)->f190;
    if (now < stamp) now += 86400;
    return now - stamp;
}

int func_021758B4(u8 *p)
{
    int limit = ((struct Obj19191 *)p)->fAA;
    int n = limit - func_02175894(p);
    if (n < 0) n = 0;
    return n;
}


int func_021758C8(u8 *o)
{
    int h;
    int v;

    if (func_02175B14(o) == 1 && o[0xd8] == 4) {
        h = ((struct Obj00567 *)o)->fA8;
        if (h != 0 || ((Flags_021758C8 *)(o + 0x1a5))->f == 0) {
            v = h - func_02175894(o);
        } else {
            v = func_021758B4(o);
        }
        if (v < 0) {
            return 0;
        }
        return v;
    }
    return 0;
}


/*
 * Three one-byte flag setters at fixed offsets.
 */
void func_02175914(int a, int b)
{
    *(unsigned char *)(a + b + 0x194) = 1;
}


void func_02175920(int a)
{
    ((struct Obj12430 *)a)->f19A = 1;
}


void func_0217592C(int a)
{
    ((struct Obj12431 *)a)->f19B = 1;
}

void func_02175938(u8 *p, const u16 *src, int index)
{
    u16 *dst = (u16 *)(p + index * 40);
    unsigned n;
    if (*((u8 *)dst + 16) != 1) {
        n = 20;
        do { *dst++ = *src++; } while (--n);
    }
}


int func_02175954(void *unused, u8 *o, Rec *src)
{
    Rec *dst;
    int r;

    dst = (Rec *)(o + 0x78);
    r = 0;
    if (src->a > 0x14 || src->b > 0xb4) {
        return 0;
    }
    if (o[0x1a1] == 0 && src->f2c != 4) {
        r = 1;
        o[0x1a1] = r;
    }
    if (dst->f2c != 4) {
        return r;
    }
    *dst = *src;
    return r;
}

void func_021759B0(u8 *p)
{
    u8 *q = func_02175B34(p);
    if (q != 0) ((struct Obj19193 *)q)->f30 = 0;
}

static inline void SetBits(State *p, u8 bit)
{
    p->active |= bit;
    p->pending |= bit;
}

/*
 * lever: u8 mask conversion through SetBits inline preserves the original
 * field load before the truncation finishes; open-coded byte locals differ.
 */
void func_021759C0(State *p, u8 index)
{
    if (p->active == 0) p->stamp = func_0203F4FC();
    SetBits(p, 1 << index);
}

/*
 * extent: follower 0x02175A24 already filed separately.
 */
void func_021759F8(u8 *p, int n)
{
    p[0x1A5] |= 2;
    ((struct Obj09352 *)p)->fAA = n;
    if (func_0203D378() == 0) ((struct Obj09352 *)p)->f190 = func_0203F4FC();
}


/*
 * Unlabelled leaf (sole blocker of ov018 func_0217C4D0): bit 1 of the
 * flag byte at +0x1A5.
 */
int func_02175A24(u8 *p)
{
    return ((Flags_02175A24 *)(p + 0x1A5))->b1;
}


void func_02175A34(void *a, u8 *b)
{
    int i;

    for (i = 0; i < 3; i++) {
        if (b[0x194 + i] == 1 && func_02173DA0((int)a, (int)b, i) == 1) {
            b[0x194 + i] = 0;
        }
    }
    if (b[0x19a] == 1 && func_02173EEC(a, (char *)b) == 1) {
        b[0x19a] = 0;
    }
    if (b[0x19b] == 1 && func_021741E8(a, (char *)b) == 1) {
        b[0x19b] = 0;
    }
    if (b[0x19c] == 1 && func_02173F74((int)a, b) == 1) {
        b[0x19c] = 2;
    }
    if (b[0x19f] != 0 && func_021742EC(b[0x19f]) == 1) {
        b[0x19f] = 0;
    }
    if (b[0x1a0] != 0 && func_021742A8(b[0x1a0]) == 1) {
        b[0x1a0] = 0;
    }
}

/*
 * prototype: func_02173FF4 trailing input omitted: full matched body neither
 * reads nor forwards d; original caller supplies no r3 value.
 */
void func_02175AE8(int ctx, u8 *p)
{
    u8 mask = p[0x19E];
    if (mask != 0) {
        if (func_02173FF4(ctx, func_021758B4(p), mask) == 1) p[0x19E] = 0;
    }
}

int func_02175B14(u8 *p)
{
    if (p[0xA4] == 4 || p[0x1A1] == 0) return 0;
    return 1;
}

/*
 * extent: two zero alignment bytes follow the compiled return.
 */
u8 *func_02175B34(u8 *p)
{
    if (func_02175B14(p) == 0) p = 0;
    else p += 0x78;
    return p;
}


void func_02175B4C(u8 *a, u8 *b)
{
    if (func_02175B14(b) == 1) {
        ((Fl *)(b + 0x1a5))->x = 1;
        ((Fl *)(b + 0x1a5))->y = 0;
        a[0x8a] |= 0x20;
        a[0x900] = 1;
    }
}

int func_02175B8C(u8 *p)
{
    if (func_02175B14(p) == 1) return ((Flags_02175B8C *)(p + 0x1A5))->bit;
    return 0;
}

/*
 * extent: follower 0x02175BBC already filed separately.
 */
void func_02175BAC(u8 *p)
{
    p[0x1A5] |= 8;
}


/*
 * Unlabelled leaf (no lr save, prints as .word data in the listing),
 * filed as the sole blocker of ov018 func_0217BDE0: bit 3 of the byte
 * at +0x1A5.
 */
int func_02175BBC(u8 *p)
{
    return ((Fb *)(p + 0x1A5))->b;
}

u8 *func_02175BCC(u8 *p)
{
    if (func_02175DA8(p) == 0) p = 0;
    else p += 0xAC;
    return p;
}


/*
 * func_02175C04 is an unlabelled leaf (sets one bit in a byte at +0x19f or +0x1a0).
 */
int func_02175BE4(void *a)
{
    if (func_02175B8C(a) == 1 || func_02175BCC(a) != 0) {
        return 1;
    }
    return 0;
}


void func_02175C04(u8 *o, u32 bit)
{
    if (o[0xe0] == 4) {
        o[0x19f] |= (u8)(1 << bit);
    } else {
        o[0x1a0] |= (u8)(1 << bit);
    }
}
