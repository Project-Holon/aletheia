/*
 * file:     btl_server_p118.c
 * unit:     yes
 * function: func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308, func_021CE3B4, func_021CE3C8, func_021CE4D0
 * address:  0x021CE170
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021CE068  0x021CE068  thumb  ov093
 *   func_021CE08C  0x021CE08C  thumb  ov093
 *   func_021CE150  0x021CE150  thumb  ov093
 *   func_021CE160  0x021CE160  thumb  ov093
 *   func_021EE6B8 0x021EE6B8 thumb ov093
 *   func_021D3F54 0x021D3F54 thumb ov093
 *   func_021D3FD0 0x021D3FD0 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EA614 0x021EA614 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021D0B10  0x021D0B10  thumb  ov093
 *   func_021CF41C  0x021CF41C  thumb  ov093
 *   func_021CF360  0x021CF360  thumb  ov093
 *   func_021B990C  0x021B990C  thumb  ov093
 *   func_021CF470  0x021CF470  thumb  ov093
 *   func_021EAE44 0x021EAE44 thumb ov093
 *   func_021EAE54 0x021EAE54 thumb ov093
 *   func_021CF81C 0x021CF81C thumb ov093
 *   func_021D54C0 0x021D54C0 thumb ov093
 *   func_021D81F8 0x021D81F8 thumb ov093
 *   func_021D82D0 0x021D82D0 thumb ov093
 *   func_021CF58C 0x021CF58C thumb ov093
 *   func_021CF2F0 0x021CF2F0 thumb ov093
 *   func_021CE8F0 0x021CE8F0 thumb ov093
 *   func_021CE0F8 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021E9760 0x021E9760 thumb ov093
 *   func_021CE0BC 0x021CE0BC thumb ov093
 *   func_021E979C 0x021E979C thumb ov093
 *   func_021E97A4 0x021E97A4 thumb ov093
 *   func_021D62C4 0x021D62C4 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021CF430 0x021CF430 thumb ov093
 *   func_021BA1EC 0x021BA1EC thumb ov093
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021CF43C 0x021CF43C thumb ov093
 *   func_021D8454 0x021D8454 thumb ov093
 *   func_021CE7C4 0x021CE7C4 thumb ov093
 *   func_021CF3B8 0x021CF3B8 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021E9954 0x021E9954 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021CF220 0x021CF220 thumb ov093
 *   func_021CE7D4 0x021CE7D4 thumb ov093
 *   func_021CEDC0 0x021CEDC0 thumb ov093
 *   func_021CEA94 0x021CEA94 thumb ov093
 *   func_021CEEB8 0x021CEEB8 thumb ov093
 *   func_021CF078 0x021CF078 thumb ov093
 */
#include "../../matched/include/Obj01893.h"
#include "../../matched/include/Obj07769.h"
#include "../../matched/include/Obj03688.h"
#include "../../matched/include/Obj13356.h"
#include "../../matched/include/Obj00662.h"

#define Q ((struct L *)p)
#define W(o) (*(u32 *)(p+(o)))
#define P(o) (*(void **)(p+(o)))
struct L;
struct H;
struct Unk021D82D0;
struct Unk021D62A8;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 a : 5; u8 flag : 1; } Flags_021CE1B0;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

typedef struct { u8 a : 2; u8 f : 1; } Flags_021CE308;

struct L { u8 pad[0x11D]; u8 idx; u8 pad2[0x1A6-0x11E]; u8 sel; };

