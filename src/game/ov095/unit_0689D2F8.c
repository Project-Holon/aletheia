/*
 * file:     unit_0689D2F8.c
 * unit:     yes
 * function: func_0689D2F8, func_0689D320, func_0689D338, func_0689D448
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
 *   func_021B9AB0  0x021B9AB0  thumb
 *   func_021B9AC8  0x021B9AC8  thumb
 *   func_021D5440  0x021D5440  thumb
 *   func_021D5B68  0x021D5B68  thumb
 *   func_0689D544 0x0689D544 thumb ov095
 *   func_021B9934  0x021B9934  thumb
 *   func_021B9A24  0x021B9A24  thumb
 *   func_021D6DCC  0x021D6DCC  thumb
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct { u8 a, b, c; } Rec;

typedef struct { Rec r[6]; u8 idx[6]; } T;

extern int func_021B9AB0(int);
extern int func_021B9AC8(int);
extern int func_021D5B68(int);
extern int func_021D5440(int);
extern void func_0689D544(T *, int);
extern int func_021B9A24(int, int);
extern int func_021B9934(int, int);
extern int func_021D6DCC(int, int);
void func_0689D2F8(T *p, int b);
void func_0689D320(T *p, int b, int c, int d);
void func_0689D338(T *p, u32 size, u32 category, int key, int extra);
void func_0689D448(T *a, int b, int c);



/*
 * note: follower after non-C veneer 0x0689D2E8; code ends at 0x0689D320.
 */
void func_0689D2F8(T *p, int b)
{
    u32 i;
    Rec *q;
    for (i = 0; i < 6; i++) {
        q = &p->r[i];
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


/*
 * note: 2026-10-05 closed from an older DIFF draft (docs/notes/pkt_ov095_0689D338.c.txt).
 *   Fixes: idx is a separate u8[5] local declared before the 3-byte temp (frame is 8 bytes;
 *   the original overwrites the pad slot when six records match), and the record swap is
 *   written with plain struct element copies p->r[idx[k]] instead of raw casts.
 *   The else store uses i after the loop (i == 6, one record past the table): a bug of the
 *   original, reproduced. Callees 0689D408..0689D438 are linker veneers (int results).
 */
void func_0689D338(T *p, u32 size, u32 category, int key, int extra)
{
    u32 n;
    u32 i;
    int first;
    int second;
    u8 idx[5];
    Rec tr;
    if (size <= 1) return;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (category == p->r[i].b) idx[n++] = i;
    }
    first = func_021B9AB0(size);
    second = func_021B9AC8(size);
    tr = p->r[idx[0]];
    p->r[idx[first]] = p->r[idx[second]];
    p->r[idx[second]] = tr;
    if (func_021D5B68(key) == 0)
        func_0689D320(p, idx[0], func_021D5440(key), extra);
    else
        p->r[i].c = 0x1f;
    for (i = 0; i < n; i++) func_0689D544(p, idx[i]);
}


void func_0689D448(T *a, int b, int c)
{
    u32 k;
    u32 i;
    Rec *q;

    k = a->r[b].c;
    if (k == 0x1f)
        return;
    for (i = 0; i < 6; i++) {
        q = &a->r[i];
        if (q->c == 0x1f || k == q->c)
            continue;
        if (func_021B9A24(q->c, k) != 0)
            continue;
        func_021D6DCC(func_021B9934(c, q->c), k);
        func_021D6DCC(func_021B9934(c, k), q->c);
    }
}
