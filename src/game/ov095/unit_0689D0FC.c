/*
 * file:     unit_0689D0FC.c
 * unit:     yes
 * function: func_0689D0FC, func_0689D118, func_0689D134
 * address:  0x0689D0FC
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 b[0x31]; } E;

void func_0689D0FC(u8 *p);
void func_0689D118(u8 *p);
void func_0689D134(u8 *p);

void func_0689D0FC(u8 *p)
{
    u32 i;
    p[0] = 0;
    for (i = 0; i < 24; i++) {
        p[i + 25] = 31;
        p[i + 1] = 0;
    }
}

void func_0689D118(u8 *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        func_0689D0FC(p + i * 49);
    }
}

void func_0689D134(u8 *p)
{
    E *e = (E *)p;
    unsigned int i;
    for (i = 3; i != 0; i--) {
        e[i] = e[i - 1];
    }
    func_0689D0FC(p);
}
