/*
 * function: func_021B9E7C
 * address:  0x021B9E7C
 * packet:   pkt_ov088_021B9E7C
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     listing extent (72) runs 2 bytes past the compiled function (70);
 *           trailing alignment padding, no byte difference.
 *
 * symbols:
 *   func_020115EC  0x020115EC  thumb
 *   func_020489F4  0x020489F4  arm
 *   func_02048A18  0x02048A18  arm
 *   func_0204784C  0x0204784C  arm
 */

typedef signed int     s32;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct AnmCtl;
struct IcaAnime;
extern void func_020115EC(struct IcaAnime *p, s32 v);
extern u32 func_020489F4(u8 *a0, int i);
extern u32 func_02048A18(u8 *a0, int i);
extern u32 func_0204784C(struct AnmCtl *c, u32 idx, s32 *frame);

void func_021B9E7C(int *p, int x)
{
    int v;
    int base;
    unsigned i;
    void *h;
    v = x << 12;
    func_020115EC((void *)p[3], v);
    base = func_020489F4((void *)p[0], *(unsigned short *)((char *)p + 4));
    for (i = 0; i < 3; i++) {
        h = (void *)func_02048A18((void *)p[0], (unsigned short)(base + i));
        func_0204784C(h, 0, &v);
        if (i == 0)
            func_0204784C(h, 1, &v);
    }
}
