/*
 * file:     dup_fitting_item_p06.c
 * unit:     yes
 * function: func_021B8680, func_021B8930, func_021B8A30
 * address:  0x021B8680
 * region:   ov133
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021BA57C 0x021BA57C data a4
 *   d_021BA5AC 0x021BA5AC data a4
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA22C 0x021BA22C thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA24C 0x021BA24C thumb ov133
 *   func_021B8254 0x021B8254 thumb ov133
 *   func_021BA258 0x021BA258 thumb ov133
 *   func_021F5450 0x021F5450 thumb ov112
 *   func_021F4B24 0x021F4B24 thumb ov112
 *   func_021F4EE8 0x021F4EE8 thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021B8444 0x021B8444 thumb ov133
 *   func_021BA238 0x021BA238 thumb ov133
 *   func_021B82E8 0x021B82E8 thumb ov133
 *   _fflt 0x0209BDBC arm
 *   _fadd 0x0209C95C arm
 *   _fsub 0x0209CB8C arm
 *   _ffix 0x0209C494 arm
 *   _fdiv 0x0209CE10 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   func_021B8BB4 0x021B8BB4 thumb ov133
 *   func_021F50F4 0x021F50F4 thumb ov112
 *   func_021B9028 0x021B9028 thumb ov133
 *   func_021B9D54 0x021B9D54 thumb ov133
 *   func_021B765C 0x021B765C thumb ov133
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8AC8 0x021B8AC8 thumb ov133
 */
#include "../../matched/include/Obj00004.h"
#include "../../matched/include/Obj06498.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct { int x,y,z; } Vec;

typedef struct { int x,y; } Pair;

typedef struct { u16 a:2; u16 flag:1; u16 b:13; } Flags;

typedef unsigned int   u32;

typedef signed short s16;

extern unsigned int func_021BA218(u8 *p);
extern void func_021BA22C(u8 *p, const u8 *src);
extern void func_021F4E8C(int,int,Vec *);
extern void func_021BA21C(u8 *p, const u8 *src);
extern void func_021BA24C(char *p, unsigned int v);
extern void func_021B8254(u8 *);
extern unsigned int func_021BA258(char *p);
extern u8 *func_021F5450(u8 *,int);
extern int func_021F4B24(u8 *);
extern void func_021F4EE8(int,Flags *,int);
extern void func_021F4ED4(u32 unused, u32 p, u16 v);
extern void func_021B8444(u8 *);
extern u8 *func_021BA238(u8 *p);
extern void func_021B82E8(u8 *,int);
extern int func_021B8BB4(u8 *, void *, const int *, u16 *);
extern int func_021F50F4(unsigned);
extern void func_021B9028(u8 *, int, u16);
extern void func_021B9D54(u8 *, int);
extern void *func_021B765C(u8 *p, u16 base, s16 speed, u16 rx, u16 ry);
extern void func_020061E4(u32 a);
extern void func_021B8AC8(u8 *);
void func_021B8680(u8 *p);
int func_021B8930(u8 *p);
void func_021B8A30(u8 *p);
extern const Vec d_021BA57C,d_021BA5AC;

/*
 * lever: Unsigned word state local restores the state/sprite register pair; int and long left DIFF7.
 * ABI: func_021F4B24 declared int here: its forwarded func_021F50D0 returns 0/1; original compares the returned r0 despite legacy void declarations.
 */
