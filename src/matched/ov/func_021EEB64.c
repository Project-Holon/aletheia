/*
 * function: BTL_ADAPTER_GetSendBuffer
 * address:  0x021EEB64
 * packet:   pkt_021EDF78
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_ADAPTER_GetSendBuffer   0x021EEB64  thumb
 *
 * Leaf with no calls and no pool; 6 instructions, 12 bytes: cmp r1, #0; beq loc_021EEB6C; ldr r2, [r0, #8]; str r2, [r1]; ldr r0, [r0, #4]; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021EEB64  cmp r1,#0; beq; ldr r2,[r0,#8]; str r2,[r1]; ldr r0,[r0,#4] */
struct QW { u8 pad[4]; u32 a; u32 b; };
u32 BTL_ADAPTER_GetSendBuffer(struct QW *p, u32 *out)
{
    if (out != 0)
        *out = p->b;
    return p->a;
}

