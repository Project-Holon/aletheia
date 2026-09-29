/*
 * function: func_021C7960
 * address:  0x021C7960
 * packet:   pkt_ov016_021C7960
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      dispCaret (libdwcutil.TWL.HYB.a sceneseteditaddress.o)
 *
 * symbols:
 *   g_021DE5E4     0x021DE5E4  data
 *   g_021DA5D4     0x021DA5D4  data
 */

typedef struct GXOamAttr {
    union {
        struct {
            unsigned short attr0;
            unsigned short attr1;
        } h;
        unsigned int attr01;
    } u;
    unsigned short attr2;
    unsigned short attr3;
} GXOamAttr;

typedef struct MemSsea {
    unsigned char pad0[4];
    GXOamAttr *caret;
    unsigned char pad1[0xC];
    unsigned char pos;
    unsigned char result;
} MemSsea;

extern MemSsea *g_021DE5E4;
extern unsigned char g_021DA5D4[];

void func_021C7960(void)
{
    int p = g_021DE5E4->pos;
    int x;
    if (p > 3)
        p = 3;
    x = g_021DA5D4[p * 3 + 2];
    g_021DE5E4->caret->u.attr01 = (g_021DE5E4->caret->u.attr01 & 0xFE00FF00) | 0x28 | ((x & 0x1FF) << 16);

}
