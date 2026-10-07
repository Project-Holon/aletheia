/*
 * file:     wih_p05.c
 * unit:     yes
 * function: func_0217814C, func_02178168
 * address:  0x0217814C
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
 *   g_021797A8 0x021797A8 data ov014 a4
 *   func_02178198 0x02178198 thumb ov014
 *   func_0208F480 0x0208F480 arm
 *   func_02178138 0x02178138 thumb ov014
 */
typedef unsigned char u8;

typedef unsigned short u16;

extern void func_02178198(void *);
extern int func_0208F480(void (*)(void *), void *);
extern void func_02178138(int);
void func_0217814C(int error);
int func_02178168(void);
extern u8 *g_021797A8;

void func_0217814C(int error)
{
    if ((unsigned)(*(int *)(g_021797A8 + 0x1e70) - 9) > 1)
        *(int *)(g_021797A8 + 0x1e98) = error;
}

int func_02178168(void)
{
    int result;
    func_02178138(3);
    result = func_0208F480(func_02178198, g_021797A8);
    if (result != 2) {
        func_0217814C(result);
        func_02178138(9);
        return 0;
    }
    return 1;
}
