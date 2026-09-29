/*
 * function: func_021F0FB0
 * address:  0x021F0FB0
 * packet:   pkt_ov029_021F0FB0
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202173C  0x0202173C  thumb
 *   d_021F31B6     0x021F31B6  data  a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed   short s16;

extern u16 d_021F31B6[];
extern int func_0202173C(void *p, u16 mask, u16 col, s16 step, u8 b, u8 c, u16 d, void *ctx);

void func_021F0FB0(char *p)
{
    func_0202173C(*(void **)(p + 0x210), 8, 0xFFFF, 1, 0x10, 0,
                  d_021F31B6[*(u8 *)(p + 0x459)], *(void **)(p + 0x204));
}
