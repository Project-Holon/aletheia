/*
 * function: _gsi_memalign
 * address:  0x0217EA7C
 * packet:   pkt_ov009_0217EA7C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      _gsi_memalign (gsmemory.o)
 *
 * symbols:
 *   MSL_C_LIB_Calloc                  0x0209146C  arm
 *   _u32_div_f                     0x0209C2B0  arm
 */

extern void *MSL_C_LIB_Calloc(unsigned long n, unsigned long size);

void *_gsi_memalign(unsigned long boundary, unsigned long size)
{
    void *ptr = MSL_C_LIB_Calloc(size / boundary, boundary);
    return ptr;
}
