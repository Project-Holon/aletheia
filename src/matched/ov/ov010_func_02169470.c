/*
 * function: FIELD_G3D_MAP_StartLoad
 * address:  0x02169470
 * packet:   pkt_ov010_02169470
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * lever: initialized table-read temporary in the once-only budget-300 permuter
 * gives table r1 and sentinel r0; validation agrees with all five relocations.
 *
 * symbols:
 *   FIELD_G3D_MAP_ClearRenderObjModel  0x02169998  thumb  ov010
 *   FIELD_G3D_MAP_ClearModelRes  0x02169550  thumb  ov010
 *   FIELD_G3D_MAP_ClearTextureRes  0x02169568  thumb  ov010
 *   FIELD_G3D_MAP_ClearPlacements  0x02169880  thumb  ov010
 *   ARC_TOOL_ReadHandleMemberRange  0x0204944C  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct E
{
  int key;
  int a;
  int b;
  int c;
} E;
inline static int Find(const u16 *pv, const E *tbl)
{
  unsigned i;
  i = 0;
  while (tbl[i].key != (-1))
  {
    if ((*pv) == tbl[i].key)
      break;
    i++;
  }

  return i;
}

extern int FIELD_G3D_MAP_ClearRenderObjModel(int a0, int a1);
extern void FIELD_G3D_MAP_ClearModelRes(char *p);
extern void FIELD_G3D_MAP_ClearTextureRes(char *p);
extern void FIELD_G3D_MAP_ClearPlacements(u8 *p);
struct ArcFile;
extern void ARC_TOOL_ReadHandleMemberRange(struct ArcFile *h, u32 b, u32 c, u32 d, void *out);
void FIELD_G3D_MAP_StartLoad(u8 *p, u32 b)
{
  u16 v;
  const E *tbl;
  int i;
  E *tmp;
  FIELD_G3D_MAP_ClearRenderObjModel((int)(*((void **) (p + 0x2c))), b);
  FIELD_G3D_MAP_ClearModelRes((char *)p);
  FIELD_G3D_MAP_ClearTextureRes((char *)p);
  FIELD_G3D_MAP_ClearPlacements(p);
  *((u32 *) (p + 0x14)) = b;
  ARC_TOOL_ReadHandleMemberRange((struct ArcFile *)*((u32 *) (p + 0x10)), b, 0, 2, &v);
  tmp = *((E **) (p + 0x28));
  tbl = *((E **) (p + 0x28));
  i = Find(&v, tmp);
  tbl = tbl;
  *((int *) (p + 0x18)) = i;
  *((u16 *) (p + 0xb0)) = 1;
}
