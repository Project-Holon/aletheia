/*
 * function: func_021EFFD4
 * address: 0x021EFFD4
 * packet: pkt_ov035_021EFFD4
 * region: ov035
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021A0FB4 0x021A0FB4 thumb ov021
 *   func_021F0218 0x021F0218 thumb ov035
 *   func_021F015C 0x021F015C thumb ov035
 *   func_021F0100 0x021F0100 thumb ov035
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_02045C04 0x02045C04 arm
 *   func_0201D83C 0x0201D83C thumb
 */
#include "../include/Obj05127.h"
typedef unsigned int   u32;
struct PrintSys;
struct Rec;
extern void func_021A0FB4(u32 *p, u32 a);
extern void func_021F0218(char *);
extern void func_021F015C(char *);
extern void func_021F0100(char *);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern void func_02045C04(struct Rec *rec);
extern void func_0201D83C(void *);
void func_021EFFD4(char *p) { func_021A0FB4(((struct Obj05127 *)p)->fC,((struct Obj05127 *)p)->f0); func_021F0218(p); func_021F015C(p); func_021F0100(p); func_0201C6EC(((struct Obj05127 *)p)->f3C); func_0201C4C0(((struct Obj05127 *)p)->f3C); func_02045C04(((struct Obj05127 *)p)->f38); func_0201D83C(((struct Obj05127 *)p)->f34); }
