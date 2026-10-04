/*
 * function: func_021D046C
 * address:  0x021D046C
 * packet:   pkt_ov021_021D046C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021DB93C     0x021DB93C  data  ov021  a4
 *   func_021ABE18  0x021ABE18  thumb  ov021
 *   func_021ABEA0  0x021ABEA0  thumb  ov021
 *   func_021ABFA8  0x021ABFA8  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Arg021D046C {
    u32 h1;
    u32 h2;
    u32 b;
    u32 c;
} Arg021D046C;

extern int func_021ABEA0(u32 a, u32 b);
extern u32 func_021ABE18(void *a);
extern void func_021ABFA8(void *a, void *b, u32 c, u32 d, void *e, u32 f);
extern char d_021DB93C[];

void func_021D046C(void *a, u32 b, u32 c)
{
    Arg021D046C arg;

    arg.h1 = func_021ABEA0((u32)a, 0xf);
    arg.h2 = func_021ABE18(a);
    arg.b = b;
    arg.c = c;
    func_021ABFA8(a, d_021DB93C, 0, 0, &arg, 0);
}
