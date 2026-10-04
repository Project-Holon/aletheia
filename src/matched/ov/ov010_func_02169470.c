/*
 * function: func_02169470
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
 *   func_02169998  0x02169998  thumb  ov010
 *   func_02169550  0x02169550  thumb  ov010
 *   func_02169568  0x02169568  thumb  ov010
 *   func_02169880  0x02169880  thumb  ov010
 *   func_0204944C  0x0204944C  arm
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

extern void func_02169998(void *p);
extern void func_02169550(void *p);
extern void func_02169568(void *p);
extern void func_02169880(void *p);
struct ArcFile;
extern void func_0204944C(struct ArcFile *h, u32 b, u32 c, u32 d, void *out);
void func_02169470(u8 *p, u32 b)
{
  u16 v;
  const E *tbl;
  int i;
  E *tmp;
  func_02169998(*((void **) (p + 0x2c)));
  func_02169550(p);
  func_02169568(p);
  func_02169880(p);
  *((u32 *) (p + 0x14)) = b;
  func_0204944C((struct ArcFile *)*((u32 *) (p + 0x10)), b, 0, 2, &v);
  tmp = *((E **) (p + 0x28));
  tbl = *((E **) (p + 0x28));
  i = Find(&v, tmp);
  tbl = tbl;
  *((int *) (p + 0x18)) = i;
  *((u16 *) (p + 0xb0)) = 1;
}
