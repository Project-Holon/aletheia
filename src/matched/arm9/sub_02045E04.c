/*
 * unit:     no
 * function: sub_02045E04
 * address:  0x02045E04
 * packet:   pkt_02045C44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sub_020458F8  0x020458F8  arm
 *   sub_02045A90  0x02045A90  arm
 *   sub_02045E3C  0x02045E3C  arm
 *   sub_02045900  0x02045900  arm
 *
 * Advance the object by one: read its current index (sub_020458F8), ask
 * sub_02045E3C for the entry one past it in the list sub_02045A90 returns,
 * and install the answer with sub_02045900.
 *
 * Three of the four calls need the object pointer, so it is pinned in r6
 * for the whole body; the incoming second argument survives in r5 across
 * two calls before reaching sub_02045E3C's r2.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_02045E04.c \
 *       --func sub_02045E04 --addr 0x02045E04 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;
typedef signed int    s32;

struct Obj {
    u8 unk_00[1];
};

extern s32   sub_020458F8(struct Obj *o);
extern void *sub_02045A90(struct Obj *o);
typedef unsigned short u16;
extern u32 sub_02045E3C(u16 *str, u32 count, u32 msgIndex);
extern void  sub_02045900(struct Obj *o, s32 index);

void sub_02045E04(struct Obj *o, u32 mode)
{
    s32 index = sub_020458F8(o);

    sub_02045900(o, sub_02045E3C(sub_02045A90(o), index + 1, mode));
}
