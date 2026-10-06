/*
 * function: func_021BD308
 * address: 0x021BD308
 * packet: pkt_ov208_021BD308
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BD7F8 0x021BD7F8 thumb
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
struct Ov208Item { char b[0x38]; };
struct Ov208Mgr { int idx; unsigned count; int state; int fc; int f10; char f14[0x14]; struct Ov208Item items[1]; };
extern int func_021BD7F8(char *p);
int func_021BD308(struct Ov208Mgr *m)
{
    if (m->state == 1 && m->idx != -1)
        return func_021BD7F8((char *)(&m->items[m->idx]));
    return -1;
}
