/*
 * function: SCRCMD_StartWaitSeStopped
 * address:  0x021AF2E4
 * packet:   pkt_ov021_021AF2E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WaitSeStopped  0x021AF2CC  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void VM_SetWait(char *p, int val);
extern int SCRCMD_WaitSeStopped(u32 a, u32 b, u32 c, u32 d);

int SCRCMD_StartWaitSeStopped(u32 a)
{
    VM_SetWait((char *)a, (int)SCRCMD_WaitSeStopped);
    return 1;
}
