/*
 * function: func_02189764
 * address:  0x02189764
 * packet:   pkt_ov021_02189764
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DD9C0     0x021DD9C0  data  a4
 */

typedef struct {
    int id;
    void *buf;
} Slot;

extern unsigned char d_021DD9C0[];
void *func_02030734(unsigned int a, unsigned int b, int c, const char *d, unsigned short e);

void *func_02189764(unsigned char *p, int id, int a, int b)
{
    Slot *s = (Slot *)(p + 0x118);
    if (id == -1)
        return 0;
    if (s->id != -1)
        return 0;
    s->id = id;
    return s->buf = func_02030734(a, b, 1, (const char *)d_021DD9C0, 0xD7C);
}
