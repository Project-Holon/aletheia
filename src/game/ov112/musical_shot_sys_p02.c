/*
 * file:     musical_shot_sys_p02.c
 * unit:     yes
 * function: func_021F3BF0, func_021F3C50, func_021F3CA4, func_021F3EAC, func_021F3ED0, func_021F3F00
 * address:  0x021F3BF0
 * region:   ov112
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021F6C7C 0x021F6C7C thumb ov112
 *   func_021F6F4C 0x021F6F4C thumb ov112
 *   func_021F7120 0x021F7120 thumb ov112
 *   func_021F51B0 0x021F51B0 thumb ov112
 *   func_021F4948 0x021F4948 thumb ov112
 *   func_020452E8 0x020452E8 arm
 *   func_020307B0 0x020307B0 arm
 *   func_021F7160 0x021F7160 thumb ov112
 *   func_021F51E8 0x021F51E8 thumb ov112
 *   func_021F6CB0 0x021F6CB0 thumb ov112
 *   func_021F6E74 0x021F6E74 thumb ov112
 *   func_021F75A0 0x021F75A0 thumb ov112
 *   func_021F51F4 0x021F51F4 thumb ov112
 *   func_021F718C 0x021F718C thumb ov112
 *   func_021F6F8C 0x021F6F8C thumb ov112
 *   func_021F4280 0x021F4280 thumb ov112
 *   func_02047964 0x02047964 arm
 *   func_020479D8 0x020479D8 arm
 *   func_0204F7DC 0x0204F7DC arm
 *   func_02047970 0x02047970 arm
 *   func_02046440  0x02046440  arm
 *   func_0204044C  0x0204044C  arm
 *   func_02046BE0  0x02046BE0  arm
 *   func_02048A24  0x02048A24  arm
 *   func_02048AD0  0x02048AD0  arm
 *   func_0207DCF8  0x0207DCF8  arm
 *   func_0204EBD4  0x0204EBD4  arm
 *   func_0204ED70  0x0204ED70  arm
 *   func_02040618  0x02040618  arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02049238  0x02049238  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021F81AC  0x021F81AC  data  a4
 *   d_021F81B8  0x021F81B8  data  ov112  a4
 *   d_021F81A0  0x021F81A0  data  ov112  a4
 *   d_021F81C4  0x021F81C4  data  a4
 *   d_021F8274  0x021F8274  data  a4
 *   d_021F8258  0x021F8258  data  ov112  a4
 *   d_021F8214  0x021F8214  data  a4
 *   d_021F81D4  0x021F81D4  data  ov112  a4
 *   d_021F81F4  0x021F81F4  data  ov112  a4
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_02040588 0x02040588 arm
 *   func_020414AC 0x020414AC arm
 *   func_020403F4 0x020403F4 arm
 *   func_0204ED24 0x0204ED24 arm
 *   func_02048AC4 0x02048AC4 arm
 *   func_02046788 0x02046788 arm
 *   func_021F5164 0x021F5164 thumb ov112
 *   func_021F5438 0x021F5438 thumb ov112
 *   func_021F48C0 0x021F48C0 thumb ov112
 *   func_021F709C 0x021F709C thumb ov112
 *   func_021F760C 0x021F760C thumb ov112
 *   func_021F80B0 0x021F80B0 thumb ov112
 *   func_021F8154 0x021F8154 thumb ov112
 *   func_021F6BD8 0x021F6BD8 thumb ov112
 *   func_021F40D0 0x021F40D0 thumb ov112
 *   func_021F8054 0x021F8054 thumb ov112
 *   func_021F8084 0x021F8084 thumb ov112
 *   func_021F6E78 0x021F6E78 thumb ov112
 *   func_021F6EF4 0x021F6EF4 thumb ov112
 *   d_021F8240 0x021F8240 data a4
 *   d_021F8234 0x021F8234 data a4
 *   d_021F824C 0x021F824C data a4
 */
#include "../../matched/include/Obj03246.h"
#include "../../matched/include/Obj02823.h"
#include "../../matched/include/Obj13824.h"

struct Descriptor;
struct Board;
struct Camera;
struct Lights;
struct Blk3;
struct Light;
struct BgTemplate;
struct Object;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { u32 w[7]; } T28;

typedef struct { u32 w[3]; } T12;

typedef struct 
{
  int x;
  int y;
  int z;
} Vec;

