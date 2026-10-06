/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/001_02007664.s.
 *
 * unit:     yes
 * address:  0x02007CB0
 * packet:   pkt_02007B54
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_02007CB0, sub_02007CB8, sub_02007CC8, sub_02007D00,
 *           sub_02007D6C, sub_02007D94, sub_02007DF8, sub_02007E3C,
 *           sub_02007E50, sub_02007ECC, sub_02007EF8, sub_02007F1C,
 *           sub_02007F68, sub_02007F7C, sub_02007FA0, sub_02007FB8,
 *           sub_02007FD0, sub_02007FF4, sub_02008038, sub_02008058,
 *           sub_020080A0, sub_020080FC, sub_0200816C, sub_020081DC,
 *           sub_0200823C
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_02020FE4  0x02020FE4  thumb
 *   func_02021288  0x02021288  thumb
 *   func_0202130C  0x0202130C  thumb
 *
 * The item bag: a 0x9C0 byte block holding five arrays of `{u16 id; u16
 * qty;}` entries, and the add, take, count and sort routines over them.  The
 * file boundary at the low end is the block file opening idiom: sub_02007CB0
 * returns 0x9C0 and sub_02007CB8 fills exactly 0x9C0 bytes with zero, and the
 * function before it belongs to "perapvoice.c".
 *
 * The five arrays are named by the two switches, sub_02007D00 and the
 * unlabelled sub_020081DC, which agree entry for entry:
 *
 *   id 0   offset 0x000   0x136 entries
 *   id 4   offset 0x4D8   0x053 entries
 *   id 2   offset 0x624   0x06D entries
 *   id 1   offset 0x7D8   0x030 entries
 *   id 3   offset 0x898   0x040 entries
 *
 * and 0x898 + 0x40 * 4 is 0x998, which is the whole block bar 0x28 trailing
 * bytes.  The case bodies of both switches are emitted in the order 4, 0, 3,
 * 1, 2, and per docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md
 * that order is the order the source wrote the case labels in, so it is kept
 * here.  Neither switch has a `default:` that sets the count, and
 * sub_020081DC reads an uninitialised count on an unknown id: the dispatch
 * chain branches past the merged tail rather than into it, which is the
 * reading in docs/idioms/switch-arms-tail-merge.md.
 *
 * Eleven of the twenty-five functions carry no label, all of them because
 * they save no lr.  sub_020081DC is the largest of them, 96 bytes of switch
 * plus table plus pool sitting between two literal pools in the listing.
 *
 * What the range teaches:
 *
 *  - sub_02007DF8, sub_02007E50 and sub_02007F1C pass the address of a local
 *    pointer to sub_02007D6C after having already used that pointer for
 *    something else, and the compiler gives both uses the same stack slot.
 *    Writing them as two variables produces two slots and moves every offset
 *    in the frame, so the source really does reuse the one variable.
 *  - the loop bound in sub_02008058 and its two siblings is assigned after
 *    the induction variable, not before: `for (i = 0, lim = n - 1; ...)`.
 *    Written the other way round the compiler has no zero in hand at the
 *    point it needs one and materialises it from a literal pool, which costs
 *    four bytes of pool the original does not have.
 *  - sub_020080FC compares two calls to func_0202130C.  The first result is
 *    spilled across the second call and the comparison comes out `cmp r1, r0`
 *    with the spilled operand first, which is the same tell
 *    docs/idioms/cmp-operand-order-names-the-temporary.md records; here the
 *    spill is forced by the second call rather than by a named local, so the
 *    two calls can be written inline inside the `||`.
 *  - sub_02007ECC returns `&arr[i]` from a second `return` statement rather
 *    than through a merged local.  sub_02007D94, ten functions earlier, does
 *    use the merged form, and the difference is visible: the merged form
 *    reaches the shared epilogue with an extra `adds r0, rN, #0`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

#define NULL ((void *)0)

struct Item {
    u16 id;
    u16 qty;
};

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MI_CpuFill8(void *dest, u8 value, u32 size);

