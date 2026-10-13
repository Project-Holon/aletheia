/*
 * function: SCRCMD_SCREENEFFECTS_StartBrightnessChange
 * address:  0x021B2830
 * packet:   pkt_ov021_021B2830
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   FADE_Start  0x0204E720  arm
 */

typedef unsigned int u32;

typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
typedef signed int     s32;
extern void FADE_Start(u32 a, s32 b, s32 c, s32 d);

int SCRCMD_SCREENEFFECTS_StartBrightnessChange(u32 a)
{
    u32 w = VM_GetU16((struct Stream *)a);
    u32 x = VM_GetU16((struct Stream *)a);
    u32 y = VM_GetU16((struct Stream *)a);
    u32 z = VM_GetU16((struct Stream *)a);

    FADE_Start(w, x, y, z);
    return 0;
}
