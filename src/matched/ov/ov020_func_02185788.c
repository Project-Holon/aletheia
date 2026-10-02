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
extern int func_021625FC(void *p, void *out, int a, int b);
extern void func_02014204(void *p, int id);
void func_02185788(void *p, Record *source, Record *dest)
{
    if (source->kind == 1) {
        *dest = *source;
    } else {
        if (func_021625FC(p, dest, source->h6, source->ha) == 0) {
            func_02014204(dest, source->h4);
        }
    }
}
