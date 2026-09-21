/*
 * unit:     no
 * function: func_0202D760
 * address:  0x0202D760
 * packet:   pkt_0202D6F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Builds a sprite/resource request: func_0202D064 turns the mon
 * descriptor (species/form/gender plus the three stack words) into a
 * resource id, which func_02049E34 instantiates with the caller's
 * out-slot `a0` as its a3 payload.  When the species word a1 is the
 * sentinel 0x147 the freshly filled *a0 is additionally run through the
 * func_0202D214 / func_0202D3D0 / func_0202D2EC triple, which is why
 * `*a0` is re-read before each of them (func_0202D3D0 may store through
 * it, so the load cannot be cached).  This answers the open question in
 * docs/notes/func_0202D81C.c.txt: a0 is a genuine out-parameter, written
 * by func_02049E34 via its a3, not read-only.
 *
 * Blocked at MATCH: every concrete byte is identical; the THM_CALL sites
 * for func_0202D3D0 (+0x50) and func_0202D2EC (+0x58) stay wildcarded
 * because neither address has any witness outside 0202D760..0202D7C8 --
 * this function is their only caller image-wide, so no evidence class
 * (label/matched) can attest them.  Filing either of those two addresses
 * as EXACT from pkt_0202D2EC promotes this file to EXACT unchanged.
 * (docs/notes/func_0202D3D0.c.txt is a documented near miss at 41 bytes.)
 *
 * symbols:
 *   func_0202D060   0x0202D060  thumb
 *   func_0202D064   0x0202D064  thumb
 *   func_0202D214   0x0202D214  thumb
 *   func_0202D2EC   0x0202D2EC  thumb
 *   func_0202D3D0   0x0202D3D0  thumb
 *   func_02049E34   0x02049E34  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u32   func_0202D060(void);
extern u32   func_0202D064(u32 ctx, u32 a1, u32 a2, u32 a3,
                           u32 s0, u32 s1, u32 s2);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern void  func_0202D214(u32 obj, u32 key);
extern void  func_0202D3D0(u32 obj, u32 pid);
extern void  func_0202D2EC(u32 obj, u32 key);

void *func_0202D760(u32 *out, u32 a1, u32 a2, u32 a3,
                    u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4)
{
    u32 id;
    void *res;

    id = func_0202D064(func_0202D060(), a1, a2, a3, s0, s1, s2);
    res = func_02049E34(func_0202D060(), id, 1, (u32)out, s4);
    if (a1 == 0x147) {
        func_0202D214(*out, s4);
        func_0202D3D0(*out, s3);
        func_0202D2EC(*out, s4);
    }
    return res;
}
