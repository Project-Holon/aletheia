#ifndef MUSICAL_SHOT_TYPES_H
#define MUSICAL_SHOT_TYPES_H

/*
 * Shared musical shot records for ov112. Used by musical_shot_sys.c (owner)
 * and musical_mcss.c (MUSICAL_MCSS_DrawLabel). Requires u8, u16, u32 and s16
 * to be defined before inclusion.
 */

/* The gender/shiny/form bitfield at the top of a performer (offset 0x02). */
typedef struct { u16 gender : 2; u16 shiny : 1; u16 form : 5; } MusicalPerformerBits;

/* One prop slot of a show performer (MusicalShowEquip in ov010). */
typedef struct
{
  u16 propId;
  s16 offset;
  u8 bodySlot;
  u8 pad[3];
} MusicalShowProp;

/* One performer of a show (MusicalShowPerformer in ov010, 0x58 bytes). */
typedef struct
{
  u16 monsNo;
  u16 gender : 2;
  u16 shiny : 1;
  u16 form : 5;
  u32 personality;
  u16 name[8];
  MusicalShowProp props[8];
} MusicalShowPerformer;

/* A performer seen from the record base plus 0x58 per slot. The original code
   indexes the record by 0x58, so the view starts on the record header word. */
typedef struct
{
  u32 recordHeader;
  MusicalShowPerformer performer;
} MusicalShowPerformerView;

/* The show record stored in the musical save (MusicalShowRecord in ov010, 0x1B0 bytes). */
typedef struct
{
  u32 programId : 5;
  u32 winnerMask : 4;
  u32 year : 7;
  u32 month : 5;
  u32 day : 6;
  u32 localSlot : 2;
  u32 reserved : 3;
  MusicalShowPerformer performers[4];
  u16 title[0x25];
  u8 showType;
  u8 valid;
} MusicalShowRecord;

/* The scene record owned by musical_shot_sys (allocated 100 bytes). */
typedef struct
{
  u16 heap;
  u16 pad;
  MusicalShowRecord *record;
  u8 *objects[4];
  void *camera;
  void *board;
  void *renderObj;
  void *actorPool;
  void *model;
  void *sprite;
  void *models[4];
  void *unit;
  void *effects[4];
  void *winA;
  void *winB;
  void *fontA;
  void *fontB;
} ShotScene;

#endif
