/*
 * file:     unit_021C7A30.c
 * unit:     yes
 * function: func_021C7A30, func_021C7A44
 * address:  0x021C7A30
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm  arm9
 */
typedef unsigned char u8;

typedef unsigned int u32_021C7A30;

typedef unsigned long u32_021C7A44;

extern void MI_CpuFill8(int, int, int);
extern void MI_CpuCopy8(const void *src, void *dst, u32_021C7A44 size);
void func_021C7A30(int a, int b);
void DWCi_Ndi_memcpy(void *dst, void *src, u32_021C7A44 size);


/*
 * Thunk: MI_CpuFill8(a, 0, b).
 */
void func_021C7A30(int a, int b)
{
    MI_CpuFill8(a, 0, b);
}


void DWCi_Ndi_memcpy(void *dst, void *src, u32_021C7A44 size)
{
    MI_CpuCopy8(src, dst, size);
}
