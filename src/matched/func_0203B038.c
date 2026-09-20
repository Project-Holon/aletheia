/*
 * function: func_0203B038
 * address:  0x0203B038
 * packet:   pkt_0203B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * PARKED AT MATCH.  Every concrete byte is right (76 of 76) and the file is
 * the right size; the one open site is the ABS32 to 0x0203B018, the bare
 * `bx lr` filler word that sits between func_0203AFCC's literal pool and the
 * unlabelled leaf at 0x0203B01C.  That address has no label (a prologue that
 * saves no `lr` is never auto-labelled) and the word appears in exactly one
 * literal pool image-wide - this function's own - so neither `label` nor
 * `literal` can attest it.
 * blocker:  unk_0203B018, unk_0203B01C
 *            pool word, and no EXACT manifest entry covers it)
 *
 * Both 0x0203B018 and 0x0203B01C must be declared in the symbols: block:
 * written as plain integer literals the pair folds into one pool word plus a
 * `sub r1, r4, #4`, which is four bytes short of the original's two words.
 * 0x0203B01C resolves as `literal x10`; only the no-op word does not.
 *
 * The call's completion callback is the leaf at 0x0203B01C (bumps the +0x46
 * halfword by 0x3C); the report's identifier is the no-op at 0x0203B018.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0203B038.c \
 *       --func func_0203B038 --addr 0x0203B038 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_02037A6C(int a0, int a1, int a2, int a3);
extern void func_0203AD80(int a0, int a1, int a2, int a3);
extern char unk_0203B018[];
extern char unk_0203B01C[];

void func_0203B038(u8 *a0)
{
    if (func_02037A6C(0, (int)(a0 + 0x40), 0x200, (int)unk_0203B01C) != 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)unk_0203B018, 0xA, 0x169);
}
