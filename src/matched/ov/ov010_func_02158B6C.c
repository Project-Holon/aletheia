/*
 * function: func_02158B6C
 * address:  0x02158B6C
 * packet:   pkt_ov010_02158B6C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * levers: wave76 reused cursor p across both parsing phases; p += 6 at the
 * matched key, then p += key before save accessor. Local base/q produced
 * DIFF40; cursor reuse alone31, resetting it through base129; in-place
 * advances give EXACT. Permuter300 previously consumed, not repeated.
 * symbols:
 *   func_0201296C  0x0201296C  thumb
 *   func_020143CC  0x020143CC  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct BigObj;
extern u32 func_0201296C(const struct BigObj *p);
extern u16 *func_020143CC(u32, u32);
inline static u16 RD16(const u8 *p)
{
  return (u16) (p[0] + (p[1] << 8));
}

u16 func_02158B6C(const void *a, const u8 *list, u32 key)
{
  const u8 *p = list;
  u32 h;
  const u8 *tmp;
  int pad;
  u16 tmp1;
  u32 tmp2;
  for (;; p += 6)
  {
    u32 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (key == id)
    {
      key = ((p[2] + (p[3] << 8)) + (p[4] << 16)) + (p[5] << 24);
      p += 6;
      break;
    }
  }

  if (key == 0)
    return 0xFFFF;
  p += key;
  tmp2 = func_0201296C(a);
  h = tmp2;
  for (;; p += 6)
  {
    u16 val;
    u16 id = RD16(p);
    if (id == 0)
      return 0xFFFF;
    if (id == 0)
      return 0xFFFF;
    tmp1 = RD16(p + 2);
    val = tmp1;
    if (val == (*func_020143CC(h, id)))
      return RD16(p + 4);
  }

}
