/*
 * function: func_021BA328
 * address:  0x021BA328
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Reconstructed from the listing (.inst decoded).
 *
 * symbols:
 *   func_021BA3E0  0x021BA3E0  thumb  ov217
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u32 func_0204B3DC();
extern u32 func_0204B8C4();
struct Obj;
extern void func_0204B92C(struct Obj *p, unsigned int v);
extern u32 func_0204B954();
extern u32 func_021BA3E0();
u32 func_021BA328(u32 a0)
{
    u32 v1 = func_021BA3E0(a0, 0);
    func_0204B3DC(v1, 1);
    func_0204B92C((struct Obj *)v1, 1);
    func_0204B954(v1, 4096);
    return func_0204B8C4(v1, 0);
}

