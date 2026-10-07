/*
 * file:     unit_021B0D18_p03.c
 * unit:     yes
 * function: func_021B12FC, func_021B133C
 * address:  0x021B12FC
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   g_021B4B98     0x021B4B98  data  a4
 *   g_021B4BA0     0x021B4BA0  data  a4
 *   func_021B14A8  0x021B14A8  arm  ov013
 *   func_021B14F8  0x021B14F8  arm  ov013
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 */
struct Node;
typedef unsigned int   u32;

extern int OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(int s);
extern struct Node *func_021B14A8(u32 type);
extern u32 func_021B14F8(struct Node *n);
extern void func_021B2FE4(void *p);
void func_021B12FC(void);
void func_021B133C(unsigned int n);
extern struct {
    void *head;
    void *tail;
} g_021B4B98;
extern int g_021B4BA0[3];


void func_021B12FC(void)
{
    int s;
    int i;

    s = OS_DisableInterrupts();
    g_021B4B98.tail = 0;
    g_021B4B98.head = 0;
    for (i = 0; i < 3; i++) {
        g_021B4BA0[i] = 0;
    }
    OS_RestoreInterrupts(s);
}


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
