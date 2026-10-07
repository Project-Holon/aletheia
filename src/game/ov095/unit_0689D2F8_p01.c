/*
 * file:     unit_0689D2F8_p01.c
 * unit:     yes
 * function: func_0689D2F8, func_0689D320
 * address:  0x0689D2F8
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0689D448 0x0689D448 thumb ov095
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 a, b, c; } Rec;

typedef struct { Rec r[6]; u8 idx[6]; } T;

extern void func_0689D448(T *, int, int);
void func_0689D2F8(u8 *p, int b);
void func_0689D320(T *p, int b, int c, int d);

/*
 * note: follower after non-C veneer 0x0689D2E8; code ends at 0x0689D320.
 */
void func_0689D2F8(u8 *p, int b)
{
    u32 i;
    Rec *q;
    for (i = 0; i < 6; i++) {
        q = (Rec *)(p + i * 3);
        if (q->a != 0 && b == q->c) {
            q->c = 31;
            return;
        }
    }
}

void func_0689D320(T *p, int b, int c, int d)
{
    p->r[b].c = c;
    p->idx[c] = b;
    func_0689D448(p, b, d);
}
