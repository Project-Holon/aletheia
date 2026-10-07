/*
 * file:     script_command_p03.c
 * unit:     yes
 * function: func_021FA558, func_021FA56C, func_021FA57C, func_021FA5B0, func_021FA64C, func_021FA6CC, func_021FA7E0, func_021FA99C, func_021FAAB8
 * address:  0x021FA558
 * region:   ov132
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02040618 0x02040618 arm
 *   func_02030734 0x02030734 arm
 *   d_021FDCD8 0x021FDCD8 data a4
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020307B0 0x020307B0 arm
 *   table 0x021FDC20 data a1
 *   func_02035C08 0x02035C08 arm
 *   func_0207D658 0x0207D658 arm
 *   func_021F9730 0x021F9730 thumb ov132
 *   func_021F9768 0x021F9768 thumb ov132
 *   func_0204B9A0 0x0204B9A0 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_020355D8 0x020355D8 arm
 *   func_0204B3F4 0x0204B3F4 arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021F9E0C 0x021F9E0C thumb ov132
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_0204ABF0 0x0204ABF0 arm
 *   func_021F4F54 0x021F4F54 thumb ov112
 *   func_021F4F70 0x021F4F70 thumb ov112
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204A1BC 0x0204A1BC arm
 *   func_0206E964 0x0206E964 arm
 *   func_0204ABBC 0x0204ABBC arm
 *   func_020862F0 0x020862F0 arm
 *   func_0207E5D0 0x0207E5D0 arm
 *   func_0207E804 0x0207E804 arm
 */
#include "../../matched/include/Obj23226.h"
#include "../../matched/include/Obj23227.h"
#include "../../matched/include/Obj14092.h"
#include "../../matched/include/Obj00151.h"
#include "../../matched/include/Obj23228.h"
#include "../../matched/include/Obj23229.h"
#include "../../matched/include/Obj01550.h"
#include "../../matched/include/Obj00914.h"
#include "../../matched/include/Obj04515.h"

struct Bank;
struct Obj;
struct Actor;
struct Vec2;
typedef unsigned char u8;

typedef signed char s8;

typedef unsigned short u16;

typedef signed short s16_021FA558;

typedef unsigned int u32;

typedef signed int s32;

typedef signed short s16_021FA56C;

typedef short s16_021FA6CC;

typedef enum { FLAG_ZERO, FLAG_ONE } Flag;

typedef struct {u8 bytes[12];} Key;

typedef struct {s16_021FA6CC x,y;} Pos;

typedef short s16_021FA7E0;

typedef struct {s16_021FA7E0 x,y,index;u8 a,b;} Params;

extern void func_02040618(unsigned, unsigned, unsigned);
extern void *func_02030734(unsigned, unsigned, int, const char *, u16);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern u32 func_0204B1CC(struct Bank *bank);
extern u32 func_020307B0(void *p);
extern int func_02035C08(const void *);
extern void func_0207D658(unsigned long,int,int);
extern void func_021F9730(char *p, int value);
extern void func_0204B9A0(struct Actor *a);
extern void func_0204B3DC(struct Obj *,unsigned int);
extern void func_0204B404(struct Obj *p, const struct Vec2 *delta, u32 which);
extern void func_020355D8(u8);
extern int func_021F9768(char *p);
extern u32 func_0204B3F4(struct Obj *p);
extern u32 func_0204B98C(struct Actor *a);
extern u32 func_021F9E0C(u8 *p);
extern u8 *func_021F4F54(u8 *,int);
extern int func_021F4F70(int *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_0204B270(struct Bank *bank);
extern void func_02049238(void *);
extern void func_0204B92C(struct Obj *,u32);
extern int func_0204AC18(void *,u32,u32,u32,u16,u16,u16),func_0204A6C8(void *,u32,u32,u32,u16),func_0204AF28(void *,u32,u32,u32),func_0204ABF0(void *,u32,u32,u32,u16);
extern struct Obj *func_0204B294(void *,unsigned int,unsigned int,unsigned int,const void *,u16,u16);
extern int func_0204A1BC(int,int,int,int);
extern unsigned char *func_0206E964(unsigned char *p);
extern int func_0204ABBC(u32 idx, u32 flag);
extern void func_020862F0(void *,u32);
extern void func_0207E5D0(const void *,u32,u32);
extern void func_0207E804(const void *,void *,u32);
void func_021FA558(char *p, int i, int v);
void func_021FA56C(char *p, u8 v);
void func_021FA57C(void *unused, int x);
char *func_021FA5B0(unsigned heap, void *a, char *b);
void func_021FA64C(char *p);
void func_021FA6CC(char *p);
void func_021FA7E0(char *p);
void func_021FA99C(u8 *p,u16 slot,int resource,u32 type);
void func_021FAAB8(char *p, unsigned flag);
extern const char d_021FDCD8[];
extern const Key table;


void func_021FA558(char *p, int i, int v)
{
    char *q = p + i * 4;

    ((struct Obj23227 *)q)->f1EC = v;
    ((struct Obj23226 *)p)->f200 = 1;
}


void func_021FA56C(char *p, u8 v)
{
    ((struct Obj14092 *)p)->f1FC = v;
    ((struct Obj14092 *)p)->f200 = 1;
}

void func_021FA57C(void *unused, int x)
{
    u16 v = ((x << 7) / 256) + 64;
    func_02040618(4, 0, v);
    func_02040618(6, 0, v);
    func_02040618(5, 0, v);
}

static inline void inside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x04001048 & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x04001048 = tmp;
}

