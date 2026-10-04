/*
 * function: func_021B7734
 * address: 0x021B7734
 * packet: pkt_ov102_021B7734
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 * func_021B71C0 0x021B71C0 thumb ov101
 * func_021B89B8 0x021B89B8 thumb ov102
 * func_021B87BC 0x021B87BC thumb ov102
 * func_021B85F4 0x021B85F4 thumb ov102
 * func_021B7DA8 0x021B7DA8 thumb ov102
 * func_021B7A60 0x021B7A60 thumb ov102
 * func_021B78D0 0x021B78D0 thumb ov102
 * func_021B7C88 0x021B7C88 thumb ov102
 * func_020315D4 0x020315D4 arm
 * func_020306F0 0x020306F0 arm
 */
#include "../include/Obj22138.h"
extern void func_021B71C0(void *p);
extern void func_021B89B8(void *);
extern void func_021B87BC(void *);
extern void func_021B85F4(void *);
extern void func_021B7DA8(void *);
extern void func_021B7A60(void *);
extern void func_021B78D0(void *);
extern void func_021B7C88(void *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(unsigned);
int func_021B7734(unsigned a,int b,int c,char *p) {
 func_021B71C0((void *)(((struct Obj22138 *)p)->f468));
 func_021B89B8(p+0x118);
 func_021B87BC(p+0xfc);
 func_021B85F4(p+0xc0);
 func_021B7DA8(p+0x46c);
 func_021B7DA8(p+0xac);
 func_021B7A60(p+0x94);
 func_021B78D0(p);
 func_021B7C88(p+0x9c);
 func_020315D4((struct S020315D4 *)a);
 func_020306F0(0x3b);
 return 1;
}
