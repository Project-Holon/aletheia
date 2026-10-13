/*
 * function: func_021C23C0
 * address:  0x021C23C0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   DWC_RAP_GetFriendStatus  0x02156874  thumb  ov009
 *
 * Tail call thunk into ov009.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern unsigned char DWC_RAP_GetFriendStatus(int i);

unsigned char func_021C23C0(void *a)
{
    return DWC_RAP_GetFriendStatus((int)a);
}
