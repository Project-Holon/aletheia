/*
 * function: func_0220B3EC
 * address: 0x0220B3EC
 * packet: pkt_ov197_0220B3EC
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Width: original narrows y to signed halfword before printer; corresponding extern keeps s16 despite owner u32.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045334 0x02045334 arm
 *   d_0220DA3C 0x0220DA3C data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned long u32;
extern void *func_02045770(void *);
extern u8 func_02045738(void *);
extern void func_02043B5C(void *, u8);
extern void *func_02045EC0(void *, u32);
extern void func_0201EFA4(void *, u32, u32, u32, u32, u32);
extern void func_0201EF40(void *, u32, u32);
extern void func_0201F250(void *, void *, void *);
extern void func_0201C724(void *, void *, s16, s16, void *, u32, u16);
extern void func_02045808(void *);
extern void func_02045334(void *);
extern const char d_0220DA3C[];
void func_0220B3EC(char *p, u32 i, int id, int w, int unused, int y, int unused2)
{
  char *windows = p + 0x28;
  void *handle = *((void **) (windows + (w * 8)));
  void *text;
  void *font;
  void *surface;
  int page;
  char *tmp;
  u16 pad;
  u32 *tmp1;
  char *tmp2;
  func_02043B5C(func_02045770(handle), 0);
  page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
  if (((*((u16 *) ((page + (i * 4)) + 0x152))) != 0) && ((*((int *) ((*((char **) p)) + 8))) != 1))
  {
    text = func_02045EC0(*((void **) (p + 0xC)), *((u32 *) (d_0220DA3C + (id * 8))));
    page = ((u32) p) + (((u8 *) p)[0x533] * 0x90);
    func_0201EFA4(*((void **) (p + 0x10)), 0, *((u16 *) (((u32) (page + (i * 4))) + 0x152)), 3, 0, 1);
    tmp2 = p + 0x14;
    func_0201F250(*((void **) (p + 0x10)), *((void **) tmp2), text);
    font = *((void **) (p + 0x18));
    surface = func_02045770(*((void **) (windows + (w * 8))));
    tmp = p + 0x14;
    tmp1 = (u32 *) ((*((char **) p)) + 4);
    func_0201C724(font, surface, 0, y, *((void **) tmp), *tmp1, 0x3C40);
    (p + (w * 8))[0x2C] = 1;
    func_02045808(text);
  }
  else
  {
    func_02045334(handle);
  }
}
