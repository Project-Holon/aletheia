/*
 * file:     event_field_proclink_p28.c
 * unit:     yes
 * function: func_02161D18, func_02161D64, func_02161D98, func_02161DC4
 * address:  0x02161D18
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012984 0x02012984 thumb
 *   func_02169100 0x02169100 thumb ov010
 *   func_02169110 0x02169110 thumb ov010
 *   func_02161C84 0x02161C84 thumb ov010
 *   func_02013A80  0x02013A80  thumb
 *   func_02161E78 0x02161E78 thumb ov010
 *   func_02161ECC  0x02161ECC  thumb
 */
#include "../../matched/include/Obj12047.h"
#include "../../matched/include/Obj12329.h"

struct BigObj;
struct Ctx;
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012984(const struct BigObj *p);
extern int func_02169100(int);
extern int func_02169110(int);
extern void func_02161C84(int, int, int, u8, u32, u8, u8, int);
extern int func_02013A80();
extern void func_02161E78(void *a0);
extern int func_02161ECC(char *);
void func_02161D18(int a, int b, u8 c, u8 d);
int func_02161D64(int a0);
void func_02161D98(char *p);
char *func_02161DC4(char *p, int id, unsigned mode);

/*
 * Padding: two zero alignment bytes after the 74-byte function.
 * Lever: c and d are u8, as in matched caller ov010_func_02161B90.c;
 * this puts the c home store before r0 is assigned b for the first call.
 */
void func_02161D18(int a, int b, u8 c, u8 d)
{
    int r4 = (int)func_020120F4((const struct Ctx *)b);
    int r6 = func_02169100(r4);
    int r7 = func_02169110(r4);
    int r0 = func_02012984((const struct BigObj *)r4);
    func_02161C84(a, b, c, d, 0, (u8)r6, (u8)r7, r0);
}


int func_02161D64(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
a0 = ((struct Obj12047 *)t4)->f2;
    if (a0 != 1) goto loc_02161D7E;
loc_02161D6E:
a0 = 0;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D76:
a0 = 1;
a1 = 1;
    a0 = func_02013A80(a0, a1);
loc_02161D7E:
a0 = ((struct Obj12047 *)t4)->f2;
    if (a0 != 0) goto loc_02161D94;
loc_02161D84:
a0 = 0;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D8C:
a0 = 1;
a1 = 0;
    a0 = func_02013A80(a0, a1);
loc_02161D94:
    return a0;}

void func_02161D98(char *p)
{
    int i;
    char *b;
    char *a;
    ((struct Obj12329 *)p)->f0 = 0;
    ((struct Obj12329 *)p)->f2 = 2;
    a = p + 8;
    b = p + 0xF8;
    for (i = 0; i < 10; i++) {
        func_02161E78((unsigned char *)(a + i * 24));
        func_02161E78((unsigned char *)(b + i * 24));
    }
}


char *func_02161DC4(char *p, int id, unsigned mode)
{
    int i;
    char *b;
    char *a;
    unsigned m1;

    m1 = mode - 1;
    a = p + 8;
    i = 0;
    b = p + 0xF8;

    for (; i < 10; i++) {
        if (mode == 0 || mode == 2) {
            if (func_02161ECC(a + i * 0x18) != 0 && (u8)p[i * 0x18 + 9] == id)
                return p + 8 + i * 0x18;
        }
        if (m1 <= 1) {
            if (func_02161ECC(b + i * 0x18) != 0 && (u8)p[i * 0x18 + 0xF9] == id)
                return p + 0xF8 + i * 0x18;
        }
    }
    return 0;
}
