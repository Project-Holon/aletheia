/*
 * function: func_021E2E70
 * address: 0x021E2E70
 * packet: pkt_ov183_021E2E70
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Bounded permuter split the scaled index and delayed the base load, then introduced store-address temporaries after the constructor. Fixed one validated its behavior-preserving winning C.
 * symbols:
 *   func_021FD12C 0x021FD12C thumb ov186
 *   func_021FC21C 0x021FC21C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_021FD19C 0x021FD19C thumb ov186
 *   func_02045808 0x02045808 arm
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E3928 0x021E3928 data a4
 */
typedef unsigned short u16;
extern void *func_021FD12C(int a, void *owner, u16 heap);
extern int func_021FC21C(char *);
extern int func_021FC214(char *);
typedef unsigned int   u32;
struct U16Vec;
struct WordSet;
extern unsigned func_021FC20C(char *p);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EE0C(void *, int, unsigned, unsigned, int, int);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_021FD19C(char *p, void *q, void *text);
extern void func_02045808(struct U16Vec *vec);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void *func_021FC6A4(u16, unsigned, u16, u16, unsigned char, unsigned char, void *, u16);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
extern const unsigned char d_021E3928[];
void func_021E2E70(char *p, const char *q)
{
  void *a;
  void *s;
  void *b;
  int h;
  int c;
  int i;
  const unsigned char *r;
  unsigned base;
  unsigned index;
  void **tmp;
  void **tmp1;
  char *tmp2;
  if (!(*((void **) (p + 8))))
    *((void **) (p + 8)) = func_021FD12C(*((int *) (q + 8)), (void *)(*((int *) (p + 4))), *((u16 *) (p + 0x38)));
  a = (void *) func_021FC21C(*((char **) (q + 8)));
  s = func_02045EC0((struct MsgBank *)func_021FC214(*((char **) (q + 8))), 0x141);
  b = func_020457B0(0x80, *((u16 *) (p + 0x38)));
  index = *((unsigned *) (p + 0x10));
  index = index * 4;
  base = *((unsigned *) (q + 0x18));
  func_0201EE0C(a, 0, *((unsigned *) ((base + index) + 0x14)), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  func_0201F250(a, b, s);
  func_021FD19C(*((void **) (p + 8)), (void *)(*((int *) (q + 8))), b);
  func_02045808(b);
  func_02045808(s);
  func_021FB964((void *)(*((int *) (q + 8))), 0x1e, *((u16 *) (p + 0x38)));
  h = func_021FC20C(*((char **) (q + 8)));
  c = func_021FC214(*((char **) (q + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    tmp2 = p + 4;
    *((void **) ((p + (i * 4)) + 0x28)) = func_021FC6A4(4, r[0], r[1], r[2], r[3], 14, *((void **) tmp2), *((u16 *) (p + 0x38)));
    tmp1 = (void **) (0x28 + (p + (i * 4)));
    tmp = tmp1;
    func_021FC754(*tmp, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}
