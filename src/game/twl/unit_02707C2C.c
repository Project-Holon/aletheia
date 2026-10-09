/*
 * file:     unit_02707C2C.c
 * unit:     yes
 * function: func_02707C2C, func_02707C48
 * address:  0x02707C2C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

extern void DC_FlushRange(const void *start, u32 bytes);
extern void DC_FlushAll(void);
extern void IC_InvalidateRange(const void *start, u32 bytes);
extern void IC_InvalidateAll(void);
extern void DC_StoreRange(const void *start, u32 bytes);
extern void DC_InvalidateRange(const void *start, u32 bytes);
void func_02707C2C(void *addr, u32 size);
void func_02707C48(void *addr, u32 size);


void func_02707C2C(void *addr, u32 size)
{
    if (size < 0x2400) {
        DC_FlushRange(addr, size);
    } else {
        DC_FlushAll();
    }
}


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
