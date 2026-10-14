/*
 * function: CTVT_CAMVIEW_SetCameraEffect
 * address:  0x021B7B3C
 * packet:   pkt_021B6100
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two guards then an ARM veneer call with 3, 3 and the third argument.
 *
 * symbols:
 *   COMM_TVT_SYS_IsNetIdle  0x021BE100  thumb  ov172
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   func_021B7B5C  0x021B7B5C  arm    ov172
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int COMM_TVT_SYS_IsNetIdle(void);
extern int OS_IsRunOnTwl(int a);
extern void func_021B7B5C(int a, int b, int c);

void CTVT_CAMVIEW_SetCameraEffect(int x, int y, int z)
{
    int r = COMM_TVT_SYS_IsNetIdle();
    if (r != 1) {
        return;
    }
    r = OS_IsRunOnTwl(r);
    if (r != 1) {
        return;
    }
    func_021B7B5C(3, 3, z);
}
