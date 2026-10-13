/*
 * function: MONOLITH_TOOL_UpdateBlink
 * address:  0x021B70C4
 * packet:   pkt_ov071_021B70C4
 * region:   ov071
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 */

typedef unsigned char u8;

typedef struct { int h; u8 a, b, c; } St;

typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void MONOLITH_TOOL_UpdateBlink(St *p)
{
    if (p->a == 1) {
        if (p->b % 5 == 0) {
            func_0204B6F4((struct Obj *)p->h, p->c, 1);
            p->c ^= 1;
            if (p->b / 5 == 3)
                p->a = 0;
        }
        p->b++;
    }
}
