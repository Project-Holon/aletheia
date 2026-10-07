/*
 * file:     worldtrade_adapter_p42.c
 * unit:     yes
 * function: func_02202094, func_022020B8, func_022020E0, func_022020F8, func_02202148, func_022021A4, func_022021C0, func_022021F8, func_022022B8, func_022023A4, func_0220246C, func_022024B0, func_022024DC, func_0220251C, func_0220252C, func_0220254C, func_022025E4, func_02202608
 * address:  0x02202094
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_020120F4 0x020120F4 thumb
 *   func_02012DD0 0x02012DD0 thumb
 *   func_021F4EC0 0x021F4EC0 thumb ov135
 *   func_021F90A0 0x021F90A0 thumb ov135
 *   func_021F4E98 0x021F4E98 thumb ov135
 *   func_0207D55C 0x0207D55C arm
 *   func_0202208C 0x0202208C thumb
 *   func_02202840  0x02202840  thumb  ov135
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_02007A18 0x02007A18 thumb
 *   func_022026A0 0x022026A0 thumb ov135
 *   func_0200ADB8 0x0200ADB8 thumb
 *   func_02007664 0x02007664 thumb
 *   func_020307B0 0x020307B0 arm
 *   func_0201AB28 0x0201AB28 thumb
 *   func_0201A9C8 0x0201A9C8 thumb
 *   func_02012F98 0x02012F98 thumb
 *   func_02012934 0x02012934 thumb
 *   func_02007C34 0x02007C34 thumb
 *   func_0200AD94 0x0200AD94 thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02017F50  0x02017F50  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_022026BC  0x022026BC  thumb
 *   func_0200752C  0x0200752C  thumb
 *   DWC_GetDateTime  0x02167ED8  arm  ov009
 *   func_0200ADD8  0x0200ADD8  thumb
 *   func_0200ADD0  0x0200ADD0  thumb
 *   func_0200949C 0x0200949C thumb
 *   func_020094D8 0x020094D8 thumb
 *   func_021F6DE8  0x021F6DE8  thumb
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02019B58  0x02019B58  thumb
 *   func_02045A90  0x02045A90  arm
 *   func_0202136C  0x0202136C  thumb
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02045808  0x02045808  arm
 *   g_02203F5C  0x02203F5C  data  ov135
 */
#include "../../matched/include/Obj09249.h"
#include "../../matched/include/Obj09250.h"
#include "../../matched/include/Obj12245.h"
#include "../../matched/include/Obj00018.h"
#include "../../matched/include/Obj23459.h"
#include "../../matched/include/Obj14178.h"
#include "../../matched/include/Obj12246.h"
#include "../../matched/include/Obj14179.h"
#include "../../matched/include/Obj01260.h"
#include "../../matched/include/Obj23460.h"
#include "../../matched/include/Obj23461.h"
#include "../../matched/include/Obj23462.h"
#include "../../matched/include/Obj23463.h"
#include "../../matched/include/Obj23464.h"
#include "../../matched/include/Obj23465.h"
#include "../../matched/include/Obj23466.h"
#include "../../matched/include/Obj23467.h"
#include "../../matched/include/Obj02864.h"
#include "../../matched/include/Obj23476.h"
#include "../../matched/include/Obj23477.h"
#include "../../matched/include/Obj23478.h"
#include "../../matched/include/Obj23479.h"
#include "../../matched/include/Obj23480.h"
#include "../../matched/include/Obj23481.h"
#include "../../matched/include/Obj12247.h"

struct Ctx;
struct BigObj;
struct Party;
struct PerapVoice;
struct Rec0200AD94;
struct Sub020079BCEntry;
struct Sub02007AC8Entry;
struct Blk37;
struct PartyMon;
struct Sub02007454Entry;
struct RegB;
struct Sub02009470Obj;
struct Rec0200AD8C;
struct MsgBank;
struct Rec;
struct Sub02008F80Obj;
struct U16Vec;
struct Mon;
struct WordSet;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int s32;

typedef signed char s8;

typedef signed short s16;

typedef struct {
    void *sys;
    u8 pad4[4];
    void *party;
    u32 box;
    void *dex;
} Ctx_022022B8;

typedef struct {
    Ctx_022022B8 *ctx;
    u8 pad4[0xDC - 4];
    u32 boxId;
    u32 pos;
} Work_022022B8;

typedef struct {
    int year;
    int month;
    int day;
    int week;
} RTCDate;

typedef struct {
    int hour;
    int minute;
    int second;
} RTCTime;

