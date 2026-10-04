/*
 * function: func_021D1488
 * address:  0x021D1488
 * packet:   pkt_ov021_021D1488
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked: d_021DB990 ({u16 v; u16 dur;} step table, two pool words for
 * +0 and +2) is contested: another overlay in the window starts an object at
 * 0x021DB990 and this function has no overlay_id site.
 *
 * symbols:
 *   d_021DB990     0x021DB990  data  a2
 *   func_021D1430  0x021D1430  thumb  ov021
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Step021D1488 {
    u16 v;
    u16 dur;
} Step021D1488;

typedef struct Anim021D1488 {
    u32 f0[5];
    int cnt;
    u32 idx;
} Anim021D1488;

extern void func_021D1430(u8 *p, u32 n);
extern Step021D1488 d_021DB990[];

void func_021D1488(void *task, Anim021D1488 *p)
{
    int c = p->cnt + 1;
    u16 d = d_021DB990[p->idx].dur;

    p->cnt = c;
    if (d <= c) {
        p->idx++;
        if (p->idx >= 4) {
            p->idx = 0;
            p->cnt = 0;
        }
        func_021D1430((u8 *)p, d_021DB990[p->idx].v);
    }
}
