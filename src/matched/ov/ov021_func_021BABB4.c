/*
 * function: FIELD_RAIL_CAMERA_ApplyLineStart
 * address:  0x021BABB4
 * packet:   pkt_ov021_021BABB4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_RAIL_GetFocusWork  0x021B8220  thumb  ov021
 *   FIELD_RAIL_WORK_GetMode  0x021B82F0  thumb  ov021
 *   FIELD_RAIL_WORK_GetStartPoint  0x021B833C  thumb  ov021
 *   FIELD_RAIL_CAMERA_ApplyPoint  0x021BB014  thumb  ov021
 */

extern unsigned int FIELD_RAIL_GetFocusWork(unsigned char *p);
typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELD_RAIL_WORK_GetMode(u8 *p);
extern u8 *FIELD_RAIL_WORK_GetStartPoint(u8 *p);
typedef unsigned int   u32;
extern void FIELD_RAIL_CAMERA_ApplyPoint(u32 a, unsigned char *b, u32 c);

void FIELD_RAIL_CAMERA_ApplyLineStart(void *p)
{
    void *a = (void *)FIELD_RAIL_GetFocusWork(p);
    int b = FIELD_RAIL_WORK_GetMode(a);
    int c = (int)FIELD_RAIL_WORK_GetStartPoint(a);

    if (b == 1) {
        FIELD_RAIL_CAMERA_ApplyPoint((u32)p, (unsigned char *)a, c);
    }
}
