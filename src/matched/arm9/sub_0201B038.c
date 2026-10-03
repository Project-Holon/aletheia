/*
 * function: sub_0201B038
 * address:  0x0201B038
 * packet:   pkt_0201B038
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * note:     EXACT* only for the two bytes of alignment padding at
 *           0x0201B0FE.  The rare random event that seeds party record
 *           field 0x97 (see docs/notes/sub_0201B038.c.txt for the draws and
 *           the version-sensitive constants 0x4000/0x8000/0xC000, 7, 0xF3,
 *           content values rather than addresses).  Closed in wave 16: the
 *           packed byte is built as `w = v; w |= (u8)(v << 4);` (the copy is
 *           the image's `adds r3, r0, #0` before the orrs), and the last two
 *           truncations are written inside the call argument, which lets the
 *           final lsls/lsrs pair straddle the argument set-up.
 * symbols:
 *   _ull_mul       0x0209C054  arm
 *   sub_0201AA18   0x0201AA18  thumb
 *   sub_0201AB28   0x0201AB28  thumb
 *   sub_0201B220   0x0201B220  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0203F0A8  0x0203F0A8  arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;
typedef unsigned long long u64;
extern u32   func_02017E1C(void *mon, u32 id, u32 v);
extern void  func_02017E40(void *mon, u32 id, u32 v);
extern u32 sub_0201AA18(void *p);
extern void *sub_0201AB28(void *p, u32 idx);
extern u32   sub_0201B220(void *party);
extern u32   func_0203F0A8(void);
void sub_0201B038(void *party)
{
    u32 mask;
    u32 r;
    u32 slot;
    void *mon;
    u32 v;
    u32 w;
    u32 n;

    n = sub_0201AA18(party);
    r = (u16)((u64)func_0203F0A8() * 0x10000 >> 32);
    mask = sub_0201B220(party);
    if (r == 0x4000 || r == 0x8000 || r == 0xC000) {
        do {
            slot = func_0203F0A8();
            if (n != 0) {
                slot = (u32)(((u64)slot * n) >> 32);
            }
            mon = sub_0201AB28(party, slot);
        } while (func_02017E1C(mon, 5, 0) == 0
                 || func_02017E1C(mon, 0x4C, 0) != 0);
        if ((mask & (1 << slot)) != 0) {
            return;
        }
        do {
            v = (u8)((u64)func_0203F0A8() * 0x100 >> 32);
        } while ((v & 7) == 0);
        if ((v & 0xF0) != 0) {
            v = v & 7;
        }
        w = v; w |= (u8)(v << 4);
        func_02017E40(mon, 0x97, (u8)((u8)(w & 0xF3) + 1));
    }
}
