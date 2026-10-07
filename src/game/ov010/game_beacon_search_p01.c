/*
 * file:     game_beacon_search_p01.c
 * unit:     yes
 * function: func_02164B38, func_02164B6C, func_02164BC4, func_02164C04, func_02164C20, func_02164C38, func_02164C64, func_02164D6C
 * address:  0x02164B38
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
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_02164A2C 0x02164A2C thumb ov010
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012138  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_0202647C  0x0202647C  thumb
 *   func_0202648C  0x0202648C  thumb
 *   func_02164FC4  0x02164FC4  thumb ov010
 *   d_021729BC     0x021729BC  data  ov010  a1
 *   func_02030B50  0x02030B50  arm
 *   func_0203CBAC  0x0203CBAC  arm
 *   d_02171C30     0x02171C30  data  ov010  a4
 *   func_02010360 0x02010360 thumb
 *   func_020103E4 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_02012E40  0x02012E40  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_020267FC  0x020267FC  thumb
 *   func_020264AC  0x020264AC  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02158570  0x02158570  thumb  ov010
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0202640C  0x0202640C  thumb
 *   func_02164FD0  0x02164FD0  thumb  ov010
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02177BF4  0x02177BF4  thumb  ov014
 *   func_02010498  0x02010498  thumb
 *   func_0203D0FC  0x0203D0FC  arm
 *   func_02164E04  0x02164E04  thumb ov010
 *   func_02082BCC  0x02082BCC  arm
 *   func_0203CF3C  0x0203CF3C  arm
 *   func_02026A60  0x02026A60  thumb
 */
#include "../../matched/include/Obj07302.h"
#include "../../matched/include/Obj12361.h"
#include "../../matched/include/Obj12363.h"
#include "../../matched/include/Obj18982.h"
#include "../../matched/include/Obj18983.h"
#include "../../matched/include/Obj18984.h"
#include "../../matched/include/Obj09313.h"

struct Desc;
struct SeqWork2;
struct Big;
struct Ctx;
struct Obj;
struct Req;
struct Comm;
struct Rec44;
struct SaveBlock;
struct BigObj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef volatile u16 vu16;

typedef struct LinkRec {
    u8 kind;            /* 0x00 */
    u8 f01;
    u8 f02;
    u8 data[6];         /* 0x03 */
} LinkRec;

typedef struct PollWork {
    u8 pad00[0xA];
    u16 last;           /* 0x0A */
    u32 cooldown;       /* 0x0C */
    u8 pad10[0x64];
    LinkRec rec;        /* 0x74 */
} PollWork;

typedef struct Handoff12 {
    void *sys;          /* 0x00 */
    u8 data[6];         /* 0x04 */
    u8 pad[2];
} Handoff12;

typedef struct Ent {
    u8 b0;
    u8 lo : 4;
    u8 hi : 4;
    u8 flag : 1;
    u8 kind : 5;
    u8 rest : 2;
} Ent;

