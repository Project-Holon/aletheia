/*
 * file:     unit_02173CB0.c
 * unit:     yes
 * function: func_02173CB0, func_02173D00, func_02173D2C, func_02173D5C, func_02173DA0, func_02173DE0, func_02173E2C, func_02173E5C, func_02173E6C, func_02173EB8, func_02173EEC, func_02173F4C, func_02173F74, func_02173F9C, func_02173FC0, func_02173FF4, func_0217403C, func_0217405C, func_0217409C, func_021740AC, func_0217410C, func_021741E8, func_02174248, func_02174258, func_02174298, func_021742A8, func_021742DC, func_021742EC, func_02174320, func_02174374, func_021743A0
 * address:  0x02173CB0
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
 *   func_02026478  0x02026478  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   func_021736D8  0x021736D8  thumb ov011
 *   func_02175648  0x02175648  thumb ov011
 *   func_020399A8  0x020399A8  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D378 0x0203D378 arm
 *   func_02175F34 0x02175F34 thumb ov011
 *   func_02175914 0x02175914 thumb ov011
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02175938  0x02175938  thumb ov011
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_020127AC  0x020127AC  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_0203D3F8  0x0203D3F8  arm
 *   func_02176048  0x02176048  thumb ov011
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_021780FC  0x021780FC  thumb ov014
 *   func_02176200  0x02176200  thumb ov011
 *   func_021761C4  0x021761C4  thumb ov011
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02175954 0x02175954 thumb ov011
 *   func_0203D578  0x0203D578  arm
 *   func_02175B34 0x02175B34 thumb ov011
 *   func_0203EFC8 0x0203EFC8 arm
 *   func_021759B0 0x021759B0 thumb ov011
 *   func_021759C0 0x021759C0 thumb ov011
 *   func_021759F8 0x021759F8 thumb ov011
 *   func_02175C88 0x02175C88 thumb ov011
 *   func_02175D20  0x02175D20  thumb ov011
 *   func_02175BAC  0x02175BAC  thumb ov011
 *   func_02175D2C  0x02175D2C  thumb ov011
 *   func_020127B8  0x020127B8  thumb
 *   func_02175DA8  0x02175DA8  thumb  ov011
 *   func_021763D8  0x021763D8  thumb  ov011
 *   func_02175E30  0x02175E30  thumb  ov011
 *   func_02176424  0x02176424  thumb  ov011
 *   func_02175D7C  0x02175D7C  thumb  ov011
 *   func_02175C04  0x02175C04  thumb ov011
 *   func_02175C58  0x02175C58  thumb ov011
 */
#include "../../matched/include/Obj19172.h"
#include "../../matched/include/Obj12417.h"

struct Big;
struct Out;
struct Entry;
struct Link;
struct SaveBlock;
struct Rec44;
typedef unsigned short u16;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct Ent {
    u16 h[8];
    u8 f10, f11, f12, pad13;
    u8 f14[0x14];
} Ent;

typedef struct { int w0; unsigned f : 4; } S;

typedef struct Rec_0 {
    u32 lo : 15;
    u32 a : 7;
    u32 b : 10;
    u8 pad04[0x28];
    u8 f2c;
    u8 pad2d[7];
} Rec_0;

typedef signed int     s32;

typedef struct Rec_0217403C { u32 w[13]; } Rec_0217403C;

struct Rec {
    u32 pad0;
    u32 lo : 4;
};

typedef struct H {
    unsigned short f : 3;
} H;