typedef struct {
    u8 pad0[8];
    void *party;
} Ctx_022024DC;

typedef struct {
    Ctx_022024DC *ctx;
    u8 pad4[0xEB0 - 4];
    u16 species;
} Work_022024DC;

extern void *func_020120F4(const struct Ctx *p);
extern int func_02012DD0(u8 *p);
extern void func_021F4FC4(u8 *p);
extern int func_02012DAC(int a0);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_021F90A0(u32 a, u32 b, u32 c, u32 d, u16 e);
extern void func_021F4E98(u8 *p, u32 a, u32 b);
extern int func_0207D55C(volatile u16 *reg);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern u32 func_02202840(u8 *p);
extern int func_02035C60(void);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_022026A0(u8 *p, u32 k);
extern void func_0200ADB8(void *dest, const void *src, u32 a2);
extern void func_02007664(void *, unsigned, unsigned);
extern u32 func_020307B0(void *p);
extern void *func_0201AB28(void *, unsigned);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern struct Sub02007AC8Entry *func_02012F98(void *p);
extern void *func_02012934(const struct BigObj *p);
extern void func_02007C34(struct PerapVoice *p, void *a);
extern void func_0200AD94(struct Rec0200AD94 *p, u16 v);
extern u32 func_02017E1C(void *mon, u32 id, u32 v);
extern void func_0200CDE0(struct Blk37 *p, void *m);
extern u32 func_0201AA18(void *p);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u8 func_02017F50(u32 species, u16 form, u32 pid);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern u32 func_022026BC(void *mon);
extern int func_0200752C(void **save, u32 box, const struct Sub02007454Entry *src);
extern int DWC_GetDateTime(RTCDate *date, RTCTime *time);
extern void func_0200ADD8(struct RegB *p, u32 value);
extern void func_0200ADD0(struct RegB *p, u32 value);
extern u32 func_0200949C(const struct Sub02009470Obj *obj, int row, int col);
extern void func_020094D8(struct Sub02009470Obj *obj, int row, int col, int value);
extern int func_021F6DE8(u32 handle);
extern u16 func_0200AD8C(const struct Rec0200AD8C *p);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 func_02045C04(struct Rec *rec);
extern void func_02019B58(void *mon);
extern u16 *func_02045A90(struct U16Vec *vec);
extern u32 func_0202136C(u16 v);
extern void *func_02008F08(int a0);
extern void func_02008F88(struct Sub02008F80Obj *obj, const void *src);
extern void func_02045808(struct U16Vec *vec);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void func_0201EEF4(struct WordSet *p, u32 i, void *mon);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
int func_02202094(u8 *p);
int func_022020B8(u8 *p);
int func_022020E0(u8 *p);
int func_022020F8(u8 *p);
int func_02202148(u8 *p);
int func_022021A4(u8 *p);
int func_022021C0(u8 *p);
void func_022021F8(u8 *p, int flag);
void func_022022B8(Work_022022B8 *p, void *mon, u32 box, int hatch);
void func_022023A4(u8 *p,void *mon,void *unused2,void *unused3,u32 index);
void func_0220246C(void *p, int which);
void func_022024B0(void *obj,u8 *p);
int func_022024DC(Work_022024DC *p, void *mon);
void func_0220251C(u8 *p, u16 a, u16 b);
u32 func_0220252C(u8 *p);
void func_0220254C(void *mon, u32 heap);
void func_022025E4(u32 a, u32 b, u32 c);
void *func_02202608(u32 heap);
extern const char g_02203F5C[];


/*
 * When the mode query answers 1, publish the u16 at +0xe0c.
 */
int func_02202094(u8 *p)
{
    if (func_02012DD0(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09249 *)p)->f0 + 0x40)))) == 1) {
        ((struct Obj09249 *)p)->f28 = ((struct Obj09249 *)p)->fE0C;
    }
    return 2;
}


/*
 * When the mode query answers 2, publish the u16 at +0xe0e and hand the object back.
 */
int func_022020B8(u8 *p)
{
    if (func_02012DD0(func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj09250 *)p)->f0 + 0x40)))) == 2) {
        ((struct Obj09250 *)p)->f28 = ((struct Obj09250 *)p)->fE0E;
        func_021F4FC4(p);
    }
    return 2;
}


/*
 * Run the sub-object init, stamp 0x27 and report 2.
 */
int func_022020E0(u8 *p)
{
    func_02012DAC((int)func_020120F4((const struct Ctx *)(*(u32 *)(((struct Obj12245 *)p)->f0 + 0x40))));
    ((struct Obj12245 *)p)->f28 = 0x27;
    return 2;
}

