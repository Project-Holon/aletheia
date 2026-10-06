/*
 * function: func_021DE608
 * address: 0x021DE608
 * packet: pkt_ov171_021DE608
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: mask each translated fixed point coordinate before shifting and narrowing.
 * symbols:
 *   func_0203F6D8 0x0203F6D8 arm
 *   func_0203F684 0x0203F684 arm
 *   func_021DE0C0 0x021DE0C0 thumb ov171
 *   _ll_mul 0x0209C054 arm
 */
typedef unsigned short u16;
typedef signed short   s16;
typedef signed int     s32;
extern s16 func_0203F6D8(s32 x);
extern int func_0203F684(u16);
typedef unsigned char  u8;
extern void func_021DE0C0(u8 *p, int i, int x, int y);
void func_021DE608(char *p, int i, int angle)
{
    int x, y;
    x = (int)(((long long)func_0203F6D8((u16)angle) * 0x64000 + 0x800) >> 12);
    y = (int)(((long long)func_0203F684((u16)angle) * 0x2c000 + 0x800) >> 12);
    x += 0x80000;
    y += 0x58000;
    func_021DE0C0((u8 *)p, i, (short)((x & 0x7ffff000) >> 12),
        (short)((y & 0x7ffff000) >> 12));
}
