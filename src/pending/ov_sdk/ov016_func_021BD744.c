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
    if (g_021DE558 != 0)
        return;
    g_021DE558 = func_021D6414(12, 4);
    g_021DE558->type = type;
    g_021DE558->obj = func_021D5368(0, *((unsigned char *)g_021DA090 + (type << 2)));
    g_021DE558->obj->u.attr01 = (g_021DE558->obj->u.attr01 & 0xFE00FF00) | 0x26 | (0xE5 << 16);
    g_021DE558->obj->attr2 = (g_021DE558->obj->attr2 & ~0xC00) | 0x800;
    g_021DE558->task = func_021D7680(0, (void (*)(void *, void *))func_021BD834, 0, 0x78);
}
