/*
 * file:     unit_021E5680_p02.c
 * unit:     yes
 * function: func_021E5C64, func_021E5D84, func_021E5DFC, func_021E5EF8, func_021E5F14
 * address:  0x021E5C64
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_02040618 0x02040618 arm
 *   func_02049238 0x02049238 arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_020450F0 0x020450F0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045374 0x02045374 arm
 *   func_02045334 0x02045334 arm
 *   d_021E81D4 0x021E81D4 data a4
 *   func_0204B3DC 0x0204B3DC arm
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B878 0x0204B878 arm
 *   func_02027694 0x02027694 thumb
 *   func_02027698 0x02027698 thumb
 *   func_0202769C 0x0202769C thumb
 *   func_020276A0 0x020276A0 thumb
 *   func_021B6208 0x021B6208 thumb ov067
 *   func_021B629C 0x021B629C thumb ov067
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_021B6284 0x021B6284 thumb ov067
 *   func_020276B4 0x020276B4 thumb
 *   func_020276B8 0x020276B8 thumb
 *   func_020276BC 0x020276BC thumb
 *   func_020276C0 0x020276C0 thumb
 *   func_021E6008 0x021E6008 thumb ov119
 */
#include "../../matched/include/Obj01055.h"
#include "../../matched/include/Obj00001.h"
#include "../../matched/include/Obj06428.h"
#include "../../matched/include/Obj10382.h"
#include "../../matched/include/Obj06429.h"

struct Cfg;
struct Descriptor;
struct MsgBank;
struct Obj;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef struct { u32 x, y; } Pos;

typedef struct { int f0; u32 f4; int f8,fC,f10,f14,f18; u8 b1c,b1d,b1e; } In;

extern void func_02040588(unsigned char which, unsigned char enable);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02041B6C(u32 bit);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_02049238(void *);
extern void func_0201DD78(u32, u32, u32);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *, s16, s16, void *, void *);
extern void func_02045374(struct Cfg *cfg);
extern void func_02045334(struct Descriptor *d);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_020456F8(struct Descriptor *d);
extern void func_0201F7A8(void *desc, u32 kind);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_02017E1C(void *,u32,u32);
extern u32 func_0202136C(u16);
extern void func_0204B878(struct Obj *p, u16 value);
extern u32 func_020275E4(void);
extern u32 func_02027694(void);
extern u32 func_02027698(void);
extern u32 func_0202769C(u32);
extern u32 func_020276A0(u32);
extern void func_021B6208(void *,In *,int,u16);
extern int func_021B629C(void *,int,u8,u8,u8,u16);
extern void func_0204B3B4(struct Obj *p);
extern void func_021B6284(unsigned int *p);
extern u32 func_0201B25C(void *);
extern u32 func_020276B4(void);
extern u32 func_020276B8(void);
extern u32 func_020276BC(u32);
extern u32 func_020276C0(u32);
extern void func_021E6008(char *p, int b, void *c);
void func_021E5C64(char *p);
void func_021E5D84(char *p);
void func_021E5DFC(char *p, int side, void *mon);
void func_021E5EF8(void *p);
void func_021E5F14(char *p, int side, int flag, void *mon);
extern Pos d_021E81D4[26];

void func_021E5C64(char *p)
{
    u32 i;
    void *h;
    func_02040588(4, 0);
    func_02040588(6, 0);
    h = func_020490F4(0x66, ((struct Obj01055 *)p)->f5F4);
    func_02049990(h, 16, 4, 0, (u16)((struct Obj01055 *)p)->f870, 0, 0, ((struct Obj01055 *)p)->f5F4);
    func_02041B6C(4);
    func_02040618(4, 0, -4);
    func_02040618(6, 0, -4);
    func_02049238(h);
    func_0201DD78(1, 2, 15);
    for (i = 0; i < 26; i++) {
        *(void **)(p + i * 4 + 0x750) = (void *)func_020450F0(6, (u8)d_021E81D4[i].x, (u8)d_021E81D4[i].y, 2, 2, 14, 0);
        func_02045CAC((struct MsgBank *)(((struct Obj01055 *)p)->f720), i + 0x35, (void *)(*(int *)&((struct Obj01055 *)p)->f730));
        func_0201C7A4(func_02045770(*(void **)(p + i * 4 + 0x750)), 0, 0, ((struct Obj01055 *)p)->f730, ((struct Obj01055 *)p)->f728);
        func_02045374(*(void **)(p + i * 4 + 0x750));
        func_02045334(*(void **)(p + i * 4 + 0x750));
    }
    func_02041B6C(6);
    func_02040588(4, 1);
    func_02040588(6, 1);
}

/*
 * lever: byte-pointer base keeps counter in r4, element base in r5.
 */
