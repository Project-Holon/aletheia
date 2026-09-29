/*
 * function: func_02177D58
 * address:  0x02177D58
 * packet:   pkt_ov014_02177D58
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   func_0203D798  0x0203D798  arm
 *   func_0203F1FC  0x0203F1FC  arm
 *   func_020862F0  0x020862F0  arm
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02178E28  0x02178E28  thumb  ov014
 *   func_021795D4  0x021795D4  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
u8 *func_0203D798(void);
u16 func_0203F1FC(void *p, u32 n);
void func_020862F0(void *p, u32 n);
int func_02178E4C(void);
void func_02178E28(void *p, u32 n);
void func_021795D4(void *p, u32 n, u32 a, u32 b);

void func_02177D58(u8 *buf, u32 len)
{
    u8 *p = g_021797A4;
    u8 *st = func_0203D798();
    if (p != 0 && st != 0) {
        *(u16 *)buf = func_0203F1FC(buf + 2, len - 2);
        func_020862F0(buf, len);
        if (func_02178E4C() == 1) {
            func_02178E28(buf, (u16)len);
            return;
        }
        func_021795D4(buf, len, *(u32 *)(st + 0x50), *(u16 *)(p + 0xC68));
    }
}
