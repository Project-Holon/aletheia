/*
 * function: EVENT_TRAINER_EYE_CreateScriptWork
 * address:  0x021AE930
 * packet:   pkt_021AE930
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   SCRIPT_SYS_CreateScriptEventSimple  0x02158768  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Desc;
extern struct Desc *SCRIPT_SYS_CreateScriptEventSimple(int a0, int a1, int a2, int a3);
extern void *FIELDMAP_GetGameSystem(void *p);

int EVENT_TRAINER_EYE_CreateScriptWork(int a, u32 b)
{
return (int)SCRIPT_SYS_CreateScriptEventSimple((int)FIELDMAP_GetGameSystem((void *)a), (226 << 4), b, 1);
}

