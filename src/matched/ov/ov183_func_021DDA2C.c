/*
 * function: BR_CODEIN_ListSetupRowC
 * address: 0x021DDA2C
 * packet: pkt_ov183_021DDA2C
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: bounded permuter rec/index declaration order, selector use and
 *        field-base expansion restore the three selector/index spill homes.
 * symbols:
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   BR_RES_GetWordSet 0x021FC21C thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_CODEIN_ListIsEventC 0x021DE058 thumb ov183
 *   BR_UTIL_Create 0x021FC6A4 thumb ov186
 *   BR_UTIL_SetTextLayout 0x021FC868 thumb ov186
 *   BSUBWAY_SCOREDATA_HasCleared 0x0200DB44 thumb
 *   BSUBWAY_SCOREDATA_GetWinCount 0x0200DAC4 thumb
 *   BSUBWAY_SCOREDATA_GetMaxWinCount 0x0200DAD8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   STRBUF_Create 0x020457B0 arm
 *   WORDSET_SetSlotNumber 0x0201EFA4 thumb
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   BR_UTIL_SetTextFromBuffer 0x021FC7C4 thumb ov186
 *   BSUBWAY_SCOREDATA_GetBattlePoints 0x0200DABC thumb
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_CODEIN_ListCreateActor 0x021DE084 thumb ov183
 *   d_021E3490 0x021E3490 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record
{
  u8 a;
  u8 b;
  u8 c;
  u8 d;
  int value;
};
struct Triple
{
  int a;
  int b;
  int c;
};
extern const struct Record d_021E3490[];
typedef unsigned int   u32;
struct Blk1AC;
struct U16Vec;
struct WordSet;
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern int BR_RES_GetWordSet(char *);
struct MsgBank;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_UTIL_SetTextLayout(u8 *p, u32 a, u32 b, u32 c);
extern int BR_CODEIN_ListIsEventC(void *p, void *q);
extern void *BR_UTIL_Create(u16, unsigned, u16, u16, u8, u8, void *, u16);
extern u32 BSUBWAY_SCOREDATA_HasCleared(struct Blk1AC *p, u32 i);
extern u16 BSUBWAY_SCOREDATA_GetWinCount(struct Blk1AC *p, u32 i);
extern u16 BSUBWAY_SCOREDATA_GetMaxWinCount(struct Blk1AC *p, u32 i);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void WORDSET_SetSlotNumber(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void BR_UTIL_SetTextFromBuffer(char *, void *, void *, u16);
extern u16 BSUBWAY_SCOREDATA_GetBattlePoints(struct Blk1AC *p);
extern int BR_RES_GetSprite(int, int, struct Triple *);
extern void BR_CODEIN_ListCreateActor(char *, void *, const char *, unsigned, short, short, u16);
void BR_CODEIN_ListSetupRowC(char *p, char *q)
{
  int first;
  int second;
  int third;
  const struct Record *rec;
  int v;
  unsigned select;
  unsigned select2;
  int index;
  char *slot;
  int number1;
  int number2;
  int number3;
  int number4;
  void *obj;
  struct Triple triple;
  char **tmp1;
  u16 tmp;
  first = BR_RES_GetFont(*((char **) (q + 8)));
  second = BR_RES_GetMsgData(*((char **) (q + 8)));
  third = BR_RES_GetWordSet(*((char **) (q + 8)));
  tmp = *((u16 *) (p + 0x7c));
  BR_RES_LoadBgGraphics((void *)(*((int *) (q + 8))), 12, tmp);
  if (BR_CODEIN_ListIsEventC((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14)))))
  {
    select = 7;
    select2 = 8;
  }
  else
  {
    select = 2;
    select2 = 3;
  }
  ;
  for (index = 0; index < 16; index++)
  {
    rec = &d_021E3490[index];
    slot = p + (index * 4);
    *((void **) (slot + 0x34)) = BR_UTIL_Create(1, (&d_021E3490[index])->a, (&d_021E3490[index])->b, (&d_021E3490[index])->c, (&d_021E3490[index])->d, 14, *((void **) (p + 4)), *((u16 *) (p + 0x7c)));
    BR_UTIL_SetTextLayout(*((void **) (slot + 0x34)), 0, 1, 0);
    switch (index)
    {
      if (select2)
      {
      }
      case 1:
        obj = func_02045EC0((struct MsgBank *)second, (BR_CODEIN_ListIsEventC((void *)(*((int *) (q + 0x10))), (void *)(*((int *) (q + 0x14))))) ? (0x85) : (0x80));
        break;

      case 3:
        obj = func_02045EC0((struct MsgBank *)second, (BSUBWAY_SCOREDATA_HasCleared(*((void **) (q + 0x10)), select)) ? (0x91) : (0x87));
        break;

      case 4:
      {
        void *base;
        number1 = BSUBWAY_SCOREDATA_GetWinCount(*((void **) (q + 0x10)), select);
        if (number1 > 9999)
          number1 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number1, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 7:
      {
        void *base;
        number2 = BSUBWAY_SCOREDATA_GetMaxWinCount(*((void **) (q + 0x10)), select);
        if (number2 > 9999)
          number2 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number2, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 10:
        obj = func_02045EC0((struct MsgBank *)second, (BSUBWAY_SCOREDATA_HasCleared(*((void **) (q + 0x10)), select2)) ? (0x91) : (0x87));
        break;

      case 11:
      {
        void *base;
        number3 = BSUBWAY_SCOREDATA_GetWinCount(*((void **) (q + 0x10)), select2);
        if (number3 > 9999)
          number3 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number3, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      case 14:
      {
        void *base;
        number4 = BSUBWAY_SCOREDATA_GetMaxWinCount(*((void **) (q + 0x10)), select2);
        if (number4 > 9999)
          number4 = 9999;
        base = func_02045EC0((struct MsgBank *)second, rec->value);
        obj = STRBUF_Create(0x80, *((u16 *) (p + 0x7c)));
        WORDSET_SetSlotNumber((void *) third, 0, number4, 4, 1, 1);
        WORDSET_CopyTaggedText((void *) third, obj, base);
        STRBUF_Delete(base);
        break;
      }

      default:
        obj = func_02045EC0((struct MsgBank *)second, rec->value);
        break;

    }

    tmp1 = (char **) (slot + 0x34);
    BR_UTIL_SetTextFromBuffer(*tmp1, obj, (void *) first, 0x3da0);
    STRBUF_Delete(obj);
  }

  v = BSUBWAY_SCOREDATA_GetBattlePoints((struct Blk1AC *)(*((int *) (q + 0x10))));
  BR_RES_GetSprite(*((int *) (q + 8)), 13, &triple);
  BR_CODEIN_ListCreateActor(p + 8, *((void **) (q + 4)), (const char *) (&triple), v, 0xa0, 0x20, *((u16 *) (p + 0x7c)));
}
