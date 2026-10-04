/*
 * function: func_021DE300, func_021DE310
 * address: 0x021DE300
 * packet: pkt_ov093_021DE300
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
 *   func_021DE2A0 0x021DE2A0 thumb ov093
 *   d_021F1A84 0x021F1A84 data a4
 */
#include "../include/Obj21385.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DE2A0(void *, void *, int, u8 *);
void func_021DE300(void *a, void *b, int c, u8 *d) { if (((struct Obj21385 *)d)->f18) func_021DE2A0(a,b,c,d); }
extern u8 d_021F1A84[];
void *func_021DE310(int *p) { *p=4; return d_021F1A84; }
