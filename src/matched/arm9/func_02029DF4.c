/*
 * function: FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx
 * address:  0x02029DF4
 * packet:   pkt_02029DF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetFieldBgmForZone  0x02029EB4  thumb
 *
 * Plain forwarder to FIELD_SOUND_SYSTEM_GetFieldBgmForZone (ldr r3, =target; bx r3).  Seeded in
 * layout/function_starts.txt from the bl sites in ov020 and ov021
 * (w6_fix18).
 */

extern unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZone(void *a, unsigned int id, unsigned int which);

unsigned int FIELD_SOUND_SYSTEM_GetFieldBgmForZoneEx(void *a, unsigned int id, unsigned int which)
{
    return FIELD_SOUND_SYSTEM_GetFieldBgmForZone(a, id, which);
}
