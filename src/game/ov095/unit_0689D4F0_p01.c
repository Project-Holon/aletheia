/*
 * file:     unit_0689D4F0_p01.c
 * unit:     yes
 * function: func_0689D544, func_0689D558
 * address:  0x0689D544
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

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

void func_0689D544(T *a, int b);
u8 func_0689D558(u8 *a, int key, u8 *out);


void func_0689D544(T *a, int b)
{
    u32 v;

    v = a->r[b].c;
    if (v != 0x1f)
        a->idx[v] = b;
}


/*
 * Unlabelled leaf (push {r3-r6}, no lr) after func_0689D544 in the handed
 * extent.  Collects the indices of the 3-byte records whose first byte is
 * non-zero, second byte equals `key` and third byte is 0x1f; returns the count.
 */
u8 func_0689D558(u8 *a, int key, u8 *out)
{
    u32 n;
    u32 i;

    n = 0;
    for (i = 0; i < 6; i++) {
        if (a[i * 3] != 0 && key == a[i * 3 + 1] && a[i * 3 + 2] == 0x1f)
            out[n++] = i;
    }
    return n;
}
