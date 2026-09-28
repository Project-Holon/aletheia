/*
 * function: func_021BDD54
 * address:  0x021BDD54
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C27D8  0x021C27D8  thumb
 *
 * Tail call onto the byte getter func_021C27D8 on the second argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x18];
    u8 f18;
} S;

extern u8 func_021C27D8(S *s);

u8 func_021BDD54(int unused, S *s)
{
    return func_021C27D8(s);
}
