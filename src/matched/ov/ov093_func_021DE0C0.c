/*
 * function: func_021DE0C0, func_021DE0D0
 * address: 0x021DE0C0
 * packet: pkt_ov093_021DE0C0
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
 *   func_021DE058 0x021DE058 thumb ov093
 *   d_021F160C 0x021F160C data a4
 */
#include "../include/Obj21380.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021DE058(void *, void *, int, u8 *);
void func_021DE0C0(void *a, void *b, int c, u8 *d) { if (((struct Obj21380 *)d)->f18) func_021DE058(a,b,c,d); }
extern u8 d_021F160C[];
void *func_021DE0D0(int *p) { *p=2; return d_021F160C; }
