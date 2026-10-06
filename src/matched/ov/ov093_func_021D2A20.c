/*
 * function: func_021D2A20
 * address: 0x021D2A20
 * packet: pkt_ov093_021D2A20
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 43/43 relocations resolved after parent-coordinated overlay
 * leaf witnesses; all ARM9 calls resolve without new ARM9 files.
 * lever: int id loaded via (u8) cast fixes spill slots; widening the
 * func_021B8DC0 third extern parameter removes absent call truncation.
 * StateData fields keep counter updates on one global base.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021B8DC0 0x021B8DC0 thumb ov093
 *   func_021F8204 0x021F8204 thumb ov094
 *   func_021D69B8 0x021D69B8 thumb ov093
 *   func_021F8134 0x021F8134 thumb ov094
 *   func_021F8180 0x021F8180 thumb ov094
 *   func_021D6EA0 0x021D6EA0 thumb ov093
 *   func_021D6BFC 0x021D6BFC thumb ov093
 *   func_021F8150 0x021F8150 thumb ov094
 *   func_02006238 0x02006238 thumb
 *   func_021EA3B8 0x021EA3B8 thumb ov093
 *   func_021EA3D4 0x021EA3D4 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_02005F38 0x02005F38 thumb
 *   func_02005E9C 0x02005E9C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_021BA238 0x021BA238 thumb ov093
 *   func_021EADA4 0x021EADA4 thumb ov093
 *   func_021EADB4 0x021EADB4 thumb ov093
 *   func_021EADC4 0x021EADC4 thumb ov093
 *   func_021EADD4 0x021EADD4 thumb ov093
 *   func_021EADE4 0x021EADE4 thumb ov093
 *   func_021EADF4 0x021EADF4 thumb ov093
 *   func_021D2CA8 0x021D2CA8 thumb ov093
 *   func_021B9358 0x021B9358 thumb ov093
 *   d_021F3B64 0x021F3B64 data a4
 */
