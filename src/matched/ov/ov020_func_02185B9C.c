/*
 * function: func_02185B9C
 * address:  0x02185B9C
 * packet:   pkt_ov020_02185B9C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B37C  0x0200B37C  thumb
 *   func_0200B394  0x0200B394  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_020493D4  0x020493D4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 */

typedef unsigned short u16;

typedef struct { int id; u16 v; u16 pad; } Ent;

int func_02012EC4(int a);
void func_0200B37C(int a);
void func_0200B394(int a, int b);
void *func_020490F4(unsigned int id, u16 heap);
Ent *func_02049250(void *h, int a, int b);
unsigned func_020493D4(void *h, int a);
void func_020307B0(void *p);
void func_02049238(void *h);

void func_02185B9C(int a0, int id)
{
    unsigned n, i;
    int r0 = func_02012EC4(a0);
    void *h;
    int c = 0x8001;
    Ent *e;

    func_0200B37C(r0);
    h = func_020490F4(0x65, c);
    e = func_02049250(h, 0, c);
    n = func_020493D4(h, 0) >> 3;
    for (i = 0; i < n; i++) {
        if (id == e[i].id) {
            func_0200B394(r0, e[i].v);
            break;
        }
    }
    func_020307B0(e);
    func_02049238(h);
}
