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
 *   BR_UTIL_CreateTextWin 0x021FD12C thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201EE0C 0x0201EE0C thumb
 *   func_0201F250 0x0201F250 thumb
 *   BR_UTIL_SetWindowTextBuf 0x021FD19C thumb ov186
 *   STRBUF_Delete 0x02045808 arm
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextFromMessage 0x021FC754 thumb ov186
 *   d_021E3928 0x021E3928 data a4
 */
typedef unsigned short u16;
extern void *BR_UTIL_CreateTextWin(int a, void *owner, u16 heap);
extern int BR_RES_GetWordSet(char *);
extern int BR_RES_GetMsgData(char *);
typedef unsigned int   u32;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
struct MsgBank;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201EE0C(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void BR_UTIL_SetWindowTextBuf(char *p, void *q, void *text);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void *BR_UTIL_Create(u16, unsigned, u16, u16, unsigned char, unsigned char, void *, u16);
extern void BR_UTIL_SetTextFromMessage(char *p, void *a, void *b, void *font, unsigned short value);
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
    *((void **) (p + 8)) = BR_UTIL_CreateTextWin(*((int *) (q + 8)), (void *)(*((int *) (p + 4))), *((u16 *) (p + 0x38)));
  a = (void *) BR_RES_GetWordSet(*((char **) (q + 8)));
  s = func_02045EC0((struct MsgBank *)BR_RES_GetMsgData(*((char **) (q + 8))), 0x141);
  b = STRBUF_Create(0x80, *((u16 *) (p + 0x38)));
  index = *((unsigned *) (p + 0x10));
  index = index * 4;
  base = *((unsigned *) (q + 0x18));
  func_0201EE0C(a, 0, (const void *)(*((unsigned *) ((base + index) + 0x14))), *((unsigned *) ((((unsigned) base) + index) + 0x24)), 1, 2);
  func_0201F250(a, b, s);
  BR_UTIL_SetWindowTextBuf(*((void **) (p + 8)), (void *)(*((int *) (q + 8))), b);
  STRBUF_Delete(b);
  STRBUF_Delete(s);
  BR_RES_LoadBgGraphics((void *)(*((int *) (q + 8))), 0x1e, *((u16 *) (p + 0x38)));
  h = BR_RES_GetFont(*((char **) (q + 8)));
  c = BR_RES_GetMsgData(*((char **) (q + 8)));
  for (i = 0; i < 2; i++)
  {
    r = d_021E3928;
    r = r + (i * 8);
    tmp2 = p + 4;
    *((void **) ((p + (i * 4)) + 0x28)) = BR_UTIL_Create(4, r[0], r[1], r[2], r[3], 14, *((void **) tmp2), *((u16 *) (p + 0x38)));
    tmp1 = (void **) (0x28 + (p + (i * 4)));
    tmp = tmp1;
    BR_UTIL_SetTextFromMessage(*tmp, (void *)c, (void *)(*((int *) (r + 4))), (void *)h, 0x3da0);
  }

}
