/*
 * function: func_02046A94
 * address:  0x02046A94
 * packet:   pkt_02046858
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A5C   0x02146A5C  data
 *   func_0206AA3C 0x0206AA3C  arm
 *   func_0206AA78 0x0206AA78  arm
 *
 * A four-halfword record written into an eight-byte slot of the global
 * context at index `idx` (the slot base is ctx + idx*8 and the record starts
 * at +0x3c of it), then the same fields read back signed for the first
 * notification call and unsigned for the second.  The context pointer is
 * re-read from its slot once per statement group because each call may
 * replace it, which is why the field accesses are not CSE'd into one load.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02046A94.c \
 *       --func func_02046A94 --addr 0x02046A94 --cc 1.1p1 --arm
 */
#include "../include/Obj06969.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef short          s16;
typedef unsigned int   u32;

extern u8 *g_02146A5C;

extern void func_0206AA3C(int idx, int a, int b, int c);
extern void func_0206AA78(int idx, u32 v);

void func_02046A94(u32 idx, const u16 *src)
{
    u8 *p = g_02146A5C + idx * 8;

    ((struct Obj06969 *)p)->f3C = src[0];
    ((struct Obj06969 *)p)->f3E = src[1];
    ((struct Obj06969 *)p)->f40 = src[2];
    ((struct Obj06969 *)p)->f42 = src[3];

    func_0206AA3C(idx, *(s16 *)(g_02146A5C + idx * 8 + 0x3c),
                  *(s16 *)(g_02146A5C + idx * 8 + 0x3e),
                  *(s16 *)(g_02146A5C + idx * 8 + 0x40));
    func_0206AA78(idx, *(u16 *)(g_02146A5C + idx * 8 + 0x42));
}
