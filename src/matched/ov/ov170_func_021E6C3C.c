/*
 * function: func_021E6C3C
 * address: 0x021E6C3C
 * packet: pkt_ov170_021E6C3C
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021ECB60 0x021ECB60 thumb ov170
 *   func_021EA750 0x021EA750 thumb ov170
 *   func_0202136C 0x0202136C thumb
 *   func_020061E4 0x020061E4 thumb
 *   func_021ED55C 0x021ED55C thumb ov170
 *   func_021EBB28 0x021EBB28 thumb ov170
 *   func_020260E0 0x020260E0 thumb
 *   func_021DEFEC 0x021DEFEC thumb ov170
 *   func_021EE038 0x021EE038 thumb ov170
 */
#include "../include/Obj00000.h"
extern void func_021ECB60(char *w, int i, int f);
extern void func_021EA750(unsigned char *p);
extern unsigned func_0202136C(unsigned short v);
extern void func_020061E4(unsigned se);
extern void func_021ED55C(char **p, int flag);
extern void func_021EBB28(unsigned char *p, int b);
typedef unsigned char  u8;
struct Sound;
extern u8 func_020260E0(struct Sound *obj);
extern void func_021DEFEC(unsigned char *p, int b);
extern void func_021EE038(char *p, int a, int b, int c);
#define WORK(p) (*(char **)((p) + 0x2C))
#define STEP(p) (*(int *)(WORK(p) + 0xA194))
typedef struct { unsigned char pad[0x1C]; unsigned char lo:4; unsigned char hi:4; } Flags;
int func_021E6C3C(unsigned char *p)
{
    unsigned short *o;
    unsigned char old;
    unsigned short slot, item;
    unsigned char r;
    if (((Flags *)p)->lo == 0)
        ((Flags *)p)->hi = 1;
    o = *(unsigned short **)(WORK(p) + 0x60);
    func_021ECB60(WORK(p), o[0], 0);
    old = p[0x16];
    slot = o[1];
    p[0x16] = o[0];
    func_021EA750(p);
    item = *(unsigned short *)(WORK(p) + 0xA16C);
    *(unsigned short *)(WORK(p) + 0xA16C) = 0;
    if (func_0202136C(item) == 1 && slot != old) {
        func_020061E4(0x557);
        func_021ED55C((char **)p, 0);
        func_021EBB28(p, 0x18);
        ((struct Obj00000 *)p)->f28 = 0x44;
        return 6;
    }
    func_021ED55C((char **)p, 1);
    r = func_020260E0(*(void **)(WORK(p) + 0x70));
    if (r < 0x24)
        func_021DEFEC(p, r);
    func_021EE038((char *)p, 0, 1, 1);
    return 0x40;
}
