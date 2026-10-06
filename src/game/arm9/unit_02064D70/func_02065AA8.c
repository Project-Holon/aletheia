/*
 * function: func_02065AA8
 * address:  0x02065AA8
 * packet:   pkt_02065AA8
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Byte-correct under the ../2.0/sp2 pin (0 concrete mismatches at the
 * original's 188 bytes); 1.1p1 is 184 bytes and 62 out.  Parked, not filed:
 * the PC24 site at +0x0008 needs func_02067A60, whose only branch anywhere
 * in the image is this function's own bl, so `label` has no outside witness.
 *
 * symbols:
 *   func_02067A60  0x02067A60  arm
 *   func_02082AC0  0x02082AC0  arm
 *   g_02147B88     0x02147B88  data
 *   g_020A81F8     0x020A81F8  data
 *   g_02148318     0x02148318  data
 *   g_02147C18     0x02147C18  data
 */
#include "../../../matched/include/Obj02326.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct S;
extern void func_02067A60(struct S *p);
extern void func_02082AC0(int a, void *p, int n);
extern u8 g_02147B88[];
extern u8 g_020A81F8[];
extern u8 g_02148318[];
extern u8 g_02147C18[];

void func_02065AA8(u8 *o)
{
    int i;
    u8 *p;
    int m1;
    int sz;
    func_02067A60((struct S *)o);
    i = 0;
    ((struct Obj02326 *)o)->f70 = i;
    ((struct Obj02326 *)o)->f74 = i;
    ((struct Obj02326 *)o)->f78 = i;
    ((struct Obj02326 *)o)->f7C = i;
    ((struct Obj02326 *)o)->f80 = i;
    ((struct Obj02326 *)o)->f84 = i;
    ((struct Obj02326 *)o)->f88 = i;
    ((struct Obj02326 *)o)->f8A = i;
    ((struct Obj02326 *)o)->f8C = i;
    ((struct Obj02326 *)o)->f90 = i;
    ((struct Obj02326 *)o)->f94 = i;
    *(u32 *)(g_02147B88 + 0xc) = i;
    *(u16 *)g_020A81F8 = 0xFFFE;
    m1 = -1;
    sz = 0x10;
    p = g_02148318;
    do {
        func_02082AC0(m1, p + 0x10, sz);
        i = i + 1;
        p = p + 0x20;
    } while (i < 0x20);
    *(u16 *)g_02147B88 = 0;
    *(u16 *)(g_02147B88 + 2) = 0;
    func_02082AC0(0, g_02147C18, 0x100);
    *(u32 *)(g_02147B88 + 4) = 0;
}
