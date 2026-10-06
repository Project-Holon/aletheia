/*
 * function: func_0203A020
 * address:  0x0203A020
 * packet:   pkt_0203A020
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02087C6C  0x02087C6C  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *
 * net_handle.c: claim a connection slot for the message a2 (MAC copy,
 * id bytes, OS_GetMacAddress) when this machine owns the table, else mark
 * the table dirty.
 *
 * The 11-byte residue of docs/notes/pkt_02039CD8.c.txt and
 * pkt_02039D94.c.txt (the in-use `strb` scheduled after the MI_CpuCopy8
 * argument setup, the `1` in r3) was the message parameter's pointee
 * qualifier: `const u8 *a2`.  With a2 const-qualified the store to p[0xd]
 * no longer has to be ordered against the reads of a2 that feed the call.
 * A top-level `u8 * const a2` does nothing.  `volatile` on the owner
 * record stays load-bearing (the zero arm's load order).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203A020.c  *       --func func_0203A020 --addr 0x0203A020 --arm --cc 1.1p1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0203D798(void);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern void func_02087C6C(u8 *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 n);
void func_0203A020(u32 idx, u32 a1, const u8 *a2, u32 a3, u8 *base)
{
  volatile u8 *r4 = func_0203D798();
  u8 *p;
  u8 *own;
  own = (u8 *) func_0203996C(0xff);
  if (own != base)
    goto mismatch;
  p = *((u8 **) ((base + (idx * 4)) + 8));
  if (p[0xd] != 0)
    return;
  p[0xd] = 1;
  MI_CpuCopy8(a2, p + 6, 6);
  p[0xc] = a2[6];
  func_02087C6C(p);
  if (a2[8] == 0)
    goto zero;
  if ((a2[6] != 0) && (a2[7] != r4[0x67]))
  {
    if ((*((u16 *) (r4 + 0x6e))) == a2[8])
    {
      p[0xf] = *((u16 *) (r4 + 0x6e));
      p[0xe] = *((u16 *) (r4 + 0x6e));
      return;
    }
  }
  if (((a2[6] == 0) && (a2[7] == r4[0x67])) && ((*((u16 *) (r4 + 0x6e))) == a2[8]))
  {
    p[0xf] = *((u16 *) (r4 + 0x6e));
    p[0xe] = *((u16 *) (r4 + 0x6e));
  }
  else
  {
    p[0xf] = 0xff;
    p[0xe] = 0;
  }
  return;
  zero:
  {
    u8 hi = r4[0x67];
    u8 lo = a2[7];
    p[0xf] = hi;
    p[0xe] = lo;
  }

  return;
  mismatch:
  base[0x4e] = 1;

}
