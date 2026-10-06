/*
 * function: func_021647A0
 * address: 0x021647A0
 * packet: pkt_ov010_021647A0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021729B0 0x021729B0 data ov010 a1
 *   func_021647F0 0x021647F0 thumb ov010
 *   func_021647FC 0x021647FC thumb ov010
 *   func_02164890 0x02164890 thumb ov010
 */
#include "../include/Obj04133.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021729B0[];
extern int func_021647F0(int a0);
extern void *func_021647FC(int a0);
extern void func_02164890(u8 *);
u8 *func_021647A0(void *a,u32 b){u8 *p=func_02030734(b,0x11c,0,d_021729B0,0x53);func_021647F0((int)p);((struct Obj04133 *)p)->f0=b;((struct Obj04133 *)p)->f4=a;func_021647FC((int)p);func_02164890(p);return p;}
