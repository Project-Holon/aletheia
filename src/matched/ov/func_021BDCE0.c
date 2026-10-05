/*
 * function: func_021BDCE0
 * address:  0x021BDCE0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0201283C  0x0201283C  thumb
 *   func_020099C8  0x020099C8  thumb
 *
 * Two arm9 calls: the pointer at +0xC4 goes through the first and the answer into the second with a zero selector.
 */
#include "../include/Obj18250.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

struct BigObj;
extern u32 func_0201283C(const struct BigObj *p);
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern struct Sub020097BCFriend *func_020099C8(struct Sub020097BCObj *obj, int i);

void func_021BDCE0(char *p)
{
    func_020099C8((struct Sub020097BCObj *)func_0201283C(((struct Obj18250 *)p)->fC4), 0);
}
