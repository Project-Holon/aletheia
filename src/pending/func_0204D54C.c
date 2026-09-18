/*
 * function: func_0204D54C
 * address:  0x0204D54C
 * packet:   pkt_0204D54C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * symbols:
 *   func_0204D52C  0x0204D52C  arm
 *   func_02064C10  0x02064C10  arm
 *
 * Blocked at MATCH: all 24 concrete bytes are correct (48 compiled with the
 * two relocations), but the PC24 at +0x10 (the call to func_02064C10) has no
 * witness of any class.  0x02064C10 sits outside this agent's window and is
 * not an SDK symbol, so no `matched` entry can be produced here and the call
 * site is the address's only branch reference in the image.  Same wall as
 * src/pending/func_0204B0F4.c.
 *
 * Tear the actor down and release the sub-object at +0x40.
 */

typedef unsigned char u8;

extern void func_0204D52C(void *p);
extern void func_02064C10(void *p);

void func_0204D54C(void *p)
{
    func_0204D52C(p);
    func_02064C10((u8 *)p + 0x40);
}
