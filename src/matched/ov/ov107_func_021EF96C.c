/*
 * function: func_021EF96C
 * address: 0x021EF96C
 * packet: pkt_ov107_021EF96C
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F6D68 0x021F6D68 data ov107 a4
 *   d_021F6D70 0x021F6D70 data ov107 a4
 *   d_021F6D60 0x021F6D60 data ov107 a4
 *   d_021F6C40 0x021F6C40 data ov107 a4
 *   func_02179024 0x02179024 thumb ov014
 *   func_02082D44 0x02082D44 arm
 *   func_021F0754 0x021F0754 thumb ov107
 *   func_021F080C 0x021F080C thumb ov107
 */
#include "../include/Obj00072.h"
typedef unsigned char u8;
typedef struct { int a,b; } Pair;
typedef struct { int words[15]; } Config;
extern const Pair d_021F6D68,d_021F6D70,d_021F6D60;
extern const Config d_021F6C40;
typedef unsigned short u16;
extern u16 func_02179024(void);
extern void func_02082D44(const void *,void *,unsigned);
extern void func_021F0754(int,int);
extern void func_021F080C(void *,int);
void func_021EF96C(u8 *p) {
 Pair a=d_021F6D68,b=d_021F6D70,c=d_021F6D60;
 Config cfg=d_021F6C40;
 int v=func_02179024();
 func_02082D44(&cfg,p+128,60);
 ((struct Obj00072 *)p)->f80=p[40]==0?a.a:a.b;
 ((struct Obj00072 *)p)->f8C=b.b;((struct Obj00072 *)p)->f90=c.b;
 ((struct Obj00072 *)p)->f84=((struct Obj00072 *)p)->f50;((struct Obj00072 *)p)->f88=((struct Obj00072 *)p)->f54;
 func_021F0754(4992,65536);func_021F080C(p+128,v);
}
