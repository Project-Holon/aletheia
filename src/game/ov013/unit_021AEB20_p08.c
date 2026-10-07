/*
 * file:     unit_021AEB20_p08.c
 * unit:     yes
 * function: func_021B07F8, func_021B0904
 * address:  0x021B07F8
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   d_021B3CB0     0x021B3CB0  data  ov013  a4
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   func_02082B0C  0x02082B0C  arm
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   d_021B3CBC     0x021B3CBC  data  ov013  a4
 *   func_021B19AC  0x021B19AC  arm  ov013
 *   func_021B190C  0x021B190C  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_021B1A74  0x021B1A74  arm  ov013
 */
#include "../../matched/include/G_Ctx42C0.h"

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

typedef struct Pkt {
    u8 pad0[0x10];
    u8 f10;
    u8 pad11[7];
    u32 f18;
    u8 pad1C[0x45C - 0x1C];
    int f45C;
    u8 pad460[4];
    u64 f464;
    u64 f46C;
    void *f474;
} Pkt;

typedef struct Slot {
    u32 f0;
    u8 pad4[4];
    int f8;
    u8 padC[8];
    int f14;
    u8 pad18[8];
    int f20;
    u8 pad24[4];
    u32 f28;
    u32 f2C;
    u8 pad30[0xC];
    Pkt *f3C;
    u8 pad40[0x18];
    u32 f58;
    u8 pad5C[0x14];
    int f70;
    u8 pad74[0x20];
} Slot;

extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u64 func_020870D0(void);
extern int func_021B19AC(u32 idx);
extern void *func_021B190C(unsigned int i);
extern void func_021B2FE4(Pkt *p);
extern int func_021B1A74(Slot *s, Pkt *p);
int func_021B07F8(const u8 *src, u32 n);
int func_021B0904(void *dst, u32 size, u32 idx, u32 *mask);
extern Ctx3C84 d_021B3C84;
extern Req * const d_021B3CB0[3];
extern struct Ctx42C0 d_021B42C0;
extern Slot d_021B3CBC[3];

#pragma opt_propagation off

/*
 * pass 3 2026-10-06 P3L09: closed. The mode field is read through a const pointer to the shared
 * state (`const Ctx3C84 *ctx = &d_021B3C84; if (ctx->f1C >= 2)`). A const load has no memory
 * dependence on the header magic store, so the scheduler issues moveq before the f1C load
 * (idiom a-load-scheduled-above-an-unrelated-store-reads-through-a-const-pointer). The rest is the
 * G7L4 form: opt_propagation off, `(i < 3) ? 1 : 0` while loop, magic and divisor as named locals.
 */
int func_021B07F8(const u8 *src, u32 n)
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
    if ((0 != d_021B3CB0[i]) && (d_021B3CB0[i]->fC == 2))
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


/*
 * Take one queued packet for slot idx (0x94-byte slots at 0x021B3CBC).
 * Compares the packet's u64 time at +0x46C against the tick count: more
 * than 0x34 ahead falls back to the slot's held packet at +0x3C, more
 * than 0x8B4C behind is released and the loop retries; otherwise it
 * counts sequence gaps (+0x14), updates +0x28/+0x2C/+0 from the tick
 * difference to +0x464, copies +0x474 to dst and sets bit (+0x10) in
 * *mask.
 * func_021B1A74 is void in its own file, but this caller loops on the
 * r0 it leaves behind (mov r4, r0 after each call), so it is declared
 * int here.
 */
int func_021B0904(void *dst, u32 size, u32 idx, u32 *mask)
{
    int n;
    Pkt *pkt;
    Slot *slot;
    int first;
    u64 now;
    u32 d;
    u32 diff;

    slot = &d_021B3CBC[idx];
    first = 1;
    n = func_021B19AC(idx);
    while (n != 0) {
        now = func_020870D0();
        pkt = func_021B190C(idx);
        if (pkt != 0) {
            if (pkt->f46C > now + 0x34) {
                if (pkt->f45C == 0 && slot->f3C != 0) {
                    slot->f20++;
                    func_02082B0C(slot->f3C->f474, dst, size);
                    func_021B2FE4(slot->f3C);
                    slot->f3C = 0;
                    if (mask != 0) {
                        *mask |= 1 << pkt->f10;
                    }
                    return 1;
                }
                return 0;
            }
            if (now > pkt->f46C + 0x8B4C) {
                slot->f58 = pkt->f18;
                n = func_021B1A74(slot, pkt);
                func_021B190C(idx);
                first = 0;
                continue;
            }
            if (slot->f58 + 1 != pkt->f18 && slot->f58 != 0 && slot->f58 <= pkt->f18) {
                if (pkt->f45C == 0) {
                    slot->f14++;
                }
            }
            slot->f58 = pkt->f18;
            if (first != 0 && slot->f70 != 0) {
                n = func_021B1A74(slot, pkt);
                func_021B190C(idx);
                slot->f70--;
                continue;
            }
            d = (u32)(now - pkt->f464);
            diff = d - slot->f28;
            slot->f28 = d;
            slot->f2C = slot->f28 + ((diff - slot->f28) >> 4);
            slot->f0 = slot->f2C;
            func_02082B0C(pkt->f474, dst, size);
            func_021B1A74(slot, pkt);
            if (mask != 0) {
                *mask |= 1 << pkt->f10;
            }
            return 1;
        } else {
            slot->f8 = n;
            return 0;
        }
    }
    if (slot->f3C != 0) {
        func_021B2FE4(slot->f3C);
        slot->f3C = 0;
    }
    return 0;
}
