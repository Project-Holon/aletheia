/*
 * function: func_021BD314
 * address: 0x021BD314
 * packet: pkt_ov209_021BD314
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BD2F4 0x021BD2F4 thumb ov209
 *   func_021B9398 0x021B9398 thumb ov067
 *   func_0200CA78 0x0200CA78 thumb
 */
#include "../include/Obj00088.h"
#include "../include/Obj25556.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021BD2F4(char *,int);extern u32 func_021B9398(char *,int);extern void func_0200CA78(void *,u16);
void func_021BD314(char *p,int i) { if(func_021BD2F4(p,i)==1)func_0200CA78(((struct Obj25556 *)(*(char * *)&((struct Obj00088 *)p)->f0))->f4,func_021B9398(*(char * *)&((struct Obj00088 *)p)->fC2C,i)); }
