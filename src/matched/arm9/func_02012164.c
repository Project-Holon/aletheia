/*
 * function: func_02012164
 * address:  0x02012164
 * packet:   pkt_02012164
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F8  0x020120F8  thumb
 *   func_02012AC8  0x02012AC8  thumb
 *   func_02013D34  0x02013D34  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_0201214C  0x0201214C  thumb
 *   func_02158318  0x02158318  thumb  ov010
 *   func_02035390  0x02035390  arm
 *   func_020353B0  0x020353B0  arm
 *   func_0200921C  0x0200921C  thumb
 *   func_020090E0  0x020090E0  thumb
 *
 * blocker:  label -- func_02158318 (ov010, thumb) is traced in ov010's
 *           listing but its only caller in the whole image is the bl at
 *           +0x38 inside this range, so `label` has no outside witness and
 *           sole-ref/code does not consider overlay starts.  Every concrete
 *           byte is right (MATCH*: the extent runs over the 2-byte pad).
 *
 * The note's 4-byte r0/r1 "tie" (docs/notes/pkt_02012164.c.txt) was a
 * misread arity: func_02012AC8 is `ldrh r0, [r0]; bx lr`, a getter taking
 * the pointer func_020120F8 returns, and func_02013D34 takes that u16 in
 * r0 -- so the image keeps it in r0 across the p->f32 test and reads the
 * byte through r1.  `id = func_02012AC8(func_020120F8(p))` then
 * `func_02013D34(id)` closes it.
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct IcaAnime {
    u8  pad00[0x1c];
    void *f1c;
    u8  pad20[0x12];
    u8  f32;
};

extern void *func_02012138(struct IcaAnime *p);
extern u8   *func_020120F8(struct IcaAnime *p);
extern u16   func_02012AC8(u8 *h);
struct Sub02009210Obj;
extern u32 func_02013D34(u32 id);
extern u32   func_0200FB24(void);
extern u32   func_0201214C(struct IcaAnime *p);
extern u32   func_02158318(struct IcaAnime *p);
extern u32   func_02035390(void);
extern int func_020353B0(void);
extern struct Sub02009210Obj *func_0200921C(void *p);
extern u8    func_020090E0(void *obj);

u32 func_02012164(struct IcaAnime *p)
{
    u16 id;

    func_02012138(p);
    id = func_02012AC8(func_020120F8(p));
    if (p->f32 == 0
     && func_02013D34(id) == 0
     && func_0200FB24() == 0
     && func_0201214C(p) == 1
     && func_02158318(p) == 1
     && !(func_02035390() == 1 && func_020353B0() == 1)) {
        if (func_020090E0(func_0200921C(p->f1c)) != 0) {
            return 1;
        }
    }
    return 0;
}
