/*
 * file:     trial_house_p17.c
 * unit:     yes
 * function: func_021D07D8, func_021D07FC
 * address:  0x021D07D8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021D08D8  0x021D08D8  thumb  ov021
 */
struct Row;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char s8;

typedef struct S_021D07D8 {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    u8 rows[6][0x14];
} S_021D07D8;

typedef struct Row {
    u32 f0;
    int f4;
    u32 f8[3];
} Row;

typedef struct S_021D07FC {
    int *f0;
    int f4;
    u8 f8;
    s8 f9;
    s8 fA;
    u8 padB;
    Row rows[6];
} S_021D07FC;

extern void func_021D08D8(struct Row *r, int a);
void func_021D07D8(void *a, S_021D07D8 *s);
Row *func_021D07FC(S_021D07FC *s);


void func_021D07D8(void *a, S_021D07D8 *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        func_021D08D8((struct Row *)s->rows[i], s->f0[7]);
    }
}


Row *func_021D07FC(S_021D07FC *s)
{
    int i;

    for (i = 0; i < 6; i++) {
        if (s->rows[i].f0 == 0) {
            return &s->rows[i];
        }
    }
    return 0;
}
