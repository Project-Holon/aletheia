/*
 * file:     unit_021C0970_p02.c
 * unit:     yes
 * function: func_021C0E64, func_021C0E8C, func_021C0EA0, func_021C0EC8, func_021C0ED8, func_021C0EF0, func_021C0F0C, func_021C0F20
 * address:  0x021C0E64
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
 *   Language                         0x021DE56C  data
 *   g_021DE56C     0x021DE56C  data
 */
#include "../../matched/include/G_UtilState.h"

struct LANG {
    char pad[0x10];
    void *f10;
    void *f14;
};

struct Ov016Bits8 {
    char pad[8];
    unsigned int f : 4;
};

void DWCi_GetParam_(void **param0, void **param1);
void func_021C0E8C(unsigned int a, unsigned int b);
void func_021C0EA0(unsigned int *a, unsigned int *b);
unsigned char func_021C0EC8(void);
unsigned int func_021C0ED8(void);
int func_021C0EF0(unsigned int v);
void func_021C0F0C(void);
unsigned char func_021C0F20(void);
extern struct LANG Language;
extern struct UtilState g_021DE56C;


void DWCi_GetParam_(void **param0, void **param1)
{
    if (param0)
        *param0 = Language.f10;
    if (param1)
        *param1 = Language.f14;
}

/*
 * Store two words into fields +0x18 and +0x1c of the global object.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0E8C.c \
 *       --func func_021C0E8C --addr 0x021C0E8C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0E8C(unsigned int a, unsigned int b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    p[6] = a;
    p[7] = b;
}

/*
 * Hand back fields +0x18 and +0x1c through two optional out pointers.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EA0.c \
 *       --func func_021C0EA0 --addr 0x021C0EA0 --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0EA0(unsigned int *a, unsigned int *b)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    if (a)
        *a = p[6];
    if (b)
        *b = p[7];
}

/*
 * Read the first byte of the global object at 0x021DE56C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EC8.c \
 *       --func func_021C0EC8 --addr 0x021C0EC8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned char func_021C0EC8(void)
{
    return *(unsigned char *)0x021DE56C;
}


/*
 * Low nibble of the word at +0x08 of the global object (4-bit field).
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0ED8.c \
 *       --func func_021C0ED8 --addr 0x021C0ED8 --region ov016 --cc dsi/1.1p1 --arm
 */
unsigned int func_021C0ED8(void)
{
    struct Ov016Bits8 *p = (struct Ov016Bits8 *)0x021DE56C;
    return p->f;
}

/*
 * Test the argument against bits 4.. of the word at +0x08.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0EF0.c \
 *       --func func_021C0EF0 --addr 0x021C0EF0 --region ov016 --cc dsi/1.1p1 --arm
 */
int func_021C0EF0(unsigned int v)
{
    unsigned int *p = (unsigned int *)0x021DE56C;
    return (v & (p[2] >> 4)) != 0;
}

/*
 * Set byte +0x01 of the global object to 1.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_021C0F0C.c \
 *       --func func_021C0F0C --addr 0x021C0F0C --region ov016 --cc dsi/1.1p1 --arm
 */
void func_021C0F0C(void)
{
    unsigned char *p = (unsigned char *)0x021DE56C;
    p[1] = 1;
}


/*
 * sdk:      kDWCi_Language (libdwcutil.TWL.HYB.a main.o)
 */
unsigned char func_021C0F20(void)
{
    if ((*(unsigned char *)&g_021DE56C) == 6)
        return 0x38;
    if ((*(unsigned char *)&g_021DE56C) == 1) {
        if (!((*(unsigned int *)((char *)&(*(unsigned char *)&g_021DE56C) + 8) >> 4) & 2))
            return 0x37;
    }
    return (*(unsigned char *)&g_021DE56C) + 0x31;
}
