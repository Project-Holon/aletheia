/*
 * file:     unit_0206A9DC.c
 * function: func_0206A9DC
 * address:  0x0206A9DC
 * packet:   pkt_0206A17C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02148B4C       0x02148B4C  data
 *
 * The sibling of src/matched/func_0206AA0C.c, one slot lower in the same rig
 * register block: copies the caller's three-word record into the block at
 * 0x02148C2C (= g_02148B4C + 0xE0) and clears the 0xa4 bit trio of the
 * "initialised subsystems" flag word at g_02148B4C + 0xFC.
 *
 * As in func_0206AA0C, the destination is spelled as one object WITH the flag
 * word rather than as a separate extern: that is what orders every access
 * behind the 12-byte ldm/stm copy and keeps the leaf at the original 48 bytes
 * with `ldr r3/r0, [pc]` twice.  Both pool words resolve on `literal` (x115).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0206A9DC.c \
 *       --func func_0206A9DC --addr 0x0206A9DC --cc 1.1p1 --arm
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
} Rec0206A9DC;

extern u32 g_02148B4C[];

void func_0206A9DC(Rec0206A9DC *p)
{
    if (p == 0) {
        return;
    }
    *(Rec0206A9DC *)(g_02148B4C + 0x38) = *p;
    g_02148B4C[0x3f] &= ~0xa4u;
}
