/*
 * function: func_021B9F24
 * address: 0x021B9F24
 * packet: pkt_ov225_021B9F24
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pooled overlay ID is an absolute data a1 symbol; callback leaf filed.
 * symbols:
 *   ov067_id 0x00000043 data a1
 *   func_02034AC4 0x02034AC4 arm
 *   func_02030734 0x02030734 arm
 *   d_021BC014 0x021BC014 data a1
 *   func_021BA160 0x021BA160 thumb ov225
 *   func_021BA1C0 0x021BA1C0 thumb ov225
 *   func_021BA1C4 0x021BA1C4 thumb ov225
 *   func_021BA41C 0x021BA41C thumb ov225
 *   func_021BA068 0x021BA068 thumb ov225
 *   func_021BA644 0x021BA644 thumb ov225
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA15C 0x021BA15C thumb ov225
 */
#include "../include/Obj06734.h"
#include "../include/Obj26144.h"
typedef unsigned short u16;
extern const char ov067_id[];
extern const char d_021BC014[];
extern int func_02034AC4(int);
extern void *func_02030734(unsigned,unsigned,int,const char *,u16);
extern void func_021BA160(char *);
extern void func_021BA1C0(void *);
extern void func_021BA1C4(char *);
extern void func_021BA41C(char *);
extern void func_021BA068(char *,unsigned);
extern void func_021BA644(char *);
extern void *func_020056A0(unsigned,unsigned,unsigned);
extern void func_021BA15C(void *,void *);
void *func_021B9F24(char *owner)
{
    char *p;
    func_02034AC4((int)ov067_id);
    p=func_02030734(((struct Obj26144 *)owner)->f4,0x4c,1,d_021BC014,235);
    ((struct Obj06734 *)p)->f0=owner;func_021BA160(p);func_021BA1C0(p);func_021BA1C4(p);func_021BA41C(p);
    ((struct Obj06734 *)p)->f8=4;p[0xc]=0;p[0xd]=0;func_021BA068(p,0);func_021BA644(p);
    ((struct Obj06734 *)p)->f48=func_020056A0((unsigned)func_021BA15C,(unsigned)p,1);
    return p;
}
