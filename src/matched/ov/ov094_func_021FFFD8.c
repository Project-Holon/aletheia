/*
 * function: func_021FFFD8
 * address:  0x021FFFD8
 * packet:   pkt_ov094_021FFFD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_020172AC 0x020172AC thumb
 *   func_02014CF8 0x02014CF8 thumb
 *   func_02015F2C 0x02015F2C thumb
 *   func_02201718 0x02201718 thumb ov094
 *   func_0202D060 0x0202D060 thumb
 *   func_021FFE24 0x021FFE24 thumb ov094
 */
#include "../include/Obj01047.h"
typedef unsigned int u32;
typedef struct { u32 v[9]; } Rec;
extern int func_022019F4(char *, int);
extern void func_020172AC(int a0, int a1);
extern void func_02014CF8(void *, void *, const Rec *);
extern void func_02015F2C(void *, int, void (*)(int), int);
extern void func_02201718(int);
extern int func_0202D060(void);
extern void func_021FFE24(char *, int);

void func_021FFFD8(char *w, int key, int flag, int clear)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Rec r;
    int odd;

    if (idx == -1)
        return;
    e = w;
    e += 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    if (flag == 0) {
        func_020172AC((int)(((struct Obj01047 *)w)->f4), *(u32 *)(w + off + 0x3c));
        func_02014CF8(((struct Obj01047 *)w)->f4, *(void **)(w + 8 + off), (const Rec *)(w + 0xc + off));
        func_02015F2C(*(void **)(w + 8 + off), idx, func_02201718, 1);
        if (clear)
            *(u32 *)(w + 0x48 + off) &= ~1u;
        *(u32 *)(w + 0x48 + off) &= ~4u;
    } else {
        r.v[0] = func_0202D060();
        odd = key & 1;
        r.v[1] = odd ? 0x37a0 : 0x37a6;
        r.v[2] = 0x37ac;
        r.v[3] = odd ? 0x37a1 : 0x37a7;
        r.v[4] = odd ? 0x37a2 : 0x37a8;
        r.v[5] = odd ? 0x37a3 : 0x37a9;
        r.v[6] = odd ? 0x37a4 : 0x37aa;
        r.v[7] = odd ? 0x37a5 : 0x37ab;
        r.v[8] = 0;
        func_02014CF8(((struct Obj01047 *)w)->f4, *(void **)(e + off), &r);
        func_021FFE24(w, key);
        if (clear)
            *(u32 *)(w + 0x48 + off) |= 1;
        *(u32 *)(w + 0x48 + off) |= 4;
    }
}
