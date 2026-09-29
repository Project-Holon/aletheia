typedef struct MemIcon {
    void *obj;
    void *task;
    signed char type;
} MemIcon;

extern void func_021D7744(int kind, void *task);
extern void func_021D6F38(void *obj);
extern void func_021D6438(MemIcon **mem);
extern MemIcon *g_021DE558;

void func_021BD7F4(void)
{
    if (g_021DE558 == 0)
        return;
    func_021D7744(0, g_021DE558->task);
    func_021D6F38(g_021DE558->obj);
    func_021D6438(&g_021DE558);
}
