/*
 * file:     gsync_state_p09.c
 * unit:     yes
 * function: func_021D634C, func_021D63D4, func_021D63E4, func_021D6404, func_021D6458, func_021D651C, func_021D652C, func_021D6548
 * address:  0x021D634C
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B570 0x0204B570 arm
 *   d_021DAACC 0x021DAACC data a4
 *   func_0204B878  0x0204B878  arm
 *   func_020490F4 0x020490F4 arm
 *   func_0201BC3C 0x0201BC3C thumb
 *   func_0204ACEC 0x0204ACEC arm
 *   func_02049238 0x02049238 arm
 *   func_0204AF28 0x0204AF28 arm
 *   d_021DA738 0x021DA738 data a4
 *   d_021DA748 0x021DA748 data a4
 *   func_0201BA68 0x0201BA68 thumb
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0201BBE8 0x0201BBE8 thumb
 *   func_0204B6F4 0x0204B6F4 arm
 *   func_0207E3D0 0x0207E3D0 arm
 *   d_021DAA88 0x021DAA88 data a2
 */
#include "../../matched/include/Obj02836.h"
#include "../../matched/include/Obj22949.h"
#include "../../matched/include/Obj10440.h"
#include "../../matched/include/Obj00343.h"
#include "../../matched/include/Obj02181.h"
#include "../../matched/include/Obj22950.h"
#include "../../matched/include/Obj13977.h"

struct Actor;
struct Obj;
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16;

typedef unsigned int u32;

struct Point { s16 x,y; u16 f4; u8 f6,f7; };

struct Entry { int x,y,n; };

typedef signed int     s32;

struct Pair { int a,b; };

extern void func_0204B3B4(struct Obj *p);
extern struct Obj *func_0204B294(void *, u32, u32, u32, const void *, u16, u16);
extern void func_0204B8C4(struct Obj *p, u32 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void func_0204B570(struct Actor *actor, u32 value);
extern void func_0204B878(struct Obj *p, u16 value);
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0201BC3C(void);
extern int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void func_02049238(void *);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern u32 func_0201BA68(void *mon);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern int func_0201BBE8(void *a0);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern void func_0207E3D0(const void *, int, int);
void func_021D634C(u8 *p, unsigned int i);
void func_021D63D4(u8 *p);
void func_021D63E4(u8 *p);
void func_021D6404(u8 *p);
void func_021D6458(struct Obj02181 *p, void *n, int i);
void func_021D651C(u8 *p);
void func_021D652C(char *p);
void func_021D6548(void *unused, u8 *p);
extern struct Entry d_021DAACC[];
extern const struct Pair d_021DA738, d_021DA748;
extern const u16 d_021DAA88[10];

/*
 * lever: indexed p+0x74 array base and non-const table retain the original scheduling.
 */
void func_021D634C(u8 *p, unsigned int i)
{
    struct Point pt;
    if (*(void **)(p + i*4 + 0x74)) func_0204B3B4(*(void **)(p+i*4+0x74));
    pt.x = d_021DAACC[i].x; pt.y = d_021DAACC[i].y;
    pt.f4 = i; pt.f6 = d_021DAACC[i].n; pt.f7 = 1;
    ((void **)(p + 0x74))[i] = func_0204B294((void *)((struct Obj02836 *)p)->fC, (u32)((struct Obj02836 *)p)->f38, ((struct Obj02836 *)p)->f20, ((struct Obj02836 *)p)->f54, &pt, 0, ((struct Obj02836 *)p)->f43C4);
    func_0204B8C4(((void **)(p+0x74))[i],0);
    func_0204B92C(((void **)(p+0x74))[i],1);
    func_0204B3DC(((void **)(p+0x74))[i],1);
    func_0204B570(((void **)(p+0x74))[i],2);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021D63D4(u8 *p)
{
    func_0204B878(((struct Obj22949 *)p)->fA8, 2);
}

void func_021D63E4(u8 *p){int i;for(i=0;i<16;i++){u8 *q=p+i*4;if(*(struct Obj * *)&((struct Obj10440 *)q)->f74){func_0204B3B4(*(struct Obj * *)&((struct Obj10440 *)q)->f74);((struct Obj10440 *)q)->f74=0;}}}

void func_021D6404(u8 *p)
{
    void *h;
    h = func_020490F4(7, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f28 = (void *)func_0204ACEC(h, func_0201BC3C(), 2, 0, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
    h = func_020490F4(143, ((struct Obj00343 *)p)->f43C4);
    ((struct Obj00343 *)p)->f5C = (void *)func_0204AF28(h, 14, 27, ((struct Obj00343 *)p)->f43C4);
    func_02049238(h);
}

void func_021D6458(struct Obj02181 *p, void *n, int i)
{
    struct Pair a = d_021DA738;
    struct Pair b = d_021DA748;
    struct Point pt;
    void *h;
    h = func_020490F4(7, p->f43C4);
    p->f40 = (void *)func_0204A6C8(h,func_0201BA68((void *)n),0,2,p->f43C4);
    if(i==0) { pt.x=a.b; pt.y=b.b; }
    else { pt.x=a.a; pt.y=b.a; }
    pt.f4=0; pt.f6=3; pt.f7=1;
    p->fA8 = func_0204B294((void *)p->fC,(unsigned int)p->f40,p->f28,p->f5C,&pt,(u16)i,p->f43C4);
    func_0204B92C(p->fA8,0);
    func_0204B3DC(p->fA8,1);
    func_0204B6F4(p->fA8,func_0201BBE8(n),1);
    func_02049238(h);
}


void func_021D651C(u8 *p)
{
    func_0204B92C(((struct Obj22950 *)p)->fA8, 1);
}


void func_021D652C(char *p)
{
    func_0204B878(((struct Obj13977 *)p)->fA8, 1);
    func_0204B92C(((struct Obj13977 *)p)->fA8, 1);
}

void func_021D6548(void *unused, u8 *p)
{
    int line;
    int idx;
    int d;
    int v;
    idx = *(s16 *)(p + 0x43C6) + 1;
    line = *(volatile u16 *)0x04000006;
    idx = (line + idx) % 0xC0;
    if (*(volatile u16 *)0x04000004 & 2) {
        *(volatile u32 *)0x0400001C = *(s16 *)(p + 0x43C8 + idx * 2) & 0x1FF;
        v = *(int *)(p + 0x455C);
        if (v >= 0xC0) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v == 0) {
            func_0207E3D0(&d_021DAA88[9], 0x142, 2);
            return;
        }
        if (line > 200) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        if (v > line) {
            func_0207E3D0(d_021DAA88, 0x142, 2);
            return;
        }
        d = line - v;
        if ((u32)d < 10 && d >= 0) {
            func_0207E3D0(&d_021DAA88[d], 0x142, 2);
            return;
        }
        func_0207E3D0(&d_021DAA88[9], 0x142, 2);
    }
}
