/*
 * file:     unit_021C7768_p03.c
 * unit:     yes
 * function: func_021C7ABC, func_021C7B34, func_021C7C74
 * address:  0x021C7ABC
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021C78A0  0x021C78A0  arm  ov016
 *   d_021DE5E4     0x021DE5E4  data
 *   func_021CFE18 0x021CFE18 arm ov016
 *   func_021C0EA0 0x021C0EA0 arm ov016
 *   func_020588D0 0x020588D0 arm
 *   g_021DA5CC 0x021DA5CC data
 *   g_021DE5E4 0x021DE5E4 data
 *   func_021D1568  0x021D1568  arm  ov016
 *   func_021CFFAC  0x021CFFAC  arm  ov016
 *   func_021D1524  0x021D1524  arm  ov016
 *   func_021C0E40  0x021C0E40  arm  ov016
 *   func_021C7CA0  0x021C7CA0  arm  ov016
 */
#include "../../matched/include/G_MemSsea.h"

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    char pad0[8];
    char addr[4][3];
} MemSsea;

typedef struct { char c[4]; } Val;

void func_021C78A0(void);
extern void func_021CFE18(char *adr, u8 *buf);
extern void func_021C0EA0(unsigned int *a, unsigned int *b);
extern int func_020588D0(u8 *address);
extern signed char func_021D1568(void);
extern void func_021CFFAC(unsigned int v);
extern void func_021D1524();
extern void func_021C0E40(unsigned int v);
extern void func_021C7CA0();
void func_021C7ABC(void);
int func_021C7B34(void);
void func_021C7C74(void);
extern struct MemSsea *d_021DE5E4;
extern Val g_021DA5CC;
extern MemSsea *g_021DE5E4;


/*
 * Sanitises four three-byte rows of a global buffer: every leading byte that
 * is NUL, space or '0' becomes a space, except the third column which becomes
 * '0'; the run stops at the first other byte.
 */
void func_021C7ABC(void)
{
    int i;

    for (i = 0; i < 4; i++) {
        char *row = ((char *)d_021DE5E4) + 8 + i * 3;
        int j;
        for (j = 0; j < 3; j++) {
            u8 c = row[j];
            if (c != 0x30 && c != 0x20 && c != 0)
                break;
            row[j] = (j == 2) ? 0x30 : 0x20;
        }
    }
    func_021C78A0();
}


/*
 * sdk:      isCorrect (libdwcutil.TWL.HYB.a(sceneseteditaddr))
 */
int func_021C7B34(void)
{
    Val VAL = g_021DA5CC;
    u8 *c;
    int prm;
    int i;
    int j;
    u8 buf[4];
    int b;

    for (i = 0; i < 4; i++) {
        c = (u8 *)g_021DE5E4->addr[i];
        if (c[0] == ' ')
            continue;
        for (j = 0; j < 3; j++) {
            if (c[j] > (u8)VAL.c[j])
                return 0;
            if (c[j] < (u8)VAL.c[j])
                break;
        }
    }
    func_021CFE18(g_021DE5E4->addr[0], buf);
    b = 0;
    func_021C0EA0((unsigned int *)((void **)&prm), 0);
    if (prm == 1) {
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 8; j++) {
                if (b != 0) {
                    if (buf[i] & (1 << (7 - j)))
                        return 0;
                } else {
                    if ((buf[i] & (1 << (7 - j))) == 0)
                        b = 1;
                }
            }
        }
        return 1;
    }
    if (func_020588D0(buf))
        b = 1;
    return b;
}


void func_021C7C74(void)
{
    if (func_021D1568())
        return;
    func_021CFFAC(6);
    func_021D1524();
    func_021C0E40((unsigned int)func_021C7CA0);
}
