/*
 * file:     field_msgbg_p07.c
 * unit:     yes
 * function: func_0218B2A8, func_0218B2E8, func_0218B310, func_0218B32C, func_0218B3DC, func_0218B408, func_0218B4B0, func_0218B53C, func_0218B56C, func_0218B630, func_0218B6AC, func_0218B6F8, func_0218B754, func_0218B7F8, func_0218B83C
 * address:  0x0218B2A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb
 *   func_02014134  0x02014134  thumb
 *   func_02012878  0x02012878  thumb
 *   func_021625CC  0x021625CC  thumb  ov010
 *   func_021626B0  0x021626B0  thumb  ov010
 *   func_02185360  0x02185360  thumb  ov020
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0219E418  0x0219E418  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3098  0x021A3098  thumb
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D5E0  0x0216D5E0  thumb  ov010
 *   func_021A2F98  0x021A2F98  thumb
 *   func_021ACBB8  0x021ACBB8  thumb
 *   func_021A2F48  0x021A2F48  thumb
 *   func_021A2F60  0x021A2F60  thumb  ov021
 *   func_02197E7C  0x02197E7C  thumb
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_021A2FD0  0x021A2FD0  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021A35A0  0x021A35A0  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188C98  0x02188C98  thumb
 *   func_021A2FA4  0x021A2FA4  thumb
 *   func_021A3364  0x021A3364  thumb
 *   func_021AB0D4  0x021AB0D4  thumb
 *   func_021AB0F8  0x021AB0F8  thumb
 *   func_021AB0F0  0x021AB0F0  thumb
 *   func_021AB2E8  0x021AB2E8  thumb
 *   func_02164208  0x02164208  thumb  ov010
 *   func_021A3460  0x021A3460  thumb
 *   func_02164294  0x02164294  thumb  ov010
 *   func_021AB194  0x021AB194  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_02164240  0x02164240  thumb  ov010
 *   func_02188C7C  0x02188C7C  thumb
 *   func_0216D8AC  0x0216D8AC  thumb  ov010
 *   func_0216DDDC  0x0216DDDC  thumb  ov010
 *   func_0219E634  0x0219E634  thumb  ov021
 *   func_0219E570  0x0219E570  thumb  ov021
 *   func_02012B70  0x02012B70  thumb
 *   func_021A30C8  0x021A30C8  thumb
 *   func_021A3128  0x021A3128  thumb
 *   func_02013E04  0x02013E04  thumb
 *   func_021A3504  0x021A3504  thumb
 *   func_021A3524  0x021A3524  thumb
 *   data_021D3CE8  0x021D3CE8  data
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021641E8  0x021641E8  thumb  ov010
 *   func_021641F8  0x021641F8  thumb  ov010
 *   func_0216DDC0  0x0216DDC0  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   d_021DD9CC     0x021DD9CC  data  ov021  a4
 *   func_0218BCE4  0x0218BCE4  thumb
 *   func_0218C490  0x0218C490  thumb
 *   func_0218C860  0x0218C860  thumb
 *   func_0218BE84  0x0218BE84  thumb
 *   func_0218BD94  0x0218BD94  thumb
 *   func_0218BB64  0x0218BB64  thumb
 *   func_0218BC6C  0x0218BC6C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0218BCF4  0x0218BCF4  thumb
 *   func_0218C124  0x0218C124  thumb
 */
#include "../../matched/include/Obj04982.h"
#include "../../matched/include/Obj19510.h"
#include "../../matched/include/Obj05974.h"
#include "../../matched/include/Obj07410.h"
#include "../../matched/include/Obj19511.h"
#include "../../matched/include/Obj02071.h"
#include "../../matched/include/Obj12562.h"

struct BigObj;
struct Rec1C;
struct Obj00020;
struct Desc;
struct Obj;
struct Ctx;
typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned char  u8;

typedef unsigned int   u32;

typedef struct {
    int f0;
    short f4;
    short f6;
    int f8;
    int fC;
} Ent;

