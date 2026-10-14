/*
 * function: func_021D7CD4
 * address:  0x021D7CD4
 * packet:   pkt_ov125_021D7CD4
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_InitMutex  0x02086004  arm
 *   gGdsSocketMutex    0x021DA174  data  ov125  a4
 *
 * DWCi_Ndi_initLockGlobal from TwlDWC libdwcnd.TWL.HYB.a(dwci_nd.o),
 * dwci_nd.c:1644 (DWARF).  The body initialises the ov125 bss lock at
 * 0x021DA174 and reports success:
 *
 *     OS_InitMutex(&gNdiLockGlobal);
 *     return TRUE;
 *
 * 0x021D7CD4 is also a Thumb game function in overlapping ov120 (packet
 * pkt_021D7CD4); this ARM copy is the ov125 SDK one, hence the ov-qualified
 * packet and file names.
 *
 * The neighbouring leaf wrappers GDS_SOCKET_Lock and GDS_SOCKET_Unlock load the
 * same pointer and tail-call OS_LockMutex / OS_UnlockMutex.
 */

extern void OS_InitMutex(void *mutex);
extern char gGdsSocketMutex[];

int func_021D7CD4(void)
{
    OS_InitMutex(gGdsSocketMutex);
    return 1;
}
