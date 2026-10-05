/*
 * function: func_021B07F8
 * address: 0x021B07F8
 * packet: pkt_ov013_021B07F8
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: DIFF
 * residual: DIFF 8/268 bytes, one pair swapped (see final push note); all six relocations resolved.
 * evidence: separate byte divisor improves 40 to 37; unsigned promotion in u64 division removes sign-word ASR and improves to 34. Inline search gave 264/217; self-copy flag tied 40. Separate address locals and unsigned-long divisor tied 34; frame-selector inline gave 39.
 * checks: 1 own EXACT memcpy and tick bodies/shards read, arities 3/0, observed unsigned n and u64 return retained; 2 fresh 0904 shares globals and callees but is not a builder twin; 3 _Bool found on unsigned-divisor best tied 34; 4 byte-signedness, flag identity and inline-allocation idioms read; 5 full idiom directory and fresh ov013 neighbours reread, no addressed stack aggregate; next hypothesis an independently evidenced frame-offset enum, no repeat scheduling sweep.
 * recoup 2026-10-05: DIFF 34 bytes, colours only (front through +0x70 and all pool words match). Original: base pool word in r4, offset r5 (found's register), hdr = r5, divisor r4; ours: base in ip, offset and hdr in r4, divisor r5. Callee types checked: func_020870D0 returns u64 (OS_GetTick, matched arm9 user), func_02082B0C is MIi_CpuCopyFast(src, dst, n), no void-return problem. Tried: named base local (CSEs with the field address, 264 B, base r4 but offset r5/hdr r4, 132 B off); named off local with inline address (same 34 B); u32 scratch reused for base and divisor (138); one scratch for found and offset (139); packet array struct buf[2] (mul by 0x460, 140); u8 array extern with raw offsets (48); u8 divisor constant (folds to shifts, 197); all six per-function pragmas (lifetimes, common_subs, scheduling, peephole tie 34; propagation 245, dead_assignments 214). Open: why base takes r4 while staying a separate (non-CSE) pool load.
 * final push 2026-10-05 G7L4: 34 to 8 bytes. All colours now match. Cause of the colour swap: the
 * original keeps the `(i < 3) ? 1 : 0` while loop (entry branch) and the packet header work under
 * opt_propagation off, with the divisor as a named local set before its store (divisor = 0x40;
 * hdr->f4 = divisor). Residue: the scheduler puts the f1C load between movne and moveq, the original
 * after moveq. Tried for it: mode read before the magic store (needed to hoist the load above the
 * store; without it the load stays below the store, 23 bytes), magic as a local (needed, else 26),
 * positions of mode, magic, hdr (8 to 28), if/else for off (8), int off (8), scheduling off (8),
 * peephole off (8), block-scoped locals (8), named tag pointer (8), mode > 1 (10), negated ternary (11),
 * ternary call argument (114+), const f1C or a const second extern name (23, 27).
 * pass 2 2026-10-06 P2L17: no change, 8/268. 45 compiles, 3 rounds. Magic assigned before the ternary splits
 * the ternary into its own blocks (f1C load then follows moveq) but the join schedules add hdr before str (16).
 * No change (8): % 2, != 0, &base[off], inline helper for off or hdr, (mode >= 2) ? 1 : 0, do-while(0) or goto
 * label after the store. Worse: u16 off (41 rows), pointer select (38), single call through dst (35), const view
 * of the global after the store (23), inline copy helper (36 rows). 1.1p1 fills between movne/moveq elsewhere
 * (ov016 021D0F7C); the original pattern is unique. Fits a block boundary between the store and the cmp;
 * no human form found for it. Compiler pins 1.2/2.0 are far worse (235, 117).
 * permuter: first recorded budget-300 search and emitted 40-byte candidate consumed in prior pass; not repeated.
 * prior evidence: named guard and while loop improved 45 to 40; enum counter 48, u16 counter 276 bytes; const byte source and unsigned-long counter tested.
 * symbols:
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   d_021B3CB0     0x021B3CB0  data  ov013  a4
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   func_02082B0C  0x02082B0C  arm
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm

 */
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
extern Req * const d_021B3CB0[3];
extern Ctx42C0 d_021B42C0;
extern void func_02082B0C(const void *src, void *dst, u32 n);
extern u64 func_020870D0(void);
#pragma opt_propagation off
int func_021B07F8(const u8 *src, u32 n)
{
  PacketHeader *hdr;
  u32 i;
  u8 divisor;
  u32 off;
  u8 found;
  u16 seq;
  int mode;
  u32 magic;
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
  mode = d_021B3C84.f1C;
  hdr->magic = magic;
  if (mode >= 2)
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
