/*
 * function: func_0216D410
 * address:  0x0216D410
 * packet:   pkt_0216D410
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * blocked:  listing 40 compiled 38
 *
 * symbols:
 *   func_0216D7C0  0x0216D7C0  thumb  ov010
 *   func_0216D7C8  0x0216D7C8  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_0216D7C0(void *p, u16 v);
extern void *func_0216D7C8(void *p, u16 v);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);

void func_0216D410(void *a0, u16 a1)
{
    u32 t4;

    func_0216D7C0(a0, a1);
    func_0216D7C8(a0, 0);
    t4 = 2;
    t4 = t4 << 8;
    func_0216D568(a0, t4);
    func_0216D570(a0, t4 << 1);
}
