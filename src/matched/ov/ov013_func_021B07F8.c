/*
 * function: VCT_SESSION_QueueFrame
 * address: 0x021B07F8
 * packet: pkt_ov013_021B07F8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * pass 3 2026-10-06 P3L09: closed. The mode field is read through a const pointer to the shared
 * state (`const Ctx3C84 *ctx = &d_021B3C84; if (ctx->f1C >= 2)`). A const load has no memory
 * dependence on the header magic store, so the scheduler issues moveq before the f1C load
 * (idiom a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer). The rest is the
 * G7L4 form: opt_propagation off, `(i < 3) ? 1 : 0` while loop, magic and divisor as named locals.
 * symbols:
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   gVctMembers     0x021B3CB0  data  ov013  a4
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   func_02082B0C  0x02082B0C  arm
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm

 */

#include "../include/G_Ctx42C0.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct
{
  u16 f0;
  u8 pad2[0x1A];
  int f1C;
  int f20;
  u32 f24;
} Ctx3C84;
typedef struct
{
  u8 pad0[0x8c0];
  int f8C0;
  u32 f8C4;
  u32 f8C8;
  u32 f8CC;
  int f8D0;
  int f8D4;
} Ctx42C0;
typedef struct
{
  u8 pad0[0xC];
  int fC;
} Req;
typedef struct
{
  u32 magic;
  u8 f4;
  u8 pad5;
  u16 f6;
  u32 f8;
} PacketHeader;
extern Ctx3C84 d_021B3C84;
extern Req * const gVctMembers[3];
extern struct Ctx42C0 d_021B42C0;
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u64 func_020870D0(void);
#pragma opt_propagation off
int VCT_SESSION_QueueFrame(const u8 *src, u32 n)
{
  PacketHeader *hdr;
  u32 i;
  u8 divisor;
  u32 off;
  u8 found;
  u16 seq;
  u32 magic;
  const Ctx3C84 *ctx;
  found = 0;
  if (n != d_021B3C84.f24)
  {
    return 0;
  }
  if (d_021B3C84.f20 == 0)
  {
    return 0;
  }
  i = 0;
  while ((i < 3) ? (1) : (0))
  {
    if ((0 != gVctMembers[i]) && (gVctMembers[i]->fC == 2))
    {
      found = 1;
      break;
    }
    i++;
  }
  if (found == 0)
  {
    return 0;
  }
  off = (d_021B42C0.f8C4 & 1) ? 0 : 0x460;
  hdr = (PacketHeader *) ((u8 *) &d_021B42C0 + off);
  magic = 0x5F564354;
  hdr->magic = magic;
  ctx = &d_021B3C84;
  if (ctx->f1C >= 2)
  {
    func_02082B0C(src, ((u8 *) hdr) + 0x10, n);
  }
  else
  {
    func_02082B0C(src, ((u8 *) hdr) + 0xC, n);
  }
  divisor = 0x40;
  hdr->f4 = divisor;
  seq = d_021B3C84.f0;
  d_021B3C84.f0 = d_021B3C84.f0 + 1;
  hdr->f6 = seq;
  hdr->f8 = (u32) (func_020870D0() / (u32)divisor);
  d_021B42C0.f8C4++;
  return 1;
}
#pragma opt_propagation reset
