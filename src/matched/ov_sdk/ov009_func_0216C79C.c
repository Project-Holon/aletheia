/*
 * function: DWCi_GT2PingCallback
 * address:  0x0216C79C
 * packet:   pkt_ov009_0216C788
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_GT2PingCallback (libdwcmatch.TWL.HYB.a(dwc_main.o), static)
 *
 * notes:    12 bytes: ldr ip / bx ip / pool word func_02177398 (vendor DWCi_PingCallback).
 *           The listing labels it veneer_0216C79C, but the vendor object holds
 *           these exact bytes as this C function, not a linker veneer.
 */

extern void func_02177398(void *connection, int latency);

void DWCi_GT2PingCallback(void *connection, int latency)
{
    func_02177398(connection, latency);
}
