/*
 * function: func_021DE76C
 * address: 0x021DE76C
 * packet: pkt_ov171_021DE76C
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 *
 * note: 2026-10-05 (wD5 lane17): tried the image statement order (sel as an int local, then n, then i = 0, then cur initialised last): the pool word folds to 0xC5E (152 bytes, 140 differ), worse. Draft kept.
 * 2026-10-04 (wD1 lane18): body is correct, only the prologue order differs (20 bytes).
 * Original: r4=0xC5C pool const, r3=r4+2, sel into r5 (ldrsb), str mode, mul, ldrh n,
 * movs i=0, then ldrsb cur last. Tried: cur/i/n declaration orders, sel as int local,
 * s8 *c base pointer (all worse: constant folds 0xC5C-2).
 * 2026-10-04 (wD2 lane19): tried statement order n, i=0, cur last with separate declarations (both orders): pool 0xC5C is then
 *   not shared (ldr + subs #2, frame grows to push r3). The shared-0xC5C form needs cur initialised at declaration; only the
 *   scheduling of the first ldrsb (cur before the mul here, after `movs i` in the original) differs. Unresolved.
 * note: 2026-10-05 (wD4 lane20): tried int off = 0xC5C / int b = 0xB34 locals (mwcc folds off+2 to a 0xC5E pool word and derives off by subs #2: worse, 139 bytes), an int copy of mode, and cur/i assigned after n. Draft stays; residue is the prologue order (sel in r5 with temp r3 in the image).
 * symbols:
 *   d_021DEC94 0x021DEC94 data
 */
typedef unsigned char u8; typedef unsigned short u16; typedef signed char s8;
typedef unsigned char u8; typedef unsigned short u16; typedef signed char s8;
extern u8 d_021DEC94[];

void func_021DE76C(u8 *p, int mode)
{
    u16 cur = *(s8 *)(p + 0xC5C);
    u16 i;
    u16 n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    for (i = 0; i < n; ) {
        if (mode == 1) {
            u8 *q = p + cur;
            q[0xB34] = *(u16 *)(d_021DEC94 + n * 0x18 + i * 4 - 0x16);
            q[0xB3A] = q[0xB34];
            cur++;
            if (cur >= *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4))
                cur = 0;
        } else {
            u8 *q = p + i;
            q[0xB34] = 0;
            q[0xB3A] = 0;
        }
        i++;
        n = *(u16 *)(p + *(s8 *)(p + 0xC5E) * 0xBC + 0xC4);
    }
}
