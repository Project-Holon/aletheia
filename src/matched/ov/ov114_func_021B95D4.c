/*
 * function: func_021B95D4
 * address: 0x021B95D4
 * packet: pkt_ov114_021B95D4
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: lead ends 021B973C; the following null-safe getter already has
 * src/matched/ov/ov114_func_021B973C.c and pkt_ov114_021B973C.json coverage.
 * lever: two-word Pair entries preserve the table's format/mode stride.
 * symbols:
 *   func_021B95A0 0x021B95A0 thumb ov114
 *   func_021B95B0 0x021B95B0 thumb ov114
 *   func_021B95C0 0x021B95C0 thumb ov114
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
 */
#include "../include/Obj08035.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 format,mode; } Pair;
extern char d_021CE2D4[],d_021CE280[];
extern Pair d_021CE284[];
extern unsigned int func_021B95A0(unsigned int,unsigned int);
extern void func_021B95B0(int);
extern int func_021B95C0(int,int,u32 *);
extern int func_021BE648(int a, int b, int c);
extern int func_021BF04C(u32,u32,void *,int,void *,int);
extern int func_021BE9C8(int,void *,int);
extern int func_021BE6BC(int,const char *,const char *);
extern int func_021BE8E8(void *handle, char *username_p, char *password_p);
extern void func_02034714(const char *,u32,const char *);
extern void func_02082BCC(void *,int,unsigned);
extern int func_0208D80C(char *,int,const char *,...);
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
    h=func_021BF04C((u32)(p+0x410),d_021CE284[index].mode,p+0x10,1024,func_021B95C0,(int)p);
    if(h==0) func_02034714(d_021CE2D4,0,d_021CE2D4);
    if(h==0) return 0;
    ((struct Obj08035 *)p)->fC=h;
    if(func_021BE9C8(h,d_021CE280,1)<0) {
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
