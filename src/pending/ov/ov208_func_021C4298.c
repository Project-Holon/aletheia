/*
 * function: ov208_func_021C4298
 * address: 0x021C4298
 * packet: pkt_ov208_021C4298
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-03): the lane size 682 is wrong, the function is 1288 bytes (021C4298..021C47A0). Control
 *   flow and callees are decoded (3 switches on ev, two 0x400-byte bufs + two u16[5] out sets for
 *   021C53F4, sys at sp+0x1c, flag at sp+0x18), jump tables match. Open: the image keeps ev, flag
 *   and sys in memory (every use reloads, ev is stored back to its home slot once at entry) and gives
 *   r7 to `id`; compiled gives r7 to ev (1236 vs 1288 bytes). Tried: volatile ev/flag, register id,
 *   u32 ev, address-taken ev (folded away).
 * note (2026-10-05, wave D4 lane 02): in the image r7 holds `id` in all four id webs (cases 0xc/0xd, both
 *   W(0x6b8) arms) and the 0x548 base in cases 0x1c/0x1d; cur/id2 spill to [sp,#0x14]/[sp,#0x10]. Ours
 *   spills the id webs to [sp,#0x28]/[sp,#0x2c] and gives r7 to ev. Tried: one `cur` for both cases
 *   (no change, 1098 bytes differ). Still 1236 vs 1288 bytes.
 * note (2026-10-05, wave D5 lane 03): logic fix: the image calls _u32_div_f (0x0209C2B0), not
 *   _s32_div_f, in cases 0x1c/0x1d; the count H(0x548) is a u32 local `n`, loaded once for the `>= 3`
 *   test and the first `%`, and reloaded (`n = H(0x548)`) in the inner if (image reloads into r2).
 *   Now 1244 vs 1288 bytes, 1106 bytes differ. Residue is still the allocator: image spills ev (13
 *   reloads via `ldr rX,=K; add rX,sp; ldr [rX,#4]`), flag and sys, and keeps id / the 0x548 base in r7;
 *   ours keeps ev in r7 and spills the 0x548 base and id. Also tried sB/sA as `struct Ov208Sel sel[2]`
 *   and bufs as `u8 buf[2][0x400]` (the image addresses sA.count as sp+0x20+0x12): no change.
 *   Hint from 021BEB18 (closed to MATCH this wave): its "parameter in home slot" residue was a wrong
 *   argument (a constant 0 that the image keeps in r7), so re-check every call argument here.
 * note (2026-10-05, wave D6 lane 04): two listing-backed changes kept. (1) Cases 0x1c/0x1d hold 0x548 in
 *   a local `k` (image: `ldr r7,=0x548`, then `adds r0,r7,#0; adds r0,#8` per access, final `adds r7,#8`),
 *   written as H(k), H(k + 6), H(k + 8). (2) flag is u8: the image stores 0 to [sp,#0x18] and reloads it for
 *   the W(0x698)/W(0x6d4)/W(0x6b4) stores (an int flag forwards the 0). Now 1248 vs 1288, 1121 differ.
 *   Residue is still ev in r7. Probe (test only, not a fix): with ONE fewer ev read (switch 1 or switch 4
 *   on another value) ev spills, the frame becomes 0x834 as in the image and id takes r7. So ev sits just
 *   above the spill threshold: the original has one less ev use, or more weight on the id/k webs.
 *   Tried without effect: separate id/k locals per web, block-scoped u16 old/cur per case (sibling
 *   021C2A70 style), u16 id/cur, int k, u8/u16/short ev, bufA/sA declared first, volatile ev+flag+sys
 *   (wrong: caches &ev, reloads flag twice), `W(0x6d4) = W(0x698) = flag` (image reloads flag once for
 *   both stores; ours reloads per store, int flag forwards the 0).
 * symbols:
 *   ov208_func_021BC3B4 0x021BC3B4 thumb ov208
 *   ov208_func_021BC3C0 0x021BC3C0 thumb ov208
 *   ov208_func_021BC3CC 0x021BC3CC thumb ov208
 *   ov208_func_021BC40C 0x021BC40C thumb ov208
 *   ov208_func_021BC3A4 0x021BC3A4 thumb ov208
 *   ov208_func_021C53F4 0x021C53F4 thumb ov208
 *   ov208_func_021C580C 0x021C580C thumb ov208
 *   ov208_func_021C5C64 0x021C5C64 thumb ov208
 *   ov208_func_021C5F34 0x021C5F34 thumb ov208
 *   ov208_func_021BDBEC 0x021BDBEC thumb ov208
 *   ov208_func_021BDBA0 0x021BDBA0 thumb ov208
 *   ov208_func_021BDC2C 0x021BDC2C thumb ov208
 *   func_02012BE0 0x02012BE0 thumb
 *   _u32_div_f 0x0209C2B0 arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208Sel {
    u16 next;
    u16 sel;
    u16 twos;
    u16 groups;
    u16 count;
};

extern void *ov208_func_021BC3B4(int key);
extern u16 ov208_func_021BC3C0(int key);
extern void ov208_func_021BC3CC(int key);
extern void ov208_func_021BC40C(int key);
extern int ov208_func_021BC3A4(int key);
extern void ov208_func_021C53F4(u16 *heap, int key, u8 *out, u16 *count, u16 *groups, u16 *twos, u16 *sel, u16 *next);
extern void ov208_func_021C580C(u16 *heap, u8 *p, int key);
extern void ov208_func_021C5C64(u16 *heap, u8 *p, int key);
extern void ov208_func_021C5F34(u16 *heap, u8 *p, int key, volatile int ev);
extern void ov208_func_021BDBEC(void *sys, int v);
extern void ov208_func_021BDBA0(void *sys);
extern int ov208_func_021BDC2C(void *sys);
extern void func_02012BE0(void *p, u32 a, u32 b);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

void ov208_func_021C4298(void *proc, int *seq, u16 *heap, u8 *p, int key, int ev)
{
    u8 bufB[0x400];
    u8 bufA[0x400];
    struct Ov208Sel sB;
    struct Ov208Sel sA;
    u32 id;
    u32 id2;
    u8 flag;
    void *sys;
    u32 cur;
    u32 n;
    u32 k;
    if (p == 0)
        return;
    sys = ov208_func_021BC3B4(key);
    flag = 0;
    W(0x698) = flag;
    W(0x6d4) = flag;
    switch (ev) {
    case 0xa: case 0xb: case 0xc: case 0xd: case 0xe: case 0xf: case 0x10: case 0x11:
    case 0x1c: case 0x1d: case 0x1e: case 0x1f: case 0x20:
        W(0x6b4) = flag;
        break;
    }
    switch (ev) {
    case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
    case 0x16: case 0x17: case 0x18: case 0x19: case 0x1a:
        flag = 1;
        W(0x6b4) = 1;
        break;
    }
    switch (ev) {
    case 0xc:
    case 0x1e:
        if (W(0x6b8) == 0) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC3CC(key);
            if (id != ov208_func_021BC3C0(key))
                ov208_func_021C580C(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC3CC(key);
            cur = ov208_func_021BC3C0(key);
            while (id != cur) {
                ov208_func_021C53F4(heap, key, bufA, &sA.count, &sA.groups, &sA.twos, &sA.sel, &sA.next);
                if (sA.count >= 2)
                    break;
                ov208_func_021BC3CC(key);
                cur = ov208_func_021BC3C0(key);
            }
            if (id != cur) {
                ov208_func_021C580C(heap, p, key);
                if (sA.count >= 3)
                    ov208_func_021BDBEC(sys, 1);
                else
                    ov208_func_021BDBEC(sys, 0);
            }
        }
        break;
    case 0xd:
    case 0x1f:
        if (W(0x6b8) == 0) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC40C(key);
            if (id != ov208_func_021BC3C0(key))
                ov208_func_021C580C(heap, p, key);
        } else if (W(0x6b8) == 4) {
            id = ov208_func_021BC3C0(key);
            ov208_func_021BC40C(key);
            id2 = ov208_func_021BC3C0(key);
            while (id != id2) {
                ov208_func_021C53F4(heap, key, bufB, &sB.count, &sB.groups, &sB.twos, &sB.sel, &sB.next);
                if (sB.count >= 2)
                    break;
                ov208_func_021BC40C(key);
                id2 = ov208_func_021BC3C0(key);
            }
            if (id != id2) {
                ov208_func_021C580C(heap, p, key);
                if (sB.count >= 3)
                    ov208_func_021BDBEC(sys, 1);
                else
                    ov208_func_021BDBEC(sys, 0);
            }
        }
        break;
    case 0x1c:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8) = H(k + 8) + 1;
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                H(k + 8) = H(k + 8) + 1;
                H(k + 8) = H(k + 8) % H(k);
            }
            ov208_func_021C5C64(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x1d:
        k = 0x548;
        n = H(k);
        if (n >= 3) {
            H(k + 8) = H(k + 8) + (u16)(n - 1);
            H(k + 8) = H(k + 8) % n;
            if (H(k + 6) == H(k + 8)) {
                n = H(k);
                H(k + 8) = H(k + 8) + (u16)(n - 1);
                H(k + 8) = H(k + 8) % n;
            }
            ov208_func_021C5C64(heap, p, key);
            W(0x698) = 1;
            W(0x6d4) = 1;
        }
        break;
    case 0x20:
        if (H(0x548) >= 2) {
            ov208_func_021C5F34(heap, p, key, 5);
            W(0x6d8) = 1;
            W(0x6dc) = 0;
            W(0x6e0) = 0;
        } else {
            W(0x6d8) = 1;
            W(0x6dc) = 1;
            W(0x6e0) = 0;
        }
        break;
    }
    switch (ev) {
    case 0:
        return;
    case 1:
    case 2:
        W(0x6b0) = 2;
        return;
    case 3:
    case 24:
        ov208_func_021BDBA0(sys);
        return;
    case 4:
    case 25:
        ov208_func_021BDBA0(sys);
        return;
    case 5:
        func_02012BE0((void *)ov208_func_021BC3A4(key), 0x14, ov208_func_021BDC2C(sys));
        ov208_func_021BDBA0(sys);
        return;
    case 6:
    case 7:
    case 8:
        W(0x6b0) = 1;
        return;
    case 21:
        if (W(0x6b8) == 4)
            ov208_func_021C5F34(heap, p, key, 6);
        return;
    case 22:
        ov208_func_021BDBA0(sys);
        return;
    case 23:
        ov208_func_021BDBA0(sys);
        return;
    case 26:
        if (W(0x6d8) != 0) {
            W(0x6e0) = 1;
            if (W(0x6dc) != 0) {
                W(0x6d8) = 0;
                ov208_func_021BDBA0(sys);
                return;
            }
        }
        return;
    default:
        if (flag != 0)
            ov208_func_021BDBA0(sys);
        return;
    }
}
