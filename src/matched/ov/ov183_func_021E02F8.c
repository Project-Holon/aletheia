/*
 * function: func_021E02F8
 * address: 0x021E02F8
 * packet: pkt_ov183_021E02F8
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FC20C 0x021FC20C thumb ov186
 *   func_021FC214 0x021FC214 thumb ov186
 *   func_021FB964 0x021FB964 thumb ov186
 *   func_021FC6A4 0x021FC6A4 thumb ov186
 *   func_021FC868 0x021FC868 thumb ov186
 *   func_021FC754 0x021FC754 thumb ov186
 *   d_021E37D8 0x021E37D8 data ov183
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Record { u8 a, b, c, d; int value; };
extern const struct Record d_021E37D8[];
extern unsigned func_021FC20C(char *p);
extern int func_021FC214(char *);
extern void func_021FB964(void *ctx, unsigned kind, unsigned short heap);
typedef unsigned int   u32;
extern void *func_021FC6A4(unsigned short plane, unsigned a, unsigned short b, unsigned short c, unsigned char d, unsigned char e, void *owner, unsigned short heap);
extern void func_021FC868(u8 *p, u32 a, u32 b, u32 c);
extern void func_021FC754(char *p, void *a, void *b, void *font, unsigned short value);
void func_021E02F8(char *p, int *q)
{
    int first, second, i;
    const struct Record *r;
    first = func_021FC20C((char *)q[2]);
    second = func_021FC214((char *)q[2]);
    func_021FB964((void *)q[2], 25, *(u16 *)(p + 0x54));
    for (i = 0; i < 6; i++) {
        r = &d_021E37D8[i];
        *(void **)(p + i * 4 + 0x20) = func_021FC6A4(1, r->a, r->b, r->c, r->d, 14, *(void **)(p + 0x48), *(u16 *)(p + 0x54));
        func_021FC868(*(void **)(p + i * 4 + 0x20), 0, 1, 0);
        func_021FC754(*(void **)(p + i * 4 + 0x20), (void *)second, (void *)r->value, (void *)first, 15776);
    }
}