typedef struct 
{
  u32 low : 5;
  u32 flags : 4;
  u32 high : 23;
} Flags;

typedef struct 
{
  u16 heap;
  u16 pad;
  Flags *cfg;
  u8 *objects[4];
  void *unused;
  void *owner;
  void *scene;
  void *actors;
  void *unused28;
  void *render;
  void *models[4];
  void *effect;
  void *effects[4];
} Context;

extern void func_021F6C7C(char *p);
extern void func_021F6F4C(u8 *p);
extern void func_021F7120(char *p);
extern void func_021F51B0(int a);
extern void func_021F4948(u8 *);
extern u32 func_020452E8(struct Descriptor *d);
extern u32 func_0201D83C(void *ptr);
extern u32 func_020307B0(void *p);
extern void func_021F7160(u8 *p);
extern void func_021F51E8(u8 *);
extern void func_021F6CB0(char *p);
extern void func_021F6E74(u32);
extern void func_021F75A0(u8 *p);
extern void func_021F51F4(void **p);
extern void func_021F718C(char *p);
extern void func_021F6F8C(u8 *p);
extern void func_021F4280(u8 *);
extern void func_02047964(void);
extern void func_020479D8(void);
extern void func_0204F7DC(struct Board *b, struct Camera *cam, struct Lights *lights);
extern void func_02047970(void);
extern void func_02046440(int, int, int, int, int, int, int);
extern void func_0204044C(u32 mode);
extern void func_02046BE0(u32 a, u32 b);
extern void *func_02048A24(int, int, int, int, int, int, int, int, const void *, const void *, const void *, int);
extern void func_02048AD0(struct Light *l);
extern void func_0207DCF8(const void *a);
extern void *func_0204EBD4(u8 *src, void *heap);
extern void func_0204ED70(u8 *dst, struct Blk3 *src);
extern void func_02040618(u32, u32, u32);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020409B4(u32 index);
extern void func_02049238(void *h);
extern void func_0207D63C(u32, u32, u32, u32, u32);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_020414AC(u32);
extern void func_020403F4(u32);
extern void func_0204ED24(void *);
extern u32 func_02048AC4(void *ptr);
extern void func_02046788(void);
extern void *func_021F5164(u32);
extern struct Object *func_021F48C0(u32 owner, int count, u16 heap);
extern u8 *func_021F709C(u16 heap, u32 b, u32 c, u32 d, u32 e);
extern void *func_021F760C(u8 *, u8 *);
extern void func_021F5438(void **p, int b);
extern void func_021F80B0(int, int);
extern int func_021F8154(int, int *, int);
extern void *func_021F6BD8(u16, void *);
extern u8 *func_021F6E78(u8 *p, int v);
extern u32 func_021F40D0(void *p, u32 i, u16 c);
extern void func_021F8054(void *unused, u32 *p, const u32 *q);
extern void func_021F8084(void *unused, u32 *p, const u32 *q);
extern void func_021F6EF4(void *unused, u32 *p, const u32 *q);
void func_021F3BF0(u8 *p);
void func_021F3C50(u8 *p);
void func_021F3CA4(char *p);
void func_021F3EAC(const void *a,u32 b,u32 c);
void func_021F3ED0(u8 *p);
void func_021F3F00(Context *p);
extern const char d_021F81AC[];
extern const char d_021F81B8[];
extern const char d_021F81A0[];
extern const char d_021F81C4[];
extern const T28 d_021F8274;
extern const T12 d_021F8258;
extern const char d_021F8214[];
extern const char d_021F81D4[];
extern const char d_021F81F4[];
extern const Vec d_021F8240;
extern const Vec d_021F8234;
extern const Vec d_021F824C;

void func_021F3BF0(u8 *p)
{
    u8 i;
    func_021F6C7C((char *)(((struct Obj03246 *)p)->f40));
    func_021F6F4C((u8 *)(((struct Obj03246 *)p)->f28));
    func_021F7120(((struct Obj03246 *)p)->f2C);
    func_021F51B0(((struct Obj03246 *)p)->f20);
    func_021F4948(*(u8 * *)&((struct Obj03246 *)p)->f24);
    func_020452E8(((struct Obj03246 *)p)->f58);
    func_020452E8(((struct Obj03246 *)p)->f54);
    func_0201D83C(((struct Obj03246 *)p)->f60);
    func_0201D83C(((struct Obj03246 *)p)->f5C);
    func_021F3ED0(p);
    for(i=0;i<4;i++) func_020307B0(*(void **)(p+i*4+8));
    func_020307B0(p);
}

