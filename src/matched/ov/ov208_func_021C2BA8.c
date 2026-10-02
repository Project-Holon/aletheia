/*
 * function: func_021C2BA8
 * address:  0x021C2BA8
 * packet:   pkt_ov208_021C2BA8
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02040618  0x02040618  arm
 *   func_020409B4  0x020409B4  arm
 *   func_021BC6BC  0x021BC6BC  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

extern void func_02040618(int a, int b, int c);
extern void func_020409B4(int a);
extern void func_021BC6BC(char *p);

void func_021C2BA8(void *unused, u8 *p)
{
    if (*(u32 *)(p + 0x1c) != 0) {
        func_02040618(3, 0, *(s16 *)(p + 0x18) - 1);
        func_02040618(3, 3, 0);
        func_020409B4(3);
        *(u32 *)(p + 0x1c) = 0;
    }
    func_021BC6BC(*(char **)(p + 0xc8));
}