void func_021B8680(u8 *p)
{
    Vec a,b,c;
    Pair posA,currentB,posB,posC;
    unsigned int state;
    u8 *sprite,*record;
    u16 flag;
    if(((struct Obj00004 *)p)->f40==2) {
        a=d_021BA57C;
        sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        posA.x=((struct Obj00004 *)p)->f1C; posA.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) a.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else a.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) a.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else a.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posA));
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,&a);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        func_021B8254(p);
        return;
    } else if(((struct Obj00004 *)p)->f40==3) {
        u8 *spriteB;
        spriteB=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        state=func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38));
        record=func_021F5450(*(u8 * *)&((struct Obj00004 *)p)->f1880,state);
        posB.x=(int)((float)(((struct Obj06498 *)record)->f4+((struct Obj06498 *)record)->f10)/4096.0f)+128;
        posB.y=(int)((float)(((struct Obj06498 *)record)->f8+((struct Obj06498 *)record)->f14)/4096.0f)+96;
        if(posB.x>0) b.x=(int)(0.5f+(float)(posB.x<<12));
        else b.x=(int)((float)(posB.x<<12)-0.5f);
        if(posB.y>0) b.y=(int)(0.5f+(float)(posB.y<<12));
        else b.y=(int)((float)(posB.y<<12)-0.5f);
        if(func_021F4B24(spriteB)==1) b.z=102<<10;
        else if(func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==7 || func_021BA258((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38))==8) b.z=222<<10;
        else b.z=202<<10;
        flag=((struct Obj06498 *)record)->f36;
        func_021F4EE8(*(int *)&((struct Obj00004 *)p)->f1884,(Flags *)spriteB,1);
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884,(int)spriteB,&b);
        func_021F4ED4(*(int *)&((struct Obj00004 *)p)->f1884,(int)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38),flag);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posB));
        currentB.x=((struct Obj00004 *)p)->f1C; currentB.y=*(int *)&((struct Obj00004 *)p)->f20;
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&currentB));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        ((struct Obj00004 *)p)->f34=state;
        func_021B8444(p);
        ((struct Obj00004 *)p)->f34=10;
        return;
    } else if(((struct Obj00004 *)p)->f40==1) {
        func_021BA238(*(u8 * *)&((struct Obj00004 *)p)->f38);
        c=d_021BA5AC;
        sprite=(u8 *)func_021BA218(*(u8 * *)&((struct Obj00004 *)p)->f38);
        func_021BA21C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(p+0x44));
        func_021BA24C((char *)(*(u8 * *)&((struct Obj00004 *)p)->f38),10);
        posC.x=((struct Obj00004 *)p)->f1C; posC.y=*(int *)&((struct Obj00004 *)p)->f20;
        if(((struct Obj00004 *)p)->f44>0) c.x=(int)(0.5f+(float)(((struct Obj00004 *)p)->f44<<12));
        else c.x=(int)((float)(((struct Obj00004 *)p)->f44<<12)-0.5f);
        if(((struct Obj00004 *)p)->f48>0) c.y=(int)(0.5f+(float)(((struct Obj00004 *)p)->f48<<12));
        else c.y=(int)((float)(((struct Obj00004 *)p)->f48<<12)-0.5f);
        func_021BA22C(*(u8 * *)&((struct Obj00004 *)p)->f38,(const u8 *)(&posC));
        func_021F4E8C(*(int *)&((struct Obj00004 *)p)->f1884,(int)sprite,&c);
        func_021B82E8(p,1);
        return;
    }
    func_021B82E8(p,0);
}

/*
 * lever: Assign mode = 8 after the sort call; the compiler hoists its saved-register assignment between the r0 and r1 argument setups.
 * checks: 1 8BB4/9D54/765C arities verified; 2 matched/pending ov133 callers agree; 3 unsigned-long phase and long mode both DIFF4; 4 early-return/assignment-argument/volatile idioms tested; 5 fresh idiom listing and neighbours reread, stack pair already matches; permuter 300 baseline DIFF4 unchanged; next lever would be inline wrapper argument binding.
 * volatile: 0x021B89AC stores A4; 0x021B89B0 rereads that word for func_021B9D54.
 */
int func_021B8930(u8 *p)
{
    int pos[2];
    u16 limit = 16;
    u16 start;
    u32 phase;
    int mode = 0;
    int index;
    phase = ((struct Obj00004 *)p)->f1834 + 0x19249;
    if (phase >= ((struct Obj00004 *)p)->fA8 * 4681u)
        start = (phase - ((struct Obj00004 *)p)->fA8 * 4681u) / 4681u;
    else start = phase / 4681u;
    pos[0] = ((struct Obj00004 *)p)->f1C - 128;
    pos[1] = *(int *)&((struct Obj00004 *)p)->f20 - 112;
    index = func_021B8BB4(p, 0, pos, &limit);
    if (index != 10) {
    mode = func_021F50F4(index);
    if (mode == 7) mode = 6;
    if (mode == ((struct Obj00004 *)p)->fA4) {
        func_021B9028(p, 8, start);
        mode = 8;
    } else func_021B9028(p, mode, start);
    ((struct Obj00004 *)p)->fA4 = mode;
    func_021B9D54(p, *(volatile int *)&((struct Obj00004 *)p)->fA4);
    ((struct Obj00004 *)p)->f98 = 1;
    *(int *)&((struct Obj00004 *)p)->f9C = 0;
    ((struct Obj00004 *)p)->fA0 = ((struct Obj00004 *)p)->f182C % 4681 + 65536;
    if (((struct Obj00004 *)p)->fA0 >= 65536 && ((struct Obj00004 *)p)->fA0 <= 65538)
        ((struct Obj00004 *)p)->fA0 += 4681;
    func_021B765C(p, ((struct Obj00004 *)p)->f182C, 0, 72, 48);
    func_020061E4(1576);
    return 1;
    }
    return mode;
}

void func_021B8A30(u8 *p)
{
    u32 delta = ((struct Obj00004 *)p)->fA0 - ((struct Obj00004 *)p)->f9C;
    u32 step = delta / 10u;
    if (step < 256) {
        if (delta < 256) {
            step = delta;
            ((struct Obj00004 *)p)->f98 = 0;
        } else step = 256;
    }
    if (delta > 4096) {
        ((struct Obj00004 *)p)->f1838 -= 512;
        if (((struct Obj00004 *)p)->f1838 < -12288) ((struct Obj00004 *)p)->f1838 = -12288;
    } else func_021B8AC8(p);
    ((struct Obj00004 *)p)->f9C += step;
    ((struct Obj00004 *)p)->f182C -= (u16)step;
    func_021B765C(p, ((struct Obj00004 *)p)->f182C, step, 72, 48);
}