struct FieldCtx_0218B4B0 {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x20];
    u32 b0 : 1;
    u32 b1 : 1;
    u32 b2 : 1;
    u32 b3 : 1;
};

typedef signed int     s32;

struct FieldCtx_0218B56C {
    u16 f0;
    u16 pad02;
    void *f4;
    void *f8;
    void *fC;
    u16 f10;
    char pad12[0x06];
    void *f18;
    char pad1C[0x08];
    u16 f24;
};

struct TileMsg {
    int (*test)(u16 attr);
    u16 dir;
    u16 msg;
};

extern u16 func_02188C9C(u8 *p);
extern void func_02014134(u8 *p, u16 b, int c, u16 d, u16 e, u16 f, u16 g, s16 h);
extern void func_02012878(struct BigObj *p, const struct Rec1C *src);
extern void *func_021625CC(char *p, unsigned i);
extern u16 func_021626B0(void *b, void *q);
extern void *func_02185360(void *p, int u, int a, int b);
void *func_021A3074(unsigned char *p);
int func_0219E418(u32 a, u32 b);
extern void *func_02188CB4(struct Obj00020 *p);
extern u32 func_021A3098(u8 *p);
extern void *func_0216D67C(void *o);
extern void func_0216D9A0(void *o);
extern void func_0216D5E0(int a0, int a1);
extern u32 func_021A2F98(u8 *p);
extern void func_021ACBB8(u32 a, u8 v);
extern void func_021A2F48(u8 *p, u32 a1);
extern void func_021A2F60(int *p);
extern int func_02197E7C(int a, int b);
extern void func_0216D410(void *o, int a);
extern int func_0216D454(void *o);
extern int func_021A2FD0(void *a);
extern u32 *func_0216D9E4(void *c);
extern void func_021A35A0(u32 *p, int a);
struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
void *func_020124E8(struct Obj *p);
extern u32 func_02188C98(u8 *p);
extern u16 func_021A2FA4(u8 *p, u32 a1);
extern void func_021A3364(u32 *a, int b, int *out);
extern int func_021AB0D4(void *a, void *b);
extern u16 func_021AB0F8(u32 attr);
extern u16 func_021AB0F0(u32 attr);
extern int func_021AB2E8(int a);
extern void func_02164208(int a, int *b, int c);
extern int func_021A3460(u32 a, u32 b, u32 c, u32 d);
extern void func_02164294(int x, int y, int z, int *out);
extern int func_021AB194(u16 id);
extern u16 func_0216D5F8(void *p);
extern void func_02164240(int dir, s16 *x, s16 *z, s16 amt);
extern void *func_02188C7C(u8 *p);
extern u32 func_0216D8AC(void *p);
extern u8 *func_0216DDDC(u32 a, u32 b, u32 c, s32 x, s32 lim, u32 d);
int func_0219E634(void *a, int *buf);
u32 func_0219E570(u32 o, u32 k, u32 flag);
extern int func_02012B70(const struct BigObj *p);
extern u32 func_021A30C8(void **ctx);
extern u32 func_021A3128(u32 *a, u32 b);
extern u32 func_02013E04(u32 id);
extern int func_021A3504(u8 *a, int b, int c);
extern int func_021A3524(u8 *a, int b, int c);
extern void *func_02012934(const struct BigObj *p);
extern u32 func_0201AA18(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void *func_020120F4(const struct Ctx *p);
extern int func_0216D83C(void *o);
extern int func_0216D86C(void *o);
extern int func_021641E8(u16 d);
extern int func_021641F8(u16 d);
extern void *func_0216DDC0(u32 a, u32 b, u32 c, u32 d);
extern void *func_02030734(unsigned int, unsigned int, int, const char *, u16);
extern void func_0218BCE4(u32 *p, u8 v);
extern void func_0218C490(char *p, char *q);
extern void func_0218C860(void *p);
extern void func_0218BE84(u8 *s, u8 *e);
extern void func_0218BD94(u8 *s);
extern int func_0218BB64(char *a);
extern void func_0218BC6C(unsigned char *p);
extern u32 func_020307B0(void *p);
extern void func_0218BCF4(char *p);
extern void func_0218C124(char *p, char *q);
void func_0218B2A8(char *p, int s, u16 *v);
int func_0218B2E8(char *p, void *x, int a, int *b);
int func_0218B310(void *a, unsigned char *s);
int func_0218B32C(void *unused, int *st, char *ctx);
int func_0218B3DC(int unused, int a, int b, int c, int d);
int func_0218B408(char *p, void *a, void *x);
int func_0218B4B0(struct FieldCtx_0218B4B0 *p, u8 *pos);
int func_0218B53C(unsigned char *p, void *b);
u16 func_0218B56C(struct FieldCtx_0218B56C *p, u8 *pos);
int func_0218B630(void *sys, u32 move);
int func_0218B6AC(void *ctx);
int func_0218B6F8(char *p, void *q);
char *func_0218B754(int a, int b, u16 c);
void func_0218B7F8(char *p);
void func_0218B83C(char *p);
extern const struct TileMsg data_021D3CE8[13];
extern int d_021DD9CC;


/*
 * Addresses are Black-image addresses.
 */
void func_0218B2A8(char *p, int s, u16 *v)
{
    int buf[7];

    func_02014134((u8 *)buf, func_02188C9C(((struct Obj04982 *)p)->f14), (s16)s, 0, 0, v[0], v[3], (s16)v[2]);
    func_02012878(((struct Obj04982 *)p)->f8, (const struct Rec1C *)buf);
}


int func_0218B2E8(char *p, void *x, int a, int *b)
{
    void *obj = func_021625CC(((struct Obj04982 *)p)->fC, (u16)a);
    return (int)func_02185360(((struct Obj04982 *)p)->f4, (int)x, (int)obj, func_021626B0(obj, b));
}


int func_0218B310(void *a, unsigned char *s)
{
    if ((func_0219E418((u32)func_021A3074(a), ((struct Obj19510 *)s)->f24) & 3) == 0)
        return 1;
    return 0;
}


int func_0218B32C(void *unused, int *st, char *ctx)
{
    void *a = func_02188CB4(((struct Obj05974 *)ctx)->fC);
    void *o;
    int r1;

    func_021A3098(a);
    o = func_021A3074(a);
    switch (*st) {
    case 0:
        func_0216D9A0(func_0216D67C(o));
        func_0216D5E0((int)o, ((struct Obj05974 *)ctx)->f4);
        *st = *st + 1;
        break;
    case 1:
        func_021ACBB8((u32)func_021A2F98(a), 0);
        func_021A2F48(a, 1);
        func_021A2F60(a);
        r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x34);
        if (((struct Obj05974 *)ctx)->f6 == 1)
            r1 = func_02197E7C(((struct Obj05974 *)ctx)->f4, 0x38);
        func_0216D410(o, r1);
        *st = *st + 1;
        break;
    case 2:
        if (func_0216D454(o) == 1) {
            func_021A2FD0(a);
            *st = *st + 1;
        }
        break;
    case 3:
        func_0216D9E4(func_0216D67C(o));
        func_021A35A0(a, 1);
        return 1;
    }
    return 0;
}


