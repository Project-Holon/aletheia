/*
 * function: func_0220C40C
 * address: 0x0220C40C
 * packet: pkt_ov197_0220C40C
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Raw byte stride i*12 emits muls rather than the flat word-index shift/add.
 * The caller stores live r0 from C3B4; its owner declaration is void.
 * symbols:
 *   CLACT_CreateUnit 0x0204B100 arm
 *   func_0220C3B4 0x0220C3B4 thumb ov197
 *   d_0220DBBC 0x0220DBBC data a4
 */
#include "../include/Obj00315.h"
#include "../include/Obj25034.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Bank;
extern struct Bank *CLACT_CreateUnit(int,u8,u32);
struct Obj;
extern struct Obj *func_0220C3B4(char *p, const int *indices);
extern const int d_0220DBBC[];
void func_0220C40C(char *p) { u32 i; *(struct Bank * *)&((struct Obj00315 *)p)->f420=CLACT_CreateUnit(67,0,((struct Obj25034 *)(*(char * *)&((struct Obj00315 *)p)->f0))->fC); for(i=0;i<63;i++) *(u32 *)(p+i*4+0x424)=(u32)func_0220C3B4(p,(const int *)((u32)d_0220DBBC+i*12)); }
