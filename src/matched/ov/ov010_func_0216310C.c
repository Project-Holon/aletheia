/*
 * function: func_0216310C
 * address: 0x0216310C
 * packet: pkt_ov010_0216310C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x0216312E before func_02163130.
 * symbols:
 *   func_0216D57C 0x0216D57C thumb ov010
 *   func_021640B0 0x021640B0 thumb ov010
 *   func_0216DA70 0x0216DA70 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern u32 func_0216D57C(void *p, u32 v);
extern int func_021640B0(int p);
extern void func_0216DA70(void *a0);
void func_0216310C(char *p)
{
    if (func_0216D57C(p, 0x800) != 0 && func_021640B0((int)p) == 1)
        func_0216DA70(p);
}
