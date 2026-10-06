/*
 * function: func_021B6AE0
 * address:  0x021B6AE0
 * packet:   pkt_ov021_021B6AE0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Formerly MATCH on unwitnessed callees; their matched entries now witness them.
 *
 * symbols:
 *   func_0201134C  0x0201134C  thumb
 *   func_0215A6D0  0x0215A6D0  thumb ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u8 pad[0x14];
    u8 *p;
} Ctx;

struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void func_0215A6D0(void *p, u32 v);

int func_021B6AE0(Ctx *c, void *b)
{
    func_0215A6D0(b, (u32)(c->p + func_0201134C((struct Cursor *)c)));
    return 0;
}