extern u32 func_02020FE4(void *a, u32 sel, u32 id);
extern u32 func_02021288(u32 a);
extern u32 func_0202130C(u32 id);

u32 sub_02007D00(u8 *base, u32 id, void **pp, u32 *pn);
u32 sub_02007D6C(u8 *base, u32 a, void **pp, u32 *pn, u16 d);
struct Item *sub_02007D94(struct Item *arr, u32 n, u16 id, u16 qty, u16 max);
struct Item *sub_02007DF8(u8 *base, u16 id, u16 qty, u16 d);
struct Item *sub_02007ECC(struct Item *arr, u32 n, u16 id, u16 qty);
struct Item *sub_02007EF8(u8 *base, u16 id, u16 qty, u16 d);
u32 sub_02007F7C(const struct Item *arr, u32 n);
void sub_02007FD0(struct Item *a, struct Item *b);
void sub_02007FF4(struct Item *arr, u32 n);
void sub_02008038(struct Item *arr, u32 n);
void sub_02008058(struct Item *arr, u32 n);
void sub_020080A0(struct Item *arr, u32 n);
void sub_020080FC(struct Item *arr, u32 n);

u32 sub_02007CB0(void)
{
    return 0x9C0;
}

void sub_02007CB8(void *p)
{
    MI_CpuFill8(p, 0, 0x9C0);
}

void sub_02007CC8(u8 *base, void *buf, u32 id, int save)
{
    void *p;
    u32 n;

    sub_02007D00(base, id, &p, &n);
    if (save) {
        MI_CpuCopy8(p, buf, n * 4);
    } else {
        MI_CpuCopy8(buf, p, n * 4);
    }
}

u32 sub_02007D00(u8 *base, u32 id, void **pp, u32 *pn)
{
    switch (id) {
    case 4:
        *pp = base + 0x4D8;
        *pn = 0x53;
        break;
    case 0:
        *pp = base;
        *pn = 0x136;
        break;
    case 3:
        *pp = base + 0x898;
        *pn = 0x40;
        break;
    case 1:
        *pp = base + 0x7D8;
        *pn = 0x30;
        break;
    case 2:
        *pp = base + 0x624;
        *pn = 0x6D;
        break;
    default:
        *pp = NULL;
        break;
    }
    return id;
}

u32 sub_02007D6C(u8 *base, u32 a, void **pp, u32 *pn, u16 d)
{
    u32 id = func_02020FE4((void *)a, 5, d);

    sub_02007D00(base, id, pp, pn);
    return id;
}

struct Item *sub_02007D94(struct Item *arr, u32 n, u16 id, u16 qty, u16 max)
{
    u32 i;
    u32 free = -1;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            struct Item *e = &arr[i];

            if (qty + e->qty > max) {
                e = NULL;
            }
            return e;
        }
        if (free == -1 && arr[i].id == 0 && arr[i].qty == 0) {
            free = i;
        }
    }
    if (free == -1) {
        return NULL;
    }
    return &arr[free];
}

struct Item *sub_02007DF8(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    if (sub_02007D6C(base, id, &p, &n, d) == 2) {
        return sub_02007D94(p, n, id, qty, 1);
    }
    return sub_02007D94(p, n, id, qty, 999);
}

