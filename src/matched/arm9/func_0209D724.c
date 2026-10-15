/*
 * unit:     no
 * function: MSL_CONSOLE_IO_NoopFinalizer
 * address:  0x0209D724
 * packet:   pkt_0209D724
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * layout/runtime_arm9.txt lists 0x0209D724 as _runtime_null_stub and claims
 * it is hand-written assembly. It is a bare 4-byte `bx lr`, which an empty
 * compiled C function reproduces byte for byte, so the row is over-broad and
 * the integrator may drop it. Reported from the runtime-library audit lane
 * (0x0209C2B0..0x0209D724).
 */

void MSL_CONSOLE_IO_NoopFinalizer(void)
{
}