extern void func_021CE068(u8 *p);
extern int func_021CE08C(u8 *p);
extern void func_021CE150(u8 *p, void *q);
extern u32 func_021CE160(u8 *p);
extern u32 *func_021EE6B8(void *,u8,u8 *,u8 *);
extern void func_021D3F54(u8 *p);
extern void func_021D3FD0(unsigned char *p);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EA614(char *p, struct H *h);
extern int func_021EA710(u32 *p);
extern void func_021D8434(u32 *p);
extern void func_021D0B10(u8 *p, u32 a, u32 b, void *q, void *out);
extern void func_021CF41C(u8 *p);
extern void func_021CF360(u8 *p);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern u32 func_021CF470(u8 *p, void *q, u8 *o);
extern void func_021EAE44(void *);
extern int func_021EAE54(void *);
extern u32 func_021CF81C(u8 *,void *,u8 *);
extern u16 func_021D54C0(u8 *p, int i);
extern u32 func_021D81F8(void *,void *,void *,u32,void *);
extern void func_021D82D0(struct Unk021D82D0 *out, u32 id, u32 sub);
extern void func_021CF58C(struct Unk021D82D0 *out, u8 *p, void *q);
extern u32 func_021CF2F0(u8 *p, s32 *st);
extern u32 func_021CE8F0(const u8 *p, u16 *out);
extern void func_021CE0F8(u8 *, u8 *, u8 *);
extern void func_021EA65C(char *p, struct H *h);
extern void func_021E9760(char *, u8 *, int, int);
extern int func_021CE0BC(u8 *p, void *q);
extern void func_021E979C(char *p);
extern int func_021E97A4(char *p);
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021E9964(u32);
extern void func_021CF430(u8 *, u32, u32);
extern int func_021BA1EC(char **p);
extern int func_021B86E4(unsigned int **p);
extern u8 func_021CF43C(u8 *, u32);
extern u32 func_021D8454(u32 *);
extern void func_021CE7C4(u8 *);
extern void func_021CF3B8(u8 *, u32);
extern int func_021E9974(u32);
extern void func_021E9954(void *);
extern u8 func_021D5440(u8 *p);
extern void func_021EAF50(struct L *p, u32 val);
extern u32 func_021CF220(u8 *p, int *st);
extern u32 func_021CE7D4(u8 *p, int *st);
extern u32 func_021CEDC0(u8 *p, int *st);
extern int func_021CEA94(u8 *p, u32 *state);
extern u32 func_021CEEB8(u8 *p, int *st);
extern u32 func_021CF078(u8 *p, u32 *st);
u32 func_021CE170(u8 *p, s32 *st);
int func_021CE1B0(u8 *p,int *state);
void func_021CE2E8(u8 *p);
u32 func_021CE308(u8 *p);
void func_021CE3B4(u8 *p, void *q);
int func_021CE3C8(u8 *p,int *state);
int func_021CE4D0(u8 *p, u32 *st);




u32 func_021CE170(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CE150(p, (void *)((u32)func_021CE308));
        func_021CE068(p);
        *st = *st + 1;
        break;
    case 1:
        func_021CE08C(p);
        if (func_021CE160(p) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}



int func_021CE1B0(u8 *p,int *state)
{
    u8 count;
    u8 flag;
    u32 *data;
    switch (*state) {
    case 0:
        if (((Flags_021CE1B0 *)(p+0x1b2))->flag) {
            func_021CE2E8(p);
            return 1;
        }
        data = func_021EE6B8(((struct Obj01893 *)p)->f14,p[0x1a6],&count,&flag);
        if (flag) func_021D3F54(p+0x18);
        *(u32 * *)&((struct Obj01893 *)p)->fD8 = data;
        ((struct Obj01893 *)p)->fDC = count * 4;
        if (((Command *)data)->kind == 8) {
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb7);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                (*state)++;
            } else {
                func_021CE2E8(p);
                p[0x1b2] |= 0x10;
                return 1;
            }
        } else if (((Command *)data)->kind == 9) {
            p[0x1b2] |= 0x20;
            func_021D3FD0(p+0x18);
            if (((struct Obj01893 *)p)->f54) {
                func_021EAF18((struct L *)(p+0x58),1,0xb8);
                func_021EA614(((struct Obj01893 *)p)->f54,(struct H *)(p+0x58));
                *state += 2;
            } else {
                func_021CE2E8(p);
                return 1;
            }
        } else return 1;
        break;
    case 1:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            p[0x1b2] |= 0x10;
            return 1;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj01893 *)p)->f54)) {
            func_021CE2E8(p);
            return 1;
        }
        break;
    }
    return 0;
}



