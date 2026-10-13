/*
 * function: FLDMMDL_BLACT_DeleteVramSlot
 * address:  0x0219C52C
 * packet:   pkt_ov021_0219C52C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BILLBOARD_ACT_GetSlotBoardId  0x02050330  arm
 *   BILLBOARD_ACT_GetBoard  0x02050080  arm
 *   BILLBOARD_ACT_DeleteSlot  0x02050304  arm
 *   BILLBOARD_ReleaseImageVram  0x0204F214  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u16 BILLBOARD_ACT_GetSlotBoardId(u8 *p, int i);
extern u32 BILLBOARD_ACT_GetBoard(u32 *p);
extern int BILLBOARD_ACT_DeleteSlot(int a0, int a1);
extern void BILLBOARD_ReleaseImageVram(u8 *a0, int i);

void FLDMMDL_BLACT_DeleteVramSlot(u32 a, u32 b)
{
    u32 x = BILLBOARD_ACT_GetSlotBoardId((u8 *)a, b);
    u32 y = BILLBOARD_ACT_GetBoard((u32 *)a);
    BILLBOARD_ACT_DeleteSlot(a, b);
    BILLBOARD_ReleaseImageVram((u8 *)y, x);
}
