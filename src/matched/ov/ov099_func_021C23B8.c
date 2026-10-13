/*
 * function: WIFICLUB_GetFriendStatus
 * address:  0x021C23B8
 * packet:   pkt_ov099_021C23B8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked (was MATCH on one witness).
 * +0004 ABS32 DWC_RAP_GetFriendStatusData          -> resolved as `matched` by
 * src/matched/ov009_func_02156860.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 opens with adds r3,r7,#0 and an
 * immediate branch), declared as `DWC_RAP_GetFriendStatusData 0x02156860 thumb ov009` below.
 *
 * symbols:
 *   DWC_RAP_GetFriendStatusData  0x02156860  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int DWC_RAP_GetFriendStatusData(int i);
int WIFICLUB_GetFriendStatus(int i) { return DWC_RAP_GetFriendStatusData(i); }
