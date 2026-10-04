/*
 * function: func_021C3530
 * address:  0x021C3530
 * packet:   pkt_ov021_021C3530
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Learnset walk as in func_021C4084. Load-bearing: lv is read from the
 * first entry copy right after it is made (the value stays in the
 * register), mv from the second copy, and mv is u32/int (u16 sinks its
 * load to the call).
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_02018584  0x02018584  thumb
 *   func_020185C4  0x020185C4  thumb
 *   func_0201ADD0  0x0201ADD0  thumb
 *   func_021C3510  0x021C3510  thumb  ov021
 *   func_021C360C  0x021C360C  thumb  ov021
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct { u16 x, y; } P;

extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02017E40(void *mon, u32 id, u32 v);
extern u32 func_02018584(u16 a, u16 b, u16 c);
extern void func_020185C4(void *mon);
extern void func_0201ADD0(unsigned int a, int b, void *buf);
extern u32 func_021C3510(u32, u32);
extern void func_021C360C(void *a, u32 b);

void func_021C3530(void *mon, u32 b)
{
    P buf[26];
    P e, d, c, a;
    u32 species;
    u32 form;
    u32 max;
    int oldlv;
    int newlv;
    u32 exp;
    int i;
    int end;
    int lv;
    u32 mv;

    species = func_02017E1C(mon, 5, 0);
    form = func_02017E1C(mon, 0x6f, 0);
    max = func_02018584(species, form, 100);
    oldlv = func_02017E1C(mon, 0x9e, 0);
    exp = func_021C3510(func_02017E1C(mon, 8, 0), b);
    if (max < exp)
        exp = max;
    func_02017E40(mon, 8, exp);
    func_020185C4(mon);
    i = 0;
    newlv = func_02017E1C(mon, 0x9e, 0);
    func_0201ADD0((u16)species, (u16)form, buf);
    goto test;
body:
    e = a;
    lv = e.y;
    d = a;
    mv = d.x;
    if (newlv < lv)
        return;
    if (oldlv < lv)
        func_021C360C(mon, mv);
    i++;
test:
    a = buf[i];
    c = a;
    end = 0;
    if (c.x == 0xffff && c.y == 0xffff)
        end = 1;
    if (!end)
        goto body;
}
