/*
 * function: func_021BDCD0
 * address:  0x021BDCD0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201283C  0x0201283C  thumb
 *   func_02009860  0x02009860  thumb
 *
 * Hands the handle at +0xC4 to one arm9 accessor and its result to another.
 */
#include "../include/Obj18249.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
extern void func_02009860(int a);

void func_021BDCD0(char *p)
{
    func_02009860(func_0201283C(((struct Obj18249 *)p)->fC4));
}
