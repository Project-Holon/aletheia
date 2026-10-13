/*
 * function: FIELD_CAMERA_StartMoveConstrained
 * address:  0x0218F918
 * packet:   pkt_ov021_0218F918
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_SetMoveGoal  0x0218F89C  thumb
 *   FIELD_CAMERA_TakeViewConstrained  0x0218F7D0  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern void FIELD_CAMERA_SetMoveGoal(void *a);
extern void FIELD_CAMERA_TakeViewConstrained(u8 *s, u8 *d);

void FIELD_CAMERA_StartMoveConstrained(u8 *a)
{
    if (a != 0) {
        FIELD_CAMERA_SetMoveGoal(a);
        FIELD_CAMERA_TakeViewConstrained(a, a + 0x124);
    }
}
