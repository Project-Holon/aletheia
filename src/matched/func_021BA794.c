/*
 * function: func_021BA794
 * address:  0x021BA794
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA770  0x021BA770  thumb  ov099
 *   func_021BA78C  0x021BA78C  thumb  ov099
 *
 * Records the bit selector at +0x0C and toggles it in the byte mask at +0x08;
 * releases the previous holder through func_021BA770 first when +0x0D is set,
 * and always finishes through func_021BA78C.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021BA770(void *p);
extern void func_021BA78C(void *p);

void func_021BA794(u8 *p, u8 b)
{
    if (p[0xD] != 0) {
        func_021BA770(p);
    }

    p[0xC] = b;
    p[0x8] ^= (u8)(1 << b);
    func_021BA78C(p);
}
