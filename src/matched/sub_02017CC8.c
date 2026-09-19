/*
 * function: sub_02017CC8
 * address:  0x02017CC8
 * packet:   pkt_02017CC8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * verdict:  EXACT* (match.py: compiled 102, listing extent 104).  The two
 *           trailing bytes at 0x02017D2E are `00 00` padding after the `pop`
 *           and the follower at 0x02017D30 carries no label, so the inferred
 *           extent runs two bytes long.  Never a byte difference; the follower
 *           is reported for the integrator rather than seeded here
 *           (layout/function_starts.txt is not this lane's file).
 *
 * symbols:
 *   func_02017E88  0x02017E88  thumb
 *   func_02019C54  0x02019C54  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AF6C  0x0201AF6C  thumb
 *   func_02017F50  0x02017F50  thumb
 *   func_02017E64  0x02017E64  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32  func_02017E88(void *a0, u32 a1, u32 a2);
extern u32  func_02019C54(void *a0, u16 a1);
extern u32  func_0201AE1C(u32 a0, u32 a1);
extern u32  func_0201AF6C(u32 a0);
extern u32  func_02017F50(void *a0, u16 a1, u32 a2);
extern void func_02017E64(void *a0, u32 a1, u32 a2);

void sub_02017CC8(void *a0, void *a1, void *a2)
{
    u32 v = func_02017E88(a0, 0x6f, 0);
    u32 t = func_0201AE1C(func_02019C54(a1, v), 0x14);
    u32 w = func_0201AE1C(func_02019C54(a2, v), 0x14);

    if (func_0201AF6C(t) == 1 && w != 0xff) {
        return;
    }
    func_02017E64(a0, 0x6e, func_02017F50(a1, v, func_02017E88(a0, 0, 0)));
}
