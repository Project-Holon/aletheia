/*
 * file:     scrcmd_musical_p03.c
 * unit:     yes
 * function: func_0215DB00, func_0215DB38, func_0215DDC8, func_0215DE0C, func_0215DE38, func_0215DE44, func_0215DE58, func_0215DEF0
 * address:  0x0215DB00
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   func_0215A5F4 0x0215A5F4 thumb ov010
 *   func_0215A5DC 0x0215A5DC thumb ov010
 *   func_0215A168 0x0215A168 thumb ov010
 *   func_0215897C 0x0215897C thumb ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02156BAC  0x02156BAC  thumb  ov010
 *   func_02156BCC  0x02156BCC  thumb  ov010
 *   func_0215DF78  0x0215DF78  thumb  ov010
 *   func_0215DFB4  0x0215DFB4  thumb  ov010
 *   func_0215E010  0x0215E010  thumb  ov010
 *   func_0215E068  0x0215E068  thumb  ov010
 *   func_0215E0B0  0x0215E0B0  thumb  ov010
 *   func_0215E0EC  0x0215E0EC  thumb  ov010
 *   func_0215E130  0x0215E130  thumb  ov010
 *   func_0215E184  0x0215E184  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   func_02012124  0x02012124  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02012F80  0x02012F80  thumb
 *   func_020113D0  0x020113D0  thumb
 *   func_02014808  0x02014808  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02030734  0x02030734  arm
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021FCDEC  0x021FCDEC  thumb  ov132
 *   func_021FDA6C  0x021FDA6C  thumb  ov132
 *   d_02172914     0x02172914  data  a1
 *   d_021BB6A4     0x021BB6A4  data  ov100
 *   ov100_id       0x00000064  data
 *   func_02012F74  0x02012F74  thumb
 *   func_02034AC4  0x02034AC4  arm
 *   ov132_id       0x00000084  data
 *   ov112_id       0x00000070  data
 *   func_020307B0  0x020307B0  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021FC644  0x021FC644  thumb  ov132
 *   func_021FC684  0x021FC684  thumb
 *   func_020124E4 0x020124E4 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_02012374 0x02012374 thumb
 *   func_02012A30 0x02012A30 thumb
 *   func_02026454 0x02026454 thumb
 *   func_0203CDBC 0x0203CDBC arm
 *   func_020121CC 0x020121CC thumb
 *   func_020120B4  0x020120B4  thumb
 *   func_020120F0  0x020120F0  thumb
 *   d_02172724     0x02172724  data
 */
#include "../../matched/include/Obj12042.h"

struct Ctx;
struct BigObj;
struct IcaAnime;
struct Obj;
struct Evt;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Link {
    void *f00;          /* 0x00 */
    void *sess;         /* 0x04 */
    u32 f08;            /* 0x08 */
    void *f0c;          /* 0x0C */
    u8 pad10[0x28 - 0x10];
    u32 f28;            /* 0x28 */
    u32 f2c;            /* 0x2C */
    u16 *f30;           /* 0x30 */
    u16 f34;            /* 0x34 */
} Link;

typedef struct Wait {
    void *vm;
    Link *link;
} Wait;

typedef signed char s8;

typedef short s16;

typedef struct Work {
    u32 f00;
    u32 f04;
} Work;

typedef signed int     s32;

typedef struct { u32 f0; u32 f4; u32 f8; } Ctx_0215DE58;

typedef struct { u32 f0; } Ctx_0215DEF0;

