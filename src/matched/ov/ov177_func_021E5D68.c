/*
 * function: WIFIBATTLEMATCH_VIEW_CreateStatusWindow
 * address: 0x021E5D68
 * packet: pkt_ov177_021E5D68
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021E8DBC 0x021E8DBC data a1
 *   func_02030734 0x02030734 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   func_0207D63C 0x0207D63C arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   CLACT_AddActorSurfacePos 0x0204B404 arm
 *   WIFIBATTLEMATCH_VIEW_SetupDateWindow 0x021E6940 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreatePokeActors 0x021E6F20 thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreatePokeActor 0x021E72FC thumb ov177
 *   WIFIBATTLEMATCH_VIEW_CreateActorFromTable 0x021E73E4 thumb ov177
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef enum 
{
  BG2 = 2,
  BG6 = 6
} Layer;
typedef struct 
{
  short x;
  short y;
} Pt;
typedef struct Work Work;
typedef struct Info Info;
extern const char d_021E8DBC[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void MI_CpuFill8(void *, u32, u32);
extern void func_0207D63C(void *, int, int, int, int);
extern void BG_SYS_FillTileMap(u8, u8, u8, u8, u8, u8);
extern void BG_SYS_PushTile(u32);
extern void WIFIBATTLEMATCH_VIEW_SetupDateWindow(Work *, u32, const Info *, void *, int, void *, void *, void *, u16);
extern void WIFIBATTLEMATCH_VIEW_CreatePokeActors(Work *, void *, void *, u16);
extern void WIFIBATTLEMATCH_VIEW_CreatePokeActor(u8 *, unsigned, unsigned, unsigned);
extern void WIFIBATTLEMATCH_VIEW_CreateActorFromTable(char *, unsigned, void *, unsigned);
extern void CLACT_AddActorSurfacePos(void *, const Pt *, u16);
char *WIFIBATTLEMATCH_VIEW_CreateStatusWindow(char *info, u32 a, void *b, void *owner, void *table, int c, void *d, void *e, void *f, void *record, int mode, u16 heap)
{
  char *w;
  Layer layer;
  Pt pos;
  Info *tmp;
  w = func_02030734(heap, 0x244, 0, d_021E8DBC, 0x27f);
  MI_CpuFill8(w, 0, 0x244);
  *((void **) (w + 0x238)) = record;
  *((u16 *) (w + 0x23c)) = heap;
  *((void **) (w + 0x240)) = owner;
  if (mode)
  {
    layer = 2;
    *((u8 *) (w + 0x230)) = 1;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 5;
    *((u8 *) (w + 0x233)) = 9;
    *((u32 *) (w + 0x234)) = 0;
    func_0207D63C((void *) 0x04000050, 4, 8, 15, 3);
  }
  else
  {
    *((u8 *) (w + 0x230)) = 5;
    *((u8 *) (w + 0x231)) = 15;
    *((u8 *) (w + 0x232)) = 3;
    *((u8 *) (w + 0x233)) = 7;
    *((u32 *) (w + 0x234)) = 1;
    layer = 6;
    func_0207D63C((void *) 0x04001050, 4, 8, 15, 3);
  }
  tmp = (Info *) info;
  switch (*((u16 *) (info + 0xaa)))
  {
    case 0:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 3);
      BG_SYS_PushTile((u8) layer);
      break;

    case 1:
      BG_SYS_FillTileMap(layer, 0, 0, 32, 5, 1);
      BG_SYS_FillTileMap(layer, 0, 5, 32, 18, 7);
      BG_SYS_PushTile((u8) layer);
      break;

  }

  WIFIBATTLEMATCH_VIEW_SetupDateWindow((Work *) w, a, tmp, b, c, d, e, f, heap);
  WIFIBATTLEMATCH_VIEW_CreatePokeActors((Work *) w, owner, record, heap);
  info += 0x9c;
  WIFIBATTLEMATCH_VIEW_CreatePokeActor((u8 *) w, *((u32 *) info), (u32) owner, heap);
  pos.x = 0x120;
  pos.y = 0x6e;
  CLACT_AddActorSurfacePos(*((void **) (w + 0x188)), &pos, *((u32 *) (w + 0x234)));
  WIFIBATTLEMATCH_VIEW_CreateActorFromTable(w, (u32) owner, table, heap);
  return w;
}