/*
 * extent: two-byte padding at 0x021F3CA2.
 */
void func_021F3C50(u8 *p)
{
    func_021F7160((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51E8(*(u8 * *)&((struct Obj02823 *)p)->f20);
    func_021F6CB0((char *)(((struct Obj02823 *)p)->f40));
    func_02047964();
    func_020479D8();
    func_021F6E74(((struct Obj02823 *)p)->f40);
    func_021F75A0((u8 *)(((struct Obj02823 *)p)->f2C));
    func_021F51F4((void **)(*(u32 *)&((struct Obj02823 *)p)->f20));
    func_021F718C((char *)(((struct Obj02823 *)p)->f2C));
    func_021F6F8C((u8 *)(((struct Obj02823 *)p)->f28));
    func_0204F7DC((struct Board *)(((struct Obj02823 *)p)->f1C),(struct Camera *)(((struct Obj02823 *)p)->f18),0);
    func_021F4280(p);
    func_02047970();
}


static inline void G2_SetWndOBJInsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~0x3F00u) | ((u32)wnd << 8);
    if (effect) tmp |= 0x2000;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}

static inline void G2_SetWndOutsidePlane(int wnd, int effect)
{
    u32 tmp;
    tmp = (*(volatile u16 *)0x0400004A & ~63u) | (u32)wnd;
    if (effect) tmp |= 32;
    *(volatile u16 *)0x0400004A = (u16)tmp;
}


/*
 * 2026-10-05 (user decision): the u32 return in the func_02049BDC declaration (void definition) is accepted as a real mismatched declaration.
 * note (2026-10-05, wave D9r lane 70): closed from 422 differing bytes. The residue (3 and 1 held
 *   in r7/r4 in the head, late r3 zeros copied from r6) came from the return type of
 *   func_02049BDC: declared u32 instead of void, the head constant webs and the fresh late zeros
 *   come out as in the original. func_02049658 is u32 as in the matched ov123 021D9D3C and
 *   ov210 021BC5DC callers (its helper 0x0204968C returns r4). Caveat for review: the matched
 *   arm9 definition of func_02049BDC is void, and its helper 0x02049C28 sets no return value on
 *   its last path, so u32 is the game header's declaration, not a computed result. Constants
 *   are plain literals (0xC000, 0x10000, 0x1000). The four contested data hints (d_021F81AC,
 *   d_021F81C4, d_021F8274, d_021F8214) resolve without the overlay token.
 * note 2026-10-05 (integrator): parked in pending although it verifies EXACT. It closes only with
 * func_02049BDC declared u32; its matched arm9 definition is void and every matched caller declares
 * it void. Waiting for the user to accept or reject that declaration.
 */
void func_021F3CA4(char *p)
{
    void *h;
    void *cam;
    T28 a;
    T12 b;
    T12 *pb;

    func_02046440(0, 2, 0, 4, 0, *(u16 *)p, 0);
    func_0204044C(3);
    func_02046BE0(0, 1);
    cam = func_02048A24(2, 0xC000, 0, 0, 0x10000, 0x1000, 0x3E8000, 0,
                        d_021F81AC, d_021F81B8, d_021F81A0, *(u16 *)p);
    *(void **)(p + 0x18) = cam;
    func_02048AD0(cam);
    func_0207DCF8(d_021F81C4);
    *(volatile u16 *)0x04000060 = *(volatile u16 *)0x04000060 & 0xCFDF;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 0x10;
    *(volatile u16 *)0x04000060 = (*(volatile u16 *)0x04000060 & ~0x3000) | 8;
    func_02046BE0(0, 0);
    a = d_021F8274;
    b = d_021F8258;
    pb = &b;
    h = func_0204EBD4((u8 *)(&a), (void *)(*(u16 *)p));
    *(void **)(p + 0x1C) = h;
    func_0204ED70(h, (struct Blk3 *)pb);
    func_021F3EAC(d_021F8214, 1, 0);
    func_021F3EAC(d_021F81D4, 2, 0);
    func_021F3EAC(d_021F81F4, 3, 0);
    func_02040618(2, 3, 0xE0);
    h = func_020490F4(0x2F, *(u16 *)p);
    func_02049BDC(h, 3, 0, 0, 0, 0x20, *(u16 *)p);
    func_02049658(h, 9, 2, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xF, 2, 0, 0, 0, *(u16 *)p);
    func_02049BDC(h, 2, 0, 0x20, 0x20, 0x20, *(u16 *)p);
    func_02049658(h, 8, 3, 0, 0, 0, *(u16 *)p);
    func_020498F4(h, 0xE, 3, 0, 0, 0, *(u16 *)p);
    func_020409B4(2);
    func_020409B4(3);
    func_02049238(h);
    func_0207D63C(0x04000050, 8, 1, 0, 0xA);
    *(volatile u32 *)0x04000000 = (*(volatile u32 *)0x04000000 & 0xFFFF1FFF) | 0x8000;
    G2_SetWndOBJInsidePlane(0x17, 1);
    G2_SetWndOutsidePlane(0x1F, 1);
}

