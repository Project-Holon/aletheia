/*
 * function: func_021818C4
 * address:  0x021818C4
 * packet:   pkt_ov018_021818C4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_0201232C  0x0201232C  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082D44  0x02082D44  arm
 *   func_02181584  0x02181584  thumb  ov018
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad00[0x40];
    u8 f40;
    u8 pad41[0x17];
    u16 f58;
} Ov018Src;

struct Obj;
void *func_020124E4(struct Obj *p);
void func_0201232C(void *, void (*)(void), int);
void *func_020124E8(struct Obj *p);
void func_02082D44(void *, void *, int);
void func_02181584(void);

void func_021818C4(void *a, Ov018Src *src)
{
    void *r;
    u8 *t;

    r = func_020124E4(a);
    func_0201232C(a, func_02181584, 0xB0);
    t = func_020124E8(a);
    func_02082D44(src, t, 0x98);
    *(int *)(t + 0xA4) = 1;
    *(void **)(t + 0x9C) = r;
    t[0xA0] = t[0x40];
    t[0xA1] = src->f58;
    t[0xA2] = 2;
}
