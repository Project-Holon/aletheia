/*
 * function: func_021C0C7C
 * address:  0x021C0C7C
 * packet:   pkt_ov099_021C0C7C
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unblocked (was MATCH on one witness).
 * +0008 ABS32 DWC_RAP_SetVchatEnabled          -> resolved as `matched` by
 * src/matched/ov009_func_02156BC4.c after fixing the ISA/region hint: the
 * target is Thumb code in ov009 (ov010 decodes to a pop with no push), declared
 * as `DWC_RAP_SetVchatEnabled 0x02156BC4 thumb ov009` below.
 *
 * symbols:
 *   DWC_RAP_SetVchatEnabled  0x02156BC4  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern void DWC_RAP_SetVchatEnabled(int);
void func_021C0C7C(void) { DWC_RAP_SetVchatEnabled(0); }