extern struct Desc *func_020122C0(void *,void *,void *,u32);
extern void *func_020124E8(struct Obj *p);
extern int func_02164A2C(void *,u32 *,struct SeqWork2 *);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0202647C(void *obj);
extern u32 func_0202648C(void *obj);
extern void func_02164FC4(char *p);
extern void func_02030B50(void *p);
extern void func_0203CBAC(struct Req *req, u32 a2, u32 a3);
extern u8 *func_02010360(int idx, void *heap);
extern void func_020103E4(u8 *);
extern int func_0203CEAC(int a0);
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern u8 func_02012E40(const u8 *o);
extern void func_02026400(struct Comm *p);
extern int func_02035390(void);
extern int func_020353B0(void);
extern void func_020267FC(void);
extern u32 func_020264AC(void *obj);
extern int func_02012B70(const struct BigObj *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u16 func_02012AC8(const struct Rec44 *p);
extern int func_02158570(u16 v);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void func_0202640C(struct Comm *p, u32 a, u32 b);
extern void func_02164FD0(u8 *obj, int flag);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern void func_02177BF4(u32 id);
extern void func_02010498(void);
extern void  func_0203D0FC(int a);
extern Ent  *func_02164E04(u8 *obj, int *out);
extern void  func_02082BCC(void *dst, int v, int n);
extern void *func_0203CF3C(u32 a);
extern int func_02026A60(struct Req *r);
void *func_02164B38(void *a, void *b, u8 c);
u8 *func_02164B6C(void *unused, void *arg);
int func_02164BC4(int *st, int unused, int *q);
void func_02164C04(u8 *p);
int func_02164C20(int a,int b,u8 *p);
int func_02164C38(int a,int b,u8 *p);
void func_02164C5C(u8 *p);
void func_02164C64(void *unused, void *sys, PollWork *w);
u8 *func_02164D6C(u8 *obj, int *arg);
extern const char d_021729BC[];
extern u8 d_02171C30[];

void *func_02164B38(void *a, void *b, u8 c){void *t=func_020122C0(a,0,(void *)func_02164A2C,0x1c);u8 *p=func_020124E8(t);void *v=func_020120F4(a);((struct Obj07302 *)p)->f4=v;((struct Obj07302 *)p)->f8=func_02012EBC(v);((struct Obj07302 *)p)->f0=a; p[0x18]=c;return t;}


/*
 * Allocates and initialises an 0x84-byte work record.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02164B6C(void *unused, void *arg)
{
    u32 v = (u32)func_020120F4(arg);
    void *w = (void *)func_02012138(arg);
    u8 *p = func_02030734(5, 0x84, 1, d_021729BC, 0x9c);
    ((struct Obj12361 *)p)->f0 = v;
    ((struct Obj12361 *)p)->fA = 0x1ab;
    if (func_0202647C(w) == 2 && func_0202648C(w) == 5) {
        func_02164FC4((char *)p);
    }
    return p;
}


/*
 * Two-step state machine on *st: step 0 registers a callback, step 1 polls.
 *
 * Addresses are Black-image addresses.
 */
int func_02164BC4(int *st, int unused, int *q)
{
    switch (*st) {
    case 0:
        func_02030B50((void *)12);
        func_0203CBAC((struct Req *)d_02171C30, (u32)func_02164C04, (u32)q);
        (*st)++;
        break;
    case 1:
        if (q[1] >= 1) {
            return 1;
        }
        break;
    }
    return 0;
}

void func_02164C04(u8 *p){((struct Obj12363 *)p)->f4=1; ((struct Obj12363 *)p)->f80=func_02010360(4,(void *)0x8005);}

int func_02164C20(int a,int b,u8 *p) { func_020103E4(*(u8 * *)&((struct Obj18982 *)p)->f80); func_0203CEAC((int)func_02164C5C); return 1; }

int func_02164C38(int a,int b,u8 *p) { if(((struct Obj18983 *)p)->f4==0) { func_020307B0(p); if(func_0200FB24()) func_0200FBA0(); return 1; } return 0; }

void func_02164C5C(u8 *p) { ((struct Obj18984 *)p)->f4=0; }


static inline int PAD_DetectFold(void)
{
    return (*(vu16 *)0x02FFFFA8 & 0x8000) >> 15;
}


/*
 * Per-frame poll of the wireless exchange while the field runs: stops the
 * field when a shutdown is pending, pulls the next received record
 * (func_02164D6C) and, for a new kind-2 record on an open lid with a free
 * field, starts the func_02164FD0 event with a 12-byte hand-off; any
 * other kind-2 record is dropped and its sender answered.
 *
 * MATCH (2026-09-28 tree_ov010_4): bytes exact with the kind-2 path as
 * nested ifs and a goto past the drop (the && chain puts the last-id
 * compare as `cmp r1, r0`). The one wildcard is the bl to ov011
 * 0x02177BF4, which has no label.
 *
 * 2026-10-05 (D8 lane 15): the ov011 hint on func_02177BF4 was wrong; the label is in ov014, so the symbols line now says ov014 and every relocation resolves.
 */
void func_02164C64(void *unused, void *sys, PollWork *w)
{
    void *field;
    void *p;
    u32 id;
    LinkRec *rec;
    Handoff12 *h;
    u16 v;

    field = (void *)func_02012138(sys);
    p = func_020120F4(sys);
    id = 0;
    if (func_02012E40(p) == 1)
        return;
    if (func_0200FB24()) {
        func_02026400(field);
        return;
    }
    if (func_02035390() == 1 && func_020353B0() == 1) {
        func_02026400(field);
        return;
    }
    if (w->cooldown != 0)
        w->cooldown--;
    func_020267FC();
    rec = (LinkRec *)func_02164D6C((u8 *)w, (int *)(&id));
    if (rec != 0) {
        if (rec->kind == 2) {
            if (!PAD_DetectFold() && !func_020264AC(field) && !func_02012B70(p)) {
                v = func_02012AC8(func_020127A4(p));
                if (v != w->last) {
                    w->last = v;
                    if (func_02158570(v) == 1) {
                        h = func_02030734(0x8005, sizeof(Handoff12), 1, d_021729BC, 0x154);
                        h->sys = sys;
                        MI_CpuCopy8(rec->data, h->data, 6);
                        func_0202640C(field, (u32)func_02164FD0, (u32)h);
                        goto end;
                    }
                }
            }
            MI_CpuFill8(&w->rec, 0, sizeof(LinkRec));
            func_02177BF4(id);
        } else {
            rec->kind = 0;
        }
    }
end:
    func_02010498();
}


/*
 * Per-frame poll: state 1 finishes a request; otherwise, while the 9-byte
 * record at +0x74 is empty, picks an entry with func_02164E04 and copies it in.
 *
 * Addresses are Black-image addresses.
 */
u8 *func_02164D6C(u8 *obj, int *arg)
{
    Ent *e;
    u8 *src;
    int i;
    u8 *rec = obj + 0x74;
    if (((struct Obj09313 *)obj)->f4 == 0) {
        return 0;
    }
    if (((struct Obj09313 *)obj)->f4 == 1) {
        func_0203D0FC(0);
        ((struct Obj09313 *)obj)->f4 = 2;
        return 0;
    }
    if (rec[0] == 0) {
        e = func_02164E04(obj, arg);
        if (e != 0) {
            if (e->flag != 0) {
                func_02177BF4(*arg);
            } else if (e->kind == 1) {
                i = 0;
                func_02082BCC(rec, 0, 9);
                rec[0] = e->b0;
                rec[1] = e->lo;
                rec[2] = e->hi;
                src = func_0203CF3C((u32)*arg);
                for (i = 0; i < 6; i++) {
                    rec[3 + i] = src[i];
                }
            } else if (e->kind == 2) {
                func_02026A60((struct Req *)((u8 *)e + 8));
                func_02177BF4(*arg);
            }
        }
    }
    if (rec[0] == 0) {
        rec = 0;
    }
    return rec;
}
