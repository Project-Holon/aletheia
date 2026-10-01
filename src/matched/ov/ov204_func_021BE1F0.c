/*
 * function: func_021BE1F0
 * address: 0x021BE1F0
 * packet: pkt_ov204_021BE1F0
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BF094 0x021BF094 thumb ov204
 *   func_021BF00C 0x021BF00C thumb ov204
 *   d_021C09D0 0x021C09D0 data a4
 */
typedef struct Row { unsigned tag; char data[20]; } Row;
extern Row *func_021BF094(unsigned);
extern int func_021BF00C(void *, void *);
extern int (*const d_021C09D0[])(void *);
int func_021BE1F0(char *p, int unused, unsigned *q)
{
    Row *row = func_021BF094(*(unsigned *)(p + 0x1c)) + *(unsigned *)(p + 0xa0);
    if (!d_021C09D0[*q](p)) row++;
    if (row) func_021BF00C(p, row);
    *(unsigned *)(p + 0xa0) += 2;
    return 1;
}
