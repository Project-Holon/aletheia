/*
 * function: func_021ABD08
 * address:  0x021ABD08
 * packet:   pkt_ov021_021ABD08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AB760  0x021AB760  thumb
 *   func_021ABBA0  0x021ABBA0  thumb
 *   func_0207C768  0x0207C768  arm
 *   func_0218ED64  0x0218ED64  thumb
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x38];
    u16 h38;
    u16 h3a;
} S;

extern int func_021AB760(int a);
extern void func_021ABBA0(const S *s, int c, int *y, int *x);
typedef unsigned int   u32;
extern u32 func_0207C768(u32 a, u32 b);
typedef unsigned char  u8;
extern void func_0218ED64(u8 *a, u16 angle);

/*
 * const on s lets mwcc hoist the two field loads above the store to the
 * address-taken x (see docs/idioms/a-const-source-pointer-hoists-the-last-
 * load-of-a-struct-copy-into-an-address-taken-local.md); the assignment
 * must stay inside the multiply for the result to land in r3.
 */
void func_021ABD08(int a, const S *s, int c)
{
    int h = func_021AB760(a);
    int y;
    int x;
    func_021ABBA0(s, c, &y, &x);
    func_0218ED64((u8 *)h, s->h38 + (s->h3a - s->h38) * (x = func_0207C768(x, y)) / 0x1000);
}
