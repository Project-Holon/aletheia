/*
 * function: func_02029D7C
 * address:  0x02029D7C
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
 */

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sys;
extern void FIELD_SOUND_SYSTEM_PostRequest(struct Sys *s, u32 a, u32 b, u16 c, u16 d);

void func_02029D7C(u32 a)
{
    FIELD_SOUND_SYSTEM_PostRequest((struct Sys *)a, 1, 0, 0, 0);
}
