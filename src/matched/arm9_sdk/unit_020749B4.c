/*
 * A whole translation unit, matched as one byte range.
 *
 * unit:     yes
 * function: func_020749B4, func_020749C4, func_020749F8, func_02074A34
 * address:  0x020749B4
 * packet:   pkt_020749C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02060468  0x02060468  arm
 *   func_02061124  0x02061124  arm
 *   func_020604AC  0x020604AC  arm
 *   func_02089D40  0x02089D40  arm
 *   func_02089B38  0x02089B38  arm
 *   func_02089CD4  0x02089CD4  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Table {
    void *heap;
    char list[0x1c];
};

extern void func_02060468(void *list, u32 param);
extern unsigned int func_02061124(char *p, int n, int v);
extern void func_020604AC(void *list, void *node);
extern u32 func_02089D40(void);
extern void func_02089B38(u32 a0);
extern void func_02089CD4(u32 tag);

int func_020749F8(struct Table *t);

void func_020749B4(void *node)
{
    func_02060468(node, 0);
}

int func_020749C4(struct Table *t, void *heap)
{
    func_02060468(&t->list, 0xc);
    t->heap = heap;
    if (func_020749F8(t)) {
        return 1;
    }
    return 0;
}

int func_020749F8(struct Table *t)
{
    void *node = (void *)func_02061124(t->heap, 0x14, 4);
    if (!node) {
        return 0;
    }
    func_020749B4(node);
    func_020604AC(&t->list, node);
    return 1;
}

void func_02074A34(void)
{
    void *p = (void *)func_02089D40();
    func_02089B38(1);
    func_02089CD4((u32)p);
}
