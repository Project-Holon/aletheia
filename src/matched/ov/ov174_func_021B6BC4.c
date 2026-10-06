/*
 * function: func_021B6BC4
 * address: 0x021B6BC4
 * packet: pkt_ov174_021B6BC4
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02030734 0x02030734 arm
 *   func_020124F4 0x020124F4 thumb
 *   func_0203630C 0x0203630C arm
 *   func_021B6100 0x021B6100 thumb ov174
 *   d_021B74AC 0x021B74AC data
 */
#include "../include/Obj01167.h"
#include "../include/Obj10673.h"
typedef unsigned short u16;
extern void func_0203064C(unsigned int src, unsigned int dst, unsigned int size);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void *func_020124F4(u16);
extern unsigned int func_0203630C(void);
typedef unsigned char  u8;
extern void func_021B6100(u8 *p);
extern char d_021B74AC[];
int func_021B6BC4(void *ctx,int unused,char *arg)
{
    char *p;
    func_0203064C(1,0x55,0x40000);
    p=func_0203159C(ctx,0x8c,0x55);
    if(arg==0) {
        arg=func_02030734(0x55,8,0,d_021B74AC,0x3b8);
        ((struct Obj10673 *)arg)->f4=func_020124F4(1);
        ((struct Obj10673 *)arg)->f0=1;
        if(func_0203630C() & 0x100) ((struct Obj10673 *)arg)->f0=5;
    }
    ((struct Obj01167 *)p)->f0=0x55;
    *(char * *)&((struct Obj01167 *)p)->f30=arg;
    func_021B6100((u8 *)p);
    return 1;
}
