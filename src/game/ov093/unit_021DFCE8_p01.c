/*
 * file:     unit_021DFCE8_p01.c
 * unit:     yes
 * function: func_021DFDA4, func_021DFDEC
 * address:  0x021DFDA4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5D14  0x021D5D14  thumb  ov093
 *   func_021DD044  0x021DD044  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 */
typedef unsigned int u32;

typedef signed char    s8;

typedef struct Rec {
    int pad00;
    int f04;
    unsigned char pad08[4];
    unsigned char f0c;
    unsigned char pad0d[2];
    unsigned char f0f;
    unsigned char f10;
} Rec;

extern int func_021D775C(int key);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5D14(s8 *p, int i, int sign);
extern void func_021DD044(void *a, void *b, int c);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
void func_021DFDA4(int a, int b, int c);
void func_021DFDEC(void *self, void *q, int id);


void func_021DFDA4(int a, int b, int c)
{
    if (c == func_021D775C(4) && func_021D775C(0x46) == 0 && func_021D775C(0x16) == 0xc) {
        if (func_021D5D14(func_021C7CF4((int *)b, c), 1, 1) != 0) {
            func_021DD044((void *)a, (void *)b, c);
        }
    }
}


void func_021DFDEC(void *self, void *q, int id)
{
    Rec *r;

    if (id != func_021D775C(2))
        return;
    r = (Rec *)func_021C88A4(q, 14, id);
    r->f0f = 1;
    r->f10 = id;
    r->f04 = 1;
    r->f0c = 1;
    func_021C88C8(q, r);
}