void func_021F3EAC(const void *a,u32 b,u32 c) { func_0203FCA0(b,a,c); func_02040588(b,1); func_020414AC(b); func_020409B4(b); }

void func_021F3ED0(u8 *p) { func_020403F4(3); func_020403F4(1); func_020403F4(2); func_0204ED24(((struct Obj13824 *)p)->f1C); func_02048AC4(((struct Obj13824 *)p)->f18); func_02046788(); func_020403F4(0); }

/*
 * checks: retry rederived all callees; prior permuter 300 retained. Original table pool is 8240,8234,824C; declaration order restores it and all three resolve.
 * match: u32 offset and integer row address retain the spilled row and live index; vectors follow frame order; second loop reuses the earlier j as mask and mask as index; final mask advances before i.
 * ABI: 760C leaves a live result used by this caller despite its own void declaration.
 */
void func_021F3F00(Context *p)
{
  u32 offset;
  Vec pos = d_021F8240;
  Vec scale = d_021F8234;
  int z[4];
  Vec temp;
  Vec base;
  u8 i;
  u8 mask;
  u8 j;
  int flags;
  int current;
  void *q;
  u8 *row;
  int tmp1;
  void *tmp;
  current = 5 << 16;
  p->scene = func_021F5164(p->heap);
  func_021F5438(p->scene, 2 << 16);
  p->actors = func_021F48C0((u32) p->owner, 36, p->heap);
  p->render = func_021F709C(p->heap, 0, (u32)p->scene, (u32)p->actors, (u32)p->owner);
  for (i = 0; i < 4; i++)
    p->models[i] = 0;

  for (j = 0; j < 4; j++)
  {
    row = ((u8 *) p) + (4 * j);
    q = func_021F760C(p->render, *((u8 **) (row + 8)));
    if (1)
    {
      *((void **) (row + 0x30)) = q;
      func_021F80B0((int)p->render, (int)q);
      func_021F8154((int) p->render, *((int **) (row + 0x30)), 1);
    }
  }

  flags = p->cfg->flags;
  for (i = 0, mask = 1; i < 4; i++, mask <<= 1)
  {
    if (!(flags & mask))
    {
      z[i] = current;
      current += 30 << 12;
    }
  }

  for (j = 1, mask = 0; mask < 4; j <<= 1, mask++)
  {
    if (flags & j)
    {
      z[mask] = current;
      current += 30 << 12;
    }
  }

  i = 0;
  mask = 1;
  tmp = func_021F6BD8(p->heap, 0);
  p->effect = tmp;
  base = d_021F824C;
  for (; i < 4; mask <<= 1, i++)
  {
    offset = 4 * i;
    row = (u8 *)(((u32)p) + offset);
    scale.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (row + 8))) + 8)));
    if (p->cfg->flags & mask)
    {
      u8 *actor;
      temp = base;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      func_021F8084(p->render, *((void **) (actor + 0x30)), (const u32 *)(&temp));
      scale.y = 22 << 14;
    }
    else
    {
      u8 *actor;
      actor = ((u8 *) p) + offset;
      pos.x = func_021F40D0(p, i, *((u16 *) ((*((u8 **) (actor + 8))) + 8)));
      pos.y = 155 << 12;
      pos.z = *((int *) (((u32) z) + offset));
      func_021F8054(p->render, *((void **) (actor + 0x30)), (const u32 *)(&pos));
      tmp1 = 2 << 18;
      scale.y = tmp1;
    }
    *((void **) (row + 0x44)) = func_021F6E78(p->effect, 1);
    func_021F6EF4(p->effect, *((void **) (row + 0x44)), (const u32 *)(&scale));
  }

}
