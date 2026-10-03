/*
 * function: func_021F3F00
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
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F80B0 0x021F80B0 thumb ov112
 *   func_021F8154 0x021F8154 thumb ov112
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F40D0 0x021F40D0 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
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
extern void *func_021F5164(u32);
struct Object;
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern void *func_021F709C(u16, void *, void *, void *, void *);
extern void *func_021F760C(u8 *, u8 *);
extern void func_021F5438(void **p, int b);
extern void func_021F80B0(int, int);
extern int func_021F8154(int, int *, int);
extern void *func_021F6BD8(u16, void *);
extern void *func_021F6E78(void *, int);
extern u32 func_021F40D0(void *p, u32 i, u16 c);
extern void func_021F8054(void *, void *, Vec *);
extern void func_021F8084(void *, void *, Vec *);
extern void func_021F6EF4(void *, void *, Vec *);
void func_021F3F00(Context *p)
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
  p->scene = func_021F5164(p->heap);
  func_021F5438(p->scene, 2 << 16);
  p->actors = func_021F48C0((u32) p->owner, 36, p->heap);
  p->render = func_021F709C(p->heap, 0, p->scene, p->actors, p->owner);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    row = ((u8 *) p) + (4 * j);
    q = func_021F760C(p->render, *((u8 **) (row + 8)));
    if (1)
    {
      *((void **) (row + 0x30)) = q;
      func_021F80B0((int)p->render, (int)q);
      func_021F8154((int) p->render, *((int **) (row + 0x30)), 1);
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
  tmp = func_021F6BD8(p->heap, 0);
  p->effect = tmp;
  base = d_021F824C;
  for (; i < 4; mask <<= 1, i++)
  {
    offset = 4 * i;
    row = (u8 *)(((u32)p) + offset);
    scale.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->cfg->flags & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), &pos);
      func_021F8084(p->render, *((void **) (actor + 0x30)), &temp);
      scale.y = 22 << 14;
    }
    else
    {
      u8 *actor;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), &pos);
      tmp1 = 2 << 18;
      scale.y = tmp1;
    }
    *((void **) (row + 0x44)) = func_021F6E78(p->effect, 1);
    func_021F6EF4(p->effect, *((void **) (row + 0x44)), &scale);
  }

}
