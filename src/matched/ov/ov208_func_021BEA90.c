/*
 * function: func_021BEA90
 * address: 0x021BEA90
 * packet: pkt_ov208_021BEA90
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * matching: full-width stack argument reloads; small pool operands are overlay ID symbols.
 * symbols:
 *   func_021BF63C 0x021BF63C thumb ov208
 *   func_021BF61C 0x021BF61C thumb ov208
 *   func_021BA2CC 0x021BA2CC thumb ov206
 *   func_021BF41C 0x021BF41C thumb ov208
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_021BC464 0x021BC464 thumb ov208
 *   func_02030EAC 0x02030EAC arm
 *   func_021BC34C 0x021BC34C thumb ov208
 *   func_02034A5C 0x02034A5C arm
 *   ov206_id 0x000000CE data
 *   ov067_id 0x00000043 data
 * Caller visibly supplies third arguments to helpers and a live r0 to BC464.
 */
#include "../include/Obj03362.h"
struct Rec;struct Node;
extern char ov206_id[],ov067_id[];
extern void func_021BF63C(int,char *,unsigned);
extern void func_021BF61C(int,char *,unsigned);
extern void func_021BA2CC(char *);
extern void func_021BF41C(int,char *,unsigned);
typedef unsigned int   u32;
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void func_021BC464(void *);
extern void func_02030EAC(struct Node *);
extern void func_021BC34C(char *);
extern void func_02034A5C(int);
int func_021BEA90(char *first,unsigned unused,int owner,char *q,unsigned heap)
{
    func_021BF63C(owner,q,heap);func_021BF61C(owner,q,heap);
    func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f8);func_021BA2CC(*(char * *)&((struct Obj03362 *)q)->f4);
    func_021BF41C(owner,q,heap);
    func_0201D83C(((struct Obj03362 *)q)->f110);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f11C);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f118);
    func_02045C04(*(struct Rec * *)&((struct Obj03362 *)q)->f114);
    func_021BC464(((struct Obj03362 *)q)->f10);func_021BC464(((struct Obj03362 *)q)->fC);
    func_02030EAC(*(struct Node * *)&((struct Obj03362 *)q)->f0);func_021BC34C(first);
    func_02034A5C((int)ov206_id);func_02034A5C((int)ov067_id);return 1;
}
