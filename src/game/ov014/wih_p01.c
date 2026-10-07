/*
 * file:     wih_p01.c
 * unit:     yes
 * function: func_02177C1C, func_02177C4C
 * address:  0x02177C1C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02178E4C 0x02178E4C thumb ov014
 *   func_02179368 0x02179368 thumb ov014
 *   func_02178E38 0x02178E38 thumb ov014
 *   func_021795A4 0x021795A4 thumb ov014
 *   g_021797A4     0x021797A4  data   a4
 *   d_0217967C     0x0217967C  data   a2
 *   func_0203D798  0x0203D798  arm
 *   func_02179024  0x02179024  thumb  ov014
 *   func_0208F1B4  0x0208F1B4  arm
 *   func_0217778C  0x0217778C  thumb  ov014
 *   func_02179288  0x02179288  thumb  ov014
 *   func_0217727C  0x0217727C  thumb  ov014
 */
#include "../../matched/include/Obj03088.h"
#include "../../matched/include/G_W.h"

typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

extern int func_02178E4C(void);
extern int func_02179368(int a, unsigned short b, int c);
extern u16 func_02178E38(void);
extern unsigned short func_021795A4(void);
extern void *func_0203D798(void);
extern u16 func_02179024(void);
extern u16 func_0208F1B4(void);
extern void func_0217778C(void);
extern int func_02179288(int mode, u16 a, int b, u16 c);
extern void func_0217727C(u32 *p, u32 v);
int func_02177C1C(void);
int func_02177C30(int a, unsigned int b, int c);
unsigned int func_02177C3C(void);
int func_02177C44(void);
void func_02177C4C(u8 *p);
extern struct W *g_021797A4;
extern u16 d_0217967C[2];

/*
 * evidence: C30 truncates r1 to u16 at the tail call; its extern reflects that caller width.
 */
int func_02177C1C(void) { if (func_02178E4C() == 2) return 1; return 0; }

int func_02177C30(int a, unsigned int b, int c) { return func_02179368(a, b, c); }

unsigned int func_02177C3C(void) { return func_02178E38(); }

int func_02177C44(void) { return func_021795A4(); }


void func_02177C4C(u8 *p)
{
    u16 buf[2];
    u8 *st;
    int r6;

    int mode = func_02178E4C();

    buf[0] = d_0217967C[0];
    buf[1] = d_0217967C[1];
    if (mode == 7) {
        st = func_0203D798();
        p[0xCEA] = 0;
        p[0xCEF] = 0;
        p[0xCE9] = 0;
        p[0xCE8] = 0;
        r6 = func_02179024();
        if (p[0xCE6] == 0xFF)
            p[0xCE6] = r6;
        else
            r6 = p[0xCE6];
        if (st[0x66] != 0)
            ((struct Obj03088 *)p)->fC68 = func_0208F1B4();
        func_0217778C();
        func_02179288(buf[st[0x64]], ((struct Obj03088 *)p)->fC68, r6, st[0x60] - 1);
        func_0217727C((u32 *)((u8 *)g_021797A4), 0);
    }
}