int func_0218B3DC(int unused, int a, int b, int c, int d)
{
    int h = (int)func_020122C0((void *)a, 0, func_0218B32C, 0x10);
    Ent *e = func_020124E8((struct Obj *)h);
    e->f8 = a;
    e->fC = b;
    e->f4 = c;
    e->f6 = d;
    return h;
}


int func_0218B408(char *p, void *a, void *x)
{
    void *cam;
    int r7;
    int t;
    int flag;
    int t2;
    void *id;
    int v;
    int buf[3];

    id = func_02188CB4(x);
    if (func_021A3098(id) == 2) {
        cam = (void *)func_02188C98(x);
        r7 = func_021A2FA4((u8 *)(*(int *)&((struct Obj07410 *)p)->f18), ((struct Obj07410 *)p)->f2C);
        if (r7 != 9) {
            func_021A3364(id, r7, buf);
            t = func_021AB0D4(cam, buf);
            v = func_021AB0F8(t);
            t2 = func_021AB0F0(t);
            flag = 0;
            if (func_021AB2E8(t2) == 1) {
                func_02164208(r7, buf, 0x10000);
                v = func_021AB0F8(func_021AB0D4(cam, buf));
                flag = 1;
            }
            if (func_0218B6F8(p, x) == 1 && !(v & 1) && !(v & 2))
                return func_0218B3DC((int)p, (int)a, (int)x, r7, flag);
        }
    }
    return 0;
}


