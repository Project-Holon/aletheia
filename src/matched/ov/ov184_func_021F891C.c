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
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
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
extern void func_021FB964(u32, u32, u16);
extern void func_021FBE54(char *, u32, u32);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_02082BCC(void *, int, unsigned);
extern void *func_021FC4DC(void *);
extern int func_021FC124(char *, unsigned, void *);
extern int func_021FB378(Config *, u16, int, int, void *, int, int, int, void *, u16);
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
  func_021FB964(*((u32 *) (q + 12)), 23, *((u16 *) (p + 36)));
  func_021FBE54(*tmp1, 6, *((u16 *) (p + 36)));
  v0 = func_021FC20C(*((char **) (q + 12)));
  v1 = func_021FC214(*((char **) (q + 12)));
  func_02082BCC(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  v = func_021FC4DC(*((void **) (q + 8)));
  func_021FC124(*((char **) (q + 12)), 6, resources);
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
    *((int *) ((p + (i * 4)) + 4)) = func_021FB378(&cfg, kind, 96, 1, v, tmp, v0, v1, resources, *((u16 *) (p + 36)));
  }
}