u32 func_02026478(void *obj);
void *func_02012EBC(struct Big *p);
u16 *func_0200BE48(void *sys);
int func_021736D8(void);
void func_02175648(void *sv, struct Out *o);
extern struct Entry *func_020399A8(void);
u32 func_0203D4D0(u32 entry, u32 mask, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 func_0203D378(void);
void func_02175F34(void *w, Ent *tbl, u32 arg, int idx);
void func_02175914(int a, int b);
int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
void func_02175938(u8 *p, const u16 *src, int index);
u32 func_0203D1A4(struct Link *p);
void *func_020127AC(struct SaveBlock *p, u32 idx);
void func_02082D44(void *d, void *s, int n);
u32 func_0203D3F8(u32 entry, unsigned char sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_02176048(char *a, char *b, void *c, int d);
void func_0203D1E8(u32 unused, void *arg);
void func_021780FC(u8 value);
void func_02176200(char *a);
void func_021761C4(u8 *p, u8 *s);
u32 func_0203D1C0(u32 index);
void *func_020127A4(struct SaveBlock *a);
unsigned short func_02012AC8(const struct Rec44 *a);
int func_02175954(void *unused, u8 *o, Rec_0 *src);
int func_0203D578(int a, int b);
u8 *func_02175B34(u8 *p);
s32 func_0203EFC8(const u8 *a, const u8 *b, u32 n);
void func_021759B0(u8 *a);
void func_021759C0(u8 *a, u8 b);
void func_021759F8(u8 *a, int b);
int func_02175C88(u8 *a, Rec_0217403C *b, int c);
void func_02175D20(u8 *p);
void func_02175BAC(u8 *p);
void func_02175D2C(u8 *p, int v);
extern void *func_020127B8(void *p);
extern int func_02175DA8(u8 *);
extern void func_021763D8(u8 *, u32);
extern void func_02175E30(void *, u8 *, struct Rec *);
extern int func_02176424(u8 *, u8 *, u8 *);
extern void func_02175D7C(void *, u8 *, void *);
void func_02175C04(u8 *p, int bit);
void func_02175C58(void *a, int b);
int func_02173CB0(int *a, int b);
void func_02173D00(u32 a, int b, int *c, u8 *d);
int func_02173D2C(int a0, int a1);
void func_02173D5C(int a, int b, char *c, char *d);
int func_02173DA0(int a, int b, int c);
void func_02173DE0(int a, int b, S *c, char *d);
int func_02173E2C(char *a, int b);
void func_02173E5C(int a, int b, u8 *c, u8 *p);
int func_02173E6C(int a, int b, int c);
void func_02173EB8(int a, int b, void *c, u8 *d);
int func_02173EEC(char *a, char *b);
void func_02173F4C(int a, int b, void *c, u8 *d);
int func_02173F74(int a, u8 *b);
void func_02173F9C(int a, int b, void *c, u8 *d);
int func_02173FC0(int a, u8 *b);
void func_02173FE4(int a, int b, int *c, u8 *d);
int func_02173FF4(int a, int b, int c);
void func_0217403C(int a, int b, void *c, u8 *d);
int func_0217405C(char *a, char *b);
void func_0217409C(int a, int b, int *c, u8 *p);
int func_021740AC(int a, int b, int c, ...);
void func_0217410C(int a0, int a1, u8 *b, u8 *s);
int func_021741E8(char *a, char *b);
void func_02174248(int a, int b, int c, u8 *p);
int func_02174258(char *a);
void func_02174298(int a, int b, int c, u8 *p);
int func_021742A8(int a);
void func_021742DC(int a, int b, int c, u8 *p);
u32 func_021742EC(u32 a);
void func_02174320(int a, int b, void *c, char *d);
int func_02174374(int *a);




int func_02173CB0(int *a, int b)
{
    int v;
    int buf[4];

    v = func_02026478((void *)a[1]);
    func_0200BE48(func_02012EBC((struct Big *)v));
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175648((void *)v, (struct Out *)buf);
    return func_0203D4D0((int)func_020399A8(), (unsigned char)b, 0x20D, 0x10, (u32)buf, 0, 0, 0);
}




/*
 * note: Two alignment bytes follow; existing pkt_ov011_02173D2C covers
 *       the next function's push at 02173D2C. No unit is created.
 */
void func_02173D00(u32 a, int b, int *c, u8 *d)
{
    if (func_0203D378()) {
        func_02175F34(d, (Ent *)(d + 0x1ac), a, *c);
        func_02175914((int)(d + 0x1ac), *c);
    }
}




int func_02173D2C(int a0, int a1)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x20E, 4, (u32)(&a1));
}




