/*
 * function: FIELD_SOUND_SYSTEM_ProcessNextRequest
 * address:  0x02028D54
 * packet:   pkt_02028D54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * closed:   blocker FIELD_SOUND_SYSTEM_ProcessNextRequest.c is now a manifest entry (matched class)
 * blocker:  02028E80; 02028EAC
 *
 * symbols:
 *   FIELD_SOUND_SYSTEM_GetReadSlot  0x02028D7C  thumb
 *   FIELD_SOUND_SYSTEM_DequeueRequest  0x02028E80  thumb
 *   FIELD_SOUND_SYSTEM_ExecuteRequest  0x02028EAC  thumb
 *   FIELD_SOUND_SYSTEM_IsKindAllowedInState  0x02028FD0  thumb
 */

typedef unsigned int   u32;
struct Cmd;
struct SoundParam;
struct SoundParam2;
struct Sys;
extern void *FIELD_SOUND_SYSTEM_GetReadSlot(void *obj);
extern u32 FIELD_SOUND_SYSTEM_IsKindAllowedInState(struct SoundParam *obj, u32 kind);
extern void FIELD_SOUND_SYSTEM_ExecuteRequest(struct SoundParam2 *obj, struct Cmd *cmd);
extern void FIELD_SOUND_SYSTEM_DequeueRequest(struct Sys *s);
void FIELD_SOUND_SYSTEM_ProcessNextRequest(int a0)
{
    int *p = FIELD_SOUND_SYSTEM_GetReadSlot((void *)a0);
    if (FIELD_SOUND_SYSTEM_IsKindAllowedInState((struct SoundParam *)a0, *p)) {
        FIELD_SOUND_SYSTEM_ExecuteRequest((struct SoundParam2 *)a0, (struct Cmd *)((int)p));
        FIELD_SOUND_SYSTEM_DequeueRequest((struct Sys *)a0);
    }
}
