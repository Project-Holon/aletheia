/*
 * function: func_021FF4C0
 * address: 0x021FF4C0
 * packet: pkt_ov094_021FF4C0
 * region: ov094
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_022019F4 0x022019F4 thumb ov094
 *   func_02015C30 0x02015C30 thumb
 *   func_02015C48 0x02015C48 thumb
 *   func_022018A8 0x022018A8 thumb ov094
 *   func_0220074C 0x0220074C thumb ov094
 *   func_021F935C 0x021F935C thumb ov094
 *   func_02200904 0x02200904 thumb ov094
 *   func_02200990 0x02200990 thumb ov094
 */
#include "../include/Obj06309.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { int x, y, z; } Vec;
extern int func_022019F4(char *p, int key);
extern void func_02015C30(void *p, u32 *out);
extern void func_02015C48(void *p, u32 *src);
extern void func_022018A8(void *, Vec *, int);
extern void func_0220074C(void *, int, int, Vec *, Vec *, int, int, int, void *, void (*)(void *), int, u8);
extern int func_021F935C(int x);
extern void func_02200904(void);
extern void func_02200990(void *p);
void func_021FF4C0(char *w, int key, int kind, Vec *q, int a, int b, int c)
{
    int idx = func_022019F4(w, key);
    char *e;
    int off;
    Vec start;
    if (idx == -1)
        return;
    e = w + 8;
    off = idx * 0x5c;
    if (*(void **)(e + off) == 0)
        return;
    func_02015C30(*(void **)(e + off), (u32 *)&start);
    if (kind == 1) {
        if (key & 1)
            q->x = start.x - q->x;
        else
            q->x += start.x;
        q->y += start.y;
        q->z += start.z;
    }
    if (kind == 5) {
        func_022018A8(w, q, key);
        kind = 1;
    }
    if (kind == 6) {
        func_022018A8(w, q, key);
        kind = 0;
    }
    if (kind == 0) {
        func_02015C48(*(void **)(e + off), (u32 *)q);
        return;
    }
    (*(u8 *)(w + 0x542 + key))++;
    func_0220074C(w, key, kind, &start, q, a, b, c, (void *)func_02200904, func_02200990, 1, *(u8 *)(w + 0x542 + key));
    ((struct Obj06309 *)w)->f514 |= func_021F935C(key);
}
