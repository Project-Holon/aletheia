/*
 * function: func_021D0218
 * address:  0x021D0218
 * packet:   pkt_ov021_021D0218
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DB8DC     0x021DB8DC  data  ov021  a4
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 *   func_021D0174  0x021D0174  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D0218 {
    u32 h;
    u32 v;
} Arg021D0218;

extern u32 func_021ABEA0(void *a, u32 b);
extern void func_021D0174(u32 h, u32 v);
extern void func_021ABFA8(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern char d_021DB8DC[];

void func_021D0218(void *a, u32 v, u32 c)
{
    Arg021D0218 arg;

    arg.h = func_021ABEA0(a, 0xe);
    arg.v = v;
    func_021D0174(arg.h, v);
    func_021ABFA8(a, d_021DB8DC, c, 0, &arg, 0);
}
