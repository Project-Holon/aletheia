/*
 * function: func_021BC168
 * address:  0x021BC168
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC1AC  0x021BC1AC  thumb  ov217
 *   func_021BC428  0x021BC428  thumb  ov217
 *   func_021BC720  0x021BC720  thumb  ov217
 *
 * Packs a 0xF8 message (second halfword from func_021BC1AC()) and pushes
 * it through the +0x0c channel, on the path where func_021BC428() is clear.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Obj;
extern void func_0204B3DC(struct Obj *, unsigned int);
extern u32 func_0204B404();
extern u32 func_021BC1AC();
extern u32 func_021BC428();
extern u32 func_021BC720();
void func_021BC168(u32 a0)
{
    u8 s[4];
    u32 v1 = func_021BC720(a0, 0);
    if (func_021BC428(a0) == 0) {
    func_0204B3DC((struct Obj *)v1, 0);
    return;
    }
    *(u16*)(((u8*)s)) = 248;
    *(u16*)(((u8*)s) + 2) = func_021BC1AC(a0);
    func_0204B404(v1, s, 0);
    func_0204B3DC((struct Obj *)v1, 1);
}
