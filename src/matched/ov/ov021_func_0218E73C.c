/*
 * function: func_0218E73C
 * address:  0x0218E73C
 * packet:   pkt_ov021_0218E73C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218E284  0x0218E284  thumb
 *   func_0218E298  0x0218E298  thumb
 *   func_0218E358  0x0218E358  thumb
 *   func_0218E404  0x0218E404  thumb
 */
#include "../include/Obj00428.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void func_0218E284(u8 *a);
extern int func_0218E298(u8 *a);
extern void func_0218E358(u8 *a);
extern void func_0218E404(u8 *a);

void func_0218E73C(u8 *a)
{
    u32 s = ((struct Obj00428 *)a)->f14;
    if (s == 0) {
        func_0218E284(a);
        func_0218E358(a);
    } else if (s == 1) {
        func_0218E298(a);
        func_0218E404(a);
    }
}
