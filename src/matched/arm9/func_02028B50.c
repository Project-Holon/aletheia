/*
 * function: FIELD_SOUND_SYSTEM_ReleaseSlot
 * address:  0x02028B50
 * packet:   pkt_02028B50
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Both halfword cells the caller clears sit in ONE struct, four bytes apart
 * (0xac and 0xb0), and the same index reaches both.  Spelled as two
 * independent `u16 *` locals the compiler recomputes the second address from
 * `idx + 1` and the frame loses two bytes; as two adjacent u16[2] fields of
 * one struct both accesses share the scaled index register and the function
 * is EXACT.
 *
 * symbols:
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   FIELD_SOUND_SYSTEM_FindSlotSound  0x021D21C0  thumb ov021
 *   FIELD_SOUND_SYSTEM_IsSlotSoundTracked  0x021D21E0  thumb ov021
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int GFL_USE_GetSeSlot(u32 a0);
extern void GFL_USE_StopSeSlot(int i);
extern int FIELD_SOUND_SYSTEM_FindSlotSound(u32 id);
extern int FIELD_SOUND_SYSTEM_IsSlotSoundTracked(u32 id);
struct S { u8 pad[0xac]; u16 lo[2]; u16 hi[2]; };
void FIELD_SOUND_SYSTEM_ReleaseSlot(u8 *p, int a0)
{
    u32 idx;
    struct S *s = (struct S *)p;
    idx = GFL_USE_GetSeSlot(a0);
    if (FIELD_SOUND_SYSTEM_FindSlotSound(a0) == 0) {
        GFL_USE_StopSeSlot(idx);
        return;
    }
    if (FIELD_SOUND_SYSTEM_IsSlotSoundTracked(a0) != 0) {
        if (a0 == s->lo[idx - 1]) {
            s->lo[idx - 1] = 0xffff;
            s->hi[idx - 1] = 0xffff;
        }
    }
    GFL_USE_StopSeSlot(idx);
}
