/*
 * function: func_02707C48
 * address:  0x02707C48
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef unsigned int u32;

extern void IC_InvalidateRange(const void *start, u32 bytes);
extern void IC_InvalidateAll(void);
extern void DC_FlushAll(void);
extern void DC_StoreRange(const void *start, u32 bytes);
extern void DC_InvalidateRange(const void *start, u32 bytes);

void func_02707C48(void *addr, u32 size)
{
    if (size < 0x400) {
        IC_InvalidateRange(addr, size);
    } else {
        IC_InvalidateAll();
    }

    if (size < 0x2400) {
        u32 end = (u32)addr + size;
        if ((u32)addr & 0x1F) {
            DC_StoreRange(addr, 1);
        }
        if (end & 0x1F) {
            DC_StoreRange((const void *)(end - 1), 1);
        }
        DC_InvalidateRange(addr, size);
    } else {
        DC_FlushAll();
    }
}
