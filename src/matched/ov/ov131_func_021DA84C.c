/*
 * function: func_021DA84C
 * address: 0x021DA84C
 * packet: pkt_ov131_021DA84C
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero alignment padding at 0x021DA8BA.
 * symbols:
 *   func_020437AC 0x020437AC arm
 *   func_021DBC3C 0x021DBC3C thumb ov131
 *   func_021DB9E8 0x021DB9E8 thumb ov131
 *   func_020452E8 0x020452E8 arm
 */
#include "../include/Obj02190.h"
typedef unsigned char u8;
struct Descriptor;
struct Obj020437AC;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_021DBC3C(u8 *p);
extern void func_021DB9E8(void *,void *,u8 *);
extern void func_020452E8(struct Descriptor *d);
void func_021DA84C(u8 *a,u8 *b) {
    u8 i;
    if(b[43]==5) {
        func_020437AC(((struct Obj02190 *)b)->fA8);
        func_021DBC3C(((struct Obj02190 *)b)->fAC);
    }
    for(i=0;i<b[43];i++) func_021DB9E8(a,b,b+176+i*24);
    for(i=0;i<13;i++) func_020452E8(*(void **)(b+92+i*4));
    *(int *)&((struct Obj02190 *)b)->f0=0;
}
