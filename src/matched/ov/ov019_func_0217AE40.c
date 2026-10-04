/*
 * function: func_0217AE40
 * address:  0x0217AE40
 * packet:   pkt_ov019_0217AE40
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * What closed it: the spilled third parameter is u16, not u32. As u32 the
 * scheduler hoists its reload (`ldr r0,[sp]`) above the `strh` of d into
 * the local; as u16 the reload stays after it (see
 * docs/notes/pkt_ov019_0217AE40.c.txt for the earlier near miss).
 *
 * symbols:
 *   func_02012964  0x02012964  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_0216E618  0x0216E618  thumb  ov010
 *   func_0216CE60  0x0216CE60  thumb  ov010
 *   d_0217FFF8     0x0217FFF8  data  ov019  a4
 *   d_0218001C     0x0218001C  data  ov019  a2
 *   d_0217FFE4     0x0217FFE4  data  ov019  a2
 */

typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef union { u32 w[9]; u16 h[18]; } Tmpl;
typedef struct { s16 x, y; } Pt;

struct BigObj;
extern u32 func_02012964(const struct BigObj *p);
extern u32 func_02025C74(u32 x);
extern void func_0216E618(void *, u32, u32, int);
extern int func_0216CE60(int, void *, int);
extern const Tmpl d_0217FFF8;
extern const Pt d_0218001C[];
extern const Pt d_0217FFE4[];

int func_0217AE40(int a, int b, u16 c, u32 d)
{
    int t;
    u16 hi, lo;
    Tmpl l;

    t = func_02012964((const struct BigObj *)b);
    hi = (u16)(d >> 8);
    lo = (u16)((d & 0xff) - 0x20);
    l = d_0217FFF8;
    l.h[0] = d;
    l.h[1] = func_02025C74(c);
    if (lo != 0)
        l.h[2] = 15;
    func_0216E618(&l, (u16)(d_0218001C[hi].x + d_0217FFE4[lo].x),
                  (u16)(d_0218001C[hi].y + d_0217FFE4[lo].y), 0);
    return func_0216CE60(t, &l, 422);
}