void func_021CE2E8(u8 *p) { *(u8 * *)&((struct Obj07769 *)p)->fC=p+0x124; func_021D8434((u32 *)(p+0x124)); *(u8 * *)&((struct Obj07769 *)p)->fD8=*(u8 * *)&((struct Obj07769 *)p)->fC; ((struct Obj07769 *)p)->fDC=4; }




u32 func_021CE308(u8 *p)
{
    u32 i = 0;
    u32 w;
    p[0x11d] = 0;
    ((s8 *)p)[0x11e] = -1;
    p[0x11f] = 0;
    ((Flags_021CE308 *)(p + 0x1b2))->f = 0;
    func_021D0B10(p, 0, p[0x11c], p + 0x184, p + 0x190);
    func_021CF41C(p);
    func_021CF360(p);
    for (i = 0; i < 3; i++) {
        func_021D8434((u32 *)(p + 0x124 + i * 4));
    }
    for (i = 0; i < p[0x11c]; i++) {
        w = (u32)func_021B990C((char *)(((struct Obj03688 *)p)->f4), p[0x1a6], (u8)i);
        if (func_021CF470(p, (void *)w, 0) == 0) {
            p[0x11f] = i;
            break;
        }
    }
    func_021CE150(p, (void *)((u32)func_021CE4D0));
    return 0;
}



void func_021CE3B4(u8 *p, void *q) { func_021EA614(((struct Obj13356 *)p)->f54,q); p[0x120]=1; }



int func_021CE3C8(u8 *p,int *state)
{
    u8 out[4];
    u32 i;
    u32 id;
    switch (*state) {
    case 0:
        func_021EAE44(((struct Obj00662 *)p)->f54);
        (*state)++;
        break;
    case 1:
        if (func_021EAE54(((struct Obj00662 *)p)->f54)) {
            for (; p[0x11d] < p[0x11c]; p[0x11d]++) {
                ((struct Obj00662 *)p)->f8 = func_021B990C(((struct Obj00662 *)p)->f4,p[0x1a6],p[0x11d]);
                *(u8 * *)&((struct Obj00662 *)p)->fC = p+0x124+p[0x11d]*4;
                func_021D8434((u32 *)(*(u8 * *)&((struct Obj00662 *)p)->fC));
                if (!func_021CF470(p,((struct Obj00662 *)p)->f8,*(u8 * *)&((struct Obj00662 *)p)->fC)) {
                    i = func_021CF81C(p,((struct Obj00662 *)p)->f8,out);
                    if (i < 4) {
                        id = func_021D54C0(((struct Obj00662 *)p)->f8,i);
                        func_021D82D0((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),id,func_021D81F8(((struct Obj00662 *)p)->f0,((struct Obj00662 *)p)->f4,((struct Obj00662 *)p)->f8,id,p+0x38));
                    } else func_021CF58C((struct Unk021D82D0 *)(*(u8 * *)&((struct Obj00662 *)p)->fC),p,((struct Obj00662 *)p)->f8);
                }
            }
            (*state)++;
        }
        break;
    case 2:
        *(u8 * *)&((struct Obj00662 *)p)->fD8 = p+0x124;
        ((struct Obj00662 *)p)->fDC = p[0x11c]*4;
        func_021CE150(p,(void *)((u32)func_021CF2F0));
        break;
    }
    return 0;
}

/*
 * note 2026-10-05 (wave P26 lane 2): byte-identical to the original except that two call
 * relocations have no witness in the current index: func_021E979C and func_021E9954. Both
 * leaves are now filed (src/matched/ov/ov093_func_021E979C.c, ov093_func_021E9954.c, EXACT);
 * the verdict becomes EXACT once the integrator regenerates the index. The original extent is
 * 772 B: 756 B of C plus the 16 B linker veneer at 021CE7C4 (not C, resolved as a veneer witness).
 * Two changes closed the 253 B residue of the older draft: (1) no shared increment label and
 * no goto: each arm writes ++*st; break; so the compiler builds the single shared state store
 * and one epilogue (756 to 748 B, branch layout); (2) the countdown loop reads the index byte
 * through a struct field (struct L at 0x11D and 0x1A6) instead of a count pointer local, so
 * mwcc hoists three separate address computations (count pointer in r5, a copy in r6, a
 * stack copy for the loop test) as in the original.
 * Not tried again from the older note: unsigned-long state pointer, full-word countdown.
 * proof: full unsigned state dispatch <=8; byte selectors0..255; countdown assigned before reads; byte/state additions wrap at their original widths; fixed veneer is omitted from C.
 */
