/*
 * file:     unit_02184D30_p09.c
 * unit:     yes
 * function: func_021864A8, func_021864C4, func_0218654C, func_02186558, func_02186564, func_021865B4, func_02186660, func_02186694, func_021866C4
 * address:  0x021864A8
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02035C08 0x02035C08 arm
 *   d_02186AAC 0x02186AAC data a4
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02040588  0x02040588  arm
 *   func_02027F60  0x02027F60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02027778  0x02027778  thumb
 *   d_02186ABC     0x02186ABC  data
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_02184180  0x02184180  thumb  ov022
 *   func_02039338  0x02039338  arm
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 */
#include "../../matched/include/Obj13027.h"
#include "../../matched/include/Obj20368.h"
#include "../../matched/include/Obj02742.h"
#include "../../matched/include/Obj03625.h"

struct MsgBank;
struct R;
struct TaskMenu;
struct TaskMenuTmpl;
struct Obj;
struct TaskMenuState;
struct U16Vec;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef struct {
    u16 n;
    u16 a;
    u16 b;
    u16 pad;
} Ent_021864C4;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Rec;

typedef unsigned int u32;

typedef struct {
    u32 a;
    u8  b;
    u32 c;
    u32 d;
    u8  e[4];
} Arg;

typedef struct {
    u32 a;
    u32 b;
} Ent_021865B4;

extern int func_02035C08(const void *p);
int func_021841A4(unsigned char *p);
unsigned char func_021841A0(unsigned char *p);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(struct Obj *);
extern u32 func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern char *func_02184180(unsigned char *p, int i);
extern u16 func_02039338(void);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
int func_021864A8(char *p);
void func_021864C4(Rec *d, Ent_021864C4 *s, int a, int c);
int func_0218654C(char *p);
int func_02186558(char *p);
void func_02186564(void);
int func_021865B4(char *p);
int func_02186660(char *p);
void func_02186694(char *p);
void func_021866C4(u32 *p);
extern char d_02186AAC[];
extern Ent_021865B4 d_02186ABC[];

int func_021864A8(char *p)
{
    if (func_02035C08(d_02186AAC) != -1)
        return 1;
    return 0;
}


void func_021864C4(Rec *d, Ent_021864C4 *s, int a, int c)
{
    int i;
    Ent_021864C4 *e;

    if (s[0].n != 0) {
        d->b[0] = s[0].a;
        d->b[2] = s[0].b;
        e = &s[s[0].n - 1];
        d->b[1] = e->a;
        d->b[3] = e->b;
        for (i = 0; i < 2; i++) {
            if (d->b[i] + d->b[i + 2] == 0) {
                s[0].n = 0;
            }
        }
    }
    if (s[0].n >= 2) {
        d->mid = 2;
    } else {
        d->mid = s[0].n;
    }
    d->lo = a;
    d->hi = c;
}


/*
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_0218654C(char *p)
{
    return func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj13027 *)p)->f4));
}


/*
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186558(char *p)
{
    return func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20368 *)p)->f4));
}


void func_02186564(void)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 = *(volatile u16 *)0x04000304 & 0xFFFF7FFF;
}


int func_021865B4(char *p)
{
    int i;
    int r;
    char *e;
    Ent_021865B4 *t;
    Arg s;

    ((struct Obj02742 *)p)->f174 = (u32)func_02027F60(0, 2, ((struct Obj02742 *)p)->fC, ((struct Obj02742 *)p)->f168, 0x28);
    for (i = 0; i < 2; i++) {
        t = &d_02186ABC[i];
        *(u32 *)(p + i * 12 + 0x17C) = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02742 *)p)->f14), d_02186ABC[i].a);
        *(u16 *)(p + i * 12 + 0x180) = 0x39E3;
        *(u32 *)(p + i * 12 + 0x184) = t->b;
    }
    s.a = 0x28;
    s.b = 2;
    s.c = (u32)(p + 0x17C);
    s.d = 0;
    s.e[0] = 0x15;
    s.e[1] = 7;
    s.e[2] = 10;
    s.e[3] = 3;
    r = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj02742 *)p)->f174));
    ((struct Obj02742 *)p)->f9E70 = 1;
    return r;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing r preserves call/store scheduling.
 */
int func_02186660(char *p)
{
    int r = 2;
    func_02027974(*(struct Obj * *)&((struct Obj03625 *)p)->f178);
    if (func_020279E8(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178) != 0) {
        u8 v = func_02027A04(*(const u8 * *)&((struct Obj03625 *)p)->f178);
        r = 0;
        if (v != 0) r = 1;
        func_02186694(p);
    }
    return r;
}

/*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 */
void func_02186694(char *p)
{
    func_02027858(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178);
    func_02045808(((struct Obj03625 *)p)->f188);
    func_02045808(((struct Obj03625 *)p)->f17C);
    func_02027FD8(*(struct TaskMenuState * *)&((struct Obj03625 *)p)->f174);
    *(int *)&((struct Obj03625 *)p)->f178 = 0;
}


void func_021866C4(u32 *p)
{
    int i;
    u32 h;
    u32 r;

    h = (u32)func_0200ED48(func_02012EBC((struct Big *)(*(u32 *)(p[1] + 4))));
    for (i = 0; i < 5; i++) {
        r = (u32)func_02184180((unsigned char *)(*(u32 *)p[1]), (u8)i);
        if (r != 0) {
            if (i != func_02039338()) {
                func_0200ED54((struct L0200ED54 *)h, func_02008530((const struct Sub0200852CObj *)r));
            }
        }
    }
}
