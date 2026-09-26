/*
 * function: func_021C28CC
 * address:  0x021C28CC
 * packet:   pkt_021C28CC
 * region:   ov217
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  5 bytes, codegen only.  The two source fields are WORD loads, not
 *   halfwords (original `ldr r3,[p+4]; ldr r0,[p+8]`), so x/y are u32; with
 *   that and this store order the loads and their registers (x->r3, y->r0)
 *   are exact.  The residual is the tail schedule: the original interleaves
 *   `adds r3,#0x14; strh r3,[a]; subs r0,#8; strh r0,[b]`, mwcc batches both
 *   arithmetic ops and then emits the stores b-then-a.  Constants: p+4 -> *a =
 *   x+0x14, p+8 -> *b = y-8.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021C28CC(char *p, u16 *a, u16 *b)
{
    u32 x = *(u32 *)(p + 4);
    u32 y = *(u32 *)(p + 8);

    *b = (u16)(y - 8);
    *a = (u16)(x + 0x14);
}
