/*
 * function: func_021B765C
 * address: 0x021B765C
 * packet: pkt_ov133_021B765C
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note (2026-10-04, wave D3 lane 08): DIFF, same length as the target. Body matches
 *   instruction for instruction except two spots. (1) Prologue order: the target stores
 *   r1 (base) to [sp] before the 0x181C pool load and stores r3 before idx; ours
 *   loads the pool first. (2) At +0x13C the target does "str r1,[sp,#8]; ldr r1,[sp,#8];
 *   muls" (the u16 at p+0xA8 is a spilled value reloaded for 0x1249*n); ours multiplies
 *   r1 before the store, which shifts all later code by 2 bytes. Tried for (2): n as int
 *   (slot moves to 0xC), lim local vs loop-condition multiply, if+do-while guard,
 *   n*0x1249 vs 0x1249*n, no n at all (field re-read so the compiler CSEs the load;
 *   spill slot right but still no reload). Keys that closed big residues: the local
 *   constants h = 0x8000 and sh = 0xC0000 (the target computes h>>1, h>>3, h>>4, h<<1,
 *   sh>>9 at run time, so they are variables, not literals); sx = tp[0]*rx and
 *   sy = tp[1]*ry operand order; cur = old = f() store order; offy written with "* -8";
 *   case a < h>>1 passes h>>3 directly (not sc) so it is not tail-merged.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged. Tried: `lim = (n = ...) * 0x1249`; `int idx = 0`
 *   at the declaration; an offset local o = 0x181C for the first access and for p + (o + 0x18) in the first
 *   0x1834 lines (no change: the pool load still schedules first); base as int or u32 (moves the base
 *   store, never to +0004). In the original, base, rx, idx and n are all stored at their definition and
 *   reloaded before use (spill everywhere); ours keeps the value in the register and the scheduler sinks the
 *   store. A fifth live value in the original (more register pressure) is the likely cause; not found.
 * symbols:
 *   func_021BA184 0x021BA184 thumb ov133
 *   func_021BA208 0x021BA208 thumb ov133
 *   func_021BA20C 0x021BA20C thumb ov133
 *   func_021BA210 0x021BA210 thumb ov133
 *   func_021BA218 0x021BA218 thumb ov133
 *   func_021BA21C 0x021BA21C thumb ov133
 *   func_021BA244 0x021BA244 thumb ov133
 *   func_021F4E8C 0x021F4E8C thumb ov112
 *   func_021F4ED4 0x021F4ED4 thumb ov112
 *   func_021F4EB4 0x021F4EB4 thumb ov112
 *   func_021F4E6C 0x021F4E6C thumb ov112
 *   func_020061E4 0x020061E4 thumb
 *   func_0204F638 0x0204F638 arm
 *   func_0204F684 0x0204F684 arm
 *   func_0204F720 0x0204F720 arm
 *   _fflt 0x0209BDBC arm
 *   _fdiv 0x0209CE10 arm
 *   _ffix 0x0209C494 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   FX_SinCosTable_ 0x020A1B38 data
 *   d_021BA3E4 0x021BA3E4 data
 *   d_021BA3E8 0x021BA3E8 data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
typedef struct {int x,y,z;} Vec;
typedef struct {int x,y;} Pair;
extern const s16 FX_SinCosTable_[];
extern u8 d_021BA3E4[], d_021BA3E8[];
extern void *func_021BA184(u8 *p);
extern u32 func_021BA208(u8 *p);
extern u32 func_021BA20C(u8 *p);
extern void func_021BA210(u8 *p, u32 v);
extern u32 func_021BA218(u8 *p);
extern void func_021BA21C(u8 *p, Pair *v);
extern void func_021BA244(u8 *p, u32 v);
extern void func_021F4E8C(int, int, Vec *);
extern void func_021F4ED4(int, int, u16);
extern void func_021F4EB4(int, int, s16, s16);
extern void func_021F4E6C(int, int, int);
extern void func_020061E4(u32);
extern void func_0204F638(int, int, Vec *);
extern void func_0204F684(int, int, s16 *, s16 *);
extern void func_0204F720(int, int, void *);
void func_021B765C(u8 *p, u16 base, int speed, int rx, u16 ry)
{
    Vec v;
    Vec w;
    Pair pos;
    s16 sc;
    int idx;
    u16 rot;
    int offx;
    int offy;
    int sx;
    int sy;
    u8 *old;
    u8 *cur;
    u16 a;
    u8 *e;
    u8 *spr;
    int t;
    u16 k;
    int lim;
    u16 n;
    const s16 *tp;
    int h = 0x8000;
    int sh = 0xC0000;

    idx = 0;
    e = func_021BA184(*(u8 **)(p + 0x181C));
    *(int *)(p + 0x1834) += speed;
    if (*(int *)(p + 0x1834) < 0)
        *(int *)(p + 0x1834) += *(u16 *)(p + 0xA8) * 0x1249;
    lim = 0x1249 * *(u16 *)(p + 0xA8);
    if (*(int *)(p + 0x1834) >= lim)
        *(int *)(p + 0x1834) -= lim;
    rot = *(u16 *)(p + 0x1838);
    offx = (FX_SinCosTable_[0] - FX_SinCosTable_[(rot >> 4) * 2]) << 3;
    offy = FX_SinCosTable_[1] - 0x8008 - FX_SinCosTable_[(rot >> 4) * 2 + 1] * -8;
    if (speed > 0x9C4 || speed < -0x9C4) {
        if (*(u16 *)(p + 0x18C2) == 0) {
            *(u16 *)(p + 0x18C2) = 30;
            func_020061E4(0x624);
        }
    }
    if (e == 0)
        goto end;
    do {
        a = (u16)((base + (idx << 16) / 14) % 0x10000);
        sc = 0;
        spr = (u8 *)func_021BA218(e);
        tp = &FX_SinCosTable_[(a >> 4) * 2];
        sx = tp[0] * rx + 0x80000;
        sy = tp[1] * ry + 0x50000;
        cur = old = (u8 *)func_021BA20C(e);
        t = *(int *)(p + 0x1834) + (a + 0x8000) % 0x10000;
        while (t < 0)
            t += *(u16 *)(p + 0xA8) * 0x1249;
        n = *(u16 *)(p + 0xA8);
        lim = n * 0x1249;
        while (t >= lim)
            t -= lim;
        if (*(int *)(p + 0x98) == 0 || *(u32 *)(p + 0x9C) > (u32)((0x18000 - a) % 0x10000)) {
            k = (u16)((t + 0x924) / 0x1249);
            if (k >= n)
                k = (u16)(k - n);
            cur = *(u8 **)(p + k * 4 + 0x1434);
            func_021BA210(e, (u32)cur);
            if (*(u16 *)old != *(u16 *)cur && e == *(u8 **)(p + 0x38))
                *(u8 **)(p + 0x38) = 0;
        }
        if (a >= h)
            a = (u16)((h << 1) - a);
        pos.x = (int)((float)sx / 4096.0f);
        pos.y = (int)((float)sy / 4096.0f);
        v.x = sx + offx;
        v.y = sy + offy;
        v.z = (h - a) + 0x14000;
        func_021F4E8C(*(int *)(p + 0x1884), (int)spr, &v);
        func_021F4ED4(*(int *)(p + 0x1884), (int)spr, rot);
        func_021BA21C(e, &pos);
        if (a < (h >> 1)) {
            sc = h >> 3;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, h >> 3, h >> 3);
            func_021F4E6C(*(int *)(p + 0x1884), (int)spr, 1);
            func_021BA244(e, h >> 3);
        } else if (a < 0x6E00) {
            sc = ((u16)(0x6E00 - a) << 11) / 0x2E00 + (h >> 4);
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C(*(int *)(p + 0x1884), (int)spr, 1);
            func_021BA244(e, sc);
        } else if (a < 0x78E0) {
            sc = ((u16)(0x78E0 - a) << 11) / 0xAE0;
            func_021F4EB4(*(int *)(p + 0x1884), (int)spr, sc, sc);
            func_021F4E6C(*(int *)(p + 0x1884), (int)spr, 1);
            func_021BA244(e, sc);
        } else {
            func_021F4E6C(*(int *)(p + 0x1884), (int)spr, 0);
            func_021BA244(e, 0);
            sc = 0;
        }
        if (*(int *)(cur + 0x10) == 1 && *(u16 *)(p + 0x94) < 45) {
            w.x = v.x / 16;
            w.y = (sh - (v.y + h)) / 16;
            w.z = v.z + (sh >> 9);
            func_0204F638(*(int *)(p + 0x188C), *(int *)(p + idx * 4 + 0x5C), &w);
            func_0204F684(*(int *)(p + 0x188C), *(int *)(p + idx * 4 + 0x5C), &sc, &sc);
            func_0204F720(*(int *)(p + 0x188C), *(int *)(p + idx * 4 + 0x5C), d_021BA3E8);
        } else {
            func_0204F720(*(int *)(p + 0x188C), *(int *)(p + idx * 4 + 0x5C), d_021BA3E4);
        }
        e = (u8 *)func_021BA208(e);
        idx++;
    } while (e != 0);
end:
    func_021BA184(*(u8 **)(p + 0x181C));
}
