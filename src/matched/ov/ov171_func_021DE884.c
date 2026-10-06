/*
 * function: func_021DE884
 * address: 0x021DE884
 * packet: pkt_ov171_021DE884
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202570C 0x0202570C thumb
 *   func_020437AC 0x020437AC arm
 *   func_02025588 0x02025588 thumb
 */
#include "../include/Obj08252.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Grid;
struct Obj020437AC;
extern void func_0202570C(struct Grid *g);
extern void func_020437AC(struct Obj020437AC *p);
extern void func_02025588(void *);
void func_021DE884(int *p) { func_0202570C(((struct Obj08252 *)p)->fC54); func_020437AC(((struct Obj08252 *)p)->fC58); func_02025588(((struct Obj08252 *)p)->fC50); }
