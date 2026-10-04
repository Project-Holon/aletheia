/*
 * function: func_0216F228
 * address:  0x0216F228
 * packet:   pkt_ov010_0216F228
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_020315D4  0x020315D4  arm
 *   func_020306F0  0x020306F0  arm
 */
#include "../include/Obj19151.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_020307B0(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int heap);

int func_0216F228(void *a, int b, int c, char *d)
{
    func_020307B0(((struct Obj19151 *)d)->f18);
    func_020315D4(a);
    func_020306F0(0x26);
    return 1;
}
