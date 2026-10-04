/*
 * function: func_0202E3E4
 * address:  0x0202E3E4
 * packet:   pkt_0202E0E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   sub_02045374  0x02045374  arm
 *   sub_020456F8  0x020456F8  arm
 *   sub_02045730  0x02045730  arm
 *   sub_02041B6C  0x02041B6C  arm
 *   sub_0204B3DC  0x0204B3DC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E3E4.c \
 *       --func func_0202E3E4 --addr 0x0202E3E4 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Obj0202E3E4 {
    u32 f00;
    u32 f04;
    u32 f08[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20[2];
};

typedef unsigned char  u8;
struct Cfg;
struct Descriptor;
extern void sub_02045374(struct Cfg *cfg);
extern void sub_020456F8(struct Descriptor *d);
extern u8 sub_02045730(struct Descriptor *p);
extern void sub_02041B6C(u32 bit);
struct Obj;
extern void sub_0204B3DC(struct Obj *a, unsigned int b);

void func_0202E3E4(struct Obj0202E3E4 *obj, u32 a1)
{
    int i;

    obj->f18 = (obj->f18 & ~2) | ((a1 & 1) << 1);
    if (a1 != 0)
        sub_02045374((struct Cfg *)obj->f00);
    else
        sub_020456F8((struct Descriptor *)obj->f00);
    sub_02041B6C(sub_02045730((struct Descriptor *)obj->f00));
    for (i = 0; i < 2; i++) {
        if (obj->f20[i] != 0)
            sub_0204B3DC((struct Obj *)obj->f08[i], a1);
    }
}
