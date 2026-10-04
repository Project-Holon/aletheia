/*
 * function: func_02160DDC
 * address: 0x02160DDC
 * packet: pkt_ov010_02160DDC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012A30 0x02012A30 thumb
 *   func_02012134 0x02012134 thumb
 *   func_02029DD8 0x02029DD8 thumb
 */
#include "../include/Obj12324.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct BigObj;
extern u32 func_02012A30(const struct BigObj *p);
extern u32 func_02012134(u32 *);
extern int func_02029DD8(int,int);
typedef enum { FALSE = 0, TRUE = 1 } BOOL;
BOOL func_02160DDC(u32 *a, u8 *b) { u32 s=func_02012A30(((struct Obj12324 *)b)->f0); func_02029DD8(s,func_02012134(*(u32 **)a[6])); if (((struct Obj12324 *)b)->fE==0) return FALSE; else return TRUE; }
