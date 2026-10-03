/*
 * unit:     yes
 * function: func_0200BFA4, func_0200C054
 * address:  0x0200BFA4
 * packet:   pkt_0200BFA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0200864C  0x0200864C  thumb
 *   func_02008650  0x02008650  thumb
 *   func_02008654  0x02008654  thumb
 *   _ull_mul       0x0209C054  arm
 *   g_02146170     0x02146170  data  a8
 *
 * battle_rec.c, 0x0200BFA4..0x0200C058: the play-clock accumulator and the
 * unlabelled 4-byte follower func_0200C054 (`return 0xEC;`, a size getter).
 *
 * func_0200BFA4 converts the h:m:s clock at q to seconds and, by mode,
 * latches it (0), adds the elapsed delta into the u64 at +0x1A8 (1), or
 * returns that total plus the delta without storing it (2).  What closed it
 * after docs/notes/pkt_0200BFA4.c.txt (79 out, 4 bytes short):
 *   - the three clock fields are u64 LOCALS: the image zeroes the high half
 *     (`movs r4, #0`) right after the first call and keeps four stack
 *     words, which a u32 t[3] never gives;
 *   - the sum is written minutes first, `mm * 60 + hh * 3600 + ss` (the
 *     _ull_mul calls follow source order);
 *   - mode 2 returns `total + (v - g)`, not `total - g` (the four missing
 *     bytes were that add).
 *
 * Integrator: seed 0x0200C054 (unlabelled follower, member of this unit).
 */

typedef unsigned char      u8;
typedef unsigned short     u16;
typedef unsigned int       u32;
typedef unsigned long long u64;

struct PlayTime;
extern u16 func_0200864C(const struct PlayTime *p);
extern u8 func_02008650(const struct PlayTime *p);
extern u8 func_02008654(const struct PlayTime *p);
extern u64 g_02146170;

u64 func_0200BFA4(u8 *p, void *q, u32 mode)
{
    u64 hh, mm, ss;
    u64 v;

    hh = func_0200864C(q);
    mm = func_02008650(q);
    ss = func_02008654(q);
    v = mm * 60 + hh * 3600 + ss;

    switch (mode) {
    case 0:
        g_02146170 = v;
        break;
    case 1:
        *(u64 *)(p + 0x1A8) = *(u64 *)(p + 0x1A8) + (v - g_02146170);
        break;
    case 2:
        return *(u64 *)(p + 0x1A8) + (v - g_02146170);
    }
    return *(u64 *)(p + 0x1A8);
}

u32 func_0200C054(void)
{
    return 0xEC;
}
