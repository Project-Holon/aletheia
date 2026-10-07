/*
 * file:     unit_021DF48C_p02.c
 * unit:     yes
 * function: func_021DF51C, func_021DF548
 * address:  0x021DF51C
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
 *   func_021D5444  0x021D5444  thumb  ov093
 *   func_021D7704  0x021D7704  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 */
struct QF;
typedef unsigned char u8;

typedef unsigned short u16;

typedef struct Word { unsigned int v; } Word;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    unsigned char pad0c[3];
    unsigned char id;
} Rec;

extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5444(struct QF *p);
extern void func_021D7704(int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern Word func_021D7D18(int x);
void func_021DF51C(int a, int b, int c);
void func_021DF548(void *self, void *q, int id);

void func_021DF51C(int a, int b, int c)
{
    if (c == func_021D775C(3) && func_021D5444(func_021C7CF4((int *)b, c)) == 0x19)
        func_021D7704(0x35, 2 << 12);
}


void func_021DF548(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != func_021D775C(2))
        return;
    tag = func_021D775C(3);
    r = (Rec *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 1;
    r->f08 = func_021D7D18(1);
    func_021C88C8(q, r);
}
