/*
 * function: func_021BD744
 * address:  0x021BD744
 * packet:   pkt_ov016_021BD744
 * region:   ov016
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_ICONlInit (libdwcutil.TWL.HYB.a icon.o)
 *
 * symbols:
 *   func_021D6414  0x021D6414  arm  ov016
 *   func_021D5368  0x021D5368  arm  ov016
 *   func_021D7680  0x021D7680  arm  ov016
 *   g_021DE558     0x021DE558  data
 *   g_021DA090     0x021DA090  data
 *   func_021BD834  0x021BD834  arm  ov016
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

typedef struct MemIcon {
    GXOamAttr *obj;
    void *task;
    signed char type;
} MemIcon;

extern void *func_021D6414(unsigned long size, int alignment);
extern GXOamAttr *func_021D5368(int lcd, int idx);
extern void *func_021D7680(int kind, void (*func)(void *, void *), void *work, unsigned char prio);
extern void func_021BD834(void);
extern MemIcon *g_021DE558;
extern unsigned char g_021DA090[4][2];

void func_021BD744(int type)
{
    int idx;
    if (g_021DE558 != 0)
        return;
    g_021DE558 = func_021D6414(12, 4);
    idx = *((unsigned char *)g_021DA090 + (type << 2));
    g_021DE558->type = type;
    g_021DE558->obj = func_021D5368(0, idx);
    g_021DE558->obj->u.attr01 = (g_021DE558->obj->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    g_021DE558->obj->attr2 = (g_021DE558->obj->attr2 & ~0xC00) | 0x800;
    g_021DE558->task = func_021D7680(0, (void (*)(void *, void *))func_021BD834, 0, 0x78);
}
