/*
 * function: func_021F3A78
 * address:  0x021F3A78
 * packet:   pkt_ov056_021F3A78
 * region:   ov056
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     twin of the head of func_021F40A0 (same clock read and clamp),
 *           with the frame counter at +0x28. EXACT* = 54 bytes of code plus
 *           2 bytes of alignment padding before matched func_021F3AB0.
 * symbols:
 *   func_02011608  0x02011608  thumb
 *   func_020115EC  0x020115EC  thumb
 *   func_021F3AB0  0x021F3AB0  thumb  ov056
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef signed int     s32;

struct IcaAnime;
extern u32 func_02011608(struct IcaAnime *p);
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern void func_021F3AB0(u32 *p);

int func_021F3A78(u8 *p)
{
    int flag;
    s32 x = func_02011608(*(struct IcaAnime **)(p + 0x0)) << 12;
    s32 y = *(s32 *)(p + 0x28) + 0x1000;

    if (x <= y) {
        flag = 1;
        *(s32 *)(p + 0x28) = x - 0x1000;
    } else {
        flag = 0;
        *(s32 *)(p + 0x28) = y;
    }
    func_020115EC(*(struct IcaAnime **)(p + 0x0), *(s32 *)(p + 0x28));
    func_021F3AB0((u32 *)p);
    return flag;
}