static inline void outside(int wnd, int effect)
{
    unsigned tmp = (*(volatile u16 *)0x0400104a & ~63) | (unsigned)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400104a = tmp;
}

/*
 * volatile: hardware register reads and writes at 021FA5FA..021FA634.
 */
char *func_021FA5B0(unsigned heap, void *a, char *b)
{
    char *p = func_02030734(heap, 0x60, 0, d_021FDCD8, 87);
    ((struct Obj00151 *)p)->f0 = heap;
    ((struct Obj00151 *)p)->f4 = a;
    *(char * *)&((struct Obj00151 *)p)->f8 = b;
    ((struct Obj00151 *)p)->fC = 0;
    ((struct Obj00151 *)p)->f10 = 0;
    ((struct Obj00151 *)p)->f14 = 2;
    ((struct Obj00151 *)p)->f48 = ((struct Obj23228 *)b)->f3E;
    ((struct Obj00151 *)p)->f4A = ((struct Obj23229 *)(*(char * *)&((struct Obj00151 *)p)->f8))->f44;
    ((struct Obj00151 *)p)->f40 = 0;
    ((struct Obj00151 *)p)->f44 = 0;
    func_021FA7E0(p);
    *(volatile unsigned *)0x04001000 = (*(volatile unsigned *)0x04001000 & ~0xe000) | 0x2000;
    inside(31, 1);
    outside(31, 0);
    *(volatile u16 *)0x04001040 = 255;
    *(volatile u16 *)0x04001044 = 0x80c0;
    return p;
}

/*
 * volatile: hardware control read at 021FA652 and store 021FA658.
 */
void func_021FA64C(char *p)
{
    *(volatile unsigned *)0x04001000 &= ~0xe000;
    if (((struct Obj01550 *)p)->f48 != 255) func_0204B3B4(((struct Obj01550 *)p)->f4C);
    if (((struct Obj01550 *)p)->f4A != 255) func_0204B3B4(((struct Obj01550 *)p)->f50);
    func_0204B3B4(((struct Obj01550 *)p)->f5C);
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f1C));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f28));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f34));
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f20));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f2C));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f38));
    func_0204ADA4((u32)(((struct Obj01550 *)p)->f24));
    func_0204A8D4((u32)(((struct Obj01550 *)p)->f30));
    func_0204AFD8((u32)(((struct Obj01550 *)p)->f3C));
    func_0204B1CC(((struct Obj01550 *)p)->f18);
    func_020307B0(p);
}

/*
 * checks: 1 fresh 9730/9768 show and 25EA4/23F60/B3DC/B9A0/B98C bodies confirm arities; 2 fresh A5B0/A64C/A7E0 no full twin; 3 u8/const-char pointer unchanged; 4 struct-field, chained-assignment and enum-zero idioms; 5 fresh directory/neighbours.
 * spelling: enum-typed one/zero locals retain separate constant webs; literals and enum-typed stores alone left six differing bytes. Prior permuter300 was not repeated.
 */
