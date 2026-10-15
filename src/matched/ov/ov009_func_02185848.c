/*
 * function: GSMD5_memset
 * address:  0x02185848
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 *
 * symbols:
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm  arm9
 *   MSL_C_LIB_MemsetPtr  0xfunc_020923B0  arm
 */

typedef unsigned int u32;

extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);

void *GSMD5_memset(void *p, int c, u32 n)
{
    return MSL_C_LIB_MemsetPtr(p, c, n);
}