#include "../include/Obj00268.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 data[0x24]; } MsgParam;
typedef struct {
    void *battle;
    void *party;
    u8 unk008[0x4c];
    void *msgWin;
    MsgParam msg;
    u8 unk07C[0x11e];
    u16 level;
    u8 unk19C[0xa];
    u8 side;
} LearnSeq;
extern u8 *func_021B9934(char *p, int i);
extern unsigned char func_021B8DC0(unsigned char *p, void *a, unsigned int b);
extern int func_021F8204(int);
struct H;
struct L;
struct Obj;
struct Result;
extern int func_021D69B8(struct Obj *p, u32 *remaining, struct Result *r);
extern void func_021F8134(int, u32);
extern int func_021F8180(void);
extern void func_021D6EA0(void *);
extern void func_021D6BFC(u8 *p);
extern void func_021F8150(int, void *);
extern int func_02006238(void);
extern void func_021EA3B8(char *ctx, int a, int b);
extern int func_021EA3D4(void *);
struct L;
extern void func_021EAF18(struct L *p, int kind, u16 id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA720(void *);
extern void func_02005DE4(void *);
extern int func_02005E64(void);
extern void func_02005D90(u32, u32);
extern int func_021EA710(u32 *p);
extern int func_02005F38(void);
extern void func_02005E9C(void);
extern u32 func_020362DC(void);
extern int func_02035C60(void);
extern void func_021BA238(char *p, void *m);
struct T;
extern void func_021EADA4(u8 *, int, struct T *);
extern int func_021EADB4(u8 *);
extern void func_021EADC4(u8 *);
extern int func_021EADD4(u8 *);
extern void func_021EADE4(u8 *);
extern int func_021EADF4(u8 *);
extern int func_021D2CA8(LearnSeq *, int *, void *);
extern void func_021B9358(char *p, int i);
struct StateData { u8 pad0[8]; int counter; u32 remaining; u32 pad10; u8 result[14]; };
extern struct StateData d_021F3B64;
int func_021D2A20(u8 *p, int *state, u32 *args)
{
    void *obj;
    int id;
    int index;
    int enabled;
    u32 remaining;
    id = (u8)args[0];
    obj = func_021B9934(*(char * *)&((struct Obj00268 *)p)->f4, id);
    index = func_021B8DC0(((struct Obj00268 *)p)->f0, ((struct Obj00268 *)p)->f4, id);
    enabled = 0;
    if (index != 0xff && func_021F8204(index)) enabled = 1;
    switch (*state) {
    case 0:
        d_021F3B64.remaining = args[1];
        d_021F3B64.counter = 0;
        *state = 1;
    case 1:
        if (d_021F3B64.remaining) {
            remaining = d_021F3B64.remaining;
            if (func_021D69B8(obj, &remaining, (struct Result *)d_021F3B64.result)) {
                *state = 3;
            } else {
                if (enabled) {
                    func_021F8134(index, d_021F3B64.remaining);
                    *state = 2;
                } else *state = 13;
                remaining = 0;
            }
            d_021F3B64.remaining = remaining;
        } else *state = 13;
        break;
    case 2:
        if (!func_021F8180()) *state = 13;
        break;
    case 3:
        func_021D6EA0(obj);
        func_021D6BFC(obj);
        if (enabled) {
            func_021F8150(index, obj);
            *state = 4;
        } else *state = 6;
        break;
    case 4:
        if (!func_021F8180() && !func_02006238()) {
            func_021EA3B8(((struct Obj00268 *)p)->f54, index, 0x25d);
            *state = 5;
        }
        break;
    case 5:
        if (func_021EA3D4(((struct Obj00268 *)p)->f54)) *state = 6;
        break;
    case 6:
        func_021EAF18((struct L *)(p + 0x58), 1, 0x3c);
        func_021EAF50((struct L *)(p + 0x58), (int)id);
        func_021EAF50((struct L *)(p + 0x58), (int)d_021F3B64.result[0]);
        func_021EA614(((struct Obj00268 *)p)->f54, (struct H *)(p + 0x58));
        *state = 7;
        break;
    case 7:
        if (func_021EA720(((struct Obj00268 *)p)->f54)) {
            func_02005DE4((void *)1);
            func_02005E64();
            func_02005D90(0x515, 0xffff);
        }
        if (func_021EA710(((struct Obj00268 *)p)->f54) && !func_02005F38()) {
            func_02005E9C();
            func_02005DE4(0);
            d_021F3B64.counter = 0;
            *state = 8;
        }
        break;
    case 8:
        d_021F3B64.counter++;
        if ((func_020362DC() & 3) || func_02035C60() || d_021F3B64.counter > 80) {
            d_021F3B64.counter = 0;
            func_021BA238(((struct Obj00268 *)p)->f0, obj);
            func_021EADA4(*(u8 * *)&((struct Obj00268 *)p)->f54, (int)obj, (struct T *)d_021F3B64.result);
            *state = 9;
        }
        break;
    case 9:
        if (func_021EADB4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADC4(((struct Obj00268 *)p)->f54);
            *state = 10;
        }
        break;
    case 10:
        if (func_021EADD4(((struct Obj00268 *)p)->f54) && ((func_020362DC() & 3) || func_02035C60())) {
            func_021EADE4(((struct Obj00268 *)p)->f54);
            *state = 11;
        }
        break;
    case 11:
        if (func_021EADF4(((struct Obj00268 *)p)->f54)) {
            d_021F3B64.counter = 0;
            *state = 12;
        }
        break;
    case 12:
        if (func_021D2CA8((LearnSeq *)p, &d_021F3B64.counter, obj)) *state = 1;
        break;
    case 13:
        func_021B9358(((struct Obj00268 *)p)->f0, id);
        return 1;
    }
    return 0;
}
