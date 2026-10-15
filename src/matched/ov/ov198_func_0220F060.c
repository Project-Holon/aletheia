/*
 * function: B_PLIST_MAIN_SyncMoveActors
 * address: 0x0220F060
 * packet: pkt_ov198_0220F060
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_MAIN_GetOrderIndex 0x022110D4 thumb ov198
 *   B_PLIST_DRAW_TransferCharacter 0x0220E82C thumb ov198
 *   B_PLIST_DRAW_PlaceActor 0x0220E7CC thumb ov198
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   d_02211DA0 0x02211DA0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct 
{
  u8 low : 6;
  u8 bit : 1;
  u8 high : 1;
} Flag;
extern int B_PLIST_MAIN_GetOrderIndex(u8 *, int);
extern void B_PLIST_DRAW_TransferCharacter(char *p, void *obj, int index, int which);
extern void B_PLIST_DRAW_PlaceActor(u8 *, u32);
extern u32 WAZA_TOOL_GetParam(u16, u32);
extern u32 d_02211DA0[];
void B_PLIST_MAIN_SyncMoveActors(u8 *p)
{
  u8 *rec;
  u8 *objects;
  int base;
  unsigned long offset;
  int i;
  u8 *entry;
  u8 *b;
  int slot;
  u8 *tmp;
  Flag *tmp1;
  tmp1 = (Flag *) (p + 0x2175);
  rec = (p + 4) + (B_PLIST_MAIN_GetOrderIndex(p, (*((u8 **) p))[32]) * 76);
  if (tmp1->bit == 0)
  {
    base = 29;
    slot = 12;
  }
  else
  {
    base = 34;
    slot = 17;
  }
  objects = p + (base * 4);
  for (i = 0; i < 4u; i++)
  {
    entry = rec + (i * 8);
    if ((*((u16 *) (entry + 44))) != 0)
    {
      offset = i * 4;
      b = objects + offset;
      B_PLIST_DRAW_TransferCharacter((char *)p, *((void **) (b + 0x1ebc)), slot + i, entry[48]);
      tmp = (u8 *) d_02211DA0;
      B_PLIST_DRAW_PlaceActor(*((u8 **) (b + 0x1ebc)), (u32) (tmp + offset));
    }
  }

  if (((*((u16 *) ((*((u8 **) p)) + 38))) != 0) && ((*((u8 **) p))[31] == 4))
  {
    offset = (base + i) * 4;
    b = p + 0x1ebc;
    B_PLIST_DRAW_TransferCharacter((char *)p, *((void **) (b + offset)), slot + i, WAZA_TOOL_GetParam(*((u16 *) ((*((u8 **) p)) + 38)), 0));
    B_PLIST_DRAW_PlaceActor(*((u8 **) (b + offset)), (u32) (d_02211DA0 + i));
  }
  ((Flag *) (p + 0x2175))->bit ^= 1;
}
