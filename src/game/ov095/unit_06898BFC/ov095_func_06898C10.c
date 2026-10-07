/*
 * function: func_06898C10
 * address: 0x06898C10
 * packet: pkt_ov095_06898C10
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Original second label is 06898C12 after push {r0-r3}; match starts at
 * 06898C10. Byte parameter a and u8 callee sub recover early homing.
 * Reading p->en directly rather than binding w recovers loop registers.
 * symbols:
 *   g_0689E7E0 0x0689E7E0 data
 *   d_0689D780 0x0689D780 data ov095 a4
 *   func_06898CC0 0x06898CC0 thumb ov095
 *   func_06898CD0 0x06898CD0 thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { void *p; u32 f, n, en; } E;
typedef struct { E e[14]; } Row;
typedef struct { int key; int (*fn)(u32 *); u32 lim; } T;
typedef struct { u32 x; } S;
extern Row g_0689E7E0[2];
extern const T d_0689D780[14];
extern void *func_06898CC0(int id, u16 key, int pri, u32 sub_pri, u8 sub, u32 f8, u16 f16);
extern void func_06898CD0(void *p, int i, u32 v);
void *func_06898C10(u8 a, int b, S c)
{
    E *p = &g_0689E7E0[a].e[b];
    u32 k;
    u32 v;
    for (k = 0; k < 14; k++) {
        if (b == d_0689D780[k].key) {
            if (p->en == 0) {
                void *r;
                int x = d_0689D780[k].fn(&v);
                r = func_06898CC0(2, b, 2, 0, a, x, v);
                func_06898CD0(r, 6, c.x);
                p->en = 1;
                p->n = 0;
                p->f = c.x;
                p->p = r;
                return r;
            }
            if (p->en < d_0689D780[k].lim) {
                p->en++;
                return p->p;
            }
        }
    }
    return 0;
}
