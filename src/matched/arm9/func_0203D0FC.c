/*
 * function: GFL_NET_EndDeviceWrapper
 * address:  0x0203D0FC
 * packet:   pkt_0203D0FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PROMOTED from src/pending/.  The `bl` to 0x0203C010 was this file's only
 * open relocation site; 0x0203C010 is now an EXACT manifest entry, so the
 * site resolves as `matched` and the file no longer needs its old cap.
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_STATE_EndDevice  0x0203C010  arm
 *
 * Two calls and nothing else: reset the sub-state, then re-enter the state
 * whose constructor src/matched/GFL_NET_STATE_EndDevice.c reproduces.  This function
 * was parked at MATCH until 0x0203C010 was matched - that call was its only
 * open relocation site, and the callee's single branch site image-wide is
 * this one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_EndDeviceWrapper.c \
 *       --func GFL_NET_EndDeviceWrapper --addr 0x0203D0FC --cc 1.1p1 --arm
 */

extern void *GFL_NET_GetSession(void);
extern void GFL_NET_STATE_EndDevice(void);

void GFL_NET_EndDeviceWrapper(int a)
{
    GFL_NET_GetSession();
    GFL_NET_STATE_EndDevice();
}
