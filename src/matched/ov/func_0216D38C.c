/*
 * function: func_0216D38C
 * address:  0x0216D38C
 * packet:   pkt_0216D38C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 28 compiled 26
 *
 * symbols:
 *   func_0216D28C  0x0216D28C  thumb  ov010
 *   func_0216DA30  0x0216DA30  thumb  ov010
 *   func_0216D3B4  0x0216D3B4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D28C();
extern int func_0216DA30();
extern int func_0216D3B4(int a0);

void func_0216D38C(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216D28C(a0);
loc_0216D394:
a0 = t4 + 0;
    a0 = func_0216DA30(a0);
loc_0216D39A:
    if (a0 != 1) goto loc_0216D3A4;
loc_0216D39E:
a0 = t4 + 0;
    a0 = func_0216D3B4(a0);
loc_0216D3A4:
    return;}
