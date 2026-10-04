/*
 * unit: no
 * function: func_0220E13C
 * address: 0x0220E13C
 * packet: pkt_ov198_0220E13C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0220E168 0x0220E168 thumb ov198
 */
#include "../include/Obj02247.h"
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
struct Descriptor;struct CharBuf;extern void func_0201F73C(void *,int,int,int);extern void *func_02045770(struct Descriptor *);extern void func_02043B5C(struct CharBuf *,u8);extern void func_0220E168(char *);
void func_0220E13C(u8 *p){func_0201F73C(((struct Obj02247 *)p)->f1F68,2,1,14);func_02043B5C(func_02045770(*(struct Descriptor * *)&((struct Obj02247 *)p)->f1F68),15);func_0220E168((char *)p);}