int func_022020F8(u8 *p)
{
    if (func_02012DD0(func_020120F4(((struct Obj23459 *)(*(u8 * *)&((struct Obj00018 *)p)->f0))->f40)) == 2) {
        func_021F4EC0(p, 1, 0);
        func_021F4FC4(p);
        func_021F90A0((u32)p, (u32)(((struct Obj00018 *)p)->fB6C), ((struct Obj00018 *)p)->f24, 1, 0xF0F);
        func_021F4E98(p, 0x2A, 0x20);
    }
    return 2;
}

/*
 * lever: nested if with equal sentinel arm first preserves the branch hop.
 */
int func_02202148(u8 *p)
{
    func_021F4FC4(p);
    if (((struct Obj14178 *)p)->fEB4 == 1) {
        if (func_0207D55C((u16 *)0x0400106C) == -16)
            func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
        else
            func_0202208C(0, 0, 0, 0, 6, 1, 0x48);
    } else {
        func_0202208C((void *)3, 0, 0, 0, 6, 1, 0x48);
    }
    ((struct Obj14178 *)p)->f28 = 0;
    return 3;
}


/*
 * When the sub-object at +0xfa0 is idle, re-arm the state word from +0x2c.
 */
int func_022021A4(u8 *p)
{
    if (func_02202840(p + 0xfa0) == 0) {
        ((struct Obj12246 *)p)->f28 = ((struct Obj12246 *)p)->f2C;
    }
    return 2;
}

int func_022021C0(u8 *p) { if((func_02202840(p+0xfa0)==0 && (func_020362DC()&1)) || func_02035C60()) { func_020061E4(0x547); ((struct Obj14179 *)p)->f28=((struct Obj14179 *)p)->f2C; } return 2; }

/*
 * tail: 022022B6..022022B8 zero alignment padding.
 */
