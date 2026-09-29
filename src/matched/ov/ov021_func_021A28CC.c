/*
 * function: func_021A28CC
 * address:  0x021A28CC
 * packet:   pkt_ov021_021A28CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   func_021A2BD4  0x021A2BD4  thumb  ov021
 *   d_021DDE80     0x021DDE80  data  a4
 */

typedef struct {
    char pad0[2];
    unsigned short n;
    char pad4[0x24];
    int f28;
} Hdr;

typedef struct {
    int f0;
    char pad4[0x18];
    int pad1c;
    Hdr *hdr;
    char pad24[4];
    char sub[0x14];
    int f3c;
} Obj;

extern int d_021DDE80;

void *func_02030734(int a, int b, int c, void *d, int e);
void func_021A2BD4(void *p, void *o, void *s, int a, int b);

void func_021A28CC(Obj *o, int heap)
{
    int i;

    o->f3c = (int)func_02030734(heap, o->hdr->f28, 1, &d_021DDE80, 0x874);
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2BD4((char *)o + 0x74 + i * 0x38, o, o->sub, o->f0, heap);
        }
    }
}
