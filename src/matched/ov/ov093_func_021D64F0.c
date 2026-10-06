/*
 * function: func_021D64F0
 * address:  0x021D64F0
 * packet:   pkt_ov093_021D64F0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02017E40  0x02017E40  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_021D533C  0x021D533C  thumb  ov093
 *   func_021D5150  0x021D5150  thumb  ov093
 *   func_021D5364  0x021D5364  thumb  ov093
 *   func_021D539C  0x021D539C  thumb  ov093
 *   func_021D6E88  0x021D6E88  thumb  ov093
 *   func_021D6C2C  0x021D6C2C  thumb  ov093
 *   func_021D6D70  0x021D6D70  thumb  ov093
 *   func_021D63B8  0x021D63B8  thumb  ov093
 *   func_021D53C0  0x021D53C0  thumb  ov093
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 */
#include "../include/Obj00041.h"
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef struct {
    void *w;
    u8 pad4[0x12];
    u16 f16;
    u8 pad18[3];
    u8 f1b_lo : 5;
    u8 f1b_b5 : 1;
} Obj;
extern void func_02082BCC(void *dst, u8 v, u32 n);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185C4(void *p);
struct S;
struct Unk021D6C2C;
struct UtilWork;
struct Work;
extern void func_021D533C(struct S *p);
extern void func_021D5150(struct Work *p);
extern void func_021D5364(struct UtilWork *p);
extern void func_021D539C(struct UtilWork *p);
extern void func_021D6E88(u8 *p);
extern void func_021D6C2C(struct Unk021D6C2C *p);
extern void func_021D6D70(unsigned char *p);
extern void func_021D63B8(u8 *p, int all);
extern int func_021D5BDC(struct UtilWork *p, u32 n);
extern void func_021D53C0(unsigned char *p);

void func_021D64F0(Obj *p)
{
    func_02082BCC((u8 *)p + 0x153, 0, 2);
    func_021D533C((struct S *)p);
    func_021D5150((struct Work *)p);
    func_021D5364((struct UtilWork *)p);
    func_021D539C((struct UtilWork *)p);
    func_021D6E88((u8 *)p);
    func_021D6C2C((struct Unk021D6C2C *)p);
    if (func_021D5BDC((struct UtilWork *)p, 0xe) == 0) {
        func_021D6D70((unsigned char *)p);
        func_021D63B8((u8 *)p, 0);
        func_021D53C0((unsigned char *)((char *)p + 0xfc));
        func_02082BCC((u8 *)p + 0x155, 0, 2);
    }
    ((u8 *)p)[0x141] = p->f1b_lo;
    ((struct Obj00041 *)p)->f13C = p->f16;
    func_02017E40(p->w, 0x6f, ((u8 *)p)[0x141]);
    func_020185C4(p->w);
}
