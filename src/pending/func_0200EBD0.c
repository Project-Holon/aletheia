/*
 * function: func_0200EBD0
 * address:  0x0200EBD0
 * packet:   pkt_0200EA3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  codegen, 6 concrete bytes: the two loaded values land in the
 *           scratch r1 and the push is {r3, r4, r5, lr} where the original
 *           reuses r6 for both and pushes {r4, r5, r6, lr}.  Eleven
 *           spellings tried; see docs/notes/pkt_0200EA3C.c.txt section 1.
 */

typedef unsigned int u32;
typedef unsigned char u8;

extern void func_0200EA3C(void *p);

struct S0200EBD0 {
    u8  pad[0x1554];
    u32 unk1554;
    u32 unk1558;
};

void func_0200EBD0(struct S0200EBD0 *obj)
{
    u32 idx;

    if (obj->unk1558 >= 9999)
        return;

    idx = obj->unk1554;
    func_0200EA3C((char *)obj + idx * 0x16c);
    obj->unk1554 = ++idx;
    if (idx >= 0xf)
        obj->unk1554 = 0;
    obj->unk1558++;
}
