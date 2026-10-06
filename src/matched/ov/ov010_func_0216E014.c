/*
 * function: func_0216E014
 * address:  0x0216E014
 * packet:   pkt_ov010_0216E014
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D844  0x0216D844  thumb  ov010
 *   func_0216D85C  0x0216D85C  thumb  ov010
 *   func_0216D874  0x0216D874  thumb  ov010
 *   func_0216D89C  0x0216D89C  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0216D5D8  0x0216D5D8  thumb  ov010
 *   func_0216D4B4  0x0216D4B4  thumb  ov010
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D570  0x0216D570  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void func_0216D844(void *p, s16 v);
extern void func_0216D85C(void *p, int v);
extern void func_0216D874(int a0, int a1);
extern void func_0216D89C(void *p, const void *q);
extern int func_02163F10(int a0);
extern int func_0216D5D8(int a0, int a1);
extern void *func_0216D4B4(char *p);
extern void *func_0216D568(void *p, u32 v);
extern char *func_0216D570(char *p, u32 v);

void func_0216E014(void *a, int *p, int b)
{
    func_0216D844(a, (s16)((p[0] >> 4) / 4096));
    func_0216D85C(a, (s16)((p[1] >> 4) / 4096));
    func_0216D874((int)a, (s16)((p[2] >> 4) / 4096));
    func_0216D89C(a, p);
    func_02163F10((int)a);
    func_0216D5D8((int)a, b);
    func_0216D4B4(a);
    func_0216D568(a, 0x20);
    func_0216D570(a, 0x50);
}
