/*
 * function: func_0203C3EC
 * address:  0x0203C3EC
 * packet:   pkt_0203C3EC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * Unlabelled ARM leaf (needs no pushed register, so disasm.py never gave it a
 * func_ label): a channel-id classifier returning 0/1/3/4/5 or 2.  Reads a
 * pointer at a global slot, then the u32 at +8 of the pointed-to record, and
 * compares it against a chain of five table addresses.
 *
 * NOT EXACT for 12 bytes.  The instruction selection is right -- the fifth
 * constant is materialised with `ldr` and the four earlier ones with `sub`
 * -- but mwcc folds the second constant 0x203c0b4 to `sub r0, r1, #0x40`
 * where the original loads it from its own pool word via `ldr r0,[pc,#0x44]`.
 * Every spelling tried (if-chain, enum, switch, explicit externs, separate
 * unsigned constants) folds the same way; the original keeps five distinct
 * pool words at 0x0203C450..0x0203C460.
 *
 * symbols:
 *   func_0203C3EC  0x0203C3EC  arm
 *   g_021469DC     0x021469DC  data  a4
 */

typedef struct Hdr021469DC {
    unsigned int pad0;
    unsigned int pad4;
    unsigned int v8;
} Hdr021469DC;

extern unsigned int g_021469DC;

int func_0203C3EC(void)
{
    Hdr021469DC **pp = (Hdr021469DC **)(&g_021469DC);
    unsigned int v = (*pp)->v8;

    if (v == 0x203c0f4) {
        return 0;
    }
    if (v == 0x203c0b4) {
        return 1;
    }
    if (v == 0x203c068) {
        return 3;
    }
    if (v == 0x203c060) {
        return 4;
    }
    if (v == 0x203c064) {
        return 5;
    }
    return 2;
}
