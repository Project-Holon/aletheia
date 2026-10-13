/*
 * function: FIELD_SUBSCREEN_ChangeModeNow
 * address:  0x021A0F40
 * packet:   pkt_ov021_021A0F40
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * State-table switch. The table is const: its loads cannot alias the p[1]
 * store, so the scheduler sinks that store below them.
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

extern const Entry d_021D872C[];

extern u32 func_021A0EE4(u32 *);

void FIELD_SUBSCREEN_ChangeModeNow(u32 *p, u32 v)
{
    u32 n = func_021A0EE4(p);
    d_021D872C[p[0]].exit(p);
    p[1] = n;
    d_021D872C[n].enter(p, p[0]);
    p[0] = p[1];
    p[2] = 0;
}
