/*
 * function: CLACT_GetCharacterVramAddress
 * address:  0x0204ABBC
 * packet:   pkt_0204A9D0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CLACT_GetCharacterProxy  0x0204AB84  arm
 *   NNSi_G2dGetVramHandleValue  0x020637B4  arm
 *
 * Snapshot one actor record into a local 36-byte buffer and hand it to
 * NNSi_G2dGetVramHandleValue with mode 1, or mode 2 when the second argument is set.
 */

typedef unsigned int u32;

struct Rec {
    u32 w[9];
};

extern void CLACT_GetCharacterProxy(u32 idx, struct Rec *dst);
extern int NNSi_G2dGetVramHandleValue(int *p, int i);

int CLACT_GetCharacterVramAddress(u32 idx, u32 flag)
{
    struct Rec buf;
    u32 mode = 1;

    if (flag != 0) {
        mode = 2;
    }
    CLACT_GetCharacterProxy(idx, &buf);
    return NNSi_G2dGetVramHandleValue((int *)(&buf), mode);
}