/*
 * Reads the object's grid position, and when the tile attribute in front
 * allows it (func_021AB194) steps it one tile in its facing direction, then
 * moves the camera object there (func_0216DDDC).
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * Addresses are Black-image addresses.
 */
int func_0218B4B0(struct FieldCtx_0218B4B0 *p, u8 *pos)
{
    void *obj = func_021A3074(p->f18);
    s16 v[3];
    int xyz[3];
    void *cam;

    func_021A3460((u32)p->f18, (u32)(&v[2]), (u32)(&v[1]), (u32)(&v[0]));
    func_02164294(v[2], v[1], v[0], xyz);
    if (func_021AB194(func_021AB0F0(func_021AB0D4((void *)func_02188C98(pos), xyz))) == 1)
        func_02164240(func_0216D5F8(obj), &v[2], &v[0], 1);
    cam = func_02188C7C(pos);
    return (int)func_0216DDDC((u32)cam, v[2], v[0], func_0216D8AC(obj), 0x10000, 0);
}


int func_0218B53C(unsigned char *p, void *b)
{
    int buf[2];
    if (func_0219E634(func_021A3074(((struct Obj19511 *)p)->f18), buf) != 0)
        return func_0219E570((u32)func_02188C7C(b), (u32)buf, 0);
    return 0;
}


/*
 * Picks the message for the tile the player faces: the first of the 13 table
 * entries at 0x021D3CE8 whose direction matches and whose attribute test
 * passes, else the water prompts 0x2712 (when a party member knows Surf) or
 * 0x2716; 0xFFFF for none.
 *
 * Addresses are Black-image addresses.
 */
u16 func_0218B56C(struct FieldCtx_0218B56C *p, u8 *pos)
{
    u32 here;
    u32 ahead;
    u16 attr;
    u32 i;

    if (func_02012B70(p->f8) == 1)
        return 0xFFFF;
    here = func_021A30C8(p->f18);
    ahead = func_021A3128(p->f18, p->f24);
    attr = func_021AB0F0(ahead);
    for (i = 0; i < 13; i++) {
        if ((p->f24 == data_021D3CE8[i].dir || data_021D3CE8[i].dir == 9) && data_021D3CE8[i].test(attr))
            return data_021D3CE8[i].msg;
    }
    if (!func_02013E04(p->f10) || func_02012B70(p->f8) == 1)
        return 0xFFFF;
    if (func_021A3504((u8 *)p->f18, here, ahead) && func_0218B630(p->f8, 0x39) != 6)
        return 0x2712;
    if (func_021A3524((u8 *)p->f18, (u32)here, (u32)ahead))
        return 0x2716;
    return 0xFFFF;
}


/*
 * Returns the index of the first non-egg party member that knows the given
 * move (checks move slots 0x36..0x39), or 6 when none does. Called with 0x39
 * (Surf).
 *
 * Addresses are Black-image addresses.
 */
