/*
 * file:     unit_021B7560_p08.c
 * unit:     yes
 * function: func_021B8880, func_021B89DC, func_021B8A88, func_021B8ADC, func_021B8AEC
 * address:  0x021B8880
 * region:   ov104
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B87F4 0x021B87F4 thumb ov104
 *   _u32_div_f 0x0209C2B0 arm
 *   d_020A1B38 0x020A1B38 data a2
 *   func_02061CA4 0x02061CA4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021B7968 0x021B7968 thumb ov104
 *   func_021B8D08 0x021B8D08 thumb ov104
 *   func_020056EC 0x020056EC thumb
 *   func_021B8E8C 0x021B8E8C thumb ov104
 *   func_021B8DA4 0x021B8DA4 thumb ov104
 *   func_021B8D20 0x021B8D20 thumb ov104
 *   g_020A1B38 0x020A1B38 data a2
 */
#include "../../matched/include/Obj10248.h"

#define W(o) (*(u32 *)(p+(o)))
#define SHIFT(v,n) ((int)((u32)(v)<<(n)))
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct { int words[33]; } Block;

typedef short s16;

typedef signed int     s32;

typedef enum { COLOR_TWO=2, COLOR_FIVE=5 } Color;

typedef enum { END_Y=-36 } EndY;

typedef struct { int x; long y; } Point;

extern void func_021B87F4(u8 *, Block *);
extern s32 func_02061CA4(void *p, u32 a, u32 b, s32 size);
extern void func_02082BCC(void *,int,int);
extern int func_021B7968(u8 *p, int i);
extern void func_021B8D08(unsigned int *p, unsigned int a, int b);
extern u32 func_020056EC(u32);
extern u32 func_021B8E8C(u8 *);
extern void func_021B8DA4(u8 *,const Point *,const Point *,int,u32);
extern void func_021B8D20(u8 *);
int func_021B8880(u8 *p);
s32 func_021B89DC(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2);
void func_021B8A88(u8 *p,void *a,int b,int c,int d);
void func_021B8ADC(void *p);
void func_021B8AEC(u8 *p);
extern const s16 d_020A1B38[];
extern const s16 g_020A1B38[];

/*
 * lever: Direct word indexing retains the second stack record's base across the call.
 */
int func_021B8880(u8 *p) {
 Block a; Block b; int d; u32 score, sum; int i; Block *bp;
 a=*(Block *)(p+0x814);
 bp=&b;
 func_021B87F4(p+0xe0,bp);
 d=a.words[(*(u16 *)((u8 *)&a+120)-1)*2]-a.words[0]
  -(b.words[(*(u16 *)((u8 *)&b+120)-1)*2]-b.words[0]);
 if(d<0) d=-d;
 if(d==0) score=100;
 else if((u32)d<500) score=90;
 else if((u32)d<1000) score=80;
 else if((u32)d<3000) score=70;
 else if((u32)d<5000) score=60;
 else if((u32)d<10000) score=50;
 else if((u32)d<15000) score=40;
 else if((u32)d<20000) score=30;
 else if((u32)d<25000) score=20;
 else if((u32)d<30000) score=10;
 sum=0;
 for(i=1;i<10;i++) {
  d=*(int *)((u32)&a+i*8+4)-*(int *)((u32)&b+i*8+4);
  if(d<0) d=-d;
  if(d==0) sum+=100;
  else if((u32)d<50) sum+=90;
  else if((u32)d<100) sum+=80;
  else if((u32)d<200) sum+=70;
  else if((u32)d<300) sum+=60;
  else if((u32)d<400) sum+=50;
  else if((u32)d<500) sum+=40;
  else if((u32)d<600) sum+=30;
  else if((u32)d<1000) sum+=20;
  else if((u32)d<15000) sum+=10;
 }
 return (u8)((score+sum/9)/2);
}

static inline u16 blend(int angle,u16 c1,u16 c2) {
 u8 g1,r1,b1; int db,dr,dg; s16 factor;
 g1=(c1&0x3e0)>>5;
 factor=(s16)((d_020A1B38[((angle>>4)*2)+1]+0x1000)/2);
 r1=c1&31;
 b1=(c1&0x7c00)>>10;
 db=(factor*((u8)((c2&0x7c00)>>10)-b1))>>12;
 dr=(factor*((u8)(c2&31)-r1))>>12;
 dg=(factor*((u8)((c2&0x3e0)>>5)-g1))>>12;
 return ((u8)(b1+db)<<10)|((u8)(r1+dr)|((u8)(g1+dg)<<5));
}

/*
 * lever: Byte RGB endpoints and named signed db/dr/dg deltas, with the
 * cosine factor computed after green extraction, retain channel lifetimes.
 * Evidence: ov105_func_021B8734 blend spelling and own ARM9 queue body.
 */
s32 func_021B89DC(int a,u16 *p,int angle,int bank,u8 index,u16 c1,u16 c2) {
 *p=blend(angle,c1,c2);
 return func_02061CA4((void *)a,bank*32+index*2,(u32)p,2);
}

void func_021B8A88(u8 *p,void *a,int b,int c,int d) {
 int i;
 func_02082BCC(p,0,0x534); ((struct Obj10248 *)p)->f528=b;
 ((struct Obj10248 *)p)->f52C=0; ((struct Obj10248 *)p)->f530=10;
 for(i=0;i<30;i++) func_021B8D08((unsigned int *)(p+i*0x2c),(unsigned int)((void *)func_021B7968(a,c+i)),d);
}

void func_021B8ADC(void *p) { func_02082BCC(p,0,0x534); }

static inline void initialize(Point *start,Point *end,int x,EndY endY)
{
    int yy=endY;
    end->y=yy;
    start->x=end->x=x;
    start->y=228;

}

/*
 * lever: named end-Y local stored before the shared X assignment yields the original 336-byte schedule.
 */
void func_021B8AEC(u8 *p)
{
    Point end,start;
    int i,offset,angle;
    u32 life;
    Color color;
    u8 direction;
    switch(W(0x528)) {
    case 0:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    direction=func_020056EC(2);
                    initialize(&start,&end,func_020056EC(256),-36);
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    if(direction) func_021B8DA4(p+offset,&start,&end,color,life);
                    else func_021B8DA4(p+offset,&end,&start,color,life);
                    break;
                }
            }
        }
        break;
    case 1: break;
    case 2:
        if(W(0x52c)++>W(0x530)) {
            W(0x52c)=0;
            for(i=0;i<30;++i) {
                offset=i*44;
                if(!func_021B8E8C(p+offset)) {
                    angle=(u16)func_020056EC(65535)>>4;
                    end.x=SHIFT(g_020A1B38[angle*2],8)>>12;
                    end.y=SHIFT(g_020A1B38[angle*2+1],8)>>12;
                    start.x=128;start.y=96;
                    life=func_020056EC(50)+110;
                    color=2;
                    if(func_020056EC(2)) color=5;
                    func_021B8DA4(p+offset,&end,&start,color,life);
                    break;
                }
            }
        }
        break;
    }
    for(i=0;i<30;++i) func_021B8D20(p+i*44);
}