void func_021E5D84(char *p)
{
    unsigned i;
    func_02040588(4, 0);
    func_02040618(4, 0, 0);
    func_02040618(6, 0, 0);
    if (*(int *)&((struct Obj00001 *)p)->fF04) func_0204B3DC((struct Obj *)*(int *)&((struct Obj00001 *)p)->fF04, 1);
    if (((struct Obj00001 *)p)->fF18) func_0204B3DC((struct Obj *)((struct Obj00001 *)p)->fF18, 1);
    for (i = 0; i < 26; i++) {
        if (*(int *)(p + i * 4 + 0x750)) {
            func_020456F8((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            func_0201F7A8((void *)(*(int *)(p + i * 4 + 0x750)), 2);
            func_020452E8((struct Descriptor *)(*(int *)(p + i * 4 + 0x750)));
            *(int *)(p + i * 4 + 0x750) = 0;
        }
    }
    func_02041B6C(6);
}

/*
 * interface: x/y are u8 at 021E5ED6..021E5EE2; ov067's own u16 coordinate prototype is narrowed for this caller.
 * domain: side is 0/1 from 021E1E20/021E1E2C at call 021E1F14, or 2 at call 021E23B2 (r1 set 021E23AE).
 * initialization: both domain arms fill x, y, f0 and b1c; all remaining descriptor fields read by ov067 021B6208 are filled below.
 * note 2026-10-05 (wave D9r lane 131): removed the dead first assignment (`x
 * = side*128;` before `x = side*128+16;`). Game code has no line table, so
 * these were stand-ins. The plain single assignment gives EXACT in --lang
 * c99 and --lang c: the output bytes do not change. Older text in this
 * header that asks for the double assignment is superseded.
 */
void func_021E5DFC(char *p, int side, void *mon)
{
    char *q = p + 0x950;
    In in;
    int x,y;
    int flag = 0;
    u32 species = func_02017E1C(mon,6,0);
    if (func_0202136C(species)) flag = 1;
    if (((struct Obj06428 *)q)->f10) {
        if (!species) func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,0);
        else {
            func_0204B878((struct Obj *)(((struct Obj06428 *)q)->f10),flag);
            func_0204B3DC((struct Obj *)((struct Obj06428 *)q)->f10,1);
        }
        return;
    }
    if (!species) return;
    switch (side) {
    case 0: case 1:
        x = side*128+16; y = 132;
        in.f0 = 1; in.b1c = 12;
        break;
    case 2:
        x = 32; y = 172;
        in.f0 = 0; in.b1c = 6;
        break;
    }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_02027694();
    in.f10 = func_02027698();
    in.f14 = func_0202769C(2);
    in.f18 = func_020276A0(2);
    in.b1d = 0; in.b1e = 1;
    func_021B6208(q,&in,((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f5F4);
    ((struct Obj06428 *)q)->f10 = func_021B629C(q,((struct Obj00001 *)p)->f9C4,x,y,flag,((struct Obj00001 *)p)->f5F4);
}


void func_021E5EF8(void *p)
{
    if (((struct Obj10382 *)p)->f10) {
        func_0204B3B4((struct Obj *)(((struct Obj10382 *)p)->f10));
        func_021B6284(p);
        ((struct Obj10382 *)p)->f10 = 0;
    }
}

/*
 * interface: x is narrowed to u8 at 021E5FE4/021E5FEC although ov067's callee declares u16.
 * initialization: ov067 func_021B6208 reads only the seven words and bytes 1c..1e initialized below.
 * domain: call 021E1F20 loads side from the 0/1 slot initialized at 021E1E20/021E1E2C; call 021E2406 sets side=0 at 021E2400. Thus side*128+108 is 108 or 236.
 */
void func_021E5F14(char *p, int side, int flag, void *mon)
{
    char *q = p + 0x964;
    In in;
    u32 a = func_0201B25C(mon);
    if (((struct Obj06429 *)q)->f10) {
        if (!a) func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,0);
        else func_0204B3DC((struct Obj *)((struct Obj06429 *)q)->f10,1);
        return;
    }
    if (!a) {
        if (!flag) func_021E6008(p,side,(void *)mon);
        return;
    }
    if (flag) { in.f0 = 0; in.b1c = 0; }
    else { in.f0 = 1; in.b1c = 11; }
    in.f4 = 0;
    in.f8 = func_020275E4();
    in.fC = func_020276B4();
    in.f10 = func_020276B8();
    in.f14 = func_020276BC(2);
    in.f18 = func_020276C0(2);
    in.b1d = 0; in.b1e = 1;
    func_021B6208(q,&in,((struct Obj00001 *)p)->f9C4,((struct Obj00001 *)p)->f5F4);
    if (flag) ((struct Obj06429 *)q)->f10 = func_021B629C(q,((struct Obj00001 *)p)->f9C4,244,104,0,((struct Obj00001 *)p)->f5F4);
    else ((struct Obj06429 *)q)->f10 = func_021B629C(q,((struct Obj00001 *)p)->f9C4,side*128+108,24,0,((struct Obj00001 *)p)->f5F4);
}
