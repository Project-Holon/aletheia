/*
 * function: func_021BC1D0
 * address:  0x021BC1D0
 * packet:   pkt_ov091_021BC1D0
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BDD78  0x021BDD78  thumb  ov091
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    char pad[0x27e];
    int *f;
} P;

extern int func_0201AA18(int);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BDD78(int, int, int, int);

int func_021BC1D0(P *p)
{
    u8 n;
    u8 i;
    n = func_0201AA18(*p->f);
    for (i = 0; i < n; i++) {
        int **q = &p->f;
        int e = (int)func_0201AB28((void *)*p->f, i);
        if (func_021BDD78(e, *(u16 *)((char *)*q + 0x44), 0, p->id) == 1)
            return i;
    }
    return -1;
}
