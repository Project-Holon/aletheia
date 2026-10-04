/*
 * function: func_0202B2CC
 * address:  0x0202B2CC
 * packet:   pkt_0202B2CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Indexed-eighth-of-a-word helper: a u16 lane at 0xc+2i and a signed u16 lane
 * at 4+2i of the same record, fed to the tile/VRAM helpers.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B2CC.c \
 *       --func func_0202B2CC --addr 0x0202B2CC --thumb --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02005EE0(u32 a, u32 b, u32 c, u32 d);
struct Obj;
extern u32 *func_02005C3C(void);
extern void func_02073018(struct Obj *o, u32 v, u32 w);

void func_0202B2CC(u8 *p, u32 idx)
{
    u32 off = idx << 1;

    func_02005EE0(0xffff, *(u16 *)(p + 0xc + off), 0xffffffff, 0);
    func_02073018((struct Obj *)func_02005C3C(), 0xfcff, (u32)*(short *)(p + 4 + off));
}
