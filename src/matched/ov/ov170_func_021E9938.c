/*
 * function: func_021E9938
 * address: 0x021E9938
 * packet: pkt_ov170_021E9938
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021EB988 0x021EB988 thumb ov170
 *   func_021EF4E4 0x021EF4E4 thumb ov170
 *   func_021EBC58 0x021EBC58 thumb ov170
 *   func_021ED588 0x021ED588 thumb ov170
 *   d_021EF9B4 0x021EF9B4 data a1
 */
#include "../include/Obj00000.h"
#include "../include/Obj23951.h"
extern void func_021EB988(unsigned char *,const void *,unsigned); extern void func_021EF4E4(int); extern void func_021EBC58(unsigned char *,int,int,int); extern void func_021ED588(unsigned char *); extern const unsigned char d_021EF9B4[];
int func_021E9938(unsigned char *p){func_021EB988(p,d_021EF9B4,5);func_021EF4E4(((struct Obj23951 *)(*(unsigned char * *)&((struct Obj00000 *)p)->f2C))->f74);func_021EBC58(p,p[22],1,24);func_021ED588(p);return 44;}
