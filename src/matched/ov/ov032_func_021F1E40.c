/*
 * function: func_021F1E40
 * address:  0x021F1E40
 * packet:   pkt_ov032_021F1E40
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1E40 0x021F1E40 thumb
 *   func_021F1EAC 0x021F1EAC thumb
 *   func_021F0FC8 0x021F0FC8 thumb
 *   func_021F0ED0 0x021F0ED0 thumb
 *   func_020311B8 0x020311B8 arm
 *   func_02031290 0x02031290 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_02165E24 0x02165E24 thumb ov010
 *   func_02165FC0 0x02165FC0 thumb ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_021F1EAC(void *task, u8 *s);
extern void func_021F0FC8(char *p, char *q, u32 a);
extern void func_021F0ED0(char *q, int a);
extern void *func_020311B8(u32 a, void *fn, u32 sz, u32 a3);
extern u8 *func_02031290(void *node);
extern void func_02082BCC(void *p, int v, int n);
extern u16 func_02165E24(void *r);
extern u8 func_02165FC0(u32 type);

void func_021F1E40(char *p, char *q, void *x, int flag)
{
    void *t;
    u8 *r;

    t = func_020311B8(*(u32 *)(p + 0xa0), (void *)func_021F1EAC, 0x18, 0);
    r = func_02031290(t);
    func_02082BCC(r, 0, 0x18);
    *(char **)(r + 0x10) = p;
    *(char **)(r + 8) = q;
    r[1] = 0x5a;
    *(void **)(q + 0x30) = t;
    if (flag)
        *(u32 *)(r + 0xc) = 1;
    else
        *(u32 *)(r + 0xc) = func_02165E24(x);
    func_021F0FC8(p, q, func_02165FC0(*(u32 *)(r + 0xc)));
    func_021F0ED0(q, flag ? 0 : 1);
}
