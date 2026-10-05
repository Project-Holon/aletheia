/*
 * function: func_021B6100
 * address: 0x021B6100
 * packet: pkt_ov133_021B6100
 * region: ov133
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04: DIFF residue is one spot, +00F2..+0104. Original keeps k=0x1249 in r1 across
 *   the multiply (adds r3,r2; muls r3,r1,r3; cmp r0,r3; blo L; subs r0,r0,r3; b L; blx _u32_div_f
 *   with r1 still 0x1249) and takes the u16 cast right after the call. Ours multiplies in place
 *   (muls r1,r2,r1) and reloads 0x1249. Everything else (all stores, calls, tail) is byte exact.
 *   Tried: if/ternary both orders, early-return inline helper, k as local/const/inline parameter,
 *   u16 vs u32 n, k*n vs n*k, separate t/k statement. None keeps r1 live.
 *   2026-10-04 (D2): also tried x/k as u16/u32 block locals (m = x * k; t / k): same output. Note the original has a
 *   no-op `b` to the next instruction (+00FC) where the reload would sit: the join may come from an if/else whose
 *   else arm is empty or whose arms both end at the call.
 * 2026-10-05 (wave D4 lane 01): DIFF, residue unchanged (23 bytes at +00F2..+0108). Tried: k = 0x1249
 *   local for both the multiply and the divide (with if and with ternary), n and k both locals
 *   (`m = n * k`, the "separate product local" shape), a new result local `u = (t >= m) ? t - m : t`,
 *   the ternary nested in the divide, and `if (t < m) {} else t -= m;`. All give `muls r1,r2,r1` and a
 *   reload of 0x1249. The original copies n (adds r3,r2) before the multiply, so n is still live
 *   after it in the original IR, and the no-op `b` marks an empty else block. Neither is explained yet.
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_021B69AC 0x021B69AC thumb ov133
 *   func_021B6BA4 0x021B6BA4 thumb ov133
 *   func_021B6E74 0x021B6E74 thumb ov133
 *   func_021B6F00 0x021B6F00 thumb ov133
 *   func_021B9DE8 0x021B9DE8 thumb ov133
 *   func_021B9B48 0x021B9B48 thumb ov133
 *   func_021B6884 0x021B6884 thumb ov133
 *   func_020056A0 0x020056A0 thumb
 *   func_0202208C 0x0202208C thumb
 *   _u32_div_f 0x0209C2B0 arm
 *   _s32_div_f 0x0209C0A4 arm
 *   func_021B9028 0x021B9028 thumb ov133
 *   func_0200A828 0x0200A828 thumb
 *   func_0200A834 0x0200A834 thumb
 *   func_02005D90 0x02005D90 thumb
 *   func_0203D34C 0x0203D34C arm
 *   d_021BA600 0x021BA600 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const char d_021BA600[];
extern void *func_02030734(u32, u32, int, const char *, u16);
extern void func_021B69AC(u8 *),func_021B6BA4(u8 *),func_021B6E74(u8 *),func_021B6F00(u8 *),func_021B9DE8(u8 *),func_021B9B48(u8 *),func_021B6884(u8 *);
extern void *func_020056A0(void *,void *,int);
extern void func_0202208C(void *,u32,u32,u32,u32,u32,u32);
extern void func_021B9028(u8 *,int,u16);
extern u32 func_0200A828(u32);
extern void func_0200A834(u32,u32);
extern void func_02005D90(int,int);
extern void func_0203D34C(u32,u32);
extern int _s32_div_f(int, int);
u8 *func_021B6100(u8 *parent, u16 heap)
{
    u8 *p = func_02030734(heap, 0x18f0, 1, d_021BA600, 0x1de);
    u32 t, m;
    *(u16 *)p = heap;
    *(u8 **)(p + 4) = parent;
    *(u32 *)(p + 0xc) = 7;
    *(u32 *)(p + 0x10) = 0;
    *(u32 *)(p + 0x14) = 0;
    *(u32 *)(p + 0x18) = 0;
    *(u32 *)(p + 0x30) = 0;
    *(u32 *)(p + 0x38) = 0;
    *(u32 *)(p + 0x3c) = 0;
    *(u32 *)(p + 0x40) = 0;
    *(u32 *)(p + 0x98) = 0;
    *(u32 *)(p + 0xa4) = 8;
    *(u16 *)(p + 0x182c) = 0;
    *(u16 *)(p + 0x1838) = 0;
    *(u16 *)(p + 0x183a) = 0;
    *(u32 *)(p + 0x183c) = 0;
    *(u8 *)(p + 0x18c6) = 0;
    *(u32 *)(p + 0x18c8) = 0;
    *(u32 *)(p + 0x18d0) = 0;
    *(u32 *)(p + 0x18cc) = 0;
    *(u16 *)(p + 0x18d4) = 0xff;
    *(u8 *)(p + 0x18c1) = 0;
    *(u32 *)(p + 0x1834) = 0;
    *(u32 *)(p + 0x18ec) = 0;
    *(u16 *)(p + 0x182e) = 0;
    *(u32 *)(p + 0x34) = 10;
    func_021B69AC(p);
    func_021B6BA4(p);
    func_021B6E74(p);
    func_021B6F00(p);
    func_021B9DE8(p);
    func_021B9B48(p);
    *(void **)(p + 8) = func_020056A0((void *)func_021B6884, p, 8);
    func_0202208C((void *)2, 1, 1, 0x7fff, 18, 1, *(u16 *)p);
    t = *(u32 *)(p + 0x1834) + 0x18000;
    *(u16 *)(p + 0x18c2) = 10;
    m = *(u16 *)(p + 0xa8) * 0x1249;
    if (t >= m) t -= m;
    func_021B9028(p, 8, (u16)(t / 0x1249));
    *(u32 *)(p + 0xa4) = 8;
    *(u32 *)(p + 0x98) = 1;
    *(u32 *)(p + 0x9c) = 0;
    *(u32 *)(p + 0xa0) = *(u16 *)(p + 0x182c) % 0x1249 + 0x10000;
    if (func_0200A828(*(u32 *)(*(u8 **)(p + 4) + 8)) == 0) {
        func_0200A834(*(u32 *)(*(u8 **)(p + 4) + 8), 1);
        *(u32 *)(p + 0x1840) = 1;
    } else {
        *(u32 *)(p + 0x1840) = 0;
    }
    func_02005D90(0x454, 0xffff);
    func_0203D34C(0, *(u16 *)p);
    return p;
}
