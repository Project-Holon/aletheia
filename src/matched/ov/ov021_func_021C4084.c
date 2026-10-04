/*
 * function: func_021C4084
 * address:  0x021C4084
 * packet:   pkt_ov021_021C4084
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_021C42F4  0x021C42F4  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u16 x, y; } P;

extern void func_0201ADD0(unsigned int species, int form, void *dest);
extern void func_021C42F4(u32 *p, u32 v);

void func_021C4084(u32 *p)
{
    P buf[26];
    P d, c, b, a;
    int i;
    int end;
    u32 dy, lim, cx;

    func_0201ADD0((u16)p[0], (u16)p[1], buf);
    i = 0;
    goto test;
body:
    d = a;
    c = a;
    dy = d.y;
    lim = p[2];
    cx = c.x;
    if (lim < dy)
        return;
    func_021C42F4(p, cx);
    i++;
test:
    a = buf[i];
    b = a;
    end = 0;
    if (b.x == 0xffff && b.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}
