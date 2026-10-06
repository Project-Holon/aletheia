/*
 * function: func_021D7F9C
 * address: 0x021D7F9C
 * packet: pkt_ov123_021D7F9C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6E70 0x021D6E70 thumb ov123
 *   func_021D6EBC 0x021D6EBC thumb ov123
 *   func_021D66D0 0x021D66D0 thumb ov123
 *   func_021D6E08 0x021D6E08 thumb ov123
 *   func_021D7E58 0x021D7E58 thumb ov123
 *   func_021D5950 0x021D5950 thumb ov123
 *   func_021D59E4 0x021D59E4 thumb ov123
 *   func_021D5A60 0x021D5A60 thumb ov123
 *   func_021D6EA4 0x021D6EA4 thumb ov123
 *   func_021D7F5C 0x021D7F5C thumb ov123
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D746C 0x021D746C thumb ov123
 *   func_021D6FF0 0x021D6FF0 thumb ov123
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   d_021DAB78 0x021DAB78 data ov123 a1
 */
#include "../include/Obj00063.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D6E70(u8 *p);
extern int func_021D6EBC(u8 *p);
extern void func_021D66D0(u8 *,int);
extern int func_021D6E08(char *,int);
struct Sub02009448Obj;
extern int func_021B99DC(u8 *p);
extern int func_021B9790(u8 *p);
extern char *func_021B97F4(void *);
extern struct Sub02009448Obj *func_02009448(void *sys);
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082D44(const void *,void *,u32);
extern void func_021D7E58(u8 *p, void *h, u8 *q, int *r);
extern int func_021D5950(u8 *,int);
extern void func_021D59E4(char *);
extern void func_021D5A60(char *);
extern int func_021D6EA4(char *);
extern int func_021D7F5C(char *);
extern void func_021D6EE0(u8 *p, u32 v, int unused);
extern void func_021D746C(int a);
extern void func_021D6FF0(char *);
extern const char d_021DAB78[];
void func_021D7F9C(char *p)
{
    char *q, *data;
    void *v, *allocated;
    if (func_021D6E70((u8 *)p) && !func_021D6EBC((u8 *)p)) {
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
        if (func_021D6E08(p,func_021B99DC(((struct Obj00063 *)p)->f10))) return;
        if (func_021B9790(((struct Obj00063 *)p)->f10)) return;
        q=func_021B97F4(((struct Obj00063 *)p)->f10);
        v=func_02009448(((struct Obj00063 *)p)->f28);
        data=q+0x80;
        allocated=func_02030734(((struct Obj00063 *)p)->f0,0x11c,1,d_021DAB78,0x573);
        ((struct Obj00063 *)p)->f38=allocated;
        func_02082D44(data,allocated,0x11c);
        func_021D7E58((u8 *)p,v,(u8 *)data,(int *)q);
        return;
    } else {
        ++((struct Obj00063 *)p)->f74;
        if (((struct Obj00063 *)p)->f70<30) ++((struct Obj00063 *)p)->f70;
        if (((struct Obj00063 *)p)->f74==360) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,43);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==720) {
            func_021D5950(*(u8 * *)&((struct Obj00063 *)p)->f18,44);
            func_021D59E4(*(char * *)&((struct Obj00063 *)p)->f18);
        } else if (((struct Obj00063 *)p)->f74==1080) {
            if (func_021D6EA4(p)) func_021D5A60(*(char * *)&((struct Obj00063 *)p)->f18);
            if (func_021D7F5C(p)) {
                func_021D6EE0((u8 *)p,(int)func_021D746C,0x58c);
            } else {
                ((struct Obj00063 *)p)->f80=9;
                func_021D6EE0((u8 *)p,(int)func_021D6FF0,0x591);
            }
        }
        func_021D66D0(*(u8 * *)&((struct Obj00063 *)p)->f14,((struct Obj00063 *)p)->f70);
    }
}
