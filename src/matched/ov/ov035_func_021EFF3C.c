/*
 * function: func_021EFF3C
 * address: 0x021EFF3C
 * packet: pkt_ov035_021EFF3C
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F0640 0x021F0640 data ov035 a4
 *   func_021A0FA0 0x021A0FA0 thumb ov021
 *   func_0201C4E4 0x0201C4E4 thumb
 */
#include "../include/Obj02409.h"
extern int (*d_021F0640[])(char *);
typedef unsigned int   u32;
struct PrintSys;
extern void func_021A0FA0(int *p, int v);
extern u32 func_0201C4E4(struct PrintSys *ps);
void func_021EFF3C(char *p) { if(((struct Obj02409 *)p)->f4E==0) { if(d_021F0640[*(unsigned short *)(p+0x48)](p)) { func_021A0FA0(((struct Obj02409 *)p)->fC,14); ((struct Obj02409 *)p)->f4E=1; } } func_0201C4E4(((struct Obj02409 *)p)->f3C); }
