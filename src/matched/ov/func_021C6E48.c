/*
 * function: FIELD_TASK_MANAGER_IsEmpty
 * address:  0x021C6E48
 * packet:   pkt_021C6E48
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELD_TASK_MANAGER_CountUsedSlots  0x021C6E20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FIELD_TASK_MANAGER_CountUsedSlots(u32, u32, u32, u32);

int FIELD_TASK_MANAGER_IsEmpty(u32 a, u32 b, u32 c, u32 d)
{
if (FIELD_TASK_MANAGER_CountUsedSlots(a, b, c, d) == 0) {
    return 1;
}
return 0;
}

