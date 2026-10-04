/*
 * function: func_021B9718
 * address: 0x021B9718
 * packet: pkt_ov224_021B9718
 * region: ov224
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum do-loop with unsigned bound retains one table iteration; unsigned for-loop folds it, enum for-loop adds an entry guard.
 * volatile: sub-display blend/control reads and writes 021B973C-021B9746.
 * symbols:
 *   d_021B9C04 0x021B9C04 data a4
 *   func_020403F4 0x020403F4 arm
 *   func_021B9898 0x021B9898 thumb ov224
 *   func_021B99E8 0x021B99E8 thumb ov224
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj06730.h"
typedef enum { ZERO=0, ONE=1 } Index;
typedef struct { unsigned id; char fields[32]; unsigned a,b; } Entry;
extern const Entry d_021B9C04[];
extern void func_020403F4(unsigned char);
extern void func_021B9898(char *),func_021B99E8(char *);
struct S020315D4;
extern void func_02030EAC(void *),func_0201C6EC(void *),func_0201C4C0(void *),func_0201D83C(void *),func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned int heap);
int func_021B9718(void *a,int b,int c,char *p)
{
    Index i=ZERO;
    do { func_020403F4(d_021B9C04[i].id); i++; } while(i<1U);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=~0xe000;
    func_021B9898(p);
    func_02030EAC(((struct Obj06730 *)p)->f14); func_0201C6EC(((struct Obj06730 *)p)->f10); func_0201C4C0(((struct Obj06730 *)p)->f10);
    func_0201D83C(((struct Obj06730 *)p)->fC); func_021B99E8(*(char * *)&((struct Obj06730 *)p)->f8);
    func_020315D4(a); func_020306F0(136);
    return 1;
}
