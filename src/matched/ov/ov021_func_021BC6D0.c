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

typedef unsigned int   u32;
extern void func_02040E78(u32 r7, void *r6, u32 r5, u32 r4);

void func_021BC6D0(Obj *p)
{
    func_02040E78(3, (void *)p->f150->fC, 0x20, 0);
}
