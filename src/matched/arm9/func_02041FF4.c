/*
 * function: BG_SYS_CheckPixelColor
 * address:  0x02041FF4
 * packet:   pkt_02041FF4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   g_020A7E5C     0x020A7E5C  data
 *   BG_SYS_GetTileMapEntry  0x02040EE0  arm
 *   BG_SYS_GetGraphics  0x020415B4  arm
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   BG_SYS_AllocTileBuf  0x02043130  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * bg_sys.c: does the pixel under (x, y) on a layer match the caller's
 * colour list?  4bpp layers (flag_1e == 0) decode the tile into a scratch
 * 0x40-byte nibble buffer and test bit v of *flags; 8bpp layers copy the
 * tile (or, for mode 1, read the affine byte map directly) and scan a
 * 0xFFFF-terminated list.
 *
 * WHAT CLOSED IT (wave 12, 42 -> 0): the sub-tile coordinates px/py are
 * FUNCTION-SCOPE u8 locals declared first and assigned after the two
 * calls (the block-scoped `u8 px = x & 7; u16 py = y & 7;` of the wave-11
 * source kept x/y and px/py in separate registers: 42); the nibble loop
 * counter i is also function-scope (15 -> 9); and i must be declared
 * before tbl, tbl before buf (9 -> 0).  All other facts (u16 first
 * parameter of BG_SYS_AllocTileBuf, shared fail exit, mode != 1 arm first) are
 * from docs/notes/pkt_02041FF4.c.txt.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
struct BgSlot
{
  u16 heapId;
  u8 pad_02[6];
  void *tiles;
  u32 unk_0c;
  u32 size;
  u32 scroll_x;
  u32 scroll_y;
  u8 mode;
  u8 unk_1d;
  u8 flag_1e;
  u8 depth;
  u32 unk_20;
  u32 unk_24;
  u32 unk_28;
};
struct BgSys
{
  struct BgSlot slots[8];
};
extern struct BgSys *g_02146A44;
extern char g_020A7E5C[];
extern u16 BG_SYS_GetTileMapEntry(int x, int y, u32 code);
extern u32 BG_SYS_GetGraphics(u32 channel);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
extern void BG_SYS_AllocTileBuf(u16 flags, u8 *buf, u32 page);
extern void MI_CpuCopy8(void *dst, const void *src, u32 size);
u32 BG_SYS_CheckPixelColor(u32 layer, u16 x, u16 y, u16 *flags)
{
  u8 px;
  u8 py;
  u16 key;
  u8 *chr;
  u8 i;
  u16 *tbl;
  u8 *buf;
  u8 v;
  if (g_02146A44->slots[layer].tiles == 0)
    return 0;
  key = BG_SYS_GetTileMapEntry((u8) (x >> 3), (u8) (y >> 3), g_02146A44->slots[layer].unk_1d);
  chr = (u8 *)BG_SYS_GetGraphics(layer);
  px = x & 7;
  py = y & 7;
  if (g_02146A44->slots[layer].flag_1e == 0)
  {
    u8 *src;
    tbl = g_02146A44->slots[layer].tiles;
    buf = func_02030734((u16)((g_02146A44->slots[0].heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa77);
    src = chr + (((u32) (tbl[key] << 22)) >> 17);
    for (i = 0; i < 0x20; i++)
    {
      buf[i * 2] = src[i] & 0xf;
      buf[(i * 2) + 1] = src[i] >> 4;
    }

    BG_SYS_AllocTileBuf((tbl[key] >> 10) & 3, buf, g_02146A44->slots[0].heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
    if (((*flags) & (1 << v)) == 0)
      goto fail;
    return 1;
  }
  if (g_02146A44->slots[layer].mode != 1)
  {
    tbl = g_02146A44->slots[layer].tiles;
    buf = func_02030734((u16)((g_02146A44->slots[0].heapId & 0x7fff) | 0x8000), 0x40, 0, g_020A7E5C, 0xa8f);
    MI_CpuCopy8(buf, chr + (((u32) (tbl[key] << 22)) >> 16), 0x40);
    BG_SYS_AllocTileBuf((tbl[key] >> 10) & 3, buf, g_02146A44->slots[0].heapId);
    v = buf[px + (py << 3)];
    func_020307B0(buf);
  }
  else
  {
    v = chr[((((u8 *) g_02146A44->slots[layer].tiles)[key] << 6) + px) + (py << 3)];
  }
  for (;;)
  {
    if ((*flags) == 0xffff)
      goto fail;
    if (v == ((*flags) & 0xff))
      return 1;
  }
  fail:
  return 0;

}


