/*
 * function: sub_02034AC4
 * address:  0x02034AC4
 * packet:   pkt_02034AC4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   sub_02034BB0         0x02034BB0  arm
 *   func_02034D60        0x02034D60  arm
 *   func_02034CBC        0x02034CBC  arm
 *   func_02034D08        0x02034D08  arm
 *   sub_02034714         0x02034714  arm
 *   FS_SetDefaultDMA     0x0207AC64  arm
 *   FS_LoadOverlay       0x02079264  arm
 *   s_FileName           0x020A7970  data
 *   s_Expr0              0x020A7980  data
 */

typedef signed int   s32;
typedef unsigned int u32;

struct Registration {
    s32 handle;
    s32 state;
};

extern const char s_FileName[];
extern const char s_Expr0[];

extern int sub_02034BB0(s32 handle);
extern int func_02034D60(s32 handle);
extern struct Registration *func_02034CBC(int which);
extern int func_02034D08(int which);
extern void sub_02034714(const char *file, u32 line, const char *expr);
extern int FS_SetDefaultDMA(int dma);
extern int FS_LoadOverlay(int target, s32 handle);

int sub_02034AC4(s32 handle)
{
    int which;
    int oldDMA = -1;
    struct Registration *table;
    int count;
    int i;
    int success;
    int ret;

    if (handle == oldDMA) {
        return 1;
    }

    if (sub_02034BB0(handle) == 0) {
        return 0;
    }

    which = func_02034D60(handle);
    table = func_02034CBC(which);
    count = func_02034D08(which);

    for (i = 0; i < count; i++) {
        struct Registration *entry = &table[i];
        if (entry->state == 0) {
            entry->state = 1;
            entry->handle = handle;
            break;
        }
    }

    if (i >= count) {
        sub_02034714(s_FileName, 267, s_Expr0);
        return 0;
    }

    which--;
    if ((u32)which <= 1) {
        oldDMA = FS_SetDefaultDMA(-1);
    }

    success = FS_LoadOverlay(0, handle);

    if ((u32)which <= 1) {
        FS_SetDefaultDMA(oldDMA);
    }

    ret = 0;
    if (success != 0) {
        ret = 1;
    }
    return ret;
}
