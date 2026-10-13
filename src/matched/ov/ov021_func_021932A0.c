/*
 * function: FIELD_MSGBG_StreamSetSpeed
 * address:  0x021932A0
 * packet:   pkt_ov021_021932A0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02013080  0x02013080  thumb  arm9
 *   func_0201CE8C  0x0201CE8C  thumb  arm9
 *   func_0201CEB8  0x0201CEB8  thumb  arm9
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

extern signed char func_02013080(u32 idx);
typedef signed int     s32;
struct Rec;
extern void func_0201CE8C(struct Rec *p, s32 v);
extern void func_0201CEB8(struct Rec *p);

void FIELD_MSGBG_StreamSetSpeed(u32 a, int f)
{
    if (f == 1)
        func_0201CE8C((struct Rec *)a, func_02013080(2));
    else
        func_0201CEB8((struct Rec *)a);
}
