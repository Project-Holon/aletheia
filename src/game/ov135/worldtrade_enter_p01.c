/*
 * file:     worldtrade_enter_p01.c
 * unit:     yes
 * function: func_021F88B0, func_021F88D8, func_021F8908, func_021F8950, func_021F8990, func_021F89A8, func_021F89B4, func_021F89F0, func_021F8A18, func_021F8A3C, func_021F8A40, func_021F8A44, func_021F8A74, func_021F8A80, func_021F8AB0, func_021F8AF4, func_021F8B0C, func_021F8BBC, func_021F8BE8, func_021F8D10
 * address:  0x021F88B0
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
 *   d_022030E8 0x022030E8 data a2
 *   tbl_02202F0C  0x02202F0C  data
 *   func_0201F81C 0x0201F81C thumb
 *   func_0201F878 0x0201F878 thumb
 *   tbl_022030E8 0x022030E8 data a2
 *   func_021F50EC 0x021F50EC thumb ov135
 *   d_02203C1C 0x02203C1C data a4
 *   func_021F5074  0x021F5074  thumb  ov135
 *   func_021F4EC8  0x021F4EC8  thumb  ov135
 *   func_02005D90  0x02005D90  thumb
 *   func_021F4EC0  0x021F4EC0  thumb
 *   func_02168064  0x02168064  arm
 *   func_02168124 0x02168124 arm ov009
 *   func_02008540 0x02008540 thumb
 *   func_0200853C 0x0200853C thumb
 *   func_0205994C 0x0205994C arm
 *   func_021C7BA0 0x021C7BA0 arm ov114
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_021F4FC4  0x021F4FC4  thumb  ov135
 *   func_021C7C1C  0x021C7C1C  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *   func_021B9B00 0x021B9B00 thumb ov114
 *   func_021C8E18 0x021C8E18 arm ov114
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02031348 0x02031348 arm
 *   func_021F8E88 0x021F8E88 thumb ov135
 *   str_02203C34 0x02203C34 data a1
 *   d_021D6338 0x021D6338 data ov115 a4
 *   ov115_id 0x00000073 data
 */
#include "../../matched/include/Obj02204.h"
#include "../../matched/include/Obj12203.h"
#include "../../matched/include/Obj12204.h"
#include "../../matched/include/Obj05413.h"
#include "../../matched/include/Obj08184.h"
#include "../../matched/include/Obj00287.h"
#include "../../matched/include/Obj23396.h"
#include "../../matched/include/Obj23397.h"
#include "../../matched/include/Obj23398.h"
#include "../../matched/include/Obj23399.h"
#include "../../matched/include/Obj18565.h"
#include "../../matched/include/Obj04905.h"
#include "../../matched/include/Obj14167.h"
#include "../../matched/include/Obj23400.h"
#include "../../matched/include/Obj03294.h"
#include "../../matched/include/Obj23401.h"

struct Slot;
struct Obj;
struct Sub020097BCObj;
struct DWCstAccUserData;
struct Sub0200852CObj;
struct Ctx;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

typedef signed int s32;

typedef struct {
    u8 start;
    u8 id;
} Range;

typedef struct {
    u8 pad0[0x28];
    u32 x28;
    u16 x2C;
    u16 x2E;
    u16 x30;
    u8 pad32[0xEB2 - 0x32];
    u16 xEB2;
} Work_021F88B0;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0x38];
    int err;
    u8 pad3C[0xF7C - 0x3C];
    int state;
    int sub;
    u8 padF84[0xF8C - 0xF84];
    int wait;
} Work_021F8BBC;

typedef struct {
    void *handle;
    u32 f4, f8, fc;
    void *f10;
    u32 f14, f18, f1c;
    void (*callback)(void *, void *);
    void *user;
} State;

