/*
 * function: func_0219CB98
 * address:  0x0219CB98
 * packet:   pkt_ov021_0219CB98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0219CA98  0x0219CA98  thumb  ov021
 *   func_02050278  0x02050278  arm
 *   func_0219C52C  0x0219C52C  thumb  ov021
 *   func_0219CA6C  0x0219CA6C  thumb  ov021
 */
#include "../include/Obj00429.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef struct { u16 a; u16 b; u16 c; u16 pad; } Ent;
typedef struct { int n; Ent *e; } Tbl;
extern void func_0219CA98(Tbl *, u16, u16 *, u16 *);
struct BbActSys;
extern void func_02050278(struct BbActSys *o, u32 first, u32 count);
extern void func_0219C52C(u32 a, u32 b);
extern void func_0219CA6C(Tbl *t, u16 k);

void func_0219CB98(u8 *s, u16 k)
{
    u16 t[2];
    func_0219CA98((Tbl *)(s + 0x14), k, &t[0], &t[1]);
    if (t[1] & 2) {
        func_02050278((struct BbActSys *)(((struct Obj00429 *)s)->f4), t[0], 1);
    } else {
        func_0219C52C(((struct Obj00429 *)s)->f4, t[0]);
    }
    func_0219CA6C((Tbl *)(s + 0x14), k);
}
