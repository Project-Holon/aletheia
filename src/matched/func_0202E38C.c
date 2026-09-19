/*
 * function: func_0202E38C
 * address:  0x0202E38C
 * packet:   pkt_0202E0E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_02045770  0x02045770  arm
 *   sub_02043B5C  0x02043B5C  arm
 *   sub_02045334  0x02045334  arm
 *   sub_020456F8  0x020456F8  arm
 *   sub_02045730  0x02045730  arm
 *   sub_020409B4  0x020409B4  arm
 *   sub_0204B3DC  0x0204B3DC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202E38C.c \
 *       --func func_0202E38C --addr 0x0202E38C --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Obj0202E38C {
    u32 f00;
    u32 f04;
    u32 f08[2];
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20[2];
};

extern u32 sub_02045770(u32 a);
extern void sub_02043B5C(u32 a, u32 b);
extern void sub_02045334(u32 a);
extern void sub_020456F8(u32 a);
extern void sub_02045730(u32 a);
extern void sub_020409B4(void);
extern void sub_0204B3DC(u32 a, u32 b);

void func_0202E38C(struct Obj0202E38C *obj, u32 a1)
{
    u32 h;
    int i;

    sub_02043B5C(sub_02045770(obj->f00), 0);
    if (a1 != 0) {
        sub_02045334(obj->f00);
        h = obj->f00;
        sub_020456F8(h);
        sub_02045730(h);
        sub_020409B4();
    }
    for (i = 0; i < 2; i++) {
        sub_0204B3DC(obj->f08[i], 0);
        obj->f20[i] = 0;
    }
    obj->f10 = 0;
    obj->f14 = 0;
    obj->f18 &= ~1;
    obj->f18 &= ~2;
}
