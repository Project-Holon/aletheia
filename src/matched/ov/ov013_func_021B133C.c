/*
 * function: func_021B133C
 * address:  0x021B133C
 * packet:   pkt_ov013_021B133C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   func_021B14A8  0x021B14A8  arm  ov013
 *   func_021B14F8  0x021B14F8  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   g_021B4BA0     0x021B4BA0  data  a4
 */

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern void *func_021B14A8(unsigned int n);
extern void func_021B14F8(void *p);
extern void func_021B2FE4(void *p);

extern int g_021B4BA0[3];

void func_021B133C(unsigned int n)
{
    int s;
    void *p;

    s = OS_DisableInterrupts();
    while ((p = func_021B14A8(n)) != 0) {
        func_021B14F8(p);
        func_021B2FE4(p);
    }
    g_021B4BA0[n] = 0;
    OS_RestoreInterrupts(s);
}
