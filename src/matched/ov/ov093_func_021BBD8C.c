/*
 * function: func_021BBD8C
 * address: 0x021BBD8C
 * packet: pkt_ov093_021BBD8C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BB920 0x021BB920 thumb ov093
 *   func_021D74E4 0x021D74E4 thumb ov093
 *   func_021BBF88 0x021BBF88 thumb ov093
 *   func_021BBF98 0x021BBF98 thumb ov093
 *   func_021BC610 0x021BC610 thumb ov093
 *   func_021D5B68 0x021D5B68 thumb ov093
 *   func_021BDC98 0x021BDC98 thumb ov093
 *   func_021BD9D4 0x021BD9D4 thumb ov093
 *   func_021B8588 0x021B8588 thumb ov093
 *   func_021BCCE0 0x021BCCE0 thumb ov093
 *   func_021BDA00 0x021BDA00 thumb ov093
 *   func_021C5200 0x021C5200 thumb ov093
 *   func_021BC4DC 0x021BC4DC thumb ov093
 *   func_021C4614 0x021C4614 thumb ov093
 *   func_021BC2B0 0x021BC2B0 thumb ov093
 *   func_021C6158 0x021C6158 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 a; u32 kind : 4; u32 x : 3; u32 y : 3; u32 z : 1; u32 pad : 21; u32 c; u8 d, f; unsigned short pad2; } E;
typedef struct {
    u8 *f0; void *f4; u8 pad8[4]; int *fC; u8 pad10[4]; u32 f14;
    u8 pad18[0x3e0 - 0x18]; u8 g3e0[0xee]; u8 g4ce[0x77c - 0x4ce];
    u8 init; u8 pad77d[5]; u8 n; u8 k; u8 pad784[0x5c]; E e[6];
} S;
extern void func_021BB920(u8 *);
extern void func_021D74E4(void);
extern int func_021BBF88(u8 *, int);
extern int func_021BBF98(u8 *, int);
extern u8 func_021BC610(S *p, int a, E *q, int n);
extern int func_021D5B68(void *p);
extern void func_021BDC98(S *, u8 *, u8);
extern void func_021BD9D4(S *p, u8 i, u8 a, u8 b, int c);
extern u32 func_021B8588(void *p);
extern void func_021BCCE0(S *p, E *e);
extern int func_021BDA00(S *p);
extern int func_021C5200(S *p);
extern int func_021BC4DC(S *, u8 *);
extern void func_021C4614(S *);
extern int func_021BC2B0(S *);
extern void func_021C6158(S *, u8 *);

int func_021BBD8C(S *p, int a)
{
    int *q;
    u32 i;
    int saved;
    int ret;

    p->f14 = 0;
    q = p->fC;
    q[0] = 0;
    q[1] = 0;
    if (p->init == 0) {
        func_021BB920(p->f0);
        func_021D74E4();
        saved = func_021BBF88(p->g3e0, 0);
        p->n = func_021BC610(p, a, p->e, 6);
        p->k = 0;
        for (i = 0; i < p->n; i++) {
            if (p->e[i].kind == 3 && p->e[i].z == 0) {
                if (func_021D5B68((void *)p->e[i].a) == 0) {
                    func_021BDC98(p, (u8 *)p->e[i].a, p->e[i].y);
                    p->e[i].f = 1;
                }
            }
        }
        for (i = 0; i < p->n; i++) {
            if (p->e[i].kind == 3 && p->e[i].z == 0) {
                if (func_021D5B68((void *)p->e[i].a) != 0) {
                    func_021BD9D4(p, p->e[i].d, p->e[i].x, p->e[i].y, 1);
                    p->e[i].f = 1;
                }
            }
        }
        if (func_021B8588(p->f4) == 3) {
            for (i = 0; i < p->n; i++) {
                if (p->e[i].kind == 6 && p->e[i].z == 0)
                    func_021BCCE0(p, &p->e[i]);
            }
        }
        p->init = 1;
    }
    func_021BDA00(p);
    func_021C5200(p);
    func_021BC4DC(p, p->g4ce);
    ret = 0;
    if (saved == func_021BBF98(p->g3e0, 0)) {
        func_021C4614(p);
        return ret;
    }
    if (func_021BC2B0(p) == 0) {
        func_021C6158(p, p->g4ce);
        return 2;
    }
    return 4;
}
