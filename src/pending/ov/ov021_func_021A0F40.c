/*
 * function: func_021A0F40
 * address:  0x021A0F40
 * packet:   pkt_ov021_021A0F40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: logic and registers right; only residue is the str of p[1] = n, which the original schedules after the table and p[0] loads for the enter call (tried comma, index-assign, temp f/old, inline, struct, Entry pointer).
 *
 * symbols:
 *   func_021A0EE4  0x021A0EE4  thumb  ov021
 *   d_021D872C     0x021D872C  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

typedef struct {
    void (*enter)(void *, u32);
    u32 pad4;
    u32 pad8;
    int (*init)(void *, u32);
    void (*exit)(void *);
    u8 rest[8];
} Entry;

extern Entry d_021D872C[];

extern u32 func_021A0EE4(u32 *);

void func_021A0F40(u32 *p)
{
    u32 n = func_021A0EE4(p);
    u32 old;
    d_021D872C[p[0]].exit(p);
    old = p[0];
    p[1] = n;
    d_021D872C[n].enter(p, old);
    p[0] = p[1];
    p[2] = 0;
}
