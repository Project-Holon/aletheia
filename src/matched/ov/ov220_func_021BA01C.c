/*
 * function: func_021BA01C
 * address:  0x021BA01C
 * packet:   pkt_ov220_021BA01C
 * region:   ov220
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */
typedef struct Obj {
    unsigned char pad00[0x10];
    void *f10;
    unsigned char pad14[0x60 - 0x14];
    void *ptr[4];
    int done[4];
} Obj;

extern void *func_02045770(void *p);
extern int func_0201C6C4(void *a, void *b);
extern void func_02045334(void *p);
extern void func_02045374(void *p);
extern unsigned char func_02045730(void *p);
extern void func_02041B6C(unsigned int bit);

void func_021BA01C(Obj *o)
{
    unsigned char i;

    for (i = 0; i < 4; i++) {
        if (o->done[i] == 0) {
            if (func_0201C6C4(o->f10, func_02045770(o->ptr[i])) == 0) {
                void *p = o->ptr[i];
                func_02045334(p);
                func_02045374(p);
                func_02041B6C(func_02045730(p));
                o->done[i] = 1;
            }
        }
    }
}
