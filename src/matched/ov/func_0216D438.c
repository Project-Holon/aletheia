/*
 * function: func_0216D438
 * address:  0x0216D438
 * packet:   pkt_0216D438
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216D7C0();
extern void *func_0216D7C8(void *p, u16 v);
extern char *func_0216D570(char *p, u32 v);

void func_0216D438(char *a0, int a1)
{
    int t4;

t4 = (int)(a0 + 0);
    a0 = (char *)func_0216D7C0(a0, a1);
loc_0216D440:
a0 = (char *)(t4 + 0);
a1 = 0;
    a0 = (char *)func_0216D7C8(a0, a1);
loc_0216D448:
a1 = 1;
a0 = (char *)(t4 + 0);
a1 = a1 << 0xa;
    a0 = (char *)func_0216D570(a0, a1);
loc_0216D452:
    return;}
