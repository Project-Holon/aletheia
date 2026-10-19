/*
 * file:     event_id.c
 * unit:     yes
 * function: PLACE_NAME_GetBank, PLACE_NAME_GetIndex, WAZA_TOOL_IsHmMove, POKE_TOOL_HasNoHmMove
 * address:  0x0202F688
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from time_icon.c by tools/splitfile.py.
 *
 * symbols:
 *   POKE_TOOL_GetBoxValue   0x02017E88  thumb
 *   FILE_UTIL_IsHmMove  0x020212E4  thumb
 */
#include "comm_player_support_shared_types.h"
#include "save_event_shared_types.h"

extern u32 POKE_TOOL_GetBoxValue(struct SaveData *save, u32 varId, u32 defaultValue);

extern u32 FILE_UTIL_IsHmMove(u16 value);

unsigned int PLACE_NAME_GetBank(unsigned int id);

unsigned int PLACE_NAME_GetIndex(unsigned int id);

u32 WAZA_TOOL_IsHmMove(void *unused, u16 value, u16 unused2);

int POKE_TOOL_HasNoHmMove(struct SaveData *save, int unused);

/*
 * Unlabelled Thumb leaf (no entry in layout/function_starts.txt; the listing
 * shows the range as ARM). Compiled body is 80 bytes including its literal
 * pool. Witness for ov131 P_STA_INFO_GetPlaceName (bl from 0x021D878C / 0x021D8794).
 * Maps an id range to a bank number (0x0202F688) and to an index inside
 * that bank (0x0202F6D8).
 */
unsigned int PLACE_NAME_GetBank(unsigned int id) {
  if(id<0x7531) return 89;
  if(id<0x9c41) { if(id-0x7531>=14) return 89; return 92; }
  if(id<0xea61) { if(id-0x9c41>=109) return 89; return 90; }
  if(id<=65535) return 91;
  return 89;
}

/* The in-bank index half of the pair above (see PLACE_NAME_GetBank); 84 bytes with its pool. */
unsigned int PLACE_NAME_GetIndex(unsigned int id) {
  if(id<0x7531) { if(id>=117) return 2; }
  else if(id<0x9c41) { id-=0x7531; if(id>=14) return 2; }
  else if(id<0xea61) { id-=0x9c41; if(id>=109) return 2; }
  else { if(id<=65535) { id-=0xea61; if(id>=3) return 0; } else return 2; }
  return id;
}

/*
 * Twelve-byte tail forwarder (pool word and bx) to FILE_UTIL_IsHmMove with the
 * second argument; witness for ov131 P_STA_SKILL_HandleTouchForget (bl at +0x13A), whose
 * call supplies a pointer, a halfword and a second halfword.
 */
u32 WAZA_TOOL_IsHmMove(void *unused, u16 value, u16 unused2)
{
    return FILE_UTIL_IsHmMove(value);
}

/* 1 when none of the four save variables 0x36 to 0x39 passes FILE_UTIL_IsHmMove. */
int POKE_TOOL_HasNoHmMove(struct SaveData *save, int unused)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (FILE_UTIL_IsHmMove((u16)POKE_TOOL_GetBoxValue(save, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}
