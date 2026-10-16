/*
 * file:     fieldskill_mapeff.c
 * unit:     yes
 * function: FIELDSKILL_MAPEFF_Create, FIELDSKILL_MAPEFF_Delete, FIELDSKILL_MAPEFF_Update, FIELDSKILL_MAPEFF_Apply, FIELDSKILL_MAPEFF_GetFlash, FIELDSKILL_MAPEFF_InitFlash, FIELDSKILL_MAPEFF_FreeFlash, FIELDSKILL_MAPEFF_UpdateFlash, FIELDSKILL_MAPEFF_ApplyFlash
 * address:  0x021C7F70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from field_flash.c, pleasure_boat.c by tools/splitfile.py.
 *
 * symbols:
 *   GFL_HEAP_Alloc  0x02030734  arm
 *   GFL_HEAP_Free  0x020307B0  arm
 *   gFieldSkillMapEffFileName  0x021DE50C  data  ov021  a4
 *   FIELD_FLASH_Create 0x021C7DAC thumb ov021
 *   FIELD_FLASH_Delete 0x021C7DE0 thumb ov021
 *   FIELD_FLASH_Update 0x021C7DFC thumb ov021
 *   FIELD_FLASH_Apply 0x021C7E30 thumb ov021
 *   FIELD_FLASH_SetPendingCommand 0x021C7E50 thumb ov021
 */
#include "field_flash_shared_types.h"

/* FIELDSKILL_MAPEFF: holds the map effects a field skill can add; only the flash so far. */
typedef struct FieldSkillMapEff {
    FieldFlash *flash;
} FieldSkillMapEff;

extern u32 GFL_HEAP_Free(void *p);

extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *site, u16 tag);

extern char gFieldSkillMapEffFileName[];

FieldFlash *FIELD_FLASH_Create(u32 heapId);

void FIELD_FLASH_Delete(FieldFlash *flash);

void FIELD_FLASH_Update(FieldFlash *flash);

void FIELD_FLASH_Apply(FieldFlash *flash);

void FIELD_FLASH_SetPendingCommand(FieldFlash *flash, u16 command);

FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(u32 flags, u32 heapId);

void FIELDSKILL_MAPEFF_Delete(FieldSkillMapEff *mapEff);

void FIELDSKILL_MAPEFF_Update(FieldSkillMapEff *mapEff);

void FIELDSKILL_MAPEFF_Apply(FieldSkillMapEff *mapEff);

FieldFlash *FIELDSKILL_MAPEFF_GetFlash(FieldSkillMapEff *mapEff);

void FIELDSKILL_MAPEFF_InitFlash(FieldSkillMapEff *mapEff, u32 flags, u32 heapId);

void FIELDSKILL_MAPEFF_FreeFlash(FieldSkillMapEff *mapEff);

void FIELDSKILL_MAPEFF_UpdateFlash(FieldSkillMapEff *mapEff);

void FIELDSKILL_MAPEFF_ApplyFlash(FieldSkillMapEff *mapEff);

FieldSkillMapEff *FIELDSKILL_MAPEFF_Create(u32 flags, u32 heapId)
{
    FieldSkillMapEff *mapEff = GFL_HEAP_Alloc(heapId, sizeof(FieldSkillMapEff), 1, gFieldSkillMapEffFileName, 0x49);
    FIELDSKILL_MAPEFF_InitFlash(mapEff, flags, heapId);
    return mapEff;
}

void FIELDSKILL_MAPEFF_Delete(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_FreeFlash(mapEff);
    GFL_HEAP_Free(mapEff);
}

/* Tail-call thunk: forwards to FIELDSKILL_MAPEFF_UpdateFlash with no argument change. */
void FIELDSKILL_MAPEFF_Update(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_UpdateFlash(mapEff);
}

/* Tail-call thunk: forwards to FIELDSKILL_MAPEFF_ApplyFlash with no argument change. */
void FIELDSKILL_MAPEFF_Apply(FieldSkillMapEff *mapEff)
{
    FIELDSKILL_MAPEFF_ApplyFlash(mapEff);
}

/*
 * Unlabelled leaf accessor (prints as .word in the listing): returns the first word of its argument.
 * Sole blocker of ov010 MOVE_POKEMON_FlashEventMain's MATCH.
 */
FieldFlash *FIELDSKILL_MAPEFF_GetFlash(FieldSkillMapEff *mapEff)
{
    return mapEff->flash;
}

/* Creates the flash when the map effect mask has bit 0 or 1; bit 1 starts it already expanded. */
void FIELDSKILL_MAPEFF_InitFlash(FieldSkillMapEff *mapEff, u32 flags, u32 heapId)
{
    if (flags & 3) {
        mapEff->flash = FIELD_FLASH_Create(heapId);
        if (flags & 2)
            FIELD_FLASH_SetPendingCommand(mapEff->flash, FLASH_CMD_SHOW_EXPANDED);
        else
            FIELD_FLASH_SetPendingCommand(mapEff->flash, FLASH_CMD_INIT);
    } else {
        mapEff->flash = 0;
    }
}

void FIELDSKILL_MAPEFF_FreeFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Delete(mapEff->flash);
    mapEff->flash = 0;
}

/* Tail-call thunk: forwards the flash to FIELD_FLASH_Update. */
void FIELDSKILL_MAPEFF_UpdateFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Update(mapEff->flash);
}

/* Tail-call thunk: forwards the flash to FIELD_FLASH_Apply. */
void FIELDSKILL_MAPEFF_ApplyFlash(FieldSkillMapEff *mapEff)
{
    FIELD_FLASH_Apply(mapEff->flash);
}
