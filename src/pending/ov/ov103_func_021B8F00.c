/*
 * function: func_021B8F00
 * address: 0x021B8F00
 * packet: pkt_ov103_021B8F00
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note 2026-10-04 wD2 lane01: still 136 bytes. Also tried iabs() inline helper form with pa->x re-read in the loop (119 bytes, code 142 vs 160) and ax..by locals with iabs (122); a[i] via byte offset `off = i*8` (same as draft). Original is 8 bytes longer than any variant: it copies sum with `movs r3,#0` ... `adds r0,r3,#0` before the divide and loads a from [sp] twice in the loop.
 * note 2026-10-04: structure matches (four diffs computed before the abs tests, unsigned d1/d2 compare,
 *   u16 d, weights 100/80/50/30, _u32_div_f by 9). Residue is colouring only: original keeps sum in r3,
 *   i in r1, a+i*8 in r0, pa->x in ip, prologue loads pa/pb first; ours puts sum in r0 and orders spills
 *   differently (136 bytes differ). Tried declaration orders of ax/ay/bx/by/sum/i, for-init forms, u32/u16/int types.
 * symbols:
 *   _u32_div_f 0x0209C2B0 arm
 *
 * note 2026-10-05 (wD4 lane13): tried a[i].x via *(int *)((u8 *)a + i*8) with a[i].y struct (160 bytes, 145 differ, more spills), both fields raw (152), y raw only (160, 145 differ). Original reloads a before each of the two address forms and keeps sum in r3 (our sum lands in r0, ours addresses a+i*8 from the first reload). Still open: sum colour r3 and the double reload of a.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pt { int x, y; };
static inline int iabs(int v) { return v < 0 ? -v : v; }
u8 func_021B8F00(struct Pt *pa, struct Pt *a, struct Pt *pb, struct Pt *b)
{
    int ax, ay, bx, by;
    u32 sum;
    int i;
    ax = pa->x; ay = pa->y; bx = pb->x; by = pb->y;
    sum = 0;
    for (i = 1; i < 10; i++) {
        int dx1 = a[i].x - ax;
        int dy1 = a[i].y - ay;
        int dx2 = b[i].x - bx;
        int dy2 = b[i].y - by;
        u32 d1, d2;
        if (dy1 < 0) dy1 = -dy1;
        if (dx1 < 0) dx1 = -dx1;
        d1 = dx1 + dy1;
        if (dy2 < 0) dy2 = -dy2;
        if (dx2 < 0) dx2 = -dx2;
        d2 = dx2 + dy2;
        u16 d = (u16)(d1 > d2 ? d1 - d2 : d2 - d1);
        if (d == 0)
            sum += 100;
        else if (d == 1)
            sum += 80;
        else if (d == 2)
            sum += 50;
        else if (d >= 3 && d <= 5)
            sum += 30;
    }
    return (u8)(sum / 9);
}
