/*
 * function: func_021F9478
 * address:  0x021F9478
 * packet:   pkt_ov094_021F9478
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02011298  0x02011298  thumb
 *   func_02011324  0x02011324  thumb
 *   func_021F8198  0x021F8198  thumb  ov094
 *   func_021FE410  0x021FE410  thumb  ov094
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

typedef struct {
    u32 lo : 6;
    u32 b6 : 1;
    u32 b7 : 1;
    u32 rest : 24;
    char pad[0x1E4];
    void *h;            /* 0x1E8 */
} T;

struct ScriptVm;
extern int func_02011298(struct ScriptVm *vm);
extern void *func_02011324(struct ScriptVm *vm);
extern void func_021F8198(int a, int b);
extern void func_021FE410(T *t, int a, int b, int c);
extern void func_020307B0(void *p);

int func_021F9478(void *vm)
{
    int r;
    T *t;

    r = func_02011298(vm);
    t = func_02011324(vm);
    if (t->b7)
        return 0;
    if (r == 0 && t->h != 0) {
        func_021F8198(1, 2);
        if (t->b6 == 0)
            func_021FE410(t, 0x6B000, 0x7F000, 0x14);
        func_020307B0(t->h);
        t->h = 0;
    }
    return r;
}
