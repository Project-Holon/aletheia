/*
 * file:     unit_021B95A0_p12.c
 * unit:     yes
 * function: func_021BAFA8, func_021BAFD8, func_021BB000, func_021BB0AC, func_021BB0D0, func_021BB0D8
 * address:  0x021BAFA8
 * region:   ov068
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0200837C 0x0200837C thumb
 *   func_020083B4 0x020083B4 thumb
 *   func_020083D0 0x020083D0 thumb
 *   func_02008398 0x02008398 thumb
 *   func_02008430 0x02008430 thumb
 *   d_021BB704 0x021BB704 data a4
 *   d_021BB570     0x021BB570  data  a2
 *   d_021BB572     0x021BB572  data  a2
 *   d_021BB574     0x021BB574  data  a4
 *   d_021BB708     0x021BB708  data  a4
 *   func_02012FFC  0x02012FFC  thumb
 */
#include "../../matched/include/G__anon_Entry.h"
#include "../../matched/include/Obj13144.h"

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef signed char    s8;

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

extern void func_0200837C(u16 *, unsigned int);
extern void func_020083B4(u16 *, unsigned int);
extern void func_020083D0(u16 *, unsigned int);
extern void func_02008398(u16 *, unsigned int);
extern void func_02008430(u16 *, unsigned int);
void func_021BAFA8(u8 *p);
void func_021BAFD8(u8 *p, int i);
void func_021BB000(u8 *p, int i, int delta);
int func_021BB0AC(u8 *p, int i);
void func_021BB0D0(void);
int func_021BB0D8(void *p);
extern struct _anon_Entry d_021BB704[];
extern Tab d_021BB570[];
extern u16 d_021BB572[];
extern u8  d_021BB574[];
extern Ent d_021BB708[];

void func_021BAFA8(u8 *p)
{
    func_0200837C(*(u16 **)(p + 8), p[0]);
    func_020083B4(*(u16 **)(p + 8), p[1]);
    func_020083D0(*(u16 **)(p + 8), p[2]);
    func_02008398(*(u16 **)(p + 8), p[3]);
    func_02008430(*(u16 **)(p + 8), p[4]);
}

void func_021BAFD8(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] != d_021BB704[i].value) {
        p[d_021BB704[i].offset] = d_021BB704[i].value;
        p[5] = i;
        func_021BAFA8(p);
    }
}


/*
 * The three 0x021BB57x pool words and the two 0x021BB70x words are separate
 * pool entries in the original, so each is its own extern.
 */
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
            f = d_021BB704[v].value;
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

int func_021BB0AC(u8 *p, int i)
{
    if (p[d_021BB704[i].offset] == d_021BB704[i].value) return 1;
    return 0;
}


/*
 * ARM9 tail call then a byte read-modify-write.
 */
void func_021BB0D0(void)
{
    signed char func_02012FFC(void);
    func_02012FFC();
}


int func_021BB0D8(void *p)
{
    unsigned char old = ((struct Obj13144 *)p)->f5;
    ((struct Obj13144 *)p)->f5 = 0xb;
    return old;
}
