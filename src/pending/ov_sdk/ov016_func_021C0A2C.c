typedef struct UtilState {
    unsigned char lang;
    unsigned char end;
    unsigned char pad2[2];
    void *work;
    unsigned int param;
    void (*scene)(void);
} UtilState;

typedef union UtilParam {
    unsigned int value;
    struct {
        unsigned int mode : 4;
        unsigned int flags : 28;
    } b;
} UtilParam;

extern UtilState g_021DE56C;

int func_021C0A2C(int lang, unsigned int value)
{
    UtilParam param;
    param.value = value;
    g_021DE56C.lang = lang;
    g_021DE56C.param = value;
    if (lang < 0 || lang > 6)
        return 0;
    if (param.b.mode > 1)
        return 0;
    if (param.b.flags & 2)
        return 0;
    if (lang != 0 && (param.b.flags & 1))
        return 0;
    if (lang == 0 && !(param.b.flags & 1))
        return 0;
    return 1;
}
