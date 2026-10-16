/*
 * function: MUSICAL_SHOT_SYS_InitActors
 * address: 0x021F3F00
 * packet: pkt_ov112_021F3F00
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * checks: retry rederived all callees; prior permuter 300 retained. Original table pool is 8240,8234,824C; declaration order restores it and all three resolve.
 * match: u32 offset and integer row address retain the spilled row and live index; vectors follow frame order; second loop reuses the earlier j as mask and mask as index; final mask advances before i.
 * ABI: 760C leaves a live result used by this caller despite its own void declaration.
 * symbols:
 *   MUSICAL_MCSS_CreateRenderObj 0x021F5164 thumb ov112
 *   MUSICAL_MCSS_SetRenderFieldA 0x021F5438 thumb ov112
 *   MUSICAL_MCSS_CreateActorPool 0x021F48C0 thumb ov112
 *   STA_ACT_LIGHT_AddBillboardImage 0x021F709C thumb ov112
 *   STA_ACT_LIGHT_AddPokemonElem 0x021F760C thumb ov112
 *   STA_ACT_LIGHT_ResetRenderAnim 0x021F80B0 thumb ov112
 *   STA_ACT_LIGHT_SetElemValue 0x021F8154 thumb ov112
 *   STA_ACT_LIGHT_CreateUnit 0x021F6BD8 thumb ov112
 *   MUSICAL_MCSS_SetObjectValue 0x021F40D0 thumb ov112
 *   STA_ACT_LIGHT_SetActorPos 0x021F8054 thumb ov112
 *   STA_ACT_LIGHT_SetActorOffset 0x021F8084 thumb ov112
 *   STA_ACT_LIGHT_CreateActor 0x021F6E78 thumb ov112
 *   STA_ACT_LIGHT_CopyElemA 0x021F6EF4 thumb ov112
 *   d_021F8240 0x021F8240 data a4
 *   d_021F8234 0x021F8234 data a4
 *   d_021F824C 0x021F824C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct 
{
  int x;
  int y;
  int z;
} Vec;
typedef struct 
{
  u32 low : 5;
  u32 flags : 4;
  u32 high : 23;
} Flags;
typedef struct 
{
  u16 heap;
  u16 pad;
  Flags *cfg;
  u8 *objects[4];
  void *unused;
  void *owner;
  void *scene;
  void *actors;
  void *unused28;
  void *render;
  void *models[4];
  void *effect;
  void *effects[4];
} Context;
extern const Vec d_021F8240;
extern const Vec d_021F8234;
extern const Vec d_021F824C;
extern void *MUSICAL_MCSS_CreateRenderObj(u32);
struct Object;
extern struct Object *MUSICAL_MCSS_CreateActorPool(u32 owner, int count, u16 heap);
extern u8 *STA_ACT_LIGHT_AddBillboardImage(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *STA_ACT_LIGHT_AddPokemonElem(u8 *, u8 *);
extern void MUSICAL_MCSS_SetRenderFieldA(void **p, int b);
extern void STA_ACT_LIGHT_ResetRenderAnim(int, int);
extern int STA_ACT_LIGHT_SetElemValue(int, int *, int);
extern void *STA_ACT_LIGHT_CreateUnit(u16, void *);
extern u8 *STA_ACT_LIGHT_CreateActor(u8 *p, int v);
extern u32 MUSICAL_MCSS_SetObjectValue(void *p, u32 i, u16 c);
extern void STA_ACT_LIGHT_SetActorPos(void *unused, u32 *p, const u32 *q);
extern void STA_ACT_LIGHT_SetActorOffset(void *unused, u32 *p, const u32 *q);
extern void STA_ACT_LIGHT_CopyElemA(void *unused, u32 *p, const u32 *q);
void MUSICAL_SHOT_SYS_InitActors(Context *p)
{
  u32 offset;
  Vec pos = d_021F8240;
  Vec scale = d_021F8234;
  int z[4];
  Vec temp;
  Vec base;
  u8 i;
  u8 mask;
  u8 j;
  int flags;
  int current;
  void *q;
  u8 *row;
  int tmp1;
  void *tmp;
  current = 5 << 16;
  p->scene = MUSICAL_MCSS_CreateRenderObj(p->heap);
  MUSICAL_MCSS_SetRenderFieldA(p->scene, 2 << 16);
  p->actors = MUSICAL_MCSS_CreateActorPool((u32) p->owner, 36, p->heap);
  p->render = STA_ACT_LIGHT_AddBillboardImage(p->heap, 0, (u32)p->scene, (u32)p->actors, (u32)p->owner);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    row = ((u8 *) p) + (4 * j);
    q = STA_ACT_LIGHT_AddPokemonElem(p->render, *((u8 **) (row + 8)));
    if (1)
    {
      *((void **) (row + 0x30)) = q;
      STA_ACT_LIGHT_ResetRenderAnim((int)p->render, (int)q);
      STA_ACT_LIGHT_SetElemValue((int) p->render, *((int **) (row + 0x30)), 1);
    }
  }

  flags = p->cfg->flags;
  for (i = 0, mask = 1; i < 4; i++, mask <<= 1)
  {
    if (!(flags & mask))
    {
      z[i] = current;
      current += 30 << 12;
    }
  }

  for (j = 1, mask = 0; mask < 4; j <<= 1, mask++)
  {
    if (flags & j)
    {
      z[mask] = current;
      current += 30 << 12;
    }
  }

  i = 0;
  mask = 1;
  tmp = STA_ACT_LIGHT_CreateUnit(p->heap, 0);
  p->effect = tmp;
  base = d_021F824C;
  for (; i < 4; mask <<= 1, i++)
  {
    offset = 4 * i;
    row = (u8 *)(((u32)p) + offset);
    scale.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->cfg->flags & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      STA_ACT_LIGHT_SetActorPos(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      STA_ACT_LIGHT_SetActorOffset(p->render, *((void **) (actor + 0x30)), (const u32 *)(&temp));
      scale.y = 22 << 14;
    }
    else
    {
      u8 *actor;
      actor = ((u8 *) p) + offset;
      pos.x = MUSICAL_MCSS_SetObjectValue(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      STA_ACT_LIGHT_SetActorPos(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      tmp1 = 2 << 18;
      scale.y = tmp1;
    }
    *((void **) (row + 0x44)) = STA_ACT_LIGHT_CreateActor(p->effect, 1);
    STA_ACT_LIGHT_CopyElemA(p->effect, *((void **) (row + 0x44)), (const u32 *)(&scale));
  }

}
