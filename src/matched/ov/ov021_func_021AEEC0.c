/*
 * function: SCRCMD_IsBgmPlaying
 * address:  0x021AEEC0
 * packet:   pkt_ov021_021AEEC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   VM_GetU16  0x02011330  thumb  arm9
 *   GFL_USE_IsBgmPlaying  0x02005F38  thumb  arm9
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

struct Stream;
extern u16 VM_GetU16(struct Stream *s);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern int GFL_USE_IsBgmPlaying(void);

int SCRCMD_IsBgmPlaying(u32 a, u32 b)
{
    VM_GetU16((struct Stream *)a);
    *SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b) = GFL_USE_IsBgmPlaying();
    return 0;
}
