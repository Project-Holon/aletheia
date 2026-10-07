/*
 * file:     pokelist_p04.c
 * unit:     yes
 * function: func_021B7034, func_021B7040, func_021B7078, func_021B709C
 * address:  0x021B7034
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020403F4  0x020403F4  arm
 *   func_02050ED4 0x02050ED4 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_0207D63C 0x0207D63C arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020409B4 0x020409B4 arm
 *   func_0204B100  0x0204B100  arm
 *   func_0204B270  0x0204B270  arm
 *   func_0204B294  0x0204B294  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B92C  0x0204B92C  arm
 */
#include "../../matched/include/Obj20855.h"
#include "../../matched/include/Obj00047.h"

struct BgTemplate;
struct Bank;
struct Obj;
typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} R;

void func_020403F4(u32 i);
extern void func_02050ED4(void);
extern unsigned int func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void func_0207D63C(unsigned,unsigned,unsigned,unsigned,unsigned);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(unsigned);
extern void func_020409B4(u32 index);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B92C(struct Obj *p, u32 v);
void func_021B7034(void);
void func_021B7040(unsigned p);
void func_021B7078(const void *p, unsigned id,unsigned type);
void func_021B709C(u8 *p);


void func_021B7034(void)
{
    func_020403F4(0);
}

void func_021B7040(unsigned p) { func_02050ED4(); func_02048AC4((void *)(((struct Obj20855 *)p)->f258)); func_02046788(); func_020403F4(0); func_0207D63C(0x04000050,20,8,16,10); }

void func_021B7078(const void *p, unsigned id,unsigned type) { func_0203FCA0(id,p,type); func_02040588(id,1); func_020414AC(id); func_020409B4(id); }


void func_021B709C(u8 *p)
{
    R b;
    R a;
    int x;
    u32 bank;

    bank = (u32)func_0204B100(10, 8, ((struct Obj00047 *)p)->f0);
    *(u32 *)&((struct Obj00047 *)p)->f1D4 = bank;
    func_0204B270((struct Bank *)bank);
    b.a = 0;
    b.b = 0;
    b.c = 0;
    b.d = 10;
    b.e = 3;
    ((struct Obj00047 *)p)->f1D8 = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1DC = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f198,
                                        ((struct Obj00047 *)p)->f178, ((struct Obj00047 *)p)->f1B4, &b, 0, ((struct Obj00047 *)p)->f0);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1D8, 1);
    func_0204B92C((struct Obj *)((struct Obj00047 *)p)->f1DC, 1);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1D8, 0);
    func_0204B3DC((struct Obj *)((struct Obj00047 *)p)->f1DC, 0);
    a.a = 0xe0;
    a.b = 0xa8;
    a.c = 1;
    a.d = 0;
    a.e = 0;
    x = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E0 = x;
    func_0204B92C((struct Obj *)x, 1);
    a.a = 0xc4;
    a.c = 0;
    x = (int)func_0204B294((void *)((struct Obj00047 *)p)->f1D4, ((struct Obj00047 *)p)->f1A0,
                      ((struct Obj00047 *)p)->f17C, ((struct Obj00047 *)p)->f1BC, &a, 0, ((struct Obj00047 *)p)->f0);
    ((struct Obj00047 *)p)->f1E4 = x;
    func_0204B92C((struct Obj *)x, 1);
}
