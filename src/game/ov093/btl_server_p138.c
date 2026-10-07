/*
 * file:     btl_server_p138.c
 * unit:     yes
 * function: func_021CF078, func_021CF220, func_021CF2F0, func_021CF360, func_021CF37C, func_021CF3B8, func_021CF3F8, func_021CF41C
 * address:  0x021CF078
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
 *   func_021B86E4 0x021B86E4 thumb ov093
 *   func_021CF918 0x021CF918 thumb ov093
 *   func_021EAF18 0x021EAF18 thumb ov093
 *   func_021EAF50 0x021EAF50 thumb ov093
 *   func_021EAF78 0x021EAF78 thumb ov093
 *   func_021CE3B4 0x021CE3B4 thumb ov093
 *   func_021EA710 0x021EA710 thumb ov093
 *   func_021CE0F8 0x021CE0F8 thumb ov093
 *   func_021EA65C 0x021EA65C thumb ov093
 *   func_021EA720 0x021EA720 thumb ov093
 *   func_021EABC4 0x021EABC4 thumb ov093
 *   func_021EAC54 0x021EAC54 thumb ov093
 *   func_021CE08C 0x021CE08C thumb ov093
 *   func_021D8414 0x021D8414 thumb ov093
 *   func_021CE150 0x021CE150 thumb ov093
 *   func_021CE4D0 0x021CE4D0 thumb ov093
 *   func_021CE3C8 0x021CE3C8 thumb ov093
 *   func_021E9964 0x021E9964 thumb ov093
 *   func_021E9974 0x021E9974 thumb ov093
 *   func_021B990C 0x021B990C thumb ov093
 *   func_021CF470 0x021CF470 thumb ov093
 *   func_021D8434 0x021D8434 thumb ov093
 *   func_021B86C0  0x021B86C0  thumb  ov093
 *   func_021EA7FC  0x021EA7FC  thumb  ov093
 *   func_021EA814  0x021EA814  thumb  ov093
 *   func_021F7EB4  0x021F7EB4  thumb  ov094
 *   func_021CE0E0  0x021CE0E0  thumb  ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021B9090 0x021B9090 thumb ov093
 *   func_021B90BC 0x021B90BC thumb ov093
 *   func_02082BCC 0x02082BCC arm
 */
#include "../../matched/include/Obj02136.h"
#include "../../matched/include/Obj00888.h"
#include "../../matched/include/Obj07772.h"
#include "../../matched/include/Obj06234.h"
#include "../../matched/include/Obj05200.h"

struct L;
struct H;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed int     s32;

typedef signed char s8;

typedef signed short s16;

extern int func_021B86E4(unsigned int **p);
extern u32 func_021CF918(u8 *, u8 *, u16 *);
extern void func_021EAF18(struct L *p, int kind, int id);
extern void func_021EAF50(struct L *p, u32 val);
extern void func_021EAF78(u8 *, u8);
extern void func_021CE3B4(u8 *p, void *q);
extern int func_021EA710(u32 *p);
extern void func_021CE0F8(u8 *, u8 *, u8 *);
extern void func_021EA65C(char *p, struct H *h);
extern int func_021EA720(u32 *p);
extern void func_021EABC4(u8 *a, u32 x, u32 y, u32 z);
extern int func_021EAC54(void *, int *);
extern int func_021CE08C(u8 *);
extern void func_021D8414(u32 *p);
extern void func_021CE150(u8 *p, void *q);
extern int func_021CE4D0(u8 *p, u32 *st);
extern int func_021CE3C8(u8 *p, int *state);
extern void func_021E9964(u32);
extern int func_021E9974(u32);
extern void *func_021B990C(char *p, unsigned int i, unsigned int j);
extern u32 func_021CF470(u8 *, void *, u8 *);
extern void func_021D8434(u32 *p);
extern u8 func_021B86C0(u8 **p);
extern void func_021EA7FC(char *p);
extern int func_021EA814(u32 *p);
extern int func_021F7EB4(void);
extern void func_021CE0E0(u8 *p);
extern u8 func_021B8FF4(u8 *);
extern void func_021B9090(u8 *p, u32 k, u32 x);
extern void func_021B90BC(u8 *p, u8 k, u32 v);
extern void func_02082BCC(void *,int,u32);
u32 func_021CF078(u8 *p, u32 *st);
u32 func_021CF220(u8 *p, int *st);
u32 func_021CF2F0(u8 *p, s32 *st);
void func_021CF360(u8 *p);
void func_021CF37C(u8 *p,u32 i,u32 v);
void func_021CF3B8(u8 *p, u32 i);
void func_021CF3F8(u8 *p);
void func_021CF41C(u8 *p);

