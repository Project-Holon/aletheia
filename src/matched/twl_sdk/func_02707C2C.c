/*
 * function: AESi_FlushRange
 * address:  0x02707C2C
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern void DC_FlushRange(const void *start, u32 bytes);
extern void DC_FlushAll(void);

void AESi_FlushRange(void *addr, u32 size)
{
    if (size < 0x2400) {
        DC_FlushRange(addr, size);
    } else {
        DC_FlushAll();
    }
}
