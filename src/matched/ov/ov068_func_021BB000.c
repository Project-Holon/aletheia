/*
 * function: func_021BB000
 * address:  0x021BB000
 * packet:   pkt_ov068_021BB000
 * region:   ov068
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The three 0x021BB57x pool words and the two 0x021BB70x words are separate
 * pool entries in the original, so each is its own extern.
 *
 * symbols:
 *   d_021BB570     0x021BB570  data  a2
 *   d_021BB572     0x021BB572  data  a2
 *   d_021BB574     0x021BB574  data  a4
 *   d_021BB704     0x021BB704  data  a4
 *   d_021BB708     0x021BB708  data  a4
 *   func_021BAFA8  0x021BAFA8  thumb  ov068
 */

typedef unsigned char  u8;
typedef signed char    s8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 f0;
    u16 cnt;
    u8  list[4];
} Tab;

typedef struct {
    u32 f0;
    u32 f4;
    u32 pad[4];
} Ent;

extern Tab d_021BB570[];
extern u16 d_021BB572[];
extern u8  d_021BB574[];
extern Ent d_021BB704[];
extern Ent d_021BB708[];
extern void func_021BAFA8(u8 *p);

void func_021BB000(u8 *p, int i, int delta)
{
    int j;
    int k;
    int n;
    Tab *t;
    int off = i << 3;
    s8 idx;
    int t2;
    int v = -1;

    n = *(u16 *)((u8 *)d_021BB572 + off);
    j = 0;
    if (n > 0) {
        do {
            u8 cur;
            u32 f;

            t = (Tab *)((u8 *)d_021BB570 + off);
            cur = p[i];

            v = t->list[j];
            f = d_021BB704[v].f4;
            if (f == cur) {
                break;
            }
            j++;
        } while (j < t->cnt);
    }
    t2 = (s8)(v - d_021BB574[(u32)i << 3]);
    t2 = (s8)(t2 + delta);
    idx = (s8)(t2 > n - 1 ? n - 1 : (t2 < 0 ? 0 : t2));
    k = (d_021BB574 + off)[idx];
    if (p[i] != d_021BB708[k].f0) {
        p[i] = d_021BB708[k].f0;
        p[5] = k;
        func_021BAFA8(p);
    }
}