int func_021CE4D0(u8 *p, u32 *st)
{
    u32 result;
    switch (*st) {
    case 0:
        P(8) = func_021B990C(P(4), p[0x1A6], p[0x11D]);
        P(12) = p + 0x124 + p[0x11D] * 4;
        p[0x1AF] = 0;
        func_021D8434(P(12));
        if (func_021CF470(p, P(8), P(12))) {
            func_021CE150(p, (void *)((u32)func_021CF220));
            break;
        }
        if (func_021CE8F0(p, (unsigned short *)(p + 0x19E)) == 1) {
            func_021CE150(p, (void *)((u32)func_021CE7D4));
            break;
        }
        ++*st; break;
    case 1:
        if (*(signed char *)(p + 0x11E) != p[0x11D] || p[0x120]) {
            func_021CE0F8(p, P(8), p + 0x58);
            func_021EA65C(P(0x54), (struct H *)(p + 0x58));
            p[0x120] = 0;
            p[0x11E] = p[0x11D];
            ++*st; break;
        }
        *st += 2U;
        break;
    case 2:
        if (!func_021EA710(P(0x54))) return 0;
        ++*st;
        /* falls through */
    case 3:
        func_021E9760(P(0x54), P(8), p[0x11D] > p[0x11F], (int)P(12));
        ++*st; break;
    case 4:
        if (func_021CE0BC(p, (void *)((u32)func_021CE3C8))) {
            func_021E979C(P(0x54));
            return 0;
        }
        result = func_021E97A4(P(0x54));
        switch (result) {
        case 3:
            if (func_021D62C4(P(8), 0x21)) {
                func_021E9964(W(0x54));
                *st = 6;
            } else {
                func_021CF430(p, p[0x11D], 0);
                func_021CE150(p, (void *)((u32)func_021CEDC0));
            }
            break;
        case 1:
            func_021CF430(p, p[0x11D], 0);
            func_021CE150(p, (void *)((u32)func_021CEA94));
            break;
        case 2:
            if (func_021D62C4(P(8), 0x21)) *st = 6;
            else if (p[0x1AA] == 1 && !func_021BA1EC(P(0))) {
                func_021E9964(W(0x54));
                *st = 5;
            } else func_021CE150(p, (void *)((u32)func_021CEEB8));
            break;
        case 4:
            if (p[0x11D] == p[0x11F]) {
                if (func_021D62C4(P(8), 0x21) && func_021B86E4(P(0)) != 2) *st = 6;
                else {
                    func_021CF430(p, p[0x11D], 0);
                    func_021CE150(p, (void *)((u32)func_021CF078));
                }
                break;
            }
            if (p[0x11D] == 0) break;
            do {
                --Q->idx;
                if (!func_021CF470(p, func_021B990C(P(4), Q->sel, Q->idx), 0)) {
                    p[0x1AB] += func_021CF43C(p, p[0x11D]);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 3)
                        func_021CE7C4(p + 0x190);
                    if (func_021D8454((u32 *)(p + 0x124 + p[0x11D] * 4)) == 2)
                        func_021CF3B8(p, p[0x11D]);
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    return 0;
                }
            } while (Q->idx != 0);
            break;
        }
        break;
    case 5:
        if (func_021E9974(W(0x54))) *st = 3;
        break;
    case 6:
        func_021E9954(P(0x54));
        ++*st; break;
    case 7:
        if (!func_021E9974(W(0x54))) break;
        func_021EAF18((struct L *)(p + 0x58), 1, 0xC5);
        func_021EAF50((struct L *)(p + 0x58), func_021D5440(P(8)));
        func_021CE3B4(p, p + 0x58);
        ++*st; break;
    case 8:
        if (func_021EA710(P(0x54))) *st = 1;
        break;
    }
    return 0;
}
