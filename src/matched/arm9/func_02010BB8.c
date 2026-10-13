/*
 * function: func_02010BB8
 * address:  0x02010BB8
 * packet:   pkt_02010BB8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_SetMainVisiblePlanes  0x02043534  arm
 *   BG_SYS_SetSubVisiblePlanes  0x020435F4  arm
 *   GFL_HEAP_CreateChildHeap  0x0203064C  arm
 *   PROCSYS_AllocProcWork  0x0203159C  arm
 *   MI_CpuFill8  0x02082BCC  arm
 *   PROCSYS_Create  0x02031324  arm
 *
 * The save-screen constructor of the net_save.c family (see
 * docs/families/net_save.h section 3).  It blanks both display engines'
 * blend and window bits -- 0x04000000 and 0x04001000 are the two DISPCNT
 * words, masked first with ~0x1F00 and then with ~0xE000, and 0x04000050 /
 * 0x04001050 are the two BLDCNT halfwords zeroed -- then allocates a
 * 0x1A8-byte record at heap 0x5b, zeroes it, stores its third argument at
 * +0x00 and the heap's own handle (PROCSYS_Create(0x5b)) at +0x08.
 *
 * The four masked read-modify-writes are written as four separate compound
 * assignments in source order: the compiler reuses the two pooled addresses
 * across them, which is what puts the second pair's `adds r1, #0x50` /
 * `adds r0, #0x50` in place of two more pool words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02010BB8.c \
 *       --func func_02010BB8 --addr 0x02010BB8 --cc 1.1p1 --thumb
 */
#include "../include/Obj11242.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  BG_SYS_SetMainVisiblePlanes(u32 a);
extern void  BG_SYS_SetSubVisiblePlanes(u32 a);
extern void  GFL_HEAP_CreateChildHeap(u32 a, u32 heap, u32 size);
struct Obj0203159C;
extern void *PROCSYS_AllocProcWork(struct Obj0203159C *obj, u32 size, u32 heap);
extern void  MI_CpuFill8(void *dst, int val, unsigned n);
extern void *PROCSYS_Create(int a0);

int func_02010BB8(void *ctx, int a1, int a2)
{
    u8 *p;

    BG_SYS_SetMainVisiblePlanes(0);
    BG_SYS_SetSubVisiblePlanes(0);
    *(u32 *)0x04000000 &= 0xFFFFE0FF;
    *(u32 *)0x04001000 &= 0xFFFFE0FF;
    *(u32 *)0x04000000 &= 0xFFFF1FFF;
    *(u32 *)0x04001000 &= 0xFFFF1FFF;
    *(u16 *)0x04000050 = 0;
    *(u16 *)0x04001050 = 0;
    GFL_HEAP_CreateChildHeap(1, 0x5b, 0x800);
    p = PROCSYS_AllocProcWork(ctx, 0x1a8, 0x5b);
    MI_CpuFill8(p, 0, 0x1a8);
    ((struct Obj11242 *)p)->f0 = (u32)a2;
    ((struct Obj11242 *)p)->f8 = (unsigned int)PROCSYS_Create(0x5b);
    return 1;
}
