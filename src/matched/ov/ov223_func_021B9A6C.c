/*
 * function: func_021B9A6C
 * address: 0x021B9A6C
 * packet: pkt_ov223_021B9A6C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020480E4 0x020480E4 arm
 *   func_021B9600 0x021B9600 thumb ov223
 *   func_02011558 0x02011558 thumb
 */
#include "../include/Obj05571.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;struct IcaAnime;extern void func_020480E4(struct Ctx *,u32);extern void func_021B9600(void *);extern void func_02011558(struct IcaAnime *);
void func_021B9A6C(char *p) {func_020480E4(*(struct Ctx * *)&((struct Obj05571 *)p)->f28,((struct Obj05571 *)p)->f2E);func_021B9600(((struct Obj05571 *)p)->f3C);((struct Obj05571 *)p)->f3A=0;func_02011558(*(struct IcaAnime * *)&((struct Obj05571 *)p)->f40);}
