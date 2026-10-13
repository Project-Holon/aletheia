/*
 * file:     unit_0689D4F0.c
 * unit:     yes
 * function: func_0689D4F0, func_0689D544, func_0689D558, func_0689D588, func_0689D59C, func_0689D5C8, func_0689D5F4
 * address:  0x0689D4F0
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
 *   func_021B86A0  0x021B86A0  thumb
 */
typedef unsigned char u8;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Rec;

typedef unsigned int u32;

typedef struct {
    Rec r[6];
    u8 idx[6];
} T;

extern int func_021B86A0(void *, int);
void func_0689D4F0(Rec *p, int i, int j);
void func_0689D544(T *a, int b);
u8 func_0689D558(u8 *a, u8 key, u8 *out);
int func_0689D588(u8 *p, u8 key);
int func_0689D59C(u8 *p, void *q, u8 key);
u8 func_0689D5C8(u8 *base, int key);
int func_0689D5F4(u8 *p, int i);


void func_0689D4F0(Rec *p, int i, int j)
{
    Rec t;

    t = p[i];
    p[i] = p[j];
    p[j] = t;
    func_0689D544((T *)p, i);
    func_0689D544((T *)p, j);
}


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
u8 func_0689D558(u8 *a, u8 key, u8 *out)
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


/*
 * note: Two-byte zero alignment padding follows; contiguous scratch TU is EXACT.
 */
int func_0689D588(u8 *p, u8 key)
{
    if (func_0689D5C8(p, key) != 6) return 1;
    return 0;
}


int func_0689D59C(u8 *p, void *q, u8 key)
{
    int i;
    i = func_0689D5C8(p, key);
    if (i != 6) return func_021B86A0(q, i);
    return 0;
}


/*
 * Scan a table of 3-byte records: find the first record whose first byte is
 * non-zero and whose third byte equals `key`; return its index (0..5), or 6.
 * Addresses are Black-image addresses.
 */
u8 func_0689D5C8(u8 *base, int key)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (base[i * 3] != 0 && base[i * 3 + 2] == key)
            return (u8)i;
    }
    return 6;
}


/*
 * ABI: reads r0 base and full-word r1 index; byte load returned in r0.
 */
int func_0689D5F4(u8 *p, int i) { return (p + i)[18]; }
