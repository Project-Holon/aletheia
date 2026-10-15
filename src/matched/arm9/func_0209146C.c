/*
 * function: MSL_C_LIB_Calloc
 * address:  0x0209146C
 * packet:   pkt_020913FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   MSL_C_LIB_AllocFromHeap  0x020913D0  arm
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm
 */

typedef unsigned int u32;

extern void *MSL_C_LIB_AllocFromHeap(u32 heap);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);

void *MSL_C_LIB_Calloc(u32 a0, u32 a1)
{
    u32 size = a1;
    void *p;

    size = size * a0;
    p = MSL_C_LIB_AllocFromHeap(size);
    if (p != 0)
        MSL_C_LIB_MemsetPtr(p, 0, size);
    return p;
}
