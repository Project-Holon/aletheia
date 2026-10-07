/*
 * file:     br_util_p05.c
 * unit:     yes
 * function: func_021FCE60, func_021FCEDC, func_021FCF54
 * address:  0x021FCE60
 * region:   ov186
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_02035BA4 0x02035BA4 arm
 *   func_02035CB8 0x02035CB8 arm
 *   d_02200AF0 0x02200AF0 data a4
 *   func_020437D4 0x020437D4 arm
 *   func_02082A90 0x02082A90 arm
 */
#include "../../matched/include/Obj00048.h"

struct Descriptor;
struct CharBuf;
struct Bmp;
typedef struct { char pad[0x8C];int bitmap[1]; } View;

typedef unsigned char  u8;

typedef unsigned int   u32;

extern void *func_02045770(struct Descriptor *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *d);
extern int func_02035BA4(const void *);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern void *func_020437D4(const struct Bmp *bmp);
extern void func_02082A90(void *,const void *,unsigned);
void func_021FCE60(char *p,int start);
int func_021FCEDC(char *p);
void func_021FCF54(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height);
extern const char d_02200AF0[];

void func_021FCE60(char *p,int start)
{
    int i,height;
    func_02043B5C((struct CharBuf *)((int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38)),0);
    for(i=start;i<start+((struct Obj00048 *)p)->f44;i++) {
        if((unsigned)i<((struct Obj00048 *)p)->f4 && ((View *)p)->bitmap[i]) {
            height=((struct Obj00048 *)p)->fE;
            func_021FCF54(((View *)p)->bitmap[i],(int)func_02045770((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38),0,0,0,(i-start)*height,((struct Obj00048 *)p)->fA,height);
        }
    }
    func_02045334((struct Descriptor *)*(int *)&((struct Obj00048 *)p)->f38);
}

int func_021FCEDC(char *p)
{
    int x,y;
    int direction=0;
    int delta,absolute;
    if(func_02035BA4(d_02200AF0)!=-1) {
        func_02035CB8((u32 *)(&x),(u32 *)(&y));
        if(((struct Obj00048 *)p)->f84==0) {((struct Obj00048 *)p)->f84=1;((struct Obj00048 *)p)->f88=y;}
        else {
            delta=y-((struct Obj00048 *)p)->f88;
            if(delta<0) absolute=-delta;else absolute=delta;
            if(absolute>8) {
                if(delta<0) direction=-1;else direction=1;
                ((struct Obj00048 *)p)->f88=y;
            }
        }
    } else if(((struct Obj00048 *)p)->f84) ((struct Obj00048 *)p)->f84=0;
    return direction;
}

/*
 * extent: 80-byte scrolling follower filed as ov186_func_021FCF90.c.
 * lever: width-first multiply preserves the stack load and register order.
 */
void func_021FCF54(int dest,int src,int dx,int dy,unsigned short sx,unsigned short sy,unsigned short width,unsigned short height)
{
    char *d,*s;
    int doff,soff;
    d=func_020437D4((const struct Bmp *)dest);s=func_020437D4((const struct Bmp *)src);
    doff=width*dy+dx;
    soff=width*sy+sx;
    func_02082A90(d+doff*32,s+soff*32,width*height*32);
}
