/*
 * file:     sta_act_light_p04.c
 * unit:     yes
 * function: func_021F7048, func_021F7098, func_021F709C, func_021F7120, func_021F7160, func_021F718C, func_021F7204
 * address:  0x021F7048
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02047738 0x02047738 arm
 *   func_0204762C 0x0204762C arm
 *   func_02047504 0x02047504 arm
 *   func_02046EFC 0x02046EFC arm
 *   func_020470D0 0x020470D0 arm
 *   func_02030734 0x02030734 arm
 *   func_0204EFC8 0x0204EFC8 arm
 *   d_021F8464 0x021F8464 data a1
 *   func_021F77A0 0x021F77A0 thumb ov112
 *   func_0204F150 0x0204F150 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F732C 0x021F732C thumb ov112
 *   func_021F9E44 0x021F9E44 thumb ov132
 *   func_021F4990 0x021F4990 thumb ov112
 *   func_021F545C 0x021F545C thumb ov112
 *   func_021F5464 0x021F5464 thumb ov112
 *   func_0207C9D0 0x0207C9D0 arm
 *   func_0207AF38 0x0207AF38 thumb
 *   func_0207B51C 0x0207B51C arm
 *   func_0207CA00 0x0207CA00 arm
 *   func_021F5350 0x021F5350 thumb ov112
 *   func_021F5368 0x021F5368 thumb ov112
 *   func_021F535C 0x021F535C thumb ov112
 *   func_021F5424 0x021F5424 thumb ov112
 *   func_020056EC 0x020056EC thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   table 0x020A1B38 data a2
 */
#include "../../matched/include/Obj22556.h"
#include "../../matched/include/Obj13839.h"
#include "../../matched/include/Obj10318.h"
#include "../../matched/include/Obj00904.h"

struct Rec;
struct Tagged;
struct Desc;
typedef unsigned char u8;

typedef struct { int pad[7]; int single; int a[3]; int b; int c[3]; int d; } Cleanup;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short s16;

typedef signed char s8;

typedef int s32;

typedef struct { int pad[5]; int flag; } Record;

typedef struct { int x,y,z; } Vec;

typedef struct { int m[9]; } Mtx;

extern void func_02047738(struct Rec *p);
extern void func_0204762C(struct Rec *p);
extern void func_02047504(struct Rec *p);
extern void func_02046EFC(struct Tagged *p);
extern int func_020470D0(u32 *p);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0204EFC8(struct Desc *desc, u32 a1, u32 a2, u32 a3, u32 a4, u8 a5, u8 a6);
extern void func_021F77A0(char *p, char *q);
extern void func_0204F150(u8 *a0, int i);
extern u32 func_020307B0(void *p);
extern void func_021F732C(unsigned char *self, unsigned char *q);
extern u32 func_021F9E44(u8 *p);
extern void func_021F4990(int);
extern u8 *func_021F545C(u8 *);
extern char *func_021F5464(char *);
extern void func_0207C9D0(const Vec *,const Vec *,Vec *);
extern void func_0207AF38(Mtx *,int,int);
extern void func_0207B51C(const Vec *,const Mtx *,Vec *);
extern void func_0207CA00(const Vec *,const Vec *,Vec *);
extern void func_021F5350(int *p, int *q);
extern void func_021F5368(int *,u16);
extern void func_021F535C(int *p, int *q);
extern void func_021F5424(int,int);
extern u32 func_020056EC(u32);
void func_021F7048(Cleanup *p);
void func_021F7098(u8 *p, u16 v);
u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
void func_021F7120(char *p);
void func_021F7160(u8 *p);
void func_021F718C(char *p);
void func_021F7204(u8 *p,u8 *q);
extern char d_021F8464[];
extern s16 table[];

void func_021F7048(Cleanup *p) {
    u8 i;
    func_02047738((struct Rec *)p->d);
    for (i = 0; i < 3; i++) func_0204762C((struct Rec *)p->c[i]);
    func_02047504((struct Rec *)p->b);
    for (i = 0; i < 3; i++) func_02046EFC((struct Tagged *)p->a[i]);
    func_020470D0((u32 *)p->single);
    func_02046EFC((struct Tagged *)p->single);
    p->single = 0;
}


void func_021F7098(u8 *p, u16 v) { ((struct Obj22556 *)p)->f8 = v; }

