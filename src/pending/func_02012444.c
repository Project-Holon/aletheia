/*
 * function: func_02012444
 * address:  0x02012444
 * packet:   pkt_020123D8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * Verified with:
 *   python tools/match.py one --src src/pending/func_02012444.c \
 *       --func func_02012444 --addr 0x02012444 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Desc;

extern struct Desc *sub_020122C0(void *owner, void *a, void *b, u32 size);
extern u32 *sub_020124E8(struct Desc *d);
extern void *func_02012374(void *evt, void **out);
extern void func_0201240C(void);

struct Obj {
    u8    pad_00[0x10];
    void *unk_10;
};

void *func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3)
{
    struct Desc *d;
    u32 *p;

    d = sub_020122C0(obj->unk_10, 0, func_0201240C, 0xc);
    p = sub_020124E8(d);
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    return func_02012374(obj, (void **)d);
}
