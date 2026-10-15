/*
 * function: DWC_Svl_Init
 * address:  0x0217C070
 * packet:   pkt_02156B70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02059F54  0x02059F54  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   gDwcSvlWorkarea     0x021ACEF4  data
 *
 * One-time allocation of the 0x1C5C-byte control block through the caller's
 * allocator, zeroed and then stamped with the allocator itself at +0 and the
 * caller's size at +4.  An already-populated global or a failed allocation
 * reports error 9 and returns 0.
 */

typedef void *(*Alloc)(int, int);

extern void func_02059F54(int a, int b);
extern void MI_CpuFill8(void *p, int c, int n);
extern char gDwcSvlWorkarea[];

int DWC_Svl_Init(Alloc alloc, int size)
{
    void *p;

    if (*(void **)gDwcSvlWorkarea != 0) {
        func_02059F54(9, 0xFFFFA1DC);
        return 0;
    }

    p = alloc(0, 0x1C5C);
    *(void **)gDwcSvlWorkarea = p;
    if (p == 0) {
        func_02059F54(9, 0xFFFFA1DC);
        return 0;
    }

    MI_CpuFill8(p, 0, 0x1C5C);

    *(Alloc *)(*(char **)gDwcSvlWorkarea) = alloc;
    *(int *)(*(char **)gDwcSvlWorkarea + 4) = size;
    return 1;
}
