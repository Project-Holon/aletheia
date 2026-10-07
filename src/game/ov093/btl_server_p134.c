/*
 * file:     btl_server_p134.c
 * unit:     yes
 * function: func_021CE170, func_021CE1B0, func_021CE2E8, func_021CE308
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
 *   func_021CE4D0  0x021CE4D0  thumb  ov093
 */
#include "../../matched/include/Obj01893.h"
#include "../../matched/include/Obj07769.h"
#include "../../matched/include/Obj03688.h"

struct L;
struct H;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef signed short s16;

typedef signed int s32;

typedef struct { u8 a : 5; u8 flag : 1; } Flags_021CE1B0;

typedef struct { u32 kind : 4; u32 rest : 28; } Command;

typedef struct { u8 a : 2; u8 f : 1; } Flags_021CE308;

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
extern int func_021CE4D0(u8 *p, u32 *st);
u32 func_021CE170(u8 *p, s32 *st);
int func_021CE1B0(u8 *p,int *state);
void func_021CE2E8(u8 *p);
u32 func_021CE308(u8 *p);


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