void func_022021F8(u8 *p, int flag)
{
    void *mon;
    void *save;
    void *box;
    if (((struct Obj01260 *)p)->fC4 != 0xFF) {
        mon = func_02202608(0x48);
        func_022026A0((u8 *)func_02007A18(((struct Obj23460 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6), (u32)mon);
        if (flag) func_0200ADB8(((struct Obj23461 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_02007664(((struct Obj23462 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->fC, ((struct Obj01260 *)p)->fC4, ((struct Obj01260 *)p)->fC6);
        func_020307B0(mon);
    } else {
        mon = func_0201AB28(((struct Obj23463 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        if (flag) func_0200ADB8(((struct Obj23464 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, mon, ((struct Obj01260 *)p)->fC4);
        func_0201A9C8(((struct Obj23465 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f8, ((struct Obj01260 *)p)->fC6);
        save = func_020120F4(((struct Obj23466 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f40);
        box = func_02012F98(save);
        func_02007C34(box, func_02012934(save));
    }
    if (flag) func_0200AD94(((struct Obj23467 *)(*(u8 * *)&((struct Obj01260 *)p)->f0))->f0, 1);
}


void func_022022B8(Work_022022B8 *p, void *mon, u32 box, int hatch)
{
    u32 pos;
    u32 species;
    u32 form;
    u32 slot;

    func_02017E1C(mon, 6, 0);
    func_0200CDE0(p->ctx->dex, mon);
    box = 0xFF;
    if (func_0201AA18(p->ctx->party) == 6) {
        box = 0;
    }
    if (hatch != 0) {
        func_02017E40(mon, 9, 0x46);
        species = func_02017E1C(mon, 5, 0);
        form = func_02017E1C(mon, 0x6F, 0);
        func_02017E40(mon, 0x6E, func_02017F50((u16)species, form, func_02017E1C(mon, 0, 0)));
        func_0220246C(p->ctx->sys, 0);
    }
    if (box == 0xFF) {
        func_0201A98C(p->ctx->party, mon);
        slot = func_0201AA18(p->ctx->party);
        p->boxId = 0xFF;
        slot -= 1;
    } else {
        pos = 0;
        func_020076D0((void *)p->ctx->box, (int *)(&box), (int *)(&pos));
        func_0200752C((void **)p->ctx->box, box, (const struct Sub02007454Entry *)func_022026BC(mon));
        p->boxId = box;
        slot = pos;
    }
    p->pos = slot;
    func_0200AD94(p->ctx->sys, 0);
}

/*
 * evidence: func_0200CDE0 receives the entry r1 Pokemon pointer; fifth parameter is reassigned in its incoming stack slot.
 */
void func_022023A4(u8 *p,void *mon,void *unused2,void *unused3,u32 index)
{
    u32 species, form, pos;
    func_0200CDE0(*(struct Blk37 * *)&((struct Obj23476 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f10,mon);
    index=0xFF;
    if(func_0201AA18(((struct Obj23477 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8)==6) index=0;
    func_02017E40(mon,9,0x46);
    species=func_02017E1C(mon,5,0);
    form=func_02017E1C(mon,0x6F,0);
    func_02017E40(mon,0x6E,func_02017F50((u16)species,form,func_02017E1C(mon,0,0)));
    if(index==0xFF) {
        func_0201A98C(*(struct Party * *)&((struct Obj23478 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8,(const struct PartyMon *)mon);
        pos=func_0201AA18(((struct Obj23479 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->f8);
        ((struct Obj02864 *)p)->fDC=0xFF;
        pos--;
    } else {
        u32 slot=0;
        func_020076D0(((struct Obj23480 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,(int *)(&index),(int *)(&slot));
        func_0200752C(((struct Obj23481 *)(*(u8 * *)&((struct Obj02864 *)p)->f0))->fC,index,(const struct Sub02007454Entry *)func_022026BC(mon));
        ((struct Obj02864 *)p)->fDC=index;
        pos=slot;
    }
    ((struct Obj02864 *)p)->fE0=pos;
    func_0220246C(*(void **)*(u8 * *)&((struct Obj02864 *)p)->f0,1);
}


void func_0220246C(void *p, int which)
{
    RTCDate date;
    RTCTime time;
    u32 v;

    DWC_GetDateTime(&date, &time);
    v = ((u32)date.year << 24) | (((u32)date.month << 24) >> 8) | (((u32)date.day << 24) >> 16) | date.week;
    if (which == 1) {
        func_0200ADD8(p, v);
    } else {
        func_0200ADD0(p, v);
    }
}

void func_022024B0(void *obj,u8 *p) { int b=p[0x121],a=p[0x120]; if(func_0200949C(obj,a,b)==0) func_020094D8(obj,a,b,1); }


int func_022024DC(Work_022024DC *p, void *mon)
{
    if (func_021F6DE8((u32)mon) != 0 && func_0201AA18(p->ctx->party) == 6) {
        return 2;
    }
    if (p->species == 0x2D0 && func_0201AA18(p->ctx->party) == 6) {
        return 1;
    }
    return 0;
}

/*
 * Store a pair of u16 values at +0xe0c and +0xe0e.
 */
void func_0220251C(u8 *p, u16 a, u16 b)
{
    ((struct Obj00018 *)p)->fE0C = a;
    ((struct Obj00018 *)p)->fE0E = b;
}


/*
 * 1 only when the query is clear and the u16 at +0x32 is set.
 */
u32 func_0220252C(u8 *p)
{
    if (func_0200AD8C((const struct Rec0200AD8C *)(*(u32 *)(((struct Obj12247 *)p)->f0))) == 0) {
        if (((struct Obj12247 *)p)->f32 != 0) {
            return 1;
        }
    }
    return 0;
}


void func_0220254C(void *mon, u32 heap)
{
    void *bank;
    void *str;
    void *buf;
    u32 id;

    id = (heap & 0x7FFF) | 0x8000;
    bank = func_02045B38(0, 2, 0x51, (u16)id);
    str = func_02045EC0(bank, 0xF);
    func_02045C04(bank);
    func_02019B58(mon);
    func_02017E40(mon, 0x8E, (u32)func_02045A90(str));
    if (func_0202136C((u16)func_02017E1C(mon, 6, 0)) != 0) {
        buf = func_02008F08((u16)id);
        func_02017E1C(mon, 0xA7, (u32)buf);
        func_02008F88(buf, func_02045A90(str));
        func_02017E40(mon, 0xA7, (u32)buf);
        func_020307B0(buf);
    }
    func_02045808(str);
}


/*
 * Allocate a 0x48-byte block and hand it to the writer, then free the block.
 */
void func_022025E4(u32 a, u32 b, u32 c)
{
    void *blk = func_0201747C((void *)c, 0x48);

    func_0201EEF4((void *)a, b, blk);
    func_020307B0(blk);
}


/*
 * Create the table entry and register the 0x47 callback against it.
 */
void *func_02202608(u32 heap)
{
    return func_02030734(heap, func_020173EC(), 0, g_02203F5C, 0x47);
}
