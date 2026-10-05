/*
 * function: func_021BE210
 * address:  0x021BE210
 * packet:   pkt_ov172_021BE210
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Places a slot marker: k = idx (2 or 3 for slots 0/1 in mode 1), checks the slot with
 * func_021B8BA4 and func_021B8B8C, then sets the sprite position from the xv/yv byte tables.
 * idx is a u8 slot index (the sibling func_021BDD6C walks the same slots with a u8 i). The u8
 * parameter is what keeps the third-call idx reload after the byte copies (wD9r lane48).
 *
 * symbols:
 *   func_021BE05C 0x021BE05C thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B8B8C 0x021B8B8C thumb ov172
 *   func_021B8B94 0x021B8B94 thumb ov172
 *   func_02008510 0x02008510 thumb
 *   func_0201D304 0x0201D304 thumb
 *   func_02045808 0x02045808 arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B9A0 0x0204B9A0 arm
 *   d_021C7048 0x021C7048 data ov172
 *   d_021C704C 0x021C704C data ov172
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q { u8 b[4]; };
struct Pt { u16 x; u16 y; struct Q yv; struct Q xv; };
extern int func_021BE05C(void *p);
extern u32 func_021B8BA4(int unused, char *base, int i);
extern u32 func_021B8B8C(int unused, char *base, int i);
extern char *func_021B8B94(int unused, char *base, int i);
extern void *func_02008510(void *a, int tag);
extern u32 func_0201D304(void *s, u32 a, u32 b);
extern void func_02045808(void *);
extern void func_0204B404(void *, void *, u32);
extern void func_0204B3DC(void *, u32);
extern void func_0204B9A0(void *);
extern const struct Q d_021C7048;
extern const struct Q d_021C704C;
void func_021BE210(char *a, u8 idx)
{
    struct Pt rc;
    void *h;
    u32 v;
    int mode;
    u32 k;
    mode = func_021BE05C(a);
    k = idx;
    if (*(int *)(a + 8) == 3) return;
    if (mode == 1) k = (k == 0) ? 2 : 3;
    if (func_021B8BA4((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    if (func_021B8B8C((int)a, *(char **)(a + 0x1E4), idx) != 1) return;
    rc.xv = d_021C704C;
    rc.yv = d_021C7048;
    h = func_02008510(func_021B8B94((int)a, *(char **)(a + 0x1E4), idx), *(u16 *)a);
    v = (u8)func_0201D304(h, *(u32 *)(a + 0x1C8), 0);
    func_02045808(h);
    { u32 xk = rc.xv.b[k]; rc.x = xk + (v >> 1); }
    rc.y = rc.yv.b[k];
    func_0204B404(*(void **)(a + 0x1B0), &rc, 0);
    func_0204B3DC(*(void **)(a + 0x1B0), 1);
    func_0204B9A0(*(void **)(a + 0x1B0));
}
