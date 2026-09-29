/*
 * function: func_021B65D8
 * address:  0x021B65D8
 * packet:   pkt_ov021_021B65D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: func_02012FD8 (unlabelled arm9 thumb leaf, no witness; Ilias's).
 * Verified C for it (match.py one, region arm9, --thumb, EXACT, 12 bytes):
 *   extern void *func_020071CC(void *, int);
 *   void *func_02012FD8(void **p) { return func_020071CC(*p, 0x43); }
 * with symbols: func_020071CC 0x020071CC thumb.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012FD8  0x02012FD8  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0200E7BC  0x0200E7BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *);
extern void *func_0215A5DC(void *);
extern u32 func_02159B10(void *, void *);
extern void *func_020120F4(void *);
extern void *func_02012FD8(void *);
extern void *func_02012934(void *);
extern void *func_0201AB28(void *, int);
extern void func_0200E7BC(void *, int, void *);

u32 func_021B65D8(void *a, void *b)
{
    void *t;
    void *w;
    int i;
    int j;

    func_0215A5F4(b);
    t = func_020120F4(func_0215A5DC(b));
    w = func_02012FD8(t);
    t = func_02012934(t);
    i = func_02159B10(a, b);
    j = func_02159B10(a, b);
    func_0200E7BC(w, j, func_0201AB28(t, i));
    return 0;
}
