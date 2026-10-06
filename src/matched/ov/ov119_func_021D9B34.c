/*
 * function: func_021D9B34
 * address: 0x021D9B34
 * packet: pkt_ov119_021D9B34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021E1410 0x021E1410 thumb ov119
 *   func_02043534 0x02043534 arm
 *   func_021B6558 0x021B6558 thumb ov067
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9A50 0x021D9A50 thumb ov119
 *   d_021E75E4 0x021E75E4 data
 */
#include "../include/Obj22726.h"
typedef struct {int a,b,c;} Triple;
typedef unsigned int   u32;
extern int func_021E12AC(char *p);
extern void func_021E1410(void *p, int *ids, int count);
extern void func_02043534(u32 planes);
extern void func_021B6558(unsigned char *p, unsigned int id, unsigned int v);
extern void func_021D8E84(void *,int);
extern void func_021D9A50(char *p);
extern const Triple d_021E75E4;
void func_021D9B34(char *p) { if(func_021E12AC(p)) { Triple t=d_021E75E4; func_021E1410(p,(int *)(&t),3); func_02043534(31); func_021B6558((unsigned char *)(((struct Obj22726 *)p)->f9C0),1,0); func_021D8E84(p,(int)func_021D9A50); } }
