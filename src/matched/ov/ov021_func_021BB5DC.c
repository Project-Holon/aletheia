/*
 * function: func_021BB5DC
 * address:  0x021BB5DC
 * packet:   pkt_ov021_021BB5DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021AC1AC  0x021AC1AC  thumb  ov021
 *   func_021AC178  0x021AC178  thumb  ov021
 */

typedef struct {
    int w[7];
} Blk;

typedef struct {
    Blk b;
    char pad[0x10];
    int f2C;
} Out;

extern Blk *func_021AC1AC(int a);
extern void func_021AC178(int a);

void func_021BB5DC(int a, Out *out)
{
    out->b = *func_021AC1AC(a);
    out->f2C = 0x6000;
    func_021AC178(a);
}
