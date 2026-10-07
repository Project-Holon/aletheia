/*
 * file:     weather_task_p27.c
 * unit:     yes
 * function: func_021A3190, func_021A31A4
 * address:  0x021A3190
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
 *   data_021D890C  0x021D890C  data
 */
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u16 a;
    u16 b;
} Pair;

typedef struct {
    Pair e[10];
} Row;

u16 func_021A3190(int i, int j);
int func_021A31A4(int i, int v);
extern const Row data_021D890C[];


/*
 * Halfword a of entry j in row i of the 10-entry table at 0x021D890C.
 *
 * Addresses are Black-image addresses.
 */
u16 func_021A3190(int i, int j)
{
    return data_021D890C[i].e[j].a;
}


/*
 * Looks up v in the b column of row i and returns the matching a, else 1.
 *
 * Addresses are Black-image addresses.
 */
int func_021A31A4(int i, int v)
{
    const Pair *e;
    int k;

    k = 0;
    e = data_021D890C[i].e;
    for (; k < 10; k++, e++) {
        if (e->b == v)
            return e->a;
    }
    return 1;
}
