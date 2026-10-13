/*
 * function: func_021BC240
 * address:  0x021BC240
 * packet:   pkt_ov210_021BC240
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
extern void GFL_HEAP_CreateChildHeap(u32 a, u32 b, u32 c);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void MI_CpuFill8(void *p, u32 v, u32 n);

u32 func_021BC240(void *man, u32 b, u32 arg)
{
    u32 *p;
    GFL_HEAP_CreateChildHeap(1, 0x7b, 0x60000);
    p = PROCSYS_AllocProcWork(man, 0x2d4, 0x7b);
    MI_CpuFill8(p, 0, 0x2d4);
    *p = arg;
    return 1;
}
