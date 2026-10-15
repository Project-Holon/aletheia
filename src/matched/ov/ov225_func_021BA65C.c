/*
 * function: func_021BA65C
 * address: 0x021BA65C
 * packet: pkt_ov225_021BA65C
 * region: ov225
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021BC028 0x021BC028 data ov225 a1
 *   func_021BA898 0x021BA898 thumb ov225
 *   func_021BAA44 0x021BAA44 thumb ov225
 *   BG_SYS_ResetSlot 0x02041EE4 arm
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   func_021BB074 0x021BB074 thumb ov225
 *   func_021BB258 0x021BB258 thumb ov225
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021BA894 0x021BA894 thumb ov225
 *   func_021BA068 0x021BA068 thumb ov225
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
struct Obj;
struct Vec2
{
  s16 x;
  s16 y;
};
struct Data
{
  void *owner;
  u16 heap;
  u16 pad6;
  char rest[48];
};
struct Work
{
  char *owner;
  struct Data *data;
  u32 field8;
  void *a[8];
  void *b[8];
  u32 field4c;
  void *res50;
  void *res54;
  void *res58;
  struct Obj *obj;
  void *arr60[8];
  void *task;
  u32 field84;
  u32 field88;
  u32 field8c;
  signed char field90;
  u8 pad91[3];
  u32 field94;
};
extern const char d_021BC028[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_021BA898(char *);
extern void func_021BAA44(struct Work *);
extern void BG_SYS_ResetSlot(u32, u32, u32);
extern void CLACT_SetActorDrawEnable(struct Obj *, u32);
extern u16 func_021BB074(u16 **);
extern u16 func_021BB258(void *, u16, u16);
extern void CLACT_AddActorSurfacePos(struct Obj *, const struct Vec2 *, u32);
extern void *func_020056A0(u32, u32, u32);
extern void func_021BA894(void);
extern void func_021BA068(char *, unsigned);
void *func_021BA65C(char *owner, struct Data *data)
{
  struct Work *p;
  struct Vec2 v;
  u8 i;
  u32 flag;
  u32 state;
  int n;
  s16 y;
  int mode;
  p = func_02030734(data->heap, 0x98, 1, d_021BC028, 0xdf);
  p->owner = owner;
  *((u32 *) (owner + 0x10)) = 0;
  p->data = data;
  i = 0;
  do
  {
    p->a[i] = 0;
    p->b[i] = 0;
    i++;
  }
  while (i < 8);
  p->field94 = 0;
  func_021BA898((char *)p);
  func_021BAA44(p);
  BG_SYS_ResetSlot(5, 3, 12);
  flag = 0;
  if ((*((u16 *) (p->owner + 4))) > 6)
    flag = 1;
  CLACT_SetActorDrawEnable(p->obj, flag);
  n = func_021BB074((u16 **) p);
  n = n + 1;
  y = func_021BB258(p, n, *((u16 *) (p->owner + 0xc)));
  v.x = 240;
  v.y = y;
  CLACT_AddActorSurfacePos(p->obj, &v, 1);
  p->task = func_020056A0((u32) func_021BA894, (u32) p, 1);
  p->field84 = 0;
  p->field88 = 0;
  p->field8c = 0;
  p->field90 = -1;
  mode = *((int *) p->owner);
  state = 2;
  if (mode == 0)
    state = 1;
  else
    if (mode == 1)
    state = 2;
  func_021BA068(*((char **) (((char *) p->data) + 0x34)), state);
  return p;
}
