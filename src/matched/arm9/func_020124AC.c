/*
 * function: func_020124AC
 * address:  0x020124AC
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020124AC.c \
 *       --func func_020124AC --addr 0x020124AC --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Desc;

extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern u32 *sub_020124E8(struct Desc *d);
typedef signed int     s32;
extern int func_02012474(void *a0, u32 *a1, u32 *a2);
extern int func_02034AC4(s32 handle);

struct Desc *func_020124AC(void *a0, u32 a1, u32 (*fn)(void *, u32), u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = sub_020122C0(a0, 0, func_02012474, 0x10);
    p = sub_020124E8(d);
    p[0] = a1;
    func_02034AC4(a1);
    p[1] = fn(a0, a3);
    return d;
}

