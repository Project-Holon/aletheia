/*
 * function: CLACT_DeleteRenderer
 * address:  0x0204B084
 * packet:   pkt_0204B084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   CLACT_ExitRenderer 0x0204BE28 arm
 *   GFL_HEAP_Free  0x020307B0  arm
 */

typedef unsigned int u32;
struct OamState;
extern void CLACT_ExitRenderer(struct OamState *p);
extern u32 GFL_HEAP_Free(void *p);

void CLACT_DeleteRenderer(struct OamState *p)
{
    CLACT_ExitRenderer(p);
    GFL_HEAP_Free(p);
}
