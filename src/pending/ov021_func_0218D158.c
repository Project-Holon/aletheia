/*
 * function: func_0218D158
 * address:  0x0218D158
 * packet:   pkt_ov021_0218D158
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Near miss (2 bytes, one store swap).  Copies three words from *src into
 * dst+0x34/+0x38/+0x3c.  The image loads all three fields first
 * (ldr r3,[r1,#8]; ldr r2,[r1,#4]; ldr r1,[r1]) then stores +0x38, +0x34,
 * +0x3c.  A struct aggregate assignment compiles to ldm/stm (idiom
 * aggregate-assignment-is-ldm-stm); spelling the three copies out as
 * separate dereferences reproduces the loads but emits the stores in
 * +0x34, +0x38, +0x3c order, so two halfwords differ at +0x06/+0x08.
 * Tried: decl/assign permutations of the three locals, struct member
 * copies, pointer-to-struct dest; every spelling with the correct load
 * order stores +0x34 before +0x38.  No C shape found for the b,a,c store
 * schedule.
 */

void func_0218D158(char *dst, int *src)
{
    int a = src[0];
    int c = src[2];
    int b = src[1];
    *(int *)(dst + 0x34) = a;
    *(int *)(dst + 0x38) = b;
    *(int *)(dst + 0x3c) = c;
}
