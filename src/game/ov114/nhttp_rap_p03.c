/*
 * file:     nhttp_rap_p03.c
 * unit:     yes
 * function: func_021B9838, func_021B984C
 * address:  0x021B9838
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B99B8  0x021B99B8  thumb  ov114
 */
typedef unsigned char u8;

typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { char *buffer; int cursor; char *source; } Record;

extern void func_021B99B8(u8 *);
extern u32 func_020307B0(void *p);
void func_021B9838(u8 *p);
void func_021B984C(Record *p, int x);


/*
 * Frees the record's buffer, then the record itself.
 */
void func_021B9838(u8 *p)
{
    if (p == 0)
        return;
    func_021B99B8(p);
    func_020307B0(p);
}

void func_021B984C(Record *p, int x)
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
