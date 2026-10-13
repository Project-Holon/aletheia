/*
 * function: BTL_SLOT_GetPoke
 * address:  0x021B9BF0
 * packet:   pkt_021B85A0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SLOT_GetPoke   0x021B9BF0  thumb
 *
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: ldrb r2, [r0, #0x18]; cmp r1, r2; bhs loc_021B9BFC; lsls r1, r1, #2; ldr r0, [r0, r1]; bx lr; movs r0, #0; bx lr.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

/* 021B9BF0  ldrb r2,[r0,#0x18]; cmp r1,r2; bhs; lsls r1,#2; ldr r0,[r0,r1] */
struct S2 { u32 items[6]; u8 count; };
u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i)
{
    if (i < p->count)
        return ((u32 *)p)[i];
    return 0;
}