extern void *func_0201F81C(u32 n, u32 heap);
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);
extern s32 func_020200CC(struct Obj *o);
extern void func_020202EC(struct Obj *obj, u16 *out);
extern void func_020061E4(u32 id);
extern void func_021F50EC(u8 *);
extern void func_021F5074(u8 *p);
extern void func_021F4EC8(u8 *p);
extern void func_02005D90(u32 a, u32 b);
extern void func_021F4EC0(u8 *p, u32 a, u32 b);
extern void func_02168064(void);
extern int func_02168124(void);
extern struct Sub020097BCObj *func_02009860(struct Sub020097BCObj *obj);
extern int func_02009CC0(void *a0);
extern void func_02008540(struct Sub0200852CObj *obj, u32 value);
extern u32 func_0200853C(const struct Sub0200852CObj *obj);
extern unsigned long long func_0205994C(struct DWCstAccUserData *userdata);
extern void func_021C7BA0(u32 a, u32 b, u32 c, int d);
extern void func_021C8DA0(u8 *p);
extern void *func_021C7C1C();
extern u32 func_021C866C();
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_021F4FC4(u8 *p);
extern void func_021B9B00(u8 *,int);
extern void func_021C8E18(u8 *,u32);
extern int func_021F8E88(void *dialog, u8 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02082BCC(void *p, u32 value, u32 size);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02031348(void *h, u32 id, const void *a, void *b);
extern u32 func_0200F7B8(u32 a0);
void func_021F88B0(u8 *p,u32 n);
int func_021F88D8(u32 id, u32 *start);
int func_021F8908(void **menu, void *msg, int id);
int func_021F8950(void *p, u16 *old);
void func_021F8990(u8 *p);
void func_021F89A8(u8 *p, int i, u16 a, u16 b);
int func_021F89B4(u8 *p);
int func_021F89F0(u8 *p);
u32 func_021F8A18(u8 *p);
void func_021F8A3C(void *a0);
void func_021F8A40(void);
int func_021F8A44(Work_021F88B0 *p);
int func_021F8A74(void *a0);
int func_021F8A80(u8 *a0);
int func_021F8AB0(u8 **p);
int func_021F8AF4(u8 *p);
int func_021F8B0C(u8 *p);
int func_021F8BBC(u8 *p);
int func_021F8BE8(Work_021F8BBC *p);
int func_021F8D10(u8 *p);
extern const u16 d_022030E8[];
extern const Range tbl_02202F0C[];
extern u16 tbl_022030E8[];
extern const char str_02203C34[], ov115_id[];
extern const u32 d_021D6338[];




void func_021F88B0(u8 *p,u32 n) { if(n==0){((struct Obj02204 *)p)->fF84=0;return;}n--;if(n<130)((struct Obj02204 *)p)->fF84=d_022030E8[n]; }





int func_021F88D8(u32 id, u32 *start)
{
    int i;

    for (i = 0; i < 28; i++) {
        if (id == tbl_02202F0C[i].id) {
            *start = tbl_02202F0C[i].start;
            return tbl_02202F0C[i + 1].start - tbl_02202F0C[i].start;
        }
    }
    return 0;
}




#pragma opt_common_subs off




/*
 * Builds a message menu: reads the entry range for an id, allocates the table
 * and fills one slot per entry. The slot call takes five arguments (heap id
 * 0x48 on the stack), as in the other matched callers of func_0201F878 (the
 * arm9 definition lists four parameters; the fifth is passed but not read).
 * Closed with opt_common_subs off: the original does not share start + i
 * between the table index and the tag. 2026-10-05 (P21): plain form 16 bytes
 * off, only that pragma closes it. Table extern is not const (const gave 18).
 */
int func_021F8908(void **menu, void *msg, int id)
{
    int i;
    int count;
    u32 start;
    count = func_021F88D8(id, &start);
    *menu = func_0201F81C(count, 0x48);
    for (i = 0; (i < count) ? 1 : 0; i++) {
        func_0201F878(*menu, (u32)msg, tbl_022030E8[start + i], start + i + 1, 0x48);
    }
    return count;
}




#pragma opt_common_subs reset




int func_021F8950(void *p, u16 *old)
{
    u16 current;
    int result;
    result = func_020200CC(p);
    func_020202EC(p, &current);
    if (*old != current) {
        if (*old != 0xFFFF) func_020061E4(0x548);
        *old = current;
    }
    return result;
}




/*
 * Clear the two ten-entry u16 tables at +4 and +0x18 and the two header words.
 */
void func_021F8990(u8 *p)
{
    int i;
    u16 z = 0;

    for (i = 0; i < 10; i++) {
        *(u16 *)(p + i * 2 + 4) = z;
        *(u16 *)(p + i * 2 + 0x18) = z;
    }
    ((struct Obj12203 *)p)->f0 = z;
    ((struct Obj12203 *)p)->f2 = z;
}




/*
 * Store a pair of u16 values at +4 and +0x18 of record i.
 */
void func_021F89A8(u8 *p, int i, u16 a, u16 b)
{
    u8 *q = p + i * 2;

    ((struct Obj12204 *)q)->f4 = a;
    ((struct Obj12204 *)q)->f18 = b;
}




/*
 * volatile: hardware read-modify-write at 021F89C6/021F89CA, 0x04000304.
 */
int func_021F89B4(u8 *p) {func_021F50EC(p);func_021F8A3C(p);*(volatile u16 *)0x04000304 = (u16)(*(volatile u16 *)0x04000304 & ~0x8000);switch(((struct Obj05413 *)p)->f20){case 19:case 21:((struct Obj05413 *)p)->f28=2;break;case 20:((struct Obj05413 *)p)->f28=4;break;}return 1;}




extern int (*const d_02203C1C[])(void *);




int func_021F89F0(u8 *p) { int state,r;state=((struct Obj08184 *)p)->f28;r=d_02203C1C[state](p);if(state!=((struct Obj08184 *)p)->f28){((struct Obj08184 *)p)->fF88=0;((struct Obj08184 *)p)->fF8A=0;}return r; }





/*
 * Run the three teardown steps, then report 4 while the +0x10 handle is gone.
 */
u32 func_021F8A18(u8 *p)
{
    func_021F8A40();
    func_021F5074(p);
    func_021F4EC8(p);
    if (((struct Obj00287 *)p)->f10 == 0) {
        return 4;
    }
    return 0;
}




/*
 * Empty stub.
 */
void func_021F8A3C(void *a0)
{
}




void func_021F8A40(void)
{
}





int func_021F8A44(Work_021F88B0 *p)
{
    func_02005D90(0x486, 0xFFFF);
    p->x28 = 1;
    p->xEB2 = 1;
    p->x30 = 0;
    func_021F4EC0((u8 *)p, 1, 0);
    return 2;
}





/*
 * Call func_02168064 and report success.
 */
int func_021F8A74(void *a0)
{
    func_02168064();
    return 1;
}




/*
 * Extent remainder: 2-byte zero alignment padding.
 */
int func_021F8A80(u8 *a0) { switch(func_02168124()) {case 3:return 1;case 0:case 4:case 5:return 2;default:return 0;} }




/*
 * extent: 0x021F8AF2..0x021F8AF4 is two zero alignment bytes.
 */
int func_021F8AB0(u8 **p)
{
    void *handle;
    u32 id;
    u64 key;
    handle = func_02009860(((struct Obj23396 *)(*p))->f14);
    func_02008540(((struct Obj23397 *)(*p))->f1C, func_02009CC0(((struct Obj23398 *)(*p))->f14));
    id = func_0200853C(((struct Obj23399 *)(*p))->f1C);
    key = func_0205994C(handle);
    func_021C7BA0(id, (u32)key, (u32)(key >> 32), 0);
    return 1;
}





/*
 * Hand the object over, clear the +0xf8c slot and latch 1.
 */
int func_021F8AF4(u8 *p)
{
    func_021C8DA0(p);
    ((struct Obj18565 *)p)->fF8C = 0;
    return 1;
}



/*
 * 18-slot switch on the 0x021C86A8 index (case value = index + 15, bound 17):
 * index 14 returns 1, and four separate case groups (15, 13+16, 0+3, 1+12)
 * each call func_021F4FC4 and archive n at +0x38 before returning 2; the
 * remaining indexes fall through to the shared tail (one more func_021F4FC4)
 * and the function returns 0.  func_021C7C1C(p) runs first, unconditionally.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
 */
int func_021F8B0C(u8 *p)
{
    s32 n;

    if (func_021C866C(func_021C7C1C(p)) != 0) {
        n = func_021C86A8();
        ((struct Obj04905 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
            return 1;
        case 16:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 14:
        case 17:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 0:
        case 3:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        case 1:
        case 13:
            func_021F4FC4(p);
            ((struct Obj04905 *)p)->f38 = n;
            return 2;
        }
        func_021F4FC4(p);
        func_021F513C(p);
    } else {
        if (++((struct Obj04905 *)p)->fF8C == 0xe10) {
            func_021F513C(p);
        }
    }
    return 0;
}



int func_021F8BBC(u8 *p) { func_021B9B00(p+0xf18,((struct Obj23400 *)(*(u8 * *)&((struct Obj14167 *)p)->f0))->f1C);func_021C8E18(p+0xf18,(u32)(p+0xf7c));((struct Obj14167 *)p)->fF8C=0;return 1; }




/*
 * note: 2026-10-05 wave P19: the sub switch exit (state 0, sub out of range) is a cross-jumped copy of the tail, `b 0x021F8CEC` in the image. Written as `func_021F513C(p); goto done;` after the sub switch, with `done: return 0;` at the end. EXACT in c99 and c (296 bytes). Idiom: a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy.
 */
int func_021F8BE8(Work_021F8BBC *p)
{
    int code;

    func_021C7C1C();
    if (func_021C866C() != 0) {
        code = func_021C86A8();
        p->wait = 0;
        switch (code) {
        case 0:
            switch (p->state) {
            case 0:
                switch (p->sub) {
                case 0:
                    func_021F4EC0((u8 *)p, 1, 0);
                    return 1;
                case 3:
                    p->err = -5003;
                    return 2;
                case 1:
                    p->err = -5000;
                    return 2;
                case 2:
                    p->err = -5001;
                    return 2;
                }
                func_021F513C((u8 *)p);
                goto done;
            case 1:
                p->err = -5004;
                return 2;
            case 2:
                p->err = -5005;
                return 2;
            default:
                func_021F4FC4((u8 *)p);
                break;
            }
            break;
        case 1:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -1:
        case 2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -15:
        case -12:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        case -14:
        case -2:
            func_021F4FC4((u8 *)p);
            p->err = code;
            return 2;
        default:
            func_021F4FC4((u8 *)p);
            break;
        }
        func_021F513C((u8 *)p);
    } else if (++p->wait == 0xE10) {
        func_021F513C((u8 *)p);
    }
done:
    return 0;
}


/*
 * lever: ov115 data hint is witnessed by this function loading ov115 via func_02031348; no hint remains MATCH.
 */
int func_021F8D10(u8 *p)
{
    State *s;
    *(State * *)&((struct Obj03294 *)p)->f10DC = func_02030734(0x48, sizeof(State), 0, str_02203C34, 0x263);
    func_02082BCC(*(State * *)&((struct Obj03294 *)p)->f10DC, 0, sizeof(State));
    s = *(State * *)&((struct Obj03294 *)p)->f10DC;
    s->handle = func_020120F4(((struct Obj23401 *)(*(u8 * *)&((struct Obj03294 *)p)->f0))->f40);
    s->f4 = 0;
    s->f8 = 1;
    s->f10 = p + 0x116C;
    s->fc = 30;
    s->callback = (void (*)(void *, void *))func_021F8E88;
    s->user = p;
    ((struct Obj03294 *)p)->f12EC = 0;
    if (((struct Obj03294 *)p)->f20 == 21) s->f14 = 1;
    else s->f14 = 0;
    func_02031348(((struct Obj03294 *)p)->f12F0, (u32)ov115_id, d_021D6338, *(State **)(p + 0x10DC));
    func_0200F7B8(0);
    ((struct Obj03294 *)p)->f28 = 3;
    return 2;
}
