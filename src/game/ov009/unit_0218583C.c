/*
 * file:     unit_0218583C.c
 * unit:     yes
 * function: GSMD5_memcpy, func_02185848
 * address:  0x0218583C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned int u32;

extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void *func_020923B0(void *p, int c, u32 n);
void *GSMD5_memcpy(void *dest, const void *src, unsigned int n);
void *func_02185848(void *p, int c, u32 n);


/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
void *GSMD5_memcpy(void *dest, const void *src, unsigned int n)
{
    return func_02092344(dest, src, n);
}


void *func_02185848(void *p, int c, u32 n)
{
    return func_020923B0(p, c, n);
}
