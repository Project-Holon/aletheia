/*
 * function: DWCi_GT2ReceivedCallback
 * address:  0x0216C224
 * packet:   pkt_ov009_0216C0C4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2ReceivedCallback (libdwcmatch.TWL.HYB.a(dwc_main.o), static)
 *
 * notes:    12 bytes: ldr ip / bx ip / pool word DWCi_RecvCallback (vendor DWCi_RecvCallback).
 *           The listing labels it veneer_0216C224, but the vendor object holds
 *           these exact bytes as this C function, not a linker veneer.
 *
 * symbols:
 *   DWCi_RecvCallback  0x02177340  arm
 */

extern void DWCi_RecvCallback(void *connection, unsigned char *message, int size, int reliable);

void DWCi_GT2ReceivedCallback(void *connection, unsigned char *message, int size, int reliable)
{
    DWCi_RecvCallback(connection, message, size, reliable);
}
