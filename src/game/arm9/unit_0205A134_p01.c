/*
 * file:     unit_0205A134_p01.c
 * unit:     yes
 * function: func_0205A134, func_0205A148, func_0205A158
 * address:  0x0205A134
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0205A12C    0x0205A12C  arm
 *   s_mem  0x02146AB4  data  a4
 */
typedef struct {
    unsigned long magic;
    unsigned long size;
    unsigned char pad[24];
} _tagDWCiAllocHeader;

typedef void *(*DWCiMemAlloc)(int, unsigned long);

typedef void (*DWCiMemFree)(int, void *, unsigned long);

typedef struct { DWCiMemFree free; DWCiMemAlloc alloc; } DWCiMemFunc;

extern void *func_0205A12C(char *p);
void *DWCi_SetAllocateHeader(void *ptr, unsigned long size);
asm void func_0205A148(void);
void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free);


void *DWCi_SetAllocateHeader(void *ptr, unsigned long size)
{
    _tagDWCiAllocHeader *header = (_tagDWCiAllocHeader *)ptr;
    header->size = size;
    header->magic = 0x4457434d;
    return header + 1;
}


asm void func_0205A148(void)
{
    stmdb	sp!, {r3, lr}
    bl	func_0205A12C
    ldr	r0, [r0, #4]
    ldmia	sp!, {r3, pc}
}


static DWCiMemFunc s_mem;


void DWCi_SetMemFunc(DWCiMemAlloc alloc, DWCiMemFree free)
{
    s_mem.alloc = alloc;
    s_mem.free = free;
}