extern u16 *func_02159AE8(void *a0, void *a1);
extern void *func_0215A5F4(void *p);
extern void *func_0215A5DC(void *a0);
extern void *func_0215A168(int a, int b, int c);
extern void func_0215897C(void *,void *);
extern void *func_0215A5E4(void *vm);
extern u16 func_02159B10(void *c, void *vm);
extern void func_02156BAC(void *p);
extern u32 func_02156BCC(void *p);
extern void func_0215DF78(int a0, int a1, int a2);
extern int func_0215DFB4(int a0, int a1);
extern int func_0215E010(void *a, void *b);
extern int func_0215E068(int a0, int a1);
extern int func_0215E0B0(int a0, int a1);
extern int func_0215E0EC(int a0, int a1);
extern int func_0215E130(void *a, void *b);
extern int func_0215E184(int a0, int a1);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012124(struct Ctx *p, u32 v);
extern u32 func_02012138(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern int func_02012F80(char *base);
extern void func_020113D0(char *p, int val);
extern void *func_02014808(char *a0, int a1, int a2, int a3, int a4, int a5, int a6);
extern u32 func_0200FB24(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_021CD48C(void *a, void *sys, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g);
extern void func_021FCDEC(int a, int b);
extern unsigned char *func_021FDA6C(void *h);
extern void func_02012F74(void *h, void *w);
extern int func_02034AC4(s32 handle);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(s32 handle);
extern void func_021FC644(int a, void *b, void *c, int d);
extern int func_021FC684(int a0);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx_0215DE58 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02026454(void *obj);
extern int func_0203CDBC(void);
extern u32 func_020121CC(struct IcaAnime *p);
extern void func_020120B4(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 func_020120F0(const struct Ctx_0215DEF0 *p);
int func_0215DB00(void *a,void *b);
int func_0215DB38(void *c, void *vm);
void func_0215DDC8(void *unused, void *h);
void func_0215DE0C(void *w, void *h);
void func_0215DE38(int a, void *b, void *c, int d);
void func_0215DE44(int a0);
int func_0215DE58(void *a, u32 *st, Ctx_0215DE58 *c);
int func_0215DEF0(void *a, u32 *st, u32 *c);
extern const char d_02172914[];
extern u8 d_021BB6A4[];
extern u8 ov100_id[];
extern u8 ov132_id[];
extern u8 ov112_id[];
extern const char d_02172724[];

int func_0215DB00(void *a,void *b)
{
 int x = (int)func_02159AE8(a,b);
 int y = (int)func_02159AE8(a,b);
 void *p = func_0215A5F4(b);
 func_0215897C(p,func_0215A168((int)func_0215A5DC(b),x,y));
 return 1;
}


/*
 * Script command: link-session control. Reads a sub-command, an argument
 * and a result slot, then opens or closes the link work (0, 1), starts the
 * ov132 session steps (10..18, most of which install a wait callback and
 * suspend the script) or reports the session state into the slot (19..21).
 *
 * Byte-correct (first draft plus ov100_id for the pooled 0x64). Evidence
 * gaps, not C: 0x021FDA6C (ov132) has no func_ label; ov100_id is passed to
 * func_02014808 (r2), which is not in the overlay_id consumer list;
 * d_021BB6A4 is another overlay's proc data (same gap as func_02155478).
 * The empty `case 100: break;` is what leaves the lone `cmp r6, #0x64`.
 *
 * 2026-10-05 (wave D9): EXACT. d_021BB6A4 (ov100 process data) resolves with the ov100 token on its symbols line.
 */
int func_0215DB38(void *c, void *vm)
{
    void *evt;
    void *proc;
    void *h;
    void *sys;
    u16 cmd;
    u16 arg;
    u16 *dst;
    int busy;
    Link *l;

    evt = func_0215A5F4(vm);
    proc = func_0215A5DC(vm);
    h = func_0215A5E4(vm);
    sys = func_0201210C(proc);
    cmd = func_02159B10(c, vm);
    arg = func_02159B10(c, vm);
    func_02159B10(c, vm);
    dst = func_02159AE8(c, vm);
    busy = 0;
    l = 0;
    if (cmd != 0 && cmd != 0x15) {
        l = (Link *)func_02012F80(h);
        if (l->f00 != 0) {
            func_02156BAC(l->f00);
            if (func_02156BCC(l->f00) == 1)
                busy = 1;
        }
    }
    switch (cmd) {
    case 0:
        func_0215DDC8(evt, h);
        break;
    case 1:
        func_0215DE0C(l, h);
        break;
    case 10:
        func_0215DE38((int)l, proc, (void *)func_02012138(proc), arg);
        break;
    case 11:
        func_0215DE44((int)l);
        func_020113D0(c, (int)func_0215E130);
        return 1;
    case 12:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 0, 1, 0);
        func_020113D0(c, (int)func_0215DFB4);
        return 1;
    case 13:
        l->f30 = dst;
        l->f08 = func_021CD48C(func_02012944(h), sys, 2, 4, 4, 1, 1, 0);
        func_020113D0(c, (int)func_0215E010);
        return 1;
    case 14:
        if (l->sess == 0 || busy != 0)
            break;
        l->f34 = arg;
        func_021FCDEC((int)l->sess, (u8)l->f34);
        func_020113D0(c, (int)func_0215E068);
        return 1;
    case 15:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, (int)func_0215E0B0);
        return 1;
    case 16:
        func_020113D0(c, (int)func_0215E0EC);
        return 1;
    case 17:
        if (l->sess == 0 || busy != 0)
            break;
        func_020113D0(c, (int)func_0215E184);
        return 1;
    case 18: {
        Wait *w = func_02030734(0x8004, 8, (u32)1, d_02172914, (u32)0x3C8);

        w->vm = vm;
        w->link = l;
        l->f30 = dst;
        l->f0c = h;
        l->f2c = (u32)func_021FDA6C(h);
        l->f28 = arg == 0 ? 9 : 10;
        func_0215897C(evt, func_02014808(proc, (int)sys, (u32)ov100_id, (int)d_021BB6A4, (int)(&l->f0c), (int)func_0215DF78, (int)w));
        return 1;
    }
    case 19:
        if (l->sess != 0 && busy == 1)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 20:
        if (l->sess != 0)
            *dst = 1;
        else
            *dst = 0;
        break;
    case 21:
        if (func_0200FB24() != 0) {
            func_02012124(proc, 1);
            *dst = 1;
        } else {
            *dst = 0;
        }
        break;
    case 100:
        break;
    }
    return 0;
}


/*
 * Allocate the 0x38-byte link work, clear its first two words, attach
 * it to the save handle and load overlays 132 and 112.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside func_02012F80)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 */
void func_0215DDC8(void *unused, void *h)
{
    Work *w = func_02030734(4, 0x38, 1, d_02172914, 0x413);

    w->f00 = 0;
    w->f04 = 0;
    func_02012F74(h, w);
    func_02034AC4((u32)ov132_id);
    func_02034AC4((u32)ov112_id);
}


/*
 * Unload overlays 112 and 132, free the link work and detach it.
 *
 * The call to arm9 0x02012F74 (the +0x6A8 setter beside func_02012F80)
 * resolves since seeds_2 labelled and matched it (src/matched/unit_02012F68.c).
 */
void func_0215DE0C(void *w, void *h)
{
    func_02034A5C((u32)ov112_id);
    func_02034A5C((u32)ov132_id);
    func_020307B0(w);
    func_02012F74(h, 0);
}


/*
 * Forwards three of its four incoming argument registers to a callee whose
 * first parameter is the constant 4. The callee takes four arguments, so a
 * tail call is impossible (bx would spend an argument register on the
 * target), which is why the image keeps a frame and emits a direct bl.
 * The listing extent is two bytes long because of the trailing alignment
 * padding.
 */
void func_0215DE38(int a, void *b, void *c, int d)
{
    func_021FC644(4, (void *)b, (void *)c, d);
}


void func_0215DE44(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12042 *)t4)->f4;
    if (a0 == 0) goto loc_0215DE56;
