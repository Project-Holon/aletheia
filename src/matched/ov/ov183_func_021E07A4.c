/*
 * function: func_021E07A4
 * address: 0x021E07A4
 * packet: pkt_ov183_021E07A4
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_020457B0 0x020457B0 arm
 *   d_021E3968 0x021E3968 data ov183
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Object { int capacity; int entries[4]; int unused; void *vector; void *a; void *b; void *c; };
extern char d_021E3968[];
extern void *func_02030734(u16, u32, int, const char *, u16);
extern void *func_020457B0(u32, u16);
struct Object *func_021E07A4(int heap, int n, void *a, void *b, void *c, int *entries)
{
    int i;
    struct Object *p;
    p = func_02030734(heap, 40, 0, d_021E3968, 192);
    p->a = a;
    p->b = b;
    p->capacity = n;
    p->vector = func_020457B0(n + 1, heap);
    p->c = c;
    for (i = 0; i < 3; i++) p->entries[i] = entries[i];
    p->entries[i] = entries[i - 1];
    return p;
}
