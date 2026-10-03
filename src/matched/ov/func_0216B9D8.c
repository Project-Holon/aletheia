/*
 * function: func_0216B9D8
 * address:  0x0216B9D8
 * packet:   pkt_0216B9D8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0200E394  0x0200E394  thumb
 *   func_0200C0E8  0x0200C0E8  thumb
 *   func_0200C32C  0x0200C32C  thumb
 *   func_0216BB18  0x0216BB18  thumb  ov010
 *   func_0216BBC4  0x0216BBC4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern int func_0216BB18();
extern int func_0216BBC4(int index);

int func_0216B9D8(int a0)
{
    int t4;
    int t5;
    void *p;

t4 = a0 + 0;
    func_0200E394((void *)a0);
loc_0216B9E0:
a0 = t4 + 0;
    p = func_0200C0E8((void *)a0);
loc_0216B9E6:
    a0 = func_0200C32C(p);
loc_0216B9EA:
t5 = a0 + 0;
a0 = t4 + 0;
    a0 = func_0216BB18(a0);
loc_0216B9F2:
t4 = a0 + 0;
a0 = t5 << 0x18;
a0 = (unsigned)a0 >> 0x18;
    a0 = func_0216BBC4(a0);
loc_0216B9FC:
    if (a0 > t4) goto loc_0216BA04;
loc_0216BA00:
a0 = 1;
    return a0;
loc_0216BA04:
a0 = 0;
    return a0;}
