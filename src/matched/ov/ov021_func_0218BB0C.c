/*
 * function: func_0218BB0C
 * address:  0x0218BB0C
 * packet:   pkt_ov021_0218BB0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020490F4  0x020490F4  arm
 *   func_0204961C  0x0204961C  arm
 *   func_02049250  0x02049250  arm
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj00572.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020490F4(unsigned int id, u16 heap);
struct ArcFile;
extern u16 func_0204961C(void *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_02049238(void *h);

void func_0218BB0C(u8 *s, u32 a, u32 n)
{
    void *h;
    u8 *r;

    h = func_020490F4(a, (((struct Obj00572 *)s)->f0 & 0x7fff) | 0x8000);
    if (func_0204961C(h) <= n)
        n = 0;
    r = func_02049250(h, n, ((struct Obj00572 *)s)->f0);
    *(u8 * *)&((struct Obj00572 *)s)->f18 = r;
    ((struct Obj00572 *)s)->f1AC = (u32)r[2] >> 1;
    if (((struct Obj00572 *)s)->f1AC > 0x190)
        ((struct Obj00572 *)s)->f1AC = 0x80;
    func_02049238(h);
}
