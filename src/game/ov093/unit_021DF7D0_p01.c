/*
 * file:     unit_021DF7D0_p01.c
 * unit:     yes
 * function: func_021DF7E8, func_021DF7F4
 * address:  0x021DF7E8
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
 *   func_021DF93C  0x021DF93C  thumb  ov093
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021D7D18  0x021D7D18  thumb  ov093
 */
typedef struct Word { unsigned int v; } Word;

typedef struct Rec {
    int f00;
    int f04;
    Word f08;
    unsigned char pad0c[3];
    unsigned char id;
} Rec;

void func_021DF93C(int, int, int, int);
extern int func_021D775C(int key);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C88C8(void *a, void *b);
extern Word func_021D7D18(int x);
void func_021DF7E8(int a, int b, int c);
void func_021DF7F4(void *self, void *q, int id);


void func_021DF7E8(int a, int b, int c)
{
    func_021DF93C(a, b, c, 3);
}


/*
 * Twin of func_021DF548 with kind 5.
 */
void func_021DF7F4(void *self, void *q, int id)
{
    Rec *r;
    unsigned char tag;

    if (id != func_021D775C(2))
        return;
    tag = func_021D775C(3);
    r = (Rec *)func_021C88A4(q, 12, tag);
    r->id = id;
    r->f04 = 5;
    r->f08 = func_021D7D18(5);
    func_021C88C8(q, r);
}
