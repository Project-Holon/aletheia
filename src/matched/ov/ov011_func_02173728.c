/*
 * function: func_02173728
 * address: 0x02173728
 * packet: pkt_ov011_02173728
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02026478 0x02026478 thumb
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_02012B4C 0x02012B4C thumb
 * The loaded byte stays live as r1 into 02012B4C.
 */
typedef unsigned char u8;
struct Link;
typedef unsigned int   u32;
extern u32 func_02026478(void *obj);
struct Entry;
extern struct Entry *func_020399A8(void);
extern unsigned int func_0203D1A4(struct Link *);
struct BigObj;
extern void func_02012B4C(struct BigObj *p, u8 v);
void func_02173728(unsigned int a, int b, u8 *c, u8 *d)
{
    void *h;
    unsigned int n;
    h = (void *)func_02026478(*(void **)(d + 4));
    if (a != func_0203D1A4((struct Link *)func_020399A8())) {
        n = *c;
        d[0x902] = n;
        func_02012B4C(h, n);
    }
}
