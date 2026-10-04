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
 * status:   EXACT
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
 * Blocked at MATCH: every concrete byte is identical.  2026-09-21, unblock
 * lane: ONE OF THE TWO BLOCKING SITES IS NOW CLEARED.  func_0202D2EC was
 * filed EXACT (src/matched/func_0202D2EC.c, shard arm9/pkt_0202D2EC.json),
 * so the +0x58 THM_CALL resolves `matched`.  Only +0x50, the call to
 * func_0202D3D0, is still wildcarded: this function is that address's only
 * caller image-wide, so no evidence class (label/matched) can attest it and
 * nothing but an EXACT at 0x0202D3D0 will promote this file.  That function
 * is a documented near miss, now at 29 concrete mismatches (down from 41)
 * and stuck on one register-assignment decision -- see
 * docs/notes/func_0202D3D0.c.txt, which records the lever that halved it
 * and the twelve spellings that do not move it further.
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

typedef signed int     s32;
extern int func_0202D060(void);
extern s32 func_0202D064(u32 a0, u32 a1, u32 a2, u32 a3, u32 s5, u32 s6, u32 s7);
extern void *func_02049E34(u32 a0, u32 a1, u32 a2, u32 a3, u16 a4);
struct Obj;
extern void func_0202D214(void *p, u32 v);
extern void func_0202D3D0(struct Obj *obj, u32 a1);
extern void func_0202D2EC(u32 *obj, u32 heap);

void *func_0202D760(u32 *out, u32 a1, u32 a2, u32 a3,
                    u32 s0, u32 s1, u32 s2, u32 s3, volatile u16 s4)
{
    u32 id;
    void *res;

    id = func_0202D064(func_0202D060(), a1, a2, a3, s0, s1, s2);
    res = func_02049E34(func_0202D060(), id, 1, (u32)out, s4);
    if (a1 == 0x147) {
        func_0202D214((void *)(*out), s4);
        func_0202D3D0((struct Obj *)(*out), s3);
        func_0202D2EC((u32 *)(*out), s4);
    }
    return res;
}
