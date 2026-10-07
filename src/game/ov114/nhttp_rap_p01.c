/*
 * file:     nhttp_rap_p01.c
 * unit:     yes
 * function: func_021B95A0, func_021B95B0, func_021B95C0, func_021B95D4, func_021B973C, func_021B9748, func_021B9774
 * address:  0x021B95A0
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021CE2D4 0x021CE2D4 data a4
 *   d_021CE284 0x021CE284 data a4
 *   d_021CE280 0x021CE280 data a4
 *   func_021BE648 0x021BE648 arm ov114
 *   func_021BF04C 0x021BF04C arm ov114
 *   func_021BE9C8 0x021BE9C8 arm ov114
 *   func_021BE6BC 0x021BE6BC arm ov114
 *   func_021BE8E8 0x021BE8E8 arm ov114
 *   func_02034714 0x02034714 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0208D80C 0x0208D80C arm
 *   func_021BF308  0x021BF308  arm  ov114
 *   func_021BE698  0x021BE698  arm  ov114
 *   func_021BF184  0x021BF184  arm  ov114
 */
#include "../../matched/include/Obj08035.h"
#include "../../matched/include/G_Pair.h"
#include "../../matched/include/Obj22570.h"
#include "../../matched/include/Obj22571.h"
#include "../../matched/include/Obj03763.h"

typedef unsigned int   u32;

typedef unsigned char u8;

typedef struct { u32 format,mode; } Pair;

extern unsigned int func_02156F5C(unsigned int, unsigned int, unsigned int);
extern void func_02156FDC(u32 a, void *p, int b);
extern int func_021BE648(int a, int b, int c);
extern void *func_021BF04C(char *url_p, int method, char *buf_p, u32 len, int (*callback)(void *, int, void *), void *userParam_p);
extern int func_021BE9C8(int a, int b, int c);
extern int func_021BE6BC(int,const char *,const char *);
extern int func_021BE8E8(void *handle, char *username_p, char *password_p);
extern void func_02034714(const char *,u32,const char *);
extern void func_02082BCC(void *,int,unsigned);
extern int func_0208D80C(char *,int,const char *,...);
extern int func_021BF308(int);
extern void func_0203C9AC(int a, u32 b, u32 c, u32 d);
extern int func_021BF184(int a);
extern void func_021BE698(void);
unsigned int func_021B95A0(unsigned int a, unsigned int b);
void func_021B95B0(int a);
int func_021B95C0(int a, int b, unsigned int *p);
int func_021B95D4(int index,u8 *p);
int func_021B973C(char *p);
int func_021B9748(u8 *p);
void func_021B9774(u8 *p);
extern char d_021CE2D4[],d_021CE280[];
extern struct Pair d_021CE284[];

unsigned int func_021B95A0(unsigned int a, unsigned int b)
{
    return func_02156F5C(13, a, b);
}

void func_021B95B0(int a)
{
    func_02156FDC(13, (void *)a, 0);
}

int func_021B95C0(int a, int b, unsigned int *p)
{
    switch (b) {
    case 1: break;
    case 2:
    case 3: p[2] = 0; break;
    }
    return 0;
}

int func_021B95D4(int index,u8 *p)
{
    int h;
    if(func_021BE648((int)func_021B95A0,(int)func_021B95B0,12)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(p==0) return 0;
    func_02082BCC(p+0x410,0,4);
    if(index==4) func_0208D80C((char *)(p+0x410),400,(char *)d_021CE284[index].format,((struct Obj08035 *)p)->f8+69);
    else func_0208D80C((char *)(p+0x410),400,(char *)d_021CE284[index].format,((struct Obj08035 *)p)->f5A4,21,2,1,((struct Obj08035 *)p)->f8+69);
    h=(int)func_021BF04C((char *)((u32)(p+0x410)),d_021CE284[index].mode,(char *)(p+0x10),1024,(int (*)(void *, int,  void *))func_021B95C0,(void *)((int)p));
    if(h==0) func_02034714(d_021CE2D4,0,d_021CE2D4);
    if(h==0) return 0;
    ((struct Obj08035 *)p)->fC=h;
    if(func_021BE9C8(h,(int)d_021CE280,1)<0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE6BC(h,d_021CE2D4+4,d_021CE2D4+12)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE6BC(h,d_021CE2D4+16,d_021CE2D4+28)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    if(func_021BE8E8((void *)h,d_021CE2D4+40,d_021CE2D4+48)!=0) {
        func_02034714(d_021CE2D4,0,d_021CE2D4);
        return 0;
    }
    return 1;
}

/*
 * extent: the following labelled function is func_021B9748.
 */
int func_021B973C(char *p)
{
    if (p) return ((struct Obj22570 *)p)->fC;
    return 0;
}


int func_021B9748(u8 *p)
{
    int h;

    if (p != 0) {
        h = func_021BF308(((struct Obj22571 *)p)->fC);
        if (h != 0) {
            func_0203C9AC(h, 2, h, 0x3f6);
            return h;
        }
        return 0;
    }
    return 1;
}


void func_021B9774(u8 *p)
{
    if (p == 0)
        return;
    if (((struct Obj03763 *)p)->fC == 0)
        return;
    func_021BF184(((struct Obj03763 *)p)->fC);
    ((struct Obj03763 *)p)->fC = 0;
    func_021BE698();
}
