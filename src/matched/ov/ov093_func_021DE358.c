/*
 * function: func_021DE358, func_021DE368
 * address: 0x021DE358
 * packet: pkt_ov093_021DE358
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * interface: r3 is untouched before bl; forward its incoming fourth argument.
 * lever: fourth argument keeps r3 live; three arguments give ldr/cmp r3.
 * unit: yes
 * symbols:
 *   func_021DE34C 0x021DE34C thumb ov093
 *   d_021F1564 0x021F1564 data a4
 */
#include "../include/Obj21387.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DE34C(int, int, int, u8 *);
void func_021DE358(int a, int b, int c, u8 *d) { if (((struct Obj21387 *)d)->f18) func_021DE34C(a,b,c,d); }
extern u8 d_021F1564[];
void *func_021DE368(int *p) { *p=1; return d_021F1564; }
