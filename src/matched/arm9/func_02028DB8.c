/*
 * function: FIELD_SOUND_SYSTEM_HasPendingRequest
 * address:  0x02028DB8
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetReadSlot  0x02028D7C  thumb
 */

typedef unsigned int u32;

extern void *FIELD_SOUND_SYSTEM_GetReadSlot(void *obj);

int FIELD_SOUND_SYSTEM_HasPendingRequest(void *obj)
{
    return *(u32 *)FIELD_SOUND_SYSTEM_GetReadSlot(obj) != 0;
}
