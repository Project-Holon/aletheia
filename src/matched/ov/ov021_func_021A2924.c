/*
 * function: func_021A2924
 * address:  0x021A2924
 * packet:   pkt_ov021_021A2924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_021A2C10  0x021A2C10  thumb  ov021
 *   func_021A2BB8  0x021A2BB8  thumb  ov021
 *   func_021A25CC  0x021A25CC  thumb  ov021
 */

typedef struct {
    char pad0[2];
    unsigned short n;
} Hdr;

typedef struct {
    char pad0[0x20];
    Hdr *hdr;
    char pad24[0x18];
    void *f3c;
} Obj;

void func_020307B0(void *p);
void func_021A2C10(void *p);
typedef unsigned int   u32;
void func_021A2BB8(u32 a);
void func_021A25CC(void *o);

void func_021A2924(Obj *o)
{
    int i;

    if (o->f3c != 0) {
        func_020307B0(o->f3c);
        o->f3c = 0;
    }
    if (o->hdr->n != 0) {
        for (i = 0; i < 0x20; i++) {
            func_021A2C10((char *)o + 0x74 + i * 0x38);
            func_021A2BB8((u32)((char *)o + 0x74 + i * 0x38));
        }
    }
    func_021A25CC(o);
}
