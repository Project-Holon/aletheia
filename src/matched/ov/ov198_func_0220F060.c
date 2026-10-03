/*
 * function: func_0220F060
 * address: 0x0220F060
 * packet: pkt_ov198_0220F060
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022110D4 0x022110D4 thumb ov198
 *   func_0220E82C 0x0220E82C thumb ov198
 *   func_0220E7CC 0x0220E7CC thumb ov198
 *   sub_0201BD28 0x0201BD28 thumb
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
extern int func_022110D4(u8 *, int);
extern void func_0220E82C(u8 *, void *, int, int);
extern void func_0220E7CC(u8 *, u32);
extern u32 sub_0201BD28(u16, u32);
extern u32 d_02211DA0[];
void func_0220F060(u8 *p)
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
  rec = (p + 4) + (func_022110D4(p, (*((u8 **) p))[32]) * 76);
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
      func_0220E82C(p, *((void **) (b + 0x1ebc)), slot + i, entry[48]);
      tmp = (u8 *) d_02211DA0;
      func_0220E7CC(*((u8 **) (b + 0x1ebc)), (u32) (tmp + offset));
    }
  }

  if (((*((u16 *) ((*((u8 **) p)) + 38))) != 0) && ((*((u8 **) p))[31] == 4))
  {
    offset = (base + i) * 4;
    b = p + 0x1ebc;
    func_0220E82C(p, *((void **) (b + offset)), slot + i, sub_0201BD28(*((u16 *) ((*((u8 **) p)) + 38)), 0));
    func_0220E7CC(*((u8 **) (b + offset)), (u32) (d_02211DA0 + i));
  }
  ((Flag *) (p + 0x2175))->bit ^= 1;
}
