/*
 * function: func_021621C0
 * address: 0x021621C0
 * packet: pkt_ov010_021621C0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02161DC4 0x02161DC4 thumb ov010
 */
typedef unsigned short u16;
typedef struct { unsigned x; u16 b; u16 t; } S;
extern char *func_02161DC4(char *, int, unsigned);
int func_021621C0(int unused, char *p, const S *s, S *out)
{
    out->x = s->x;
    out->b = s->b;
    if (func_02161DC4(p, s->b, 1) != 0) out->t = 2;
    else out->t = 3;
    return 1;
}