u32 sub_02007E3C(u8 *base, u16 id, u16 qty, u16 d)
{
    if (sub_02007DF8(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 sub_02007E50(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;
    void *q;
    u32 m;
    u16 old;
    u32 kind;

    p = sub_02007DF8(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    old = ((struct Item *)p)->qty;
    ((struct Item *)p)->id = id;
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty + qty);
    kind = sub_02007D6C(base, id, &p, &n, d);
    if (kind == 3) {
        sub_020080A0(p, n);
    } else if (kind == 2) {
        sub_020080FC(p, n);
    } else if (old == 0) {
        sub_02007D00(base, kind, &q, &m);
        m = sub_02007F7C(q, m);
        sub_02007FF4(q, m);
    }
    return 1;
}

struct Item *sub_02007ECC(struct Item *arr, u32 n, u16 id, u16 qty)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (id == arr[i].id) {
            if (arr[i].qty < qty) {
                return NULL;
            }
            return &arr[i];
        }
    }
    return NULL;
}

struct Item *sub_02007EF8(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    sub_02007D6C(base, id, &p, &n, d);
    return sub_02007ECC(p, n, id, qty);
}

u32 sub_02007F1C(u8 *base, u16 id, u16 qty, u16 d)
{
    void *p;
    u32 n;

    p = sub_02007EF8(base, id, qty, d);
    if (p == NULL) {
        return 0;
    }
    ((struct Item *)p)->qty = (u16)(((struct Item *)p)->qty - qty);
    if (((struct Item *)p)->qty == 0) {
        ((struct Item *)p)->id = 0;
    }
    sub_02007D6C(base, id, &p, &n, d);
    sub_02008058(p, n);
    return 1;
}

u32 sub_02007F68(u8 *base, u16 id, u16 qty, u16 d)
{
    if (sub_02007EF8(base, id, qty, d) != NULL) {
        return 1;
    }
    return 0;
}

u32 sub_02007F7C(const struct Item *arr, u32 n)
{
    u32 c = 0;
    u32 i;

    if (arr != NULL) {
        for (i = 0; i < n; i++) {
            if (arr[i].id != 0) {
                c++;
            }
        }
    }
    return c;
}

u32 sub_02007FA0(u8 *base, u32 id)
{
    void *p;
    u32 n;

    sub_02007D00(base, id, &p, &n);
    return sub_02007F7C(p, n);
}

u32 sub_02007FB8(u8 *base, u16 id, u16 d)
{
    struct Item *e = sub_02007EF8(base, id, 1, d);

    if (e == NULL) {
        return 0;
    }
    return e->qty;
}

void sub_02007FD0(struct Item *a, struct Item *b)
{
    struct Item t;

    t = *a;
    *a = *b;
    *b = t;
}

void sub_02007FF4(struct Item *arr, u32 n)
{
    struct Item t;
    int i;

    t.id = 0;
    if (n <= 1) {
        return;
    }
    for (i = (int)n - 1; i >= 0; i--) {
        if (t.id == 0) {
            MI_CpuCopy8(&arr[i], &t, sizeof(struct Item));
        } else {
            MI_CpuCopy8(&arr[i], &arr[i + 1], sizeof(struct Item));
        }
    }
    MI_CpuCopy8(&t, arr, sizeof(struct Item));
}

void sub_02008038(struct Item *arr, u32 n)
{
    u32 i;

    for (i = 0; i < n; i++) {
        if (arr[i].id == 0) {
            arr[i].qty = 0;
        }
    }
}

void sub_02008058(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_020080A0(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 && arr[i].id > arr[j].id)) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_020080FC(struct Item *arr, u32 n)
{
    u32 lim;
    u32 i;
    u32 j;

    sub_02008038(arr, n);
    for (i = 0, lim = n - 1; i < lim; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[i].qty == 0 ||
                (arr[j].qty != 0 &&
                 func_0202130C(arr[i].id) > func_0202130C(arr[j].id))) {
                sub_02007FD0(&arr[i], &arr[j]);
            }
        }
    }
}

void sub_0200816C(u8 *base)
{
    void *p;
    u32 n;

    sub_02007D00(base, 4, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 0, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 3, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 1, &p, &n);
    sub_02008058(p, n);
    sub_02007D00(base, 2, &p, &n);
    sub_02008058(p, n);
}

struct Item *sub_020081DC(u8 *base, u32 id, u32 index)
{
    u32 n;

    switch (id) {
    case 4:
        base += 0x4D8;
        n = 0x53;
        break;
    case 0:
        n = 0x136;
        break;
    case 3:
        base += 0x898;
        n = 0x40;
        break;
    case 1:
        base += 0x7D8;
        n = 0x30;
        break;
    case 2:
        base += 0x624;
        n = 0x6D;
        break;
    }
    if (index >= n) {
        return NULL;
    }
    return (struct Item *)(base + index * 4);
}

u32 sub_0200823C(u32 a)
{
    if (func_02021288(a) == 1) {
        return 1;
    }
    return 999;
}
