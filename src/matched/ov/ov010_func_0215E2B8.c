/*
 * function: func_0215E2B8
 * address:  0x0215E2B8
 * packet:   pkt_ov010_0215E2B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02082BCC  0x02082BCC  arm
 *   func_02013EC0  0x02013EC0  thumb
 *   func_020493D4  0x020493D4  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   func_0204944C  0x0204944C  arm
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct R {
    u8 pad00[7];
    u8 f7;
};

extern void func_02082BCC(void *p, int v, int n);
extern u32 func_02013EC0(u32 id);
struct ArcFile;
extern u32 func_020493D4(struct ArcFile *arc, u32 member);
struct ArcFile;
extern void func_0204944C(struct ArcFile *a, u32 b, u32 c, u32 d, void *e);

int func_0215E2B8(struct R *r, int a, int b, int n)
{
    u32 q;
    int v;

    func_02082BCC(r, 0, 0xe8);
    v = func_02013EC0(b);
    if (v == 0xffff) {
        return 0;
    }
    q = func_020493D4((struct ArcFile *)a, v) / 0xe8;
    if (q != 1 && q != 4) {
        return 0;
    }
    if (q == 1) {
        n = 0;
    }
    func_0204944C((struct ArcFile *)a, v, n * 0xe8, 0xe8, r);
    r->f7 |= 0x80;
    return 1;
}
