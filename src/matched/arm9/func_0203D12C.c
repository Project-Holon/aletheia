/*
 * function: GFL_NET_SetDeviceModeIfRunning
 * address:  0x0203D12C
 * packet:   pkt_0203D12C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_SYSTEM_SetDeviceMode  0x02037A44  arm
 *
 * EXACT*, not EXACT: the inferred extent runs on to 0x0203D17C because the
 * four eight-byte ARM long-branch veneers at 0x0203D14C, 0x0203D158,
 * 0x0203D164 and 0x0203D170 save no `lr` and so carry no label.  It is not a
 * byte difference.  They want seeding into layout/function_starts.txt, which
 * is the integrator's file.
 *
 * Guarded forwarding call: the hook at 0x0203CD98 answers whether the
 * connection is up, and only then is the argument handed to 0x02037A44.  The
 * `bl` at the top passes r0 through untouched, so the callee is declared
 * `void` while this one takes the value it later forwards.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_SetDeviceModeIfRunning.c \
 *       --func GFL_NET_SetDeviceModeIfRunning --addr 0x0203D12C --cc 1.1p1 --arm
 */

extern int GFL_NET_GetRunState(void);
extern void GFL_NET_SYSTEM_SetDeviceMode(int a);

void GFL_NET_SetDeviceModeIfRunning(int a)
{
    if (GFL_NET_GetRunState() == 0)
        return;

    GFL_NET_SYSTEM_SetDeviceMode(a);
}
