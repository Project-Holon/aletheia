/*
 * function: SCRCMD_StartWaitBgmThenPop
 * address:  0x021AF370
 * packet:   pkt_ov021_021AF370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WaitBgmThenPop  0x021AF324  thumb  ov021
 *   VM_SetWait  0x020113D0  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern void VM_SetWait(char *p, int val);
extern int SCRCMD_WaitBgmThenPop(u32 a, u32 b);

int SCRCMD_StartWaitBgmThenPop(u32 a)
{
    VM_SetWait((char *)a, (int)SCRCMD_WaitBgmThenPop);
    return 1;
}