int func_0218B630(void *sys, u32 move)
{
    int n;
    void *party;
    int i;

    party = func_02012934(sys);
    n = func_0201AA18(party);

    for (i = 0; i < n; i++) {
        void *mon = func_0201AB28(party, i);

        if (func_02017E1C(mon, 0x4C, 0) == 0) {
            if (move == func_02017E1C(mon, 0x36, 0) || move == func_02017E1C(mon, 0x37, 0)
                || move == func_02017E1C(mon, 0x38, 0) || move == func_02017E1C(mon, 0x39, 0))
                return i;
        }
    }
    return 6;
}


int func_0218B6AC(void *ctx)
{
    void *list;
    void *e;
    int n;
    int i;
    int cnt;

    list = func_02012934(func_020120F4(ctx));
    n = func_0201AA18(list);
    i = 0;
    cnt = 0;
    for (; i < n; i++) {
        e = func_0201AB28(list, i);
        if (func_02017E1C(e, 0x4C, 0) == 0 && func_02017E1C(e, 0xA0, 0) != 0)
            cnt++;
    }
    return cnt;
}


int func_0218B6F8(char *p, void *q)
{
    void *o = func_021A3074(((struct Obj07410 *)p)->f18);
    u16 d = ((struct Obj07410 *)p)->f30;
    int x = func_0216D83C(o);
    int z = func_0216D86C(o);
    int i;

    for (i = 0; i < 2; i++) {
        x = (s16)(x + func_021641E8(d));
        z = (s16)(z + func_021641F8(d));
        if (func_0216DDC0((u32)func_02188C7C(q), x, z, 1))
            return 0;
    }
    return 1;
}


/*
 * Allocates and initialises a 0x13F8-byte object.
 *
 * Addresses are Black-image addresses.
 */
char *func_0218B754(int a, int b, u16 c)
{
    char *p;
    int i;
    unsigned j;
    int z = 0;

    p = (char *)func_02030734(a, 0x13F8, 0, (const char *)&d_021DD9CC, 0x193);
    ((struct Obj02071 *)p)->f0 = a;
    ((struct Obj02071 *)p)->f4 = b;
    func_0218BCE4((u32 *)(p + 8), c);
    for (i = 0; i < 7; i++)
        *(int *)(p + 0x1DC + i * 4) = z;
    for (j = 0; j < 0x120; j++)
        func_0218C490(p, p + 0x1F8 + j * 16);
    ((struct Obj02071 *)p)->f1B0 = 0;
    ((struct Obj02071 *)p)->f1B4 = 0;
    ((struct Obj02071 *)p)->f1B8 = 0;
    ((struct Obj02071 *)p)->f1BC = 0;
    ((struct Obj02071 *)p)->f1C0 = 0;
    ((struct Obj02071 *)p)->f1C4 = 0;
    ((struct Obj02071 *)p)->f1C8 = 0;
    ((struct Obj02071 *)p)->f1CC = 0;
    ((struct Obj02071 *)p)->f1D4 = 0;
    ((struct Obj02071 *)p)->f1D8 = 0;
    return p;
}


void func_0218B7F8(char *p)
{
    int i;

    for (i = 0; i < 7; i++) {
        if (*(void **)(p + 0x1DC + i * 4) != 0)
            func_0218C860(*(void **)(p + 0x1DC + i * 4));
    }
    func_0218BE84((u8 *)p, (u8 *)(p + 0x1B0));
    func_0218BD94((u8 *)p);
    func_0218BB64(p);
    func_0218BC6C((unsigned char *)p);
    func_020307B0(p);
}


void func_0218B83C(char *p)
{
    int i;
    unsigned u;

    func_0218BCF4(p + 8);
    for (i = 0; i < 7; i++) {
        char *q = *(char **)(p + 0x1DC + i * 4);
        if (q != 0)
            func_0218C124(p, q + 0xC);
    }
    for (u = 0; u < ((struct Obj12562 *)p)->f1D4; u++)
        func_0218C124(p, *(char * *)&((struct Obj12562 *)p)->f1D8 + u * 0x18);
}
