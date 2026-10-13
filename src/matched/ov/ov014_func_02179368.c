/*
 * function: DWCi_MOV_WH_SendData
 * address:  0x02179368
 * packet:   pkt_ov014_02179368
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Guard wrapper: forwards to DWCi_MOV_WH_StateInSetMPData when WIH_GetOwnAid is nonzero or
 * one of bits 1-7 of WIH_GetBitmap is set, else returns 0.  The unlabelled
 * follower at 02179394 (adds the block's +0x1C64 / +0x1444 to gWihWork,
 * tail calls a thumb function) is why the extent runs long.
 *
 * symbols:
 *   WIH_GetOwnAid  0x021795A4  thumb  ov014
 *   WIH_GetBitmap  0x02178E38  thumb  ov014
 *   DWCi_MOV_WH_StateInSetMPData  0x02178D20  thumb  ov014
 */

typedef int BOOL;

typedef unsigned short u16;
typedef unsigned int   u32;
extern unsigned short WIH_GetOwnAid(void);
extern u16 WIH_GetBitmap(void);
extern int DWCi_MOV_WH_StateInSetMPData(u32 a, u32 b, u32 c);

BOOL DWCi_MOV_WH_SendData(int a, u16 b, int c)
{
    if (WIH_GetOwnAid() == 0 && (WIH_GetBitmap() & 0xFE) == 0)
        return 0;
    return DWCi_MOV_WH_StateInSetMPData(a, b, c);
}
