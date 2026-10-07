/*
 * function: func_021B99DC
 * address: 0x021B99DC
 * packet: pkt_ov220_021B99DC
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 (wP7 V4): EXACT. The residue of the older draft was a spill slot swap of coords (sp+0x20) and gender (sp+0x10).
 *   Spill slots follow declaration order, first declared = highest slot: coords, owner, species, form, gender, then desc. Drop the
 *   artifact locals (mode, tmp, tmp1, do-while) and declare in that order. Pragmas were not needed. No real bug seen.
 * prototype: 0204B294's live r0 is the actor stored and passed to 0204B878, despite its own void declaration.
 * symbols:
 * func_020490F4 0x020490F4 arm
 * func_0204ACEC 0x0204ACEC arm
 * func_0204A6C8 0x0204A6C8 arm
 * func_0204AF28 0x0204AF28 arm
 * func_02049238 0x02049238 arm
 * func_02082BCC 0x02082BCC arm
 * func_021BA1E0 0x021BA1E0 thumb ov220
 * func_0204B294 0x0204B294 arm
 * func_0204B878 0x0204B878 arm
 * func_0204B92C 0x0204B92C arm
 * func_0204B6F4 0x0204B6F4 arm
 * func_0201BC3C 0x0201BC3C thumb
 * func_0201BABC 0x0201BABC thumb
 * func_0201BC40 0x0201BC40 thumb
 * func_0201BCB4 0x0201BCB4 thumb
 * func_0201BB5C 0x0201BB5C thumb
 * coords3 0x021BA318 data a2
 * coords4 0x021BA328 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Param
{
  s16 x;
  s16 y;
  u32 zero;
};
extern const u8 coords3[];
extern const u8 coords4[];
extern void *func_020490F4(u32 id, u32 heap);
extern int func_0204ACEC(void *, u32, u32, u32, u16);
extern int func_0204A6C8(void *, u32, u32, u32, u16);
extern int func_0204AF28(void *, u32, u32, u32);
extern void func_02049238(void *);
extern void func_02082BCC(void *, u32, u32);
struct Obj;
extern u32 func_021BA1E0(u8 *p);
extern struct Obj *func_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);
extern int func_0201BC3C(void);
extern int func_0201BC40(void);
extern int func_0201BCB4(void);
extern u32 func_0201BABC(u32, u32, u32, u32);
extern u32 func_0201BB5C(u32, u32, u32, u32);
void func_021B99DC(char *p)
{
  const u8 *coords;
  void *owner;
  u16 species;
  u8 form;
  u8 gender;
  u8 *desc;
  u8 i;
  char *res;
  char *slot;
  struct Param param;
  void *actor;
  char *args = *((char **) (p + 4));
  *((u8 *) (p + 0x18)) = 0;
  if (*((u32 *) (args + 8)))
    desc = (*((u8 **) (args + 4))) + 0x14;
  else
    desc = *((u8 **) (args + 4));
  if (*desc)
  {
    if (desc[1] == 0)
    {
      *((u8 *) (p + 0x18)) = 3;
      coords = coords3;
    }
    else
    {
      *((u8 *) (p + 0x18)) = 4;
      coords = coords4;
    }
    owner = func_020490F4(7, *((u16 *) p));
    for (i = 0; i < (*((u8 *) (p + 0x18))); i++)
    {
      species = *((u16 *) (desc + i * 4 + 4));
      form = desc[i * 4 + 6];
      gender = desc[i * 4 + 7];
      if (i == 0)
        *((u32 *) (p + i * 12 + 0x20)) = func_0204ACEC(owner, func_0201BC3C(), 0, 32, *((u16 *) p));
      res = p + i * 12;
      *((u32 *) (res + 0x1C)) = func_0204A6C8(owner, func_0201BABC(species, form, gender, 0), 0, 0, *((u16 *) p));
      *((u32 *) (res + 0x24)) = func_0204AF28(owner, func_0201BC40(), func_0201BCB4(), *((u16 *) p));
      func_02082BCC(&param, 0, 8);
      param.x = *((const s16 *) (coords + i * 4));
      param.y = *((const s16 *) (coords + i * 4 + 2));
      slot = p + i * 4;
      actor = func_0204B294((void *)func_021BA1E0(*((void **) (p + 8))), *((u32 *) (res + 0x1C)), *((u32 *) (p + 0x20)), *((u32 *) (res + 0x24)), (const void *)((u32) (&param)), 0, *((u16 *) p));
      *((void **) (slot + 0x4C)) = actor;
      func_0204B878(actor, 1);
      func_0204B92C(*((void **) (slot + 0x4C)), 0);
      func_0204B6F4(*((void **) (slot + 0x4C)), func_0201BB5C(species, form, gender, 0), 0);
    }
    func_02049238(owner);
  }
}
