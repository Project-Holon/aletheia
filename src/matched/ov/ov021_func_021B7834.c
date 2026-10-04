/*
 * function: func_021B7834
 * address:  0x021B7834
 * packet:   pkt_ov021_021B7834
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021B77E4  0x021B77E4  thumb ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Ent;
extern struct Ent *func_021B77E4(void *a, void *b, struct Ent *c);

void *func_021B7834(void *a, int *out, void *buf)
{
    int i;

    for (i = 0; i < 12; i++) {
        if (func_021B77E4(a, (void *)i, buf)) {
            *out = i;
            return buf;
        }
    }
    return 0;
}
