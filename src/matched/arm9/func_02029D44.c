/*
 * function: func_02029D44
 * address:  0x02029D44
 * packet:   pkt_02029D44
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT

 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_PostRequest  0x020289F8  thumb
 *   FIELD_SOUND_SYSTEM_GetZoneBgm  0x02029E64  thumb
 *   FIELD_SOUND_SYSTEM_FindZoneBgmOverride  0x02029E74  thumb
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void FIELD_SOUND_SYSTEM_PostRequest(u32 a, u32 b, u32 c, u32 d, u32 e);

void func_02029D44(u32 a, u32 b, u16 c, u8 d)
{
    u32 r = FIELD_SOUND_SYSTEM_FindZoneBgmOverride(b, c);

    if (r == ~0u) {
        r = FIELD_SOUND_SYSTEM_GetZoneBgm(b, c, d);
    }

    FIELD_SOUND_SYSTEM_PostRequest(a, 6, r, 0x3C, 0);
}
