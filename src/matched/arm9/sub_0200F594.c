/*
 * function: sub_0200F594
 * address:  0x0200F594
 * packet:   pkt_0200F38C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * blocking: unresolved: 0200F520 (thumb, from header) has no witness outside 0200F594..0200F
 *
 * symbols:
 *   sub_02008554   0x02008554  thumb
 *   sub_02009918   0x02009918  thumb
 *   sub_020099C8   0x020099C8  thumb
 *   sub_0200F520   0x0200F520  thumb
 *   sub_0201283C   0x0201283C  thumb
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sub0200852CObj;
struct Sub020097BCFriend;
struct Sub020097BCObj;
extern u8 sub_02008554(const struct Sub0200852CObj *obj);
extern void sub_02009918(struct Sub020097BCObj *obj, u32 i, u32 field, u32 value);
extern struct Sub020097BCFriend *sub_020099C8(struct Sub020097BCObj *obj, int i);
extern void  sub_0200F520(void *obj, void *src, int i, void *sel, int flag);
extern void *sub_0201283C(void *a);
extern void  func_02082D44(void *dst, const void *src, unsigned n);

void sub_0200F594(void *a0, void *a1, void *a2, int a3, void *a4, int mode)
{
    void *obj = sub_0201283C(a0);
    void *src = sub_020099C8(obj, a3);

    if (mode != 2) {
        func_02082D44(a2, src, 0xc);
    }
    if (mode == 0) {
        sub_0200F520(obj, a1, a3, a4, 1);
    } else if (mode == 1) {
        sub_0200F520(obj, a1, a3, a4, 0);
    }
    sub_02009918(obj, a3, 8, sub_02008554(a1));
}
