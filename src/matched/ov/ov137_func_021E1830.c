/*
 * function: func_021E1830
 * address: 0x021E1830
 * packet: pkt_ov137_021E1830
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E15DC 0x021E15DC thumb ov137
 *   d_021E1F04 0x021E1F04 data a4
 */
typedef unsigned short u16;
struct Range { u16 lo, hi; };
struct Entry { unsigned count; struct Range *ranges; };
extern struct Entry d_021E1F04[];
extern void func_021E15DC(int *, int);
int func_021E1830(char *p, int angle, int index)
{
    int tmp;
    unsigned a;
    unsigned count;
    unsigned b;
    struct Range *r;
    struct Entry *e;
    func_021E15DC(&angle, -*(int *)(p + 0x11c));
    func_021E15DC(&angle, -*(int *)(p + 0x124));
    tmp = angle;
    func_021E15DC(&tmp, -0x4000);
    a = tmp / 0x1000;
    tmp = angle;
    func_021E15DC(&tmp, 0x5000);
    b = tmp / 0x1000;
    e = &d_021E1F04[index];
    count = e->count;
    r = e->ranges;
    while (count) {
        if ((a >= r->lo && a <= r->hi) || (b >= r->lo && b <= r->hi))
            return 1;
        r++;
        count--;
    }
    return 0;
}
