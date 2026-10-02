/*
 * function: func_02011D9C
 * address:  0x02011D9C
 * packet:   pkt_02011D9C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * promoted: wave 21 lane T, EXACT (match.py one, 25 of 25 relocations)
 *           once the ov230d token let the probe targets resolve
 *
 * symbols:
 *   ov230_id       0x000000E6  data
 *   g_02146248     0x02146248  data
 *   func_021882A0  0x021882A0  arm  ov230d
 *   func_02188354  0x02188354  arm  ov230d
 *   func_02188390  0x02188390  arm  ov230d
 *   func_0215FA00  0x0215FA00  thumb  ov010
 *   _u32_div_f     0x0209C2B0  arm
 *
 * ica_anime.c: scene bring-up.  Loads overlay 230, runs three checksum
 * probes over this family's own code (func_02011D28 to func_02011D40,
 * func_02011D60, func_02011D7C; each result compared with the complement of
 * the end address), creates three heaps through func_0203064C, allocates
 * the work block and publishes it to g_02146248, then, when the probe
 * results do not add up to a multiple of 0x12AF, runs a func_0200C258-counted
 * loop of func_02011D40.
 *
 * Byte-correct: 272 of 272 bytes, 0 concrete bytes out (match.py one,
 * dsi/1.1p1, 2026-09-24 wave 21 lane H).  The lever that closed it after
 * eight waves at 8 out: the probes' shared start address is held in a u32
 * local (`start = (u32)func_02011D28;`) and cast back at each call
 * (docs/idioms/an-address-held-in-a-u32-local-is-reloaded-at-every-site.md).
 * The local's web spans the second heap call, so the argument 4 there is
 * rematerialised (`movs r2,#4 ... movs r1,#4; lsls r2,r2,#14`) instead of
 * being common-subexpression-eliminated into r1, which is what the image
 * does; the single-call shape `off = 0; if (flag == 0) off = 0x191;` is the
 * right control flow once that holds.
 *
 * Probe targets (wave 21 lanes H2 and T): 0x021882A0, 0x02188354 and
 * 0x02188390 are slots 0, 3 and 4 of the six ARM thunk slots ov230's first
 * static initialiser (func_02188408) decrypts in place when this function
 * loads the overlay.  The ROM bytes there are ciphertext, so ov230's ROM
 * listing never labels them; tools/ovcrypt.py replays ov230's own
 * decryptor (every range checked to be a clean ARM function ending in a
 * return) and asm/ov230d/ov230d.s lists the result.  With the `ov230d`
 * token on the three symbols: lines they resolve as sole-ref/code against
 * that listing: 25 of 25 sites (ov230_id as overlay_id, func_0215FA00
 * sole-ref/code with the ov010 hint).
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int            s32;
typedef signed char s8;
typedef signed short s16;

extern u32   func_02011F24(void);
extern u8 ov230_id[];
extern void  func_02034AC4(u8 *id);
extern u32   func_021882A0(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188354(void (*a)(void), void (*b)(void), u32 c);
extern u32   func_02188390(void (*a)(void), void (*b)(void), u32 c);
//P
extern void  func_02034A5C(u8 *id);
extern void *func_0203159C(void *a, u32 size, u32 c);
extern void  func_02082BCC(void *p, u32 v, u32 size);
extern void *g_02146248;
extern void  func_02011FB8(void *p, u32 a, u32 b);
extern u32   func_0215FA00(void *p, u32 a);
extern void  func_02012108(void *p, u32 v);
extern void *func_020120F4(void *p);
extern void *func_02012F08(void *sys);
extern s32   func_0200C258(void *p);
extern void  func_02011D40(void);
extern void  func_02011D28(void);
extern void  func_02011D60(void);
extern void  func_02011D7C(void);

extern void func_0203064C(u32 a, u32 b, u32 c);

u32 func_02011D9C(void *a0, u32 a1, u32 a2)
{
    u32 size;
    u32 base;
    u32 flag;
    u32 off;
    void *p;
    s32 n;
    s32 i;
    u32 start;

    size = func_02011F24();
    start = (u32)func_02011D28;
    base = 0xc35ffb;
    func_02034AC4(ov230_id);
    flag = 0;
    if (func_021882A0((void (*)(void))start, func_02011D40, 0) == ~(u32)func_02011D40)
        flag = 1;
    base += flag * 0x47;
    func_0203064C(1, 3, 0xa << 12);
    flag = 1;
    if (func_02188354((void (*)(void))start, func_02011D60, 0) != ~(u32)func_02011D60)
        flag = 0;
    off = 0;
    if (flag == 0)
        off = 0x191;
    func_0203064C(1, 4, 4 << 14);
    func_02188390((void (*)(void))start, func_02011D7C, 0);
    func_0203064C(9, 5, 5 << 10);
    func_02034A5C(ov230_id);
    p = func_0203159C(a0, size, 3);
    func_02082BCC(p, 0, size);
    g_02146248 = p;
    func_02011FB8(p, 3, a2);
    func_02012108(p, func_0215FA00(p, a2));
    if ((base + off) % 0x12af != 0) {
        n = func_0200C258(func_02012F08(func_020120F4(p)));
        for (i = 0; i < n; i++)
            func_02011D40();
    }
    return 1;
}
