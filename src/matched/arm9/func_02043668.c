/*
 * function: BG_SYS_GetSubVisiblePlanes
 * address:  0x02043668
 * packet:   pkt_0204361C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Read back gVisiblePlane[0], the engine-A software copy of the visible
 * plane set that BG_SYS_SetMainVisiblePlanes writes.  Twin of the third leaf in
 * src/matched/unit_0204361C.c, which reads element 1.  Saves no lr, so
 * disasm.py does not label it.
 *
 * symbols:
 *   gVisiblePlane  0x02146A48  data
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BG_SYS_GetSubVisiblePlanes.c \
 *       --func BG_SYS_GetSubVisiblePlanes --addr 0x02043668 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32 gVisiblePlane[2];

u32 BG_SYS_GetSubVisiblePlanes(void)
{
    return gVisiblePlane[0];
}
