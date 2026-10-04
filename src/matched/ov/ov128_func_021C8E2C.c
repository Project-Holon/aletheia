/*
 * function: func_021C8E2C, func_021C8F24
 * unit: yes
 * address: 0x021C8E2C
 * packet: pkt_ov128_021C8E2C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: Includes the eight-byte forwarding follower at 0x021C8F24.
 * symbols:
 *   func_021C8E24 0x021C8E24 thumb ov128
 *   func_021C9180 0x021C9180 thumb ov128
 *   func_021C8F2C 0x021C8F2C thumb ov128
 *   func_021CA3A0 0x021CA3A0 thumb ov128
 *   func_021CA3C4 0x021CA3C4 thumb ov128
 *   func_0204B98C 0x0204B98C arm
 *   func_021C6438 0x021C6438 thumb ov128
 *   func_021C91CC 0x021C91CC thumb ov128
 *   func_021C9154 0x021C9154 thumb ov128
 */
#include "../include/Obj03813.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C8E24(void *, void *, void *, int);
extern void func_021C9180(void *, void *, void *);
extern int func_021C8F2C(void *, int *);
struct Actor;
extern void func_020061E4(u32 a);
extern void func_021CA3A0(void *);
extern void func_021CA3C4(void *);
extern u32 func_0204B98C(struct Actor *a);
extern void func_021C6438(u8 *p, u8 a, u8 b);
extern void func_021C91CC(char *p, void *q);
extern void func_0202208C(void *, u32, u32, u32, u32, u32, u32);
extern u32 func_020221A4(void);
extern void func_021C9154(char *p, int unused, char *q);
void func_021C8F24(void *, void *, void *);
int func_021C8E2C(void *p, u8 *q, u8 *r, int heap)
{
    int v;
    switch (q[8]) {
    case 0:
        func_021C8E24(p, q, r, 52);
        func_021C9180(p, q, r);
        q[8] = 1;
        break;
    case 1:
        v = func_021C8F2C(p, (int *)q);
        if (v == 0) {
            func_020061E4(0x551);
            func_021CA3A0(r);
            q[8] = 2;
        } else if (v == 1) {
            func_020061E4(0x556);
            func_021CA3C4(r);
            q[8] = 3;
        }
        break;
    case 2:
        if (func_0204B98C(((struct Obj03813 *)r)->f164) != 1) {
            func_021C6438(q, 0, 2);
            func_021C91CC(p, r);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    case 3:
        if (func_0204B98C(((struct Obj03813 *)r)->f168) != 1) q[8] = 4;
        break;
    case 4:
        func_0202208C(0, 0, 0, 0, 6, 1, heap);
        q[8] = 5;
        break;
    case 5:
        if (func_020221A4() == 1) {
            func_021C6438(q, 6, 0);
            func_021C8F24(p, q, r);
            return 1;
        }
        break;
    }
    return 0;
}
void func_021C8F24(void *p, void *q, void *r)
{
    func_021C9154(p, (int)q, r);
}