void func_021FA6CC(char *p)
{
    Key key;
    Pos pos;
    int hit;
    Flag one,zero;
    if(((struct Obj00914 *)p)->fC==1) {
        key=table;
        hit=func_02035C08(&key);
        func_0207D658(0x04001050,16,0);
        if(hit!=-1 && *(u16 *)(p+0x48+hit*2)!=255 && *(int *)(p+0x40+hit*4)==0) {
            if(hit==0) func_021F9730(((struct Obj00914 *)p)->f4,7);
            else func_021F9730(((struct Obj00914 *)p)->f4,8);
            func_0207D658(0x04001050,16,-8);
            one=FLAG_ONE;
            zero=FLAG_ZERO;
            *(u32 *)(p+0x40+hit*4)=one;
            *(u32 *)&((struct Obj00914 *)p)->f10=one;
            *(u32 *)&((struct Obj00914 *)p)->fC=zero;
            ((struct Obj00914 *)p)->f14=hit;
            pos.x=hit==0?32:224;
            pos.y=128;
            func_0204B9A0(((struct Obj00914 *)p)->f5C);
            func_0204B3DC(((struct Obj00914 *)p)->f5C,1);
            func_0204B404(((struct Obj00914 *)p)->f5C,(const struct Vec2 *)(&pos),1);
            func_020355D8(1);
        }
    }
    if(((struct Obj00914 *)p)->f14!=2) {
        if(func_021F9768(((struct Obj00914 *)p)->f4)==0) {
            if(((struct Obj00914 *)p)->f10==0) {
                ((struct Obj00914 *)p)->fC=1;
                func_0204B3DC(*(void **)(p+0x4c+((struct Obj00914 *)p)->f14*4),0);
                func_0204B3DC(*(void **)(p+0x54+((struct Obj00914 *)p)->f14*4),0);
                ((struct Obj00914 *)p)->f14=2;
            }
        } else {
            if(((struct Obj00914 *)p)->f10==1) ((struct Obj00914 *)p)->f10=0;
        }
    }
    if(func_0204B3F4(((struct Obj00914 *)p)->f5C)==1) {
        if(func_0204B98C(((struct Obj00914 *)p)->f5C)==0) func_0204B3DC(((struct Obj00914 *)p)->f5C,0);
    }
}

/*
 * extent: 021FA99A zero halfword is alignment padding before labelled 021FA99C.
 * ABI: B294 forwards an address-valued u32 payload and returns the actor in r0; ABF0 tail-forwards AC18's index despite void declaration.
 */
