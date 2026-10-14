/*
 * function: SCRCMD_FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript
 * address:  0x021B23B8
 * packet:   pkt_ov021_021B23B8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   VM_GetU16  0x02011330  thumb
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript  0x021F4134  thumb  ov039
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
typedef unsigned short u16;
struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern void FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(void *p, u32 i);

int SCRCMD_FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(u32 a, u32 b)
{
    void *d;
    u8 k;

    SCRCMD_WORK_GetScriptWork((void *)b);
    d = SCRCMD_WORK_GetGameSystem((void *)b);
    k = VM_GetU16((struct Stream *)a);
    FIELD_GIMMICK_CART_LANES_UnlockLaneFromScript(d, k);
    return 0;
}
