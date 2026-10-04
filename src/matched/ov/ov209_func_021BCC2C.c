/*
 * function: func_021BCC2C
 * address: 0x021BCC2C
 * packet: pkt_ov209_021BCC2C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE34C 0x021BE34C thumb ov209
 *   func_021B93B0 0x021B93B0 thumb ov067
 *   func_021BE51C 0x021BE51C thumb ov209
 *   func_021BE5D4 0x021BE5D4 thumb ov209
 */
#include "../include/Obj00088.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021BE34C(char *,int),func_021BE51C(char *,int),func_021BE5D4(char *,int);extern int func_021B93B0(char *);
void func_021BCC2C(char *p,int delta) { func_021BE34C(p,(signed char)-delta);func_021BE51C(p,func_021B93B0(*(char * *)&((struct Obj00088 *)p)->fC2C));func_021BE5D4(p,1); }
