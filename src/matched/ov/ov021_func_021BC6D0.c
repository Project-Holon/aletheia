/*
 * function: func_021BC6D0
 * address:  0x021BC6D0
 * packet:   pkt_ov021_021BC6D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef struct {
    char pad[0xC];
    int fC;
} Inner;

typedef struct {
    char pad[0x150];
    Inner *f150;
} Obj;

extern void func_02040E78(int a, int b, int c, int d);

void func_021BC6D0(Obj *p)
{
    func_02040E78(3, p->f150->fC, 0x20, 0);
}
