/*
 * function: func_02185788
 * address: 0x02185788
 * packet: pkt_ov020_02185788
 * region: ov020
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021625FC 0x021625FC thumb ov010
 *   func_02014204 0x02014204 thumb
 */
typedef unsigned short u16;
typedef struct { int kind; u16 h4, h6, h8, ha; int c, d, e, f; } Record;
typedef unsigned char  u8;
struct t;
extern int func_021625FC(const u8 *q, int *out, int id, int k);
extern void func_02014204(struct t *p, int id);
void func_02185788(void *p, Record *source, Record *dest)
{
    if (source->kind == 1) {
        *dest = *source;
    } else {
        if (func_021625FC(p, (int *)dest, source->h6, source->ha) == 0) {
            func_02014204((struct t *)dest, source->h4);
        }
    }
}
