/*
 * function: func_02175274
 * address:  0x02175274
 * packet:   pkt_ov011_02175274
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_021751D4  0x021751D4  thumb ov011
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct C12 {
    int w[3];
} C12;

typedef unsigned int   u32;
struct BigObj;
struct Ent;
u32 func_02026478(void *obj);
u8 func_02012B58(const struct BigObj *p);
void func_021751D4(u8 *p, u16 a, int b, struct Ent *c);

void func_02175274(u8 *p, int arg)
{
    u8 *arr;
    u8 *h;
    int n;
    int i;
    u8 *e;

    n = func_02012B58((const struct BigObj *)func_02026478((void *)(*(int *)(p + 4))));
    h = p + 0x70;
    i = 0;
    arr = p + 0x8C;
    for (; i < 3; i++) {
        if ((p[0x8FB] & (1 << i)) && i != n) {
            e = arr + i * 0x1C;
            *(C12 *)(e + 4) = *(C12 *)(p + 0xE4 + i * 0x14);
            func_021751D4(p, *(u16 *)(h + 0x14), arg, (struct Ent *)e);
        }
    }
}