void func_021FA7E0(char *p)
{
    Params configs[2];
    u8 *table;
    void *narc;
    u8 i=0;
    int format;
    table=(u8 *)func_021F9E0C((u8 *)(*(char * *)&((struct Obj00151 *)p)->f4));
    ((struct Obj00151 *)p)->f18=func_0204B100(5,0,((struct Obj00151 *)p)->f0);
    func_0204B270(((struct Obj00151 *)p)->f18);
    narc=func_020490F4(47,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f1C=func_0204AC18(narc,0,1,0,0,2,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f28=func_0204A6C8(narc,6,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f34=func_0204AF28(narc,18,21,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f20=func_0204AC18(narc,1,1,64,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f2C=func_0204A6C8(narc,7,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f38=func_0204AF28(narc,19,22,((struct Obj00151 *)p)->f0);
    func_02049238(narc);
    narc=func_020490F4(46,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f24=func_0204ABF0(narc,0,1,96,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f30=func_0204A6C8(narc,26,0,1,((struct Obj00151 *)p)->f0);
    *(int *)&((struct Obj00151 *)p)->f3C=func_0204AF28(narc,18,22,((struct Obj00151 *)p)->f0);
    func_02049238(narc);
    for(i=0;i<2;i++) {
        if(*(u16 *)(p+i*2+0x48)!=255) {
            format=func_021F4F70((int *)func_021F4F54(table,*(u16 *)(p+i*2+0x48)));
            if(i==0) configs[1].x=32;
            else configs[1].x=224;
            configs[1].y=160;
            configs[1].index=i;
            configs[1].a=10;
            configs[1].b=0;
            *(void **)(p+i*4+0x4c)=func_0204B294((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f28,((struct Obj00151 *)p)->f1C,((struct Obj00151 *)p)->f34,&configs[1],1,((struct Obj00151 *)p)->f0);
            configs[1].index=0;
            *(void **)(p+i*4+0x54)=func_0204B294((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f2C,((struct Obj00151 *)p)->f20,((struct Obj00151 *)p)->f38,&configs[1],1,((struct Obj00151 *)p)->f0);
            func_0204B3DC(*(void **)(p+i*4+0x4c),0);
            func_0204B3DC(*(void **)(p+i*4+0x54),0);
            func_021FA99C((u8 *)p,i,*(u16 *)(p+i*2+0x48),format);
        }
    }
    configs[0].x=128; configs[0].y=96; configs[0].index=0;configs[0].a=0;configs[0].b=0;
    ((struct Obj00151 *)p)->f5C=func_0204B294((void *)*(u32 *)&((struct Obj00151 *)p)->f18,((struct Obj00151 *)p)->f30,((struct Obj00151 *)p)->f24,((struct Obj00151 *)p)->f3C,&configs[0],1,((struct Obj00151 *)p)->f0);
    func_0204B3DC(((struct Obj00151 *)p)->f5C,0);
    func_0204B92C(((struct Obj00151 *)p)->f5C,1);
}

/*
 * note 2026-10-05: copies a tile sheet into VRAM in 4-byte pieces (block x line x column).
 * func_0204ABBC returns a pointer (the matched ov119 021E6E7C and ov131 021DBCF4 use it so),
 * which removed the old prototype blocker. Levers: locals declared in the order of the
 * frame slots (dst, block, height, line, y, x, src), u16 slot (puts its entry spill first),
 * u8 height, case 50 reads x = y, and y = 0 written after the blob call (literal 0 in it).
 */
void func_021FA99C(u8 *p,u16 slot,int resource,u32 type)
{
    int blob;
    u32 charSize,palSize;
    u8 *dst;
    u8 block;
    u8 height;
    u8 line;
    u32 y;
    u32 x;
    u8 *src;
    u8 *tex;
    u32 palOffset;
    u8 col;
    blob=func_0204A1BC(45,resource,0,*(u16 *)p);
    y=0;
    tex=func_0206E964((unsigned char *)blob);
    src=tex+*(u32 *)(tex+20);
    charSize=*(u16 *)(tex+12)*8;
    palOffset=*(u32 *)(tex+0x38);
    palSize=*(u16 *)(tex+0x30)*8;
    dst=(u8 *)func_0204ABBC(*(u32 *)(p+0x28),1);
    dst+=(slot<<11);
    func_020862F0(tex+palOffset,palSize);
    func_0207E5D0(tex+palOffset,slot*32,palSize);
    func_020862F0(src,charSize);
    switch(type) {
    case 34: x=2; y=2; type=4; height=4; break;
    case 35: x=2; type=4; height=8; break;
    case 50: x=y; y=2; type=8; height=4; break;
    default: x=2; y=2; type=4; height=4; break;
    }
    for(block=0;block<height;block++) {
        for(line=0;line<8;line++) {
            for(col=0;col<type;col++) {
                func_0207E804(src+(col*4+(block*32*type+line*type*4)),dst+(line*4+((col+x)*32+((block+y)*256))),4);
            }
        }
    }
    func_020307B0((void *)blob);
}

void func_021FAAB8(char *p, unsigned flag)
{
    if (((struct Obj04515 *)p)->f48 != 255) {
        func_0204B3DC(((struct Obj04515 *)p)->f4C, flag);
        func_0204B3DC(((struct Obj04515 *)p)->f54, flag);
    }
    if (((struct Obj04515 *)p)->f4A != 255) {
        func_0204B3DC(((struct Obj04515 *)p)->f50, flag);
        func_0204B3DC(((struct Obj04515 *)p)->f58, flag);
    }
    ((struct Obj04515 *)p)->fC = flag;
}
