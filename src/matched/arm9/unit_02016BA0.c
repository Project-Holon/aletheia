/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02016BA0
 * packet:   pkt_02015F2C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02016BA0, sub_02016C0C
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02030EE8  0x02030EE8  arm
 *   func_02016C0C  0x02016C0C  thumb
 *
 * alias: a teardown chain on the same object class as unit_02015BA4.c.
 * sub_02016BA0 releases eight pointer fields of the object through
 * func_020307B0 (a generic release call reached by blx, so it is ARM),
 * zeroes three of them (+0x98, +0xd4, +0xd8, all past the immediate str
 * reach so the compiler adds the offset into a register first), then
 * zeroes the other four (+0xc, +0x1c, +0x14, +0x24, +0x2c) and, if the
 * object's own field at +0 is non-zero, recurses into sub_02016C0C with
 * that field's value before zeroing it too. sub_02016C0C turns an id into
 * an object through func_02030EE8, releases one or two of the object's own
 * pointer fields the same way, releases the object itself, and finally
 * releases the id through func_02030EAC.
 *
 * The immediate follower, sub_02016C38 (38 bytes, same shape over a third
 * field, one level of extra indirection), is a documented near miss: this
 * front end assigns it only two callee-saved registers (padding a filler
 * into r3) where the original spends three (r4, r5, r6), so the second
 * fetch of the inner pointer is a register move here and a reload from
 * memory in every source shape tried. Left out rather than forced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02016BA0.c \
 *       --addr 0x02016BA0 --thumb
 */

typedef unsigned char u8;

extern void func_020307B0(void *obj);
struct Node;
extern void func_02030EAC(struct Node *n);
typedef unsigned int   u32;
struct S02030EE8;
extern u32 func_02030EE8(struct S02030EE8 *p);
extern void func_02016C0C(void *id);

void sub_02016BA0(void *obj)
{
    u8 *o = (u8 *)obj;

    func_020307B0(*(void **)(o + 0xc));
    func_020307B0(*(void **)(o + 0x1c));
    func_020307B0(*(void **)(o + 0x14));
    func_020307B0(*(void **)(o + 0x24));
    func_020307B0(*(void **)(o + 0x98));
    func_020307B0(*(void **)(o + 0x2c));
    func_020307B0(*(void **)(o + 0xd4));
    func_020307B0(*(void **)(o + 0xd8));

    *(void **)(o + 0x98) = 0;
    *(void **)(o + 0xd4) = 0;
    *(void **)(o + 0xd8) = 0;

    {
        void *v = *(void **)o;
        *(void **)(o + 0xc) = 0;
        *(void **)(o + 0x1c) = 0;
        *(void **)(o + 0x14) = 0;
        *(void **)(o + 0x24) = 0;
        *(void **)(o + 0x2c) = 0;
        if (v != 0) {
            func_02016C0C(v);
            *(void **)o = 0;
        }
    }
}

void sub_02016C0C(void *id)
{
    void *obj = (void *)func_02030EE8(id);

    if (*(void **)((u8 *)obj + 0x10) != 0) {
        func_020307B0(*(void **)((u8 *)obj + 0x10));
    }
    if (*(void **)((u8 *)obj + 0x14) != 0) {
        func_020307B0(*(void **)((u8 *)obj + 0x14));
    }
    func_020307B0(obj);
    func_02030EAC(id);
}
