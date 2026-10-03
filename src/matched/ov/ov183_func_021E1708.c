/*
 * function: func_021E1708
 * address: 0x021E1708
 * packet: pkt_ov183_021E1708
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Matching: named digit load and byte-field address, with group before used in declaration order, preserve the original loop registers.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_02045AA8 0x02045AA8 arm
 *   func_0201F35C 0x0201F35C thumb
 *   func_0204B878 0x0204B878 arm
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E1374 0x021E1374 thumb ov183
 *   _ull_mul 0x0209C054 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef unsigned long long u64;
struct Obj;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_02045AA8(struct U16Vec *dst, struct U16Vec *src);
extern void func_0201F35C(void *, int, u32, u32, u32);
extern void func_0204B878(struct Obj *p, u16 value);
extern int func_021E0E40(int, int);
extern void func_021E1374(char *, int);
void func_021E1708(char *p)
{
  u32 group = 0;
  u32 i;
  int used = 0;
  int digit;
  void *text;
  char *record;
  u64 *acc;
  u64 product;
  u32 tmp;
  char *tmp1;
  text = func_020457B0(100, *((u16 *) (p + 0x34C)));
  tmp1 = p + 0x210;
  *((int *) (p + 0x1F8)) = 1;
  *((u8 *) tmp1) = 0;
  *((int *) (p + 0x354)) = 0;
  *((int *) (p + 0x358)) = 0;
  *((int *) (p + 0x35C)) = 0;
  *((u32 *) (p + 0x360)) = 0;
  *((u32 *) (p + 0x364)) = 0;
  i = 0;
  if (((int) i) < (*((int *) (p + 0x23C))))
  {
    acc = (u64 *) (p + 0x360);
    do
    {
      record = (char *) (((u32) p) + (i * 28));
      if ((*((int *) record)) == 0)
      {
        *((int *) record) = 1;
        func_0204B878(*((void **) (record + 12)), func_021E0E40(1, *((int *) (record + 8))));
      }
      tmp = *((u32 *) record);
      digit = tmp - 1;
      func_0201F35C(text, digit, 1, 1, 1);
      func_02045AA8(*((void **) (p + 0x33C)), text);
      *((int *) ((((u32) p) + (group * 4)) + 0x354)) *= 10;
      *((int *) ((((u32) p) + (group * 4)) + 0x354)) += digit;
      used++;
      if (((int) used) >= (*((int *) ((((u32) p) + (group * 4)) + 0x328))))
      {
        group++;
        used = 0;
      }
      product = (*acc) * 10;
      *acc = product + ((u32) digit);
      i++;
    }
    while (((int) i) < (*((int *) (p + 0x23C))));
  }
  func_02045808(text);
  func_021E1374(p, 3);
  *((int *) (p + 0x350)) = 2;
}
