/*
 * function: func_021BD994
 * address:  0x021BD994
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_020399A8  0x020399A8  arm
 *   sub_02039C68  0x02039C68  arm
 *
 * The result of the first arm9 call is the first argument of the second.
 * Returns the second argument.
 */
#include "../include/Obj18245.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct Entry;
extern struct Entry *sub_020399A8(void);
struct Link;
extern void sub_02039C68(struct Link *a, unsigned int b, unsigned int c);

int func_021BD994(void *v, int b)
{
    sub_02039C68((struct Link *)sub_020399A8(), 0x1B, 0x0A);
    ((struct Obj18245 *)v)->f1CC = 0x8B;

    return b;
}
