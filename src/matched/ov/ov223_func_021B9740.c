/*
 * function: func_021B9740
 * address: 0x021B9740
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9740
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj03380.h"
typedef unsigned int u32;
extern void func_02040588(u32,u32);
void func_021B9740(void *unused,char *p)
{
    if(((struct Obj03380 *)p)->f24&1) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&2) func_02040588(3,0);
    if(((struct Obj03380 *)p)->f24&4) {func_02040588(3,1);func_02040588(2,1);}
    if(((struct Obj03380 *)p)->f24&8) {func_02040588(3,0);func_02040588(2,0);}
    if(((struct Obj03380 *)p)->f24&16) {func_02040588(7,1);func_02040588(6,1);func_02040588(5,1);}
    if(((struct Obj03380 *)p)->f24&32) {func_02040588(7,0);func_02040588(6,0);func_02040588(5,0);}
    if(((struct Obj03380 *)p)->f24&64) func_02040588(3,1);
    if(((struct Obj03380 *)p)->f24&128) func_02040588(3,0);
    ((struct Obj03380 *)p)->f24=0;
}
