/*
 * unit:     yes
 * function: func_0202B7F8, func_0202B804, func_0202B810
 * address:  0x0202B7F8
 * packet:   pkt_0202B7BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three iss_3ds_sys.c tail-call units that resolve without any further
 * work: func_0202B7F8 forwards the +4 field to func_020127A4,
 * func_0202B804 chains it into func_02012AC8, and func_0202B810 is a bare
 * thunk to func_02005C44.  All three are named in the `function:` field
 * above so that the `matched` class attests all three addresses: the 32
 * bytes laid out by `tu` cover all three entry points, and
 * src/pending/func_0202B744.c needs 0x0202B804 as a witness.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0202B7F8.c \
 *       --addr 0x0202B7F8 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;

extern u32  func_020127A4(u32 v);
extern void func_02012AC8(u32 v);
typedef unsigned short u16;
extern u16 func_02005C44(void);

u32 func_0202B7F8(struct Obj *o)
{
    return func_020127A4(*(u32 *)((u8 *)o + 0x4));
}

void func_0202B804(struct Obj *o)
{
    func_02012AC8(func_0202B7F8(o));
}

void func_0202B810(void)
{
    func_02005C44();
}
