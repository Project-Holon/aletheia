/*
 * function: func_021E5914
 * address:  0x021E5914
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021EE3E4  0x021EE3E4  thumb  ov170
 *   func_021ED55C  0x021ED55C  thumb  ov170
 *   func_021EBA5C  0x021EBA5C  thumb  ov170
 *   func_021DD14C  0x021DD14C  thumb  ov170
 *
 * Refresh the tag-derived index, re-key, arm, retag 0x18, forward,
 *   and report 0x31.
 */
#include "../include/Obj00000.h"


typedef unsigned char  u8;
struct Sound;
extern void func_020260E4(struct Sound *obj, u8 sel);
extern void func_021EE3E4(char *, int);
extern void func_021ED55C(char *, int);
extern void func_021EBA5C(char *p, int i);
extern void func_021DD14C(char *);
int func_021E5914(char *p)
{
    func_020260E4((struct Sound *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x70)),
                  (unsigned char)(((struct Obj00000 *)p)->f16 - 0x1e));
    func_021EE3E4(p, ((struct Obj00000 *)p)->f16 - 0x1e);
    func_021ED55C(p, 1);
    func_021EBA5C((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 0x18);
    func_021DD14C(p);
    return 0x31;
}
