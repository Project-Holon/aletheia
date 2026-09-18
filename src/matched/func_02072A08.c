/*
 * function: func_02072A08
 * address:  0x2072A08
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   g_0214DEC0       0x214DEC0  data
 *
 * The mask is materialised as `mvn r0, r2, lsl r0` (the shift is fused into
 *  * the mvn's second operand) and ANDed in, which is what `&= ~(1 << x)` gives.
 *  *
 *  * The field must be written as a member of the object so the +4 stays in the
 *  * load/store offset: with `*(u32 *)(g_0214DEC0 + 4)` the constant folds into
 *  * the relocation and the pool word becomes 0x0214DEC4, which no other pool
 *  * holds, and every byte around it moves.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct G { u32 f0; u32 f4; u32 f8; };
extern struct G g_0214DEC0;

void func_02072A08(int x)
{
    g_0214DEC0.f4 &= ~(1 << x);
}
