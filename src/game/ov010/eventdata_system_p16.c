/*
 * file:     eventdata_system_p16.c
 * unit:     yes
 * function: func_02162C54, func_02162C84
 * address:  0x02162C54
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
 *   func_02162AA4  0x02162AA4  thumb  ov010
 */
typedef unsigned char u8;

typedef unsigned short u16;

typedef signed short s16_02162C54;

typedef unsigned int u32;

typedef short s16_02162C84;

struct Sub {
    s16_02162C84 f0;
    s16_02162C84 f2;
    s16_02162C84 f4;
    u16 f6;
    u16 f8;
};

struct Box {
    u16 pad0[4];
    struct Sub s;
};

extern u16 func_02162AA4(int q, int m, int a, int b, u16 n);
int func_02162C54(u8 *p);
void func_02162C84(struct Box *b, int q, int *out);

/*
 * lever: case 0 falls through into default at the final shared return.
 */
int func_02162C54(u8 *p)
{
    switch (p[4]) {
    case 1: return 0;
    case 2: return 1;
    case 3: return 2;
    case 4: return 3;
    case 0:
    default: return 1;
    }
}


void func_02162C84(struct Box *b, int q, int *out)
{
    struct Sub *s = &b->s;
    int m = func_02162C54((u8 *)b);
    out[0] = b->s.f0 << 12;
    out[1] = s->f2 << 12;
    out[2] = s->f4 << 12;
    if (s->f6 > 1) {
        out[0] += func_02162AA4(q, m, 0, 0, s->f6) << 16;
    } else if (s->f8 > 1) {
        out[2] += func_02162AA4(q, m, 0, 0, s->f8) << 16;
    }
}
