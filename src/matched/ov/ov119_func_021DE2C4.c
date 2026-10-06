/*
 * function: func_021DE2C4
 * address: 0x021DE2C4
 * packet: pkt_ov119_021DE2C4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_02040588 0x02040588 arm
 *   func_021E6440 0x021E6440 thumb ov119
 *   func_021E1CE8 0x021E1CE8 thumb ov119
 *   func_020490F4 0x020490F4 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_021E3208 0x021E3208 thumb ov119
 *   func_02041B6C 0x02041B6C arm
 *   func_021D8FA4 0x021D8FA4 thumb ov119
 *   func_021D89EC 0x021D89EC thumb ov119
 *   func_021D9468 0x021D9468 thumb ov119
 *   func_021DEBD4 0x021DEBD4 thumb ov119
 *   func_021DD09C 0x021DD09C thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DEA24 0x021DEA24 thumb ov119
 *   func_021D8980 0x021D8980 thumb ov119
 *   func_0202208C 0x0202208C thumb
 */
#include "../include/Obj06426.h"
typedef unsigned short u16;
extern unsigned func_020221A4(void);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02040588(u32 which, u32 enable);
extern void func_021E6440(int,int,int);
extern void func_021E1CE8(void *,int);
extern void *func_020490F4(unsigned int id, u16 heap);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_021E3208(void *,int);
extern void func_02041B6C(u32 bit);
extern void *func_021D8FA4(void *,int);
extern int func_021D89EC(const u8 *p);
extern void func_021D9468(void *,int,void *);
extern void func_021DEBD4(void *);
extern void func_021DD09C(char *p);
extern int func_021D8980(char *p);
extern void func_021D8E84(void *,int);
extern void func_021DEA24(char *p);
extern void func_0202208C(void *,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned);
void func_021DE2C4(char *p)
{
    void *resource;
    int zero,slot;
    void *mon;
    if(func_020221A4()) {
        zero=0;
        func_02040588(3,zero);
        func_021E6440((int)p,-1,-1);
        func_021E1CE8(p,0);
        resource=func_020490F4(102,((struct Obj06426 *)p)->f5F4);
        func_02049990(resource,11,2,0,(u16)((struct Obj06426 *)p)->f86C,zero,zero,((struct Obj06426 *)p)->f5F4);
        func_02049238(resource);
        func_021E3208(p,0);
        func_02041B6C(3);
        p[0x11f3]=zero;
        slot=1;
        if(func_021D89EC(func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        slot=0;
        if(func_021D89EC(func_021D8FA4(p,slot))) {
            mon=func_021D8FA4(p,slot);
            func_021D9468(p,slot,mon);
        }
        func_021DEBD4(p);
        func_021DD09C(p);
        func_021D8E84(p,(int)func_021DEA24);
        func_021D8980(p);
        func_0202208C((void *)3,1,1,0,6,1,((struct Obj06426 *)p)->f5F4);
    }
}
