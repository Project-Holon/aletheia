/*
 * function: func_021BD500
 * address: 0x021BD500
 * packet: pkt_ov099_021BD500
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BA928 0x021BA928 thumb ov099
 *   func_020362DC 0x020362DC arm
 *   func_021BA8EC 0x021BA8EC thumb ov099
 *   func_021BCBBC 0x021BCBBC thumb ov099
 *   func_021BBEB4 0x021BBEB4 thumb ov099
 */
#include "../include/Obj07949.h"
#include "../include/Obj22037.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BA928(char *p, int result);
extern u32 func_020362DC(void);
extern void func_021BA8EC(char *p);
extern int func_021BCBBC(int a, int b, int *out);
extern void func_021BBEB4(char *p, int a, u8 b, int c);
int func_021BD500(char *p, int result)
{
    int out;
    if (func_021BA928(p, result) == 0) return result;
    if (func_020362DC() != 0) {
        func_021BA8EC(p);
        func_021BCBBC(((struct Obj07949 *)p)->f1348, ((struct Obj07949 *)p)->fCC, &out);
        func_021BBEB4(p, out, ((struct Obj22037 *)(*(u8 * *)&((struct Obj07949 *)p)->f248))->f48, 3);
        ((struct Obj07949 *)p)->f1CC = 0x6d;
    }
    return result;
}
