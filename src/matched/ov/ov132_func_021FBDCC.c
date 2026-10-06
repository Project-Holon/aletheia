/*
 * function: func_021FBDCC
 * address: 0x021FBDCC
 * packet: pkt_ov132_021FBDCC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * prototype: 021F6B18's own source reads r0 only; this caller additionally
 * supplies r1 as a narrowed halfword, retained as an unused second input.
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_021F9DAC 0x021F9DAC thumb ov132
 *   func_021F6B18 0x021F6B18 thumb ov112
 *   func_021F9DB8 0x021F9DB8 thumb ov132
 */
#include "../include/Obj10555.h"
#include "../include/Obj14112.h"
struct Cursor;
extern unsigned int func_0201134C(struct Cursor *);
struct Object; struct Entry;
extern void *func_021F9DAC(void *p);
extern struct Entry *func_021F6B18(struct Object *,unsigned short);
typedef unsigned int   u32;
extern void func_021F9DB8(void *p, void *v, u32 i);
int func_021FBDCC(int unused,char *p) { char *obj; unsigned int a,b; struct Entry *entry;obj=*(char * *)&((struct Obj10555 *)p)->f0;a=func_0201134C(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);b=func_0201134C(*(struct Cursor * *)&((struct Obj10555 *)p)->f4);entry=func_021F6B18(func_021F9DAC(((struct Obj14112 *)obj)->f34),b);func_021F9DB8(((struct Obj14112 *)obj)->f34,entry,(unsigned char)a);return 0; }
