/*
 * file:     unit_021F8480_p02.c
 * unit:     yes
 * function: func_021F88A4, func_021F88E0, func_021F891C
 * address:  0x021F88A4
 * region:   ov184
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021FEEC0  0x021FEEC0  thumb  ov186
 *   func_021FBDA4  0x021FBDA4  thumb  ov186
 *   func_021FC1F8  0x021FC1F8  thumb  ov186
 *   func_021FC610  0x021FC610  thumb  ov186
 *   func_021F3AF0  0x021F3AF0  thumb  ov112
 *   func_021F3BF0  0x021F3BF0  thumb  ov112
 *   func_021FC640  0x021FC640  thumb  ov186
 *   func_021FC148  0x021FC148  thumb  ov186
 *   func_021FB964  0x021FB964  thumb  ov186
 *   func_021FBE54 0x021FBE54 thumb ov186
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_02082BCC 0x02082BCC arm
 *   func_021FC4DC 0x021FC4DC thumb ov186
 *   func_021FC124 0x021FC124 thumb ov186
 *   func_021FB378 0x021FB378 thumb ov186
 */
#include "../../matched/include/Obj06618.h"
#include "../../matched/include/Obj08319.h"
#include "../../matched/include/Obj02233.h"
#include "../../matched/include/Obj04581.h"

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned char  u8;

typedef struct
{
  u16 x;
  u16 y;
  u16 index;
  unsigned char flag;
  unsigned char pad;
} Config;

extern void func_021FEEC0(char *p, int mode, u32 value);
extern void func_021FBDA4(int a, unsigned mode);
extern void func_021FC1F8(int *p, int i);
extern void func_021FC610(u32 a, u16 b);
extern u8 *func_021F3AF0(u8 *src, u16 heap);
extern void func_021F3BF0(u8 *p);
extern void func_021FC640(u32 a, u16 b);
extern void func_021FC148(char *p, unsigned i, unsigned heap);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
extern void func_021FBE54(char *, u32, u32);
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_02082BCC(void *, int, unsigned);
extern u32 func_021FC4DC(u8 *p);
extern int func_021FC124(char *, unsigned, void *);
extern int func_021FB378(Config *, u16, int, int, void *, int, int, int, void *, u16);
void func_021F88A4(char *p, char *q);
void func_021F88E0(char *p, char *q);
void func_021F891C(char *p, const char *q);


void func_021F88A4(char *p, char *q)
{
    if (((struct Obj06618 *)p)->f0 != 0)
        return;
    func_021FEEC0((char *)(((struct Obj08319 *)q)->f4), 0, 0);
    func_021FBDA4(((struct Obj08319 *)q)->fC, 0);
    func_021FC1F8((int *)(((struct Obj08319 *)q)->fC), 0);
    func_021FC610(((struct Obj08319 *)q)->f8, ((struct Obj06618 *)p)->f24);
    ((struct Obj06618 *)p)->f0 = (unsigned int)func_021F3AF0((u8 *)(((struct Obj06618 *)p)->f28), ((struct Obj06618 *)p)->f24);
}


void func_021F88E0(char *p, char *q)
{
    if (*(u32 *)&((struct Obj02233 *)p)->f0 == 0)
        return;
    func_021F3BF0(((struct Obj02233 *)p)->f0);
    *(u32 *)&((struct Obj02233 *)p)->f0 = 0;
    func_021FC640(((struct Obj04581 *)q)->f8, ((struct Obj02233 *)p)->f24);
    func_021FC148((char *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    func_021FB964((void *)(*(u32 *)&((struct Obj04581 *)q)->fC), 0, ((struct Obj02233 *)p)->f24);
    func_021FEEC0((char *)(((struct Obj04581 *)q)->f4), 0, 1);
}

/*
 * tail: 021F89CE..021F89D0 is two zero alignment bytes before matched021F89D0.
 * lever: first types search extracted full-word temporaries and took kind's address;
 * its volatile parameter was removed, and the clean spelling independently matched.
 */
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
  func_021FB964((void *)(*((u32 *) (q + 12))), 23, *((u16 *) (p + 36)));
  func_021FBE54(*tmp1, 6, *((u16 *) (p + 36)));
  v0 = func_021FC20C(*((char **) (q + 12)));
  v1 = func_021FC214(*((char **) (q + 12)));
  func_02082BCC(&cfg, 0, 8);
  cfg.y = 168;
  cfg.flag = 1;
  v = (void *)func_021FC4DC(*((void **) (q + 8)));
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
