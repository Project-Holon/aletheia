/*
 * function: RINGTONE_SYS_Update
 * address:  0x02029F4C
 * packet:   pkt_02029F4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   RINGTONE_SYS_HandleRingTimeout  0x0202A0E8  thumb
 */

typedef unsigned int   u32;
extern void RINGTONE_SYS_HandleRingTimeout(u32 *p);

void RINGTONE_SYS_Update(void *p)
{
    RINGTONE_SYS_HandleRingTimeout(p);
}
