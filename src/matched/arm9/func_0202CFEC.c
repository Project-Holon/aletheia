/*
 * function: BGWINFRM_SetClipArea
 * address:  0x0202CFEC
 * packet:   pkt_0202CFEC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * packet line: 42 bytes, 0 relocation sites
 *
 * EXACT* only: the follower at 0x0202D016 is unlabelled (it saves no lr),
 * so the inferred extent runs 2 bytes long.  Never a byte difference.
 *
 * The struct spelling is load-bearing.  Writing the same four stores
 * through a flat `u8 **o` with `i * 0x10 + 0xc` offsets compiles to 48
 * bytes: the front end then folds the four `ldr [o]` reloads into one
 * cached base and re-derives each offset.  Declaring the 0x10-stride entry
 * array makes each store re-load `o->ents` exactly as the image does.
 *
 * c and d are s8, not u8: both are read with `ldrsb` at a REGISTER offset
 * off the stacked-argument area (+0x14 `ldrsb r4,[r3,r2]`, +0x20
 * `ldrsb r2,[r3,r2]`), and immediate-offset ldrsb does not exist --
 * docs/idioms/ldrsh-register-offset-is-signedness.md, same tell for bytes.
 */

typedef unsigned char u8;
typedef signed char   s8;
typedef unsigned int  u32;

struct Ent {
    u8 pad_00[0xc];
    u8 a;
    u8 b;
    s8 c;
    s8 d;
};

struct Obj {
    struct Ent *ents;
};

void BGWINFRM_SetClipArea(struct Obj *o, u32 i, u8 a, u8 b, s8 c, s8 d)
{
    o->ents[i].a = a;
    o->ents[i].b = b;
    o->ents[i].c = c;
    o->ents[i].d = d;
}
