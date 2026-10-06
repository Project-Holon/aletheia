/*
 * function: func_021B6460
 * address: 0x021B6460
 * packet: pkt_ov173_021B6460
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B6348 0x021B6348 thumb ov173
 *   func_021B7C7C 0x021B7C7C thumb ov173
 *   func_021B71B8 0x021B71B8 thumb ov173
 *   func_021B6828 0x021B6828 thumb ov173
 *   func_021B6794 0x021B6794 thumb ov173
 *   func_021B6678 0x021B6678 thumb ov173
 *   func_021B688C 0x021B688C thumb ov173
 *   func_021B7694 0x021B7694 thumb ov173
 *   func_02030EAC 0x02030EAC arm
 */
#include "../include/Obj00362.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B6348(u8 *);
extern int func_021B7C7C(int *);
extern void func_021B71B8(char *);
extern void func_021B6828(char *);
extern int func_021B6794(int *);
extern void func_021B6678(void);
extern void func_021B688C(char *);
extern void func_021B7694(u8 *p);
struct Node;
extern void func_02030EAC(struct Node *n);
void func_021B6460(char *p) { func_021B6348((u8 *)p); func_021B7C7C((int *)p); func_021B71B8(p); func_021B6828(p); func_021B6794((int *)p); func_021B6678(); func_021B688C(p); func_021B7694((u8 *)p); func_02030EAC(((struct Obj00362 *)p)->f68); }
