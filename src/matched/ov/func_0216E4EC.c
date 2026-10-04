/*
 * function: func_0216E4EC
 * address:  0x0216E4EC
 * packet:   pkt_0216E4EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216E5FC  0x0216E5FC  thumb  ov010
 *   func_0216D590  0x0216D590  thumb  ov010
 *   func_0216D588  0x0216D588  thumb  ov010
 *   func_0216E4B0  0x0216E4B0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_0216D598(void *p);
extern int func_0216E5FC();
extern u16 func_0216D590(void *p);
extern u16 func_0216D588(void *p);
extern int func_0216E4B0(int a, int b);

int func_0216E4EC(int a0, int a1)
{
    int t4;
    int t5;

t4 = a0 + 0;
t5 = 0x1e;
    a0 = func_0216D598((void *)a0);
loc_0216E4F6:
    a0 = func_0216E5FC(a0);
loc_0216E4FA:
    if (a0 != 1) goto loc_0216E516;
loc_0216E4FE:
a0 = t4 + 0;
    a0 = func_0216D590((void *)a0);
loc_0216E504:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216D588((void *)a0);
loc_0216E50C:
a1 = a0 + 0;
a0 = t5 + 0;
    a0 = func_0216E4B0(a0, a1);
loc_0216E514:
t5 = a0 + 0;
loc_0216E516:
a0 = t5 + 0;
    return a0;}
