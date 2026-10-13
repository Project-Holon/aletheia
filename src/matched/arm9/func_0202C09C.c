/*
 * function: ISS_SWITCH_SYS_Main
 * address:  0x0202C09C
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * When ISS_SWITCH_SYS_IsOn reports true, runs ISS_SWITCH_SYS_UpdateActiveSet and ISS_SWITCH_SYS_UpdateVolume.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ISS_SWITCH_SYS_Main.c \
 *       --func ISS_SWITCH_SYS_Main --addr 0x0202C09C --thumb --cc 1.1p1
 *
 * symbols:
 *   ISS_SWITCH_SYS_UpdateActiveSet  0x0202C1C4  thumb
 *   ISS_SWITCH_SYS_UpdateVolume  0x0202C2C0  thumb
 *   ISS_SWITCH_SYS_IsOn  0x0202C2D8  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 ISS_SWITCH_SYS_IsOn(u32 *p);
extern int ISS_SWITCH_SYS_UpdateActiveSet(int a0);
extern void ISS_SWITCH_SYS_UpdateVolume(void *p);

void ISS_SWITCH_SYS_Main(u8 *p)
{
    if (ISS_SWITCH_SYS_IsOn((u32 *)p) != 0) {
        ISS_SWITCH_SYS_UpdateActiveSet((int)p);
        ISS_SWITCH_SYS_UpdateVolume(p);
    }
}
