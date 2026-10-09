/*
 * file:     unit_0689D0FC.c
 * unit:     yes
 * function: func_0689D0FC, func_0689D118, func_0689D134, func_0689D15C, func_0689D174, func_0689D184, func_0689D1A0, func_0689D1BC, func_0689D1D4
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


/* One 0x31-byte slot: a count, 24 flag bytes, 24 value bytes (31 = unset). */
typedef struct {
    u8 n;
    u8 a[24];
    u8 b[24];
} Slot;

void func_0689D15C(Slot *s, u8 v)
{
    u8 *q;

    if (s->n < 24) {
        q = (u8 *)s + s->n;
        q[25] = v;
        q[1] = 0;
        s->n++;
    }
}


u8 func_0689D174(Slot *s, u32 i)
{
    if (i < 4)
        return s[i].n;
    return 0;
}


u8 func_0689D184(Slot *s, u32 i, u32 j)
{
    if (i < 4 && j < s[i].n)
        return s[i].b[j];
    return 0x1f;
}


u8 func_0689D1A0(Slot *s, u32 i, u32 j)
{
    if (i < 4 && j < s[i].n)
        return s[i].a[j];
    return 0;
}


void func_0689D1BC(Slot *s, u32 i, u32 j)
{
    if (i < 4 && j < s[i].n)
        s[i].a[j] = 1;
}


u8 func_0689D1D4(Slot *s)
{
    u32 i;

    for (i = 0; i < 4; i++) {
        if (s[i].n != 0)
            return s[i].b[s[i].n - 1];
    }
    return 0x1f;
}