u32 func_021CF078(u8 *p, u32 *st)
{
    u8 id;
    u16 k;
    int result;
    switch (*st) {
    case 0:
        switch (func_021B86E4(((struct Obj02136 *)p)->f0)) {
        default:
        case 0:
            if (func_021CF918(p, &id, &k) == 4) {
                *st = 5;
                break;
            }
            if (k) {
                func_021EAF18((struct L *)(p + 0x58), 2, 0x365);
                func_021EAF50((struct L *)(p + 0x58), id);
                func_021EAF50((struct L *)(p + 0x58), k);
            } else {
                func_021EAF18((struct L *)(p + 0x58), 1, 0x4a);
            }
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 1:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4c);
            func_021CE3B4(p, p + 0x58);
            *st = 1;
            break;
        case 2:
            func_021EAF18((struct L *)(p + 0x58), 1, 0x4d);
            func_021EAF78(p + 0x58, 0xff);
            func_021CE3B4(p, p + 0x58);
            *st = 3;
            break;
        }
        break;
    case 1:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            func_021CE0F8(p, *(u8 * *)&((struct Obj02136 *)p)->f8, p + 0x58);
            func_021EA65C(((struct Obj02136 *)p)->f54, (struct H *)(p + 0x58));
            *st = 2;
        }
        break;
    case 2:
        if (func_021EA710(((struct Obj02136 *)p)->f54))
            func_021CE150(p, (void *)((u32)func_021CE4D0));
        break;
    case 3:
        func_021EA710(((struct Obj02136 *)p)->f54);
        if (func_021EA720(((struct Obj02136 *)p)->f54)) {
            func_021EAF18((struct L *)(p + 0x58), 3, 8);
            func_021EAF18((struct L *)(p + 0x7c), 3, 9);
            func_021EABC4(((struct Obj02136 *)p)->f54, (u32)(p + 0x58), (u32)(p + 0x7c), 1);
            *st = 4;
        }
        break;
    case 4:
        if (func_021EA710(((struct Obj02136 *)p)->f54)) {
            if (func_021EAC54(((struct Obj02136 *)p)->f54, &result)) {
                if (result == 0)
                    *st = 5;
                else
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
            } else if (func_021CE08C(p)) {
                func_021CE150(p, (void *)((u32)func_021CE3C8));
            }
        }
        break;
    case 5:
        func_021D8414(((struct Obj02136 *)p)->fC);
        p[0x1b2] |= 4;
        func_021CE150(p, (void *)((u32)func_021CF220));
        break;
    }
    return 0;
}

u32 func_021CF220(u8 *p, int *st)
{
    u8 n;
    void *q;
    switch (*st) {
    case 0:
        func_021E9964(((struct Obj00888 *)p)->f54);
        ++*st;
        break;
    case 1:
        if (func_021E9974(((struct Obj00888 *)p)->f54)) {
            ++p[0x11d];
            if (p[0x11d] < p[0x11c]) {
                if ((((u32)p[0x1b2] << 29) >> 31) == 0) {
                    func_021CE150(p, (void *)((u32)func_021CE4D0));
                    break;
                }
                while (p[0x11d] < p[0x11c]) {
                    q = func_021B990C((char *)(((struct Obj00888 *)p)->f4), p[0x1a6], p[0x11d]);
                    if (!func_021CF470(p, q, p + 0x124 + p[0x11d] * 4))
                        func_021D8434((u32 *)(p + 0x124 + p[0x11d] * 4));
                    ++p[0x11d];
                }
            }
            if (p[0x11d] >= p[0x11c]) {
                n = p[0x11c] + p[0x1af];
                p[0x1af] = 0;
                *(u8 * *)&((struct Obj00888 *)p)->fD8 = p + 0x124;
                ((struct Obj00888 *)p)->fDC = n * 4;
                func_021CE150(p, (void *)((u32)func_021CF2F0));
            }
        }
        break;
    }
    return 0;
}


u32 func_021CF2F0(u8 *p, s32 *st)
{
    switch (*st) {
    case 0:
        func_021CF3F8(p);
        if (func_021B86C0(*(u8 ** *)&((struct Obj07772 *)p)->f0) != 0) {
            p[0x1a9] = 1;
            func_021EA7FC((char *)(*(u32 *)&((struct Obj07772 *)p)->f54));
            *st = *st + 1;
        } else {
            *st = *st + 2;
        }
        break;
    case 1:
        if (func_021EA814(*(u32 * *)&((struct Obj07772 *)p)->f54) != 0) {
            *st = *st + 1;
        }
        break;
    case 2:
        if (func_021F7EB4() == 0) {
            func_021CE0E0(p);
            *st = *st + 1;
            return 1;
        }
        break;
    default:
        return 1;
    }
    return 0;
}

void func_021CF360(u8 *p) { u32 i; for(i=0;i<3;i++) *(u16 *)(p+0x1a0+i*2)=0; }

void func_021CF37C(u8 *p,u32 i,u32 v) { if(p[0x1aa]==0) { if(p[0x1a6]==func_021B8FF4(*(u8 * *)&((struct Obj06234 *)p)->f0)) { *(u16 *)(p+0x1a0+i*2)=v; func_021B9090(*(u8 * *)&((struct Obj06234 *)p)->f0,p[0x1a6],v); } } }

/*
 * lever: func_021B90BC consumes the live r2 halfword as its third argument;
 * its matched body forwards it to func_02007E50.
 */
void func_021CF3B8(u8 *p, u32 i)
{
    if (p[0x1aa] == 0) {
        if (p[0x1a6] == func_021B8FF4(*(u8 * *)&((struct Obj05200 *)p)->f0)) {
            u16 *a = (u16 *)(p + 0x1a0);
            u32 v = a[i];
            if (v != 0) {
                a[i] = 0;
                func_021B90BC(*(u8 * *)&((struct Obj05200 *)p)->f0, p[0x1a6], v);
            }
        }
    }
}

void func_021CF3F8(u8 *p) { u32 i; if(p[0x1aa]==0) for(i=0;i<3;i++) func_021CF3B8(p,(u8)i); }

void func_021CF41C(u8 *p) { func_02082BCC(p+0x130,0,3); }
