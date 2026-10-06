/*
 * function: func_021BD4A8
 * address: 0x021BD4A8
 * packet: pkt_ov099_021BD4A8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BCB70 0x021BCB70 thumb ov099
 *   func_021BBEB4 0x021BBEB4 thumb ov099
 */
#include "../include/Obj07948.h"
#include "../include/Obj22036.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(char *, int);
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *);
struct BigObj;
extern int func_021BCB70(void *rules, const struct BigObj *obj, u32 *mask);
struct O;
extern void func_021BBEB4(struct O *p, int mask, u32 a, int mode);
int func_021BD4A8(char *p, int ret)
{
    int out;
    if (func_021BA928(p, ret) == 0) return ret;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCB70((void *)(((struct Obj07948 *)p)->f1348), (const struct BigObj *)(((struct Obj07948 *)p)->fC4), (u32 *)(&out));
        func_021BBEB4((struct O *)p, out, ((struct Obj22036 *)(*(u8 * *)&((struct Obj07948 *)p)->f248))->f48, 2);
        ((struct Obj07948 *)p)->f1CC = 0x6d;
    }
    return ret;
}
