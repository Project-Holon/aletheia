/*
 * function: func_021B63D4
 * address: 0x021B63D4
 * packet: pkt_ov179_021B63D4
 * region: ov179
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware writes 021B63E8 and 021B63EC.
 * symbols:
 *   func_02043534 0x02043534 arm
 *   func_020435F4 0x020435F4 arm
 *   func_0204363C 0x0204363C arm
 *   func_021B615C 0x021B615C thumb ov179
 *   func_021B616C 0x021B616C thumb ov179
 *   func_020490F4 0x020490F4 arm
 *   func_021B622C 0x021B622C thumb ov179
 *   func_021B624C 0x021B624C thumb ov179
 *   func_021B6290 0x021B6290 thumb ov179
 *   d_021B6A1C 0x021B6A1C data a4
 */
#include "../include/Obj14386.h"
typedef unsigned short u16;

typedef unsigned int   u32;
extern void func_02043534(u32 planes);
extern void func_020435F4(u32 planes);
extern void func_0204363C(u32 swap);
extern void func_021B615C(void);
extern void func_021B616C(char *);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_021B622C(char *);
extern void func_021B624C(int *);
extern void func_021B6290(char *,unsigned,unsigned,unsigned);
typedef struct {unsigned short value;char pad[10];} Entry;
extern const Entry d_021B6A1C[];
int func_021B63D4(char *p)
{
 func_02043534(0);func_020435F4(0);
 *(volatile unsigned short *)0x04000050=0;
 *(volatile unsigned short *)0x04001050=0;
 func_0204363C(1);func_021B615C();func_021B616C(p);
 ((struct Obj14386 *)p)->f4=func_020490F4(d_021B6A1C[**(unsigned short **)p].value,0x7F);
 func_021B622C(p);func_021B624C((int *)p);func_021B6290(p,1,1,5);
 ((struct Obj14386 *)p)->f6058=1;
 return 2;
}