u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e)
{
    u8 i = 0;
    u8 *p;
    p = func_02030734(heap, 0x440, 0, d_021F8464, 0x93);
    *(u16 *)p = heap;
    *(u32 *)(p + 4) = b;
    *(u32 *)(p + 0xc) = c;
    *(u32 *)(p + 0x10) = d;
    *(u16 *)(p + 0x434) = i;
    *(u32 *)(p + 8) = e;
    *(u8 *)(p + 0x43c) = i;
    for (i = 0; i < 4; i++) {
        u8 *q = p + i * 0x108;
        *(u32 *)(q + 0x14) = 0;
        *(u32 *)(q + 0x18) = 0;
    }
    *(u32 *)(p + 0x438) = func_0204EFC8((struct Desc *)(*(u32 *)(p + 8)), 0x2f, 0x1d, 3, 0x33, 0x40, 0x40);
    return p;
}

void func_021F7120(char *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1)
            func_021F77A0((char *)((int)p), (char *)((int)(p + 0x14 + i * 0x108)));
    }
    func_0204F150((u8 *)(((struct Obj13839 *)p)->f8), ((struct Obj13839 *)p)->f438);
    func_020307B0((void *)((int)p));
}

/*
 * extent: two zero alignment bytes follow code.
 */
void func_021F7160(u8 *p) { int i; for(i=0;i<4;i++) if(*(int *)(p+i*264+20)==1) func_021F7204(p,p+20+i*264); }

/*
 * extent: two-byte zero padding before 021F7204.
 */
void func_021F718C(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1) {
            func_021F732C((unsigned char *)p, (unsigned char *)(p + 0x14 + i * 0x108));
            if (((struct Obj10318 *)p)->f4 != 0) {
                for (j = 0; j < func_021F9E44((u8 *)(((struct Obj10318 *)p)->f4)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    func_021F4990(((struct Obj10318 *)p)->f10);
}

/*
 * ABI: 5350/535C/5368 forward r1 to6234/624C/6264; complete targets read vector/u16 despite legacy wrapper declarations omitting it.
 * original: delta.z stack slot is untouched before the RotZ multiplication and subtraction, which cancel its contribution; retain original stores only.
 */
void func_021F7204(u8 *p,u8 *q)
{
    Vec pos;
    Vec scale;
    Vec delta;
    Mtx matrix;
    Vec *a;
    Vec *b;
    int angle;
    a=(Vec *)func_021F545C(*(u8 * *)&((struct Obj00904 *)q)->f58);
    b=(Vec *)func_021F5464(*(char * *)&((struct Obj00904 *)q)->f58);
    func_0207C9D0((Vec *)(q+24),(Vec *)(q+48),&pos);
    angle=((struct Obj00904 *)q)->f48;
    delta.x=0;
    delta.y=b->y;
    func_0207AF38(&matrix,-table[(angle>>4)*2],table[(angle>>4)*2+1]);
    func_0207B51C(&delta,&matrix,(Vec *)(q+60));
    func_0207CA00(&delta,(Vec *)(q+60),(Vec *)(q+60));
    pos.x=(pos.x-a->x-((struct Obj00904 *)q)->f3C)/16;
    pos.y=(0xc0000-(pos.y-a->y+((struct Obj00904 *)q)->f40))/16;
    func_021F5350(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&pos));
    func_021F5368(*(int * *)&((struct Obj00904 *)q)->f58,((struct Obj00904 *)q)->f48);
    scale.x=((struct Obj00904 *)q)->f24<<4;
    scale.y=((struct Obj00904 *)q)->f28<<4;
    scale.z=((struct Obj00904 *)q)->f2C<<4;
    if(((struct Obj00904 *)q)->f54==1) scale.x*=-1;
    func_021F535C(*(int * *)&((struct Obj00904 *)q)->f58,(int *)(&scale));
    ((struct Obj00904 *)q)->f4=0;
    if(((struct Obj00904 *)q)->f4C==1) {
        ((struct Obj00904 *)q)->f50+=(u16)func_020056EC(2);
        if(((struct Obj00904 *)q)->f50>120) func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,1);
        else func_021F5424(*(int *)&((struct Obj00904 *)q)->f58,0);
        if(((struct Obj00904 *)q)->f50>125) ((struct Obj00904 *)q)->f50=func_020056EC(120)/3U;
    }
}