loc_0215DE4E:
    a0 = func_021FC684(a0);
loc_0215DE52:
a0 = 0;
((struct Obj12042 *)t4)->f4 = a0;
loc_0215DE56:
    return;}

/*
 * Padding: two zero alignment bytes after the 150-byte function.
 * Lever: context remains live in r0 across the switch for func_02012A30(p).
 */
int func_0215DE58(void *a, u32 *st, Ctx_0215DE58 *c)
{
    void *p;
    p = func_020120F4(func_020124E4(a));
    switch (*st) {
    case 0:
        func_02012374(a, (struct Evt **)c->f0);
        (*st)++;
        break;
    case 1:
        func_02012A30(p);
        func_0215DE44(c->f4);
        (*st)++;
        break;
    case 2:
        {
            void *q = (void *)func_02012138(func_020124E4(a));
            if (c->f8 != 0) {
                if (func_02026454(q) != 0)
                    break;
            }
        }
        (*st)++;
        break;
    case 3:
        if (func_0203CDBC() != 1) {
            if (c->f8 != 0)
                break;
        }
        if (c->f8 == 1) {
            func_020121CC(func_020124E4(a));
        }
        func_0215DE0C((void *)c->f4, p);
        (*st)++;
        return 1;
    }
    return 0;
}


int func_0215DEF0(void *a, u32 *st, u32 *c)
{
    void *h = func_020124E4(a);
    func_020120F4(h);
    func_0201210C(h);
    switch (*st) {
    case 0:
        (*st)++;
        break;
    case 1:
        (*st)++;
        break;
    case 2:
        (*st)++;
        break;
    case 3:
        func_020120B4(h, -1, (void *)d_02172724, (void *)(*c));
        (*st)++;
        break;
    case 4:
        if (func_020120F0(h) != 0)
            break;
        (*st)++;
        break;
    case 5:
        (*st)++;
        break;
    case 6:
        func_020307B0(((void **)*c)[1]);
        func_020307B0((void *)*c);
        return 1;
    }
    return 0;
}
