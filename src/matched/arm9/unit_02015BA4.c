/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * address:  0x02015BA4
 * packet:   pkt_02015BA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02015BA4, sub_02015BF0, sub_02015C00, sub_02015C0C,
 *           sub_02015C1C
 *
 * symbols:
 *   func_02016BA0  0x02016BA0  thumb
 *   func_02016C0C  0x02016C0C  thumb
 *   func_02016C38  0x02016C38  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * alias: sub_02015BA4 tears down an object: it calls func_02016BA0(obj), then
 * for each of the three word fields at +0, +4 and +8 that is non-zero it
 * passes that field's *value* (not the object) to a cleanup call
 * (func_02016C0C for +0, func_02016C38 for +4 and +8) and zeroes the field;
 * it then clears a slot this object owns in an array reached through
 * sys->+0x14, indexed by the object's own field at +0x148, and finally
 * hands the object to func_020307B0 through an interworking blx.
 *
 * The four followers are unlabelled leaf accessors on the same class of
 * object, found in the .word run disasm.py left undecoded immediately
 * after sub_02015BA4 (its prologue has no register-saving push that a
 * two-word bit-flag accessor shares); see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md. Two work a
 * flag at +0x2c: sub_02015BF0 clears then re-sets bit 0 (a clear/set pair
 * rather than a plain |=, which is what tells apart the extra bics), and
 * sub_02015C00 only clears it. The other two work a flag at +0x140, too far
 * from the object base for an immediate str, which is why the compiler
 * computes the offset into a register instead of folding it into the
 * instruction: sub_02015C0C sets bit 0x1D (0x20000000) and sub_02015C1C
 * clears it via the pool word 0xDFFFFFFF immediately after it.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02015BA4.c \
 *       --addr 0x02015BA4 --thumb
 */

typedef unsigned int  u32;
typedef unsigned char u8;

extern void func_02016BA0(void *obj);
extern void func_02016C0C(void *id);
extern int func_02016C38(int a0);
extern void func_020307B0(void *obj);

void sub_02015BA4(void *sys, void *obj)
{
    u32 *p = (u32 *)obj;
    u32 idx;
    u32 *arr;

    func_02016BA0(obj);

    if (p[0] != 0) {
        func_02016C0C((void *)p[0]);
        p[0] = 0;
    }
    if (p[1] != 0) {
        func_02016C38(p[1]);
        p[1] = 0;
    }
    if (p[2] != 0) {
        func_02016C38(p[2]);
        p[2] = 0;
    }

    idx = *(u32 *)((u8 *)obj + 0x148);
    arr = *(u32 **)((u8 *)sys + 0x14);
    arr[idx] = 0;

    func_020307B0(obj);
}

void sub_02015BF0(void *obj)
{
    *(u32 *)((u8 *)obj + 0x2c) &= ~1;
    *(u32 *)((u8 *)obj + 0x2c) |= 1;
}

void sub_02015C00(void *obj)
{
    *(u32 *)((u8 *)obj + 0x2c) &= ~1;
}

void sub_02015C0C(void *obj)
{
    *(u32 *)((u8 *)obj + 0x140) |= 0x20000000;
}

void sub_02015C1C(void *obj)
{
    *(u32 *)((u8 *)obj + 0x140) &= ~0x20000000;
}
