/*
 * file:     unit_0689C424.c
 * unit:     yes
 * function: func_0689C424, func_0689C464
 * address:  0x0689C424
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
 *   func_021C8838  0x021C8838  thumb
 *   func_021C8860  0x021C8860  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021E8B80  0x021E8B80  thumb
 *   d_0689E21C   0x0689E21C  data  ov095  a4
 */
typedef unsigned int u32;

typedef short s16;

typedef struct Ent {
    u32 key;
    s16 a;
    s16 b;
} Ent;

typedef unsigned short u16;

typedef struct Word { int v; } Word;

extern void func_021C8838(void *, int, u16);
extern int func_021D5440(void *);
extern void func_021C8860(void *, int);
extern int func_021E8B80(Word);
int func_0689C424(u32 key, int flag);
int func_0689C464(int a, Word b, void *c, unsigned char d, void *e);
extern Ent d_0689E21C[17];


int func_0689C424(u32 key, int flag)
{
    u32 i;
    int v;

    for (i = 0; i < 17; i++) {
        if (key == d_0689E21C[i].key) {
            if (flag != 0)
                v = d_0689E21C[i].b;
            else
                v = d_0689E21C[i].a;
            if (v < 0)
                return d_0689E21C[i].a;
            return v;
        }
    }
    return -1;
}


int func_0689C464(int a, Word b, void *c, unsigned char d, void *e)
{
    int f;
    int k;

    f = 1;
    if (d == 0)
        f = 0;
    k = func_0689C424(a, f);
    if (k >= 0) {
        func_021C8838(e, 2, k);
        func_021C8860(e, func_021D5440(c));
        if (f != 0)
            func_021C8860(e, d);
        switch (a) {
        case 8:
            func_021C8860(e, func_021E8B80(b));
            break;
        case 0x12:
            func_021C8860(e, 0x49);
            break;
        }
        return 1;
    }
    return 0;
}
