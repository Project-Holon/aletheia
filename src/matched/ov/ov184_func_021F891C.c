/*
 * function: func_021F891C
 * address: 0x021F891C
 * packet: pkt_ov184_021F891C
 * region: ov184
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021F89CE..021F89D0 is two zero alignment bytes before matched021F89D0.
 * lever: first types search extracted full-word temporaries and took kind's address;
 * its volatile parameter was removed, and the clean spelling independently matched.
 * symbols:
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_RES_LoadSprite 0x021FBE54 thumb ov186
 *   BR_RES_GetFont 0x021FC20C thumb ov186
 *   BR_RES_GetMsgData 0x021FC214 thumb ov186
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_GRAPHIC_GetActorUnit 0x021FC4DC thumb ov186
 *   BR_RES_GetSprite 0x021FC124 thumb ov186
 *   BR_BTN_CreateFromMessage 0x021FB378 thumb ov186
 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct
{
  u16 x;
  u16 y;
  u16 index;
  unsigned char flag;
  unsigned char pad;
} Config;
typedef unsigned char  u8;
extern void BR_RES_LoadBgGraphics(void *ctx, unsigned kind, unsigned short heap);
extern void BR_RES_LoadSprite(char *, u32, u32);
extern unsigned BR_RES_GetFont(char *p);
extern int BR_RES_GetMsgData(char *);
extern void MI_CpuFill8(void *, int, unsigned);
extern u32 BR_GRAPHIC_GetActorUnit(u8 *p);
extern int BR_RES_GetSprite(char *, unsigned, void *);
extern int BR_BTN_CreateFromMessage(Config *, u16, int, int, void *, int, int, int, void *, u16);
void func_021F891C(char *p, const char *q)
{
  Config cfg;
  int resources[3];
  void *v;
  int v0;
  int v1;
  int i;
  int kind;
  int tmp;
  char **tmp1;
  (void) (&kind);
  if (*((int *) (p + 4)))
    return;
  tmp1 = (char **) (q + 12);
  BR_RES_LoadBgGraphics((void *)(*((u32 *) (q + 12))), 23, *((u16 *) (p + 36)));
  BR_RES_LoadSprite(*tmp1, 6, *((u16 *) (p + 36)));
  v0 = BR_RES_GetFont(*((char **) (q + 12)));
  v1 = BR_RES_GetMsgData(*((char **) (q + 12)));
  MI_CpuFill8(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  v = (void *)BR_GRAPHIC_GetActorUnit(*((void **) (q + 8)));
  BR_RES_GetSprite(*((char **) (q + 12)), 6, resources);
  for (i = 0; i < 2; i++)
  {
    if (i == 0)
    {
      kind = 4;
      cfg.x = 32;
      cfg.index = 0;
    }
    else
    {
      kind = 43;
      cfg.x = 128;
      cfg.index = 4;
    }
    tmp = *((int *) (p + 28));
    *((int *) ((p + (i * 4)) + 4)) = BR_BTN_CreateFromMessage(&cfg, kind, 96, 1, v, tmp, v0, v1, resources, *((u16 *) (p + 36)));
  }
}
