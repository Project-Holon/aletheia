/*
 * file:     dwc_rap_p09.c
 * unit:     yes
 * function: func_02155C70, func_02155C8C, func_02155D2C
 * address:  0x02155C70
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02177270  0x02177270  arm
 *   func_0216B838  0x0216B838  arm
 *   func_0216B908  0x0216B908  arm
 *   func_02034714  0x02034714  arm
 *   func_02155374  0x02155374  thumb  ov009
 */
#include "../../matched/include/G__anon_Work.h"

typedef unsigned char u8;

typedef struct {
    char pad[0x764];
    int n;
    char pad2[0x7a8 - 0x768];
    u8 flag;
} G;

typedef unsigned int   u32;

extern void func_02082BCC(void *p, int v, int n);
int func_02177270(u8 a, int b);
unsigned char func_0216B838(void);
int func_0216B908(void);
void func_02034714(const char *expr, u32 line, const char *file);
extern void func_02155374(int v);
void func_02155C70(void);
void func_02155C8C(void);
void func_02155D2C(int e);
extern struct _anon_Work *g_021A8264;
extern G *d_021A8264;
extern char d_021A1C5C[];


/*
 * Clears the eight bytes at +0x784 of the block the module pointer holds.
 */
void func_02155C70(void)
{
    func_02082BCC(((char *)g_021A8264) + 0x784, 0, 8);
}


void func_02155C8C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
        func_02177270(i, 0);
    if (func_0216B838() == 0) {
        for (j = 0; j < d_021A8264->n; j++) {
            if (j != func_0216B838() && (func_0216B908() & (1 << j)) != 0) {
                if (func_02177270(j, 10000) == 0)
                    func_02034714(d_021A1C5C, 0, d_021A1C5C);
            }
        }
    } else {
        if (func_02177270(0, 10000) == 0)
            func_02034714(d_021A1C5C, 0, d_021A1C5C);
    }
    d_021A8264->flag = 1;
    func_02155C70();
}


/*
 * Enables slot 9 then calls the wakeup.
 */
void func_02155D2C(int e)
{
    func_02155374(9);
    func_02155C8C();
}