void func_02173D5C(int a, int b, char *c, char *d)
{
    int v;
    int t;

    v = func_02026478((void *)(((struct Obj19172 *)d)->f4));
    t = (unsigned char)c[0x24];
    func_02175938((u8 *)(d + 0x1AC), (const u16 *)c, t);
    if (t != func_0203D1A4((struct Link *)((int)func_020399A8()))) {
        func_02082D44(c, func_020127AC((struct SaveBlock *)v, t), 0x10);
    }
}




int func_02173DA0(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3F8((u32)func_020399A8(), 0xFF, 0x20F, 0x28, b + c * 0x28, 0, 0, 1);
}




void func_02173DE0(int a, int b, S *c, char *d)
{
    unsigned t;

    if (func_0203D378()) {
        if (func_02176048(d, d + 0x1AC, c, a) == 1) {
            t = c->f;
            if (t == 0 || t == 3) {
                func_0203D1E8((u32)func_020399A8(), 0);
                func_021780FC(1);
                d[0x93C] = 1;
            }
        }
    }
}



int func_02173E2C(char *a, int b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    func_02176200(a + 0x1AC);
    return func_0203D3A8(func_020399A8(), 0x210, 0x30, b);
}


void func_02173E5C(int a, int b, u8 *c, u8 *p)
{
    func_021761C4(p + 0x1ac, c);
}







int func_02173E6C(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    if (func_0203D1C0(c & 0xFF) == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), (unsigned char)c, 0x211, 0x38, b, 0, 0, 0);
}







void func_02173EB8(int a, int b, void *c, u8 *d)
{
    func_02012AC8(func_020127A4((struct SaveBlock *)func_02026478(((struct Obj12417 *)d)->f4)));
    if (func_02175954(d, d + 0x1ac, c) == 1) d[0x90d] = 1;
}







int func_02173EEC(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x212) == 1) {
        return 0;
    }
    func_02082D44(b + 0x78, a + 0x3F0, 0x34);
    return func_0203D3F8((int)func_020399A8(), 0xFF, 0x212, 0x34, (u32)(a + 0x3F0), 0, 0, 1);
}







void func_02173F4C(int a, int b, void *c, u8 *d)
{
    void *p;
    p = func_02175B34(d + 0x1ac);
    if (p != 0 && func_0203EFC8(p, c, 0x34) == 0) func_021759B0(d + 0x1ac);
}







/*
 * note: The matched void forwarder func_021736D8 leaves r0 live and this
 *       caller tests it at 02173F7C. func_0203D3A8's final send result is
 *       returned in live r0 at 02173F94, so both externs return int here.
 */
int func_02173F74(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x213, 0x34, (u32)(b + 0x78));
}






void func_02173F9C(int a, int b, void *c, u8 *d)
{
    func_02175B34(d + 0x1ac);
    if (func_0203D378()) func_021759C0(d + 0x1ac, a);
}






/*
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. func_021736D8's void forwarder
 *       leaves r0 live, tested at 02173FC8; func_0203D3A8's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 */
int func_02173FC0(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((struct Entry *)((int)func_020399A8()), 0x214, 0x34, (u32)(b + 0x78));
}






void func_02173FE4(int a, int b, int *c, u8 *d)
{
    func_021759F8(d + 0x1ac, *c);
}






int func_02173FF4(int a, int b, int c)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D4D0((int)func_020399A8(), (unsigned char)c, 0x215, 4, (u32)(&b), 0, 0, 0);
}




void func_0217403C(int a, int b, void *c, u8 *d)
{
    if (func_0203D378()) func_02175C88(d + 0x1ac, c, a);
}



int func_0217405C(char *a, char *b)
{
    int r;

    if (func_021736D8() == 0) {
        return 0;
    }
    func_02175D20((u8 *)(a + 0x1AC));
    r = func_0203D3A8(func_020399A8(), 0x216, 0x34, (u32)(b + 0x78));
    if (r == 1) {
        func_02175BAC((u8 *)(a + 0x1AC));
    }
    return r;
}


void func_0217409C(int a, int b, int *c, u8 *p)
{
    func_02175D2C(p + 0x1ac, *c);
}



/*
 * Handed as 0x021740AE; the function starts at the push {r0-r3} at 0x021740AC.
 */
