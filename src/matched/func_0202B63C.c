/*
 * function: func_0202B63C
 * address:  0x0202B63C
 * packet:   pkt_0202B59C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Builds the +0x1c sub-object from the object's u16 id.
 *
 * Promoted out of src/pending: the callee func_0202BE68 acquired an EXACT
 * manifest entry, so the THM_CALL field now resolves through the `matched`
 * class.  Every byte is hard; the listing extent is two bytes longer than the
 * code because of the Thumb alignment pad the front end emits after `pop`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;

extern u32 func_0202BE68(u32 id);

void func_0202B63C(struct Obj *o)
{
    *(u32 *)((u8 *)o + 0x1c) = func_0202BE68(*(u16 *)o);
}
