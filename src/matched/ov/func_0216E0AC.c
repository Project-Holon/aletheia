/*
 * function: func_0216E0AC
 * address:  0x0216E0AC
 * packet:   pkt_0216E0AC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D67C  0x0216D67C  thumb  ov010
 *   func_0216D71C  0x0216D71C  thumb  ov010
 *   func_0216CFC4  0x0216CFC4  thumb  ov010
 *   func_0216D02C  0x0216D02C  thumb  ov010
 *   func_0216D230  0x0216D230  thumb  ov010
 *   func_0216D268  0x0216D268  thumb  ov010
 *   func_0216D0E8  0x0216D0E8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D67C();
extern void func_0216D71C(void *a0);
extern int func_0216CFC4();
extern int func_0216D02C();
extern int func_0216D230();
extern int func_0216D268();
extern int func_0216D0E8();

void func_0216E0AC(void *a0, void *a1)
{
    void *t4;
    void *t5;
    int t6;

t5 = a0;
t4 = a1;
    t6 = func_0216D67C(a0);
loc_0216E0B6:
    func_0216D71C(t5);
loc_0216E0BE:
    func_0216CFC4(t5, t4);
loc_0216E0C6:
    func_0216D02C(t5, t4);
loc_0216E0CE:
    func_0216D230(t5);
loc_0216E0D4:
    func_0216D268(t6, t5);
loc_0216E0DC:
    func_0216D0E8(t5, t4, 0);
loc_0216E0E6:
    return;}