int func_021740AC(int a, int b, int c, ...)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    if ((int)func_0203D1C0((unsigned char)c) == 0) {
        return 1;
    }
    return func_0203D3F8((u32)func_020399A8(), c, 0x217, 4, (u32)&b, 0, 0, 0);
}



void func_0217410C(int a0, int a1, u8 *b, u8 *s)
{
    u8 *y;
    int flag;
    void *x;
    u8 buf[2];
    int r7;
    int r6;

    x = (void *)func_02026478(*(void **)(s + 4));
    y = func_020127B8(x);
    buf[1] = 0;
    flag = 0;
    buf[0] = 0;
    r7 = 0;
    r6 = 0;
    if (b[0x2c] == 4) {
        return;
    }
    if (func_02175DA8(s + 0x1ac) == 1) {
        return;
    }
    if (b[0x28] == func_0203D1A4((struct Link *)func_020399A8())) {
        if (b[0x37] == 1) {
            func_021763D8(y, ((struct Rec *)b)->lo);
            s[0x907] = 1;
        } else {
            func_02175E30(x, s, (struct Rec *)b);
            s[0x907] = 1;
        }
        if (func_02176424(y, &buf[1], &buf[0]) == 1) {
            flag = 1;
            s[0x907] = 1;
        }
        if (b[0x2e] == 1) {
            r6 = 1;
        } else {
            r7 = 1;
        }
        if (flag == 1) {
            r6 += buf[0];
            r7 += buf[1];
        }
        s[0x354] = r7;
        s[0x355] = r6;
        s[0x356] = 1;
        s[0x93e] = 1;
    }
    func_02175D7C(s, s + 0x1ac, b);
}


int func_021741E8(char *a, char *b)
{
    if (func_021736D8() == 0) {
        return 0;
    }
    if (func_0203D578((int)func_020399A8(), 0x218) == 1) {
        return 0;
    }
    func_02082D44(b + 0xac, a + 0x424, 0x3c);
    return func_0203D3F8((int)func_020399A8(), 0xff, 0x218, 0x3c, (u32)(a + 0x424), 0, 0, 1);
}


void func_02174248(int a, int b, int c, u8 *p)
{
    func_02175C04(p + 0x1ac, a);
}


int func_02174258(char *a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    func_02175C58(a + 0x1ac, 0);
    return func_0203D3F8((u32)func_020399A8(), 0, 0x219, 0, 0, 0, 0, 0);
}


void func_02174298(int a, int b, int c, u8 *p)
{
    func_02175C58(p + 0x1ac, 1);
}


int func_021742A8(int a)
{
    if (func_021736D8() == 0) {
        return 1;
    }
    return func_0203D4D0((u32)func_020399A8(), a, 0x21a, 0, 0, 0, 0, 0);
}


void func_021742DC(int a, int b, int c, u8 *p)
{
    func_02175C58(p + 0x1ac, 2);
}



/*
 * note: func_021736D8's matched void forwarder leaves r0 live and the
 *       caller tests r0 at 021742F6; its extern returns int here.
 */
u32 func_021742EC(u32 a)
{
    if (func_021736D8() == 0) return 1;
    return func_0203D4D0((u32)func_020399A8(), a, 0x21b, 0, 0, 0, 0, 0);
}




void func_02174320(int a, int b, void *c, char *d)
{
    int p;

    p = func_02026478((void *)(((int *)d)[1]));
    if (a != func_0203D1A4((struct Link *)((int)func_020399A8())) && ((unsigned char)d[0x8fb] & (1 << a))) {
        func_02082D44(c, func_020127AC((struct SaveBlock *)p, a), 0x10);
        if (a == ((H *)(d + 0x86))->f) {
            d[0x8fb + 0xb] = 1;
        }
    }
}




int func_02174374(int *a)
{
    int r;

    r = (int)func_020127B8((void *)func_02026478((void *)a[1]));
    if (func_021736D8() == 0) {
        return 0;
    }
    return func_0203D3A8(func_020399A8(), 0x21c, 0x10, r);
}


void func_021743A0(int a, int b, void *dst, u8 *p)
{
    func_02082D44(dst, p + 0x358, 4);
}
