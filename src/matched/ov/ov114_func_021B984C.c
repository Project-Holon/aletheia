/*
 * function: NHTTP_RAP_WritePostHeader
 * address: 0x021B984C
 * packet: pkt_ov114_021B984C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned short u16;
typedef struct { char *buffer; int cursor; char *source; } Record;
void NHTTP_RAP_WritePostHeader(Record *p, int x)
{
    char c;
    x = (u16)x;
    if (p) {
        p->cursor = 0;
        while ((c = (p->source + p->cursor)[0x45]) != 0) {
            p->buffer[p->cursor] = c;
            p->cursor++;
        }
        p->buffer[p->cursor++] = 0;
        p->buffer[p->cursor++] = x >> 8;
        p->buffer[p->cursor++] = x;
    }
}
