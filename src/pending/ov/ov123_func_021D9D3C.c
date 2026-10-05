/*
 * function: func_021D9D3C
 * address: 0x021D9D3C
 * packet: pkt_ov123_021D9D3C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * 2026-10-05 (wD8 lane04): still DIFF, same residue (movs r5,#3 hoist). Tried u8 for the second and third parameters of 02049B68/02049658/020498F4 (no change, 441 differ). Matched callers use (void *, u32, u32, u32, u32, [u32,] u16).
 * 2026-10-05 (wD7 lane19): still DIFF (same 3-in-r5 residue). Replaced the redundant `base0 = p; base0 = p + 0x10;` with a static inline PalBase() accessor (D6 lever): it gives the image's str/adds/str double store at [sp,#0x2c] without a redundant statement. Tried `int j = 0;` as a declaration initialiser with j or literal 0 args (473 differ, j store moves above the open). Same late-call copies (r2 = r5, r3 = [sp,#0x18]) as ov210 021BC5DC from call 8 on.
 * note-2026-10-04: DIFF. Whole structure and every slot matches (declaration order base0, base1, h, done, k, j, i, cur reproduces slots 0x18..0x2c; j doubles as the zero args). Residue: compiler hoists constant 3 into r5 (movs r5,#3 after the first func_02049B68 call) and reuses it for the last func_020498F4 r2, so the last call also gets r3=[j slot] instead of movs r3,#0, and +2 bytes shift everything after. Original keeps literals. Also original loads heap into r5 before func_02082BCC (adds r3,r5 for 02049F78); an explicit u16 heap local did not remove the hoist. Tried param types u16 on 49B68/49658/498F4 arg2: no effect. Next: find what stops the const-3 hoist (different source of 3 in calls 1/4 or a call between).
 * note-2026-10-05 (wave D4 lane 06): still DIFF, same residue.  Findings: (1) with literal 0
 *   for every zero argument the compiler still reloads the stack zeros from j's slot [sp,#0x18]
 *   (it value-numbers 0 with j), even with j = 0 moved to just before the loop; so "j doubles as
 *   the zero args" is the compiler's choice, not a source statement.  (2) the movs r5,#3 hoist
 *   exists only while the eighth call (func_020498F4(h, 7, 3, ...)) is present; changing the 3
 *   of call 1 does not remove it; it also brings r3 = [sp,#0x18] in call 8 and r1 = [sp,#0x18]
 *   for func_02082BCC.  Removing the heap local (expression inline) does not change it.  The
 *   same late-call constant reuse shows in ov112 021F3CA4 (r3 = r6 in its last calls).
 *   Not tried: inline helpers per bg-load group, a different source for the 3 in call 8.
 * note-2026-10-05 (wave D5 lane 13): still DIFF, same residue. Findings: removing call 7
 *   (func_02049658(h, 4, 3, ...)) removes the movs r5,#3 hoist; adding a call after call 8 keeps
 *   it. So the hoist needs the two adjacent calls with 3 in r2. Tried: calls 7 and 8 through a
 *   static inline helper (hoist moves to r6), literal 0 for all zero args (same), j as u32
 *   (same), int params on func_02049658 (same). Also the later i = 0 store comes out as a
 *   copy of j ([sp,#0x18]); the original stores a literal 0, so the original compiler did not
 *   treat j as the constant 0 after the calls.
 * note-2026-10-05 (wD6 lane17): still DIFF, same residue. Checked all callee prototypes against matched
 *   callers (02049B68/02049658/020498F4 as used, 02082BCC (void *, int, int)): no missing or extra argument.
 *   The original keeps every outer-loop local in memory ([sp,#0x14] i, 0x18 j, 0x1c k, 0x20 done) and
 *   loads the stack-argument zeros from j's slot, so j = 0 before the eight calls is right. Open: why the
 *   original does not CSE the four 3s into the free r5.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02049F78 0x02049F78 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02021F64 0x02021F64 thumb
 *   func_020862F0 0x020862F0 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021D9F40 0x021D9F40 thumb ov123
 *   func_0207D63C 0x0207D63C arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(u32 id, u16 heap);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern void func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02082BCC(void *, u8, u32);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02082D44(const void *, void *, u32);
extern void func_020307B0(void *);
extern void func_02021F64(u16 *, u16 *, int, u8, u16);
extern void func_020862F0(void *, int);
extern void *func_020056A0(void *, void *, int);
extern void func_021D9F40(void *, char *);
extern void func_0207D63C(void *, int, int, int, int);
extern void func_02049238(void *);
static inline u16 *PalBase(char *p)
{
    u16 *r = (u16 *)p;
    r += 8;
    return r;
}
void func_021D9D3C(char *p)
{
    void *record;
    u16 *base0;
    u16 *base1;
    void *h;
    int done;
    int k;
    int j;
    int i;
    u16 *cur;
    void *allocated;
    int m;
    int t;
    u16 *dst;
    u16 *src;
    u16 heap;
    h = func_020490F4(0x91, *(u16 *)(p + 0x9e4));
    j = 0;
    func_02049B68(h, 3, 4, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 6, 4, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049B68(h, 3, 0, 0, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 5, 0, 0, j, j, *(u16 *)(p + 0x9e4));
    func_02049658(h, 4, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    func_020498F4(h, 7, 3, 0, j, j, *(u16 *)(p + 0x9e4));
    heap = *(u16 *)(p + 0x9e4);
    func_02082BCC(p + 8, 0, 0x970);
    allocated = func_02049F78(h, 2, (u32)&record, heap);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x10, 0x1e0);
    func_02082D44(*(void **)((u8 *)record + 0xc), p + 0x1f0, 0x1e0);
    func_020307B0(allocated);
    base1 = (u16 *)(p + 0x1f0);
    base0 = PalBase(p);
    for (i = 0; i < 15; i++) {
        t = i + 1;
        if (t >= 15) t -= 15;
        k = 0;
        done = 0;
        cur = (u16 *)(p + t * 32);
        while (1) {
            dst = base0 + i * 16;
            src = base1 + j * 16;
            for (m = 4; m < 11; m++) {
                func_02021F64(dst + m, src + m, 1, (u8)(k >> 8), cur[m + 8]);
            }
            j++;
            if (done == 1) break;
            k += 0x600;
            if (k >= 0x1000) {
                k = 0x1000;
                done = 1;
            }
        }
    }
    func_020862F0(p + 0x1f0, 0x780);
    *(u32 *)(p + 0xc) = 1;
    *(void **)(p + 8) = func_020056A0((void *)func_021D9F40, p + 8, 0x14);
    func_0207D63C((void *)0x04000050, 1, 8, 8, 0x10);
    *(u8 *)(p + 0x974) = 0;
    func_02049238(h);
}
