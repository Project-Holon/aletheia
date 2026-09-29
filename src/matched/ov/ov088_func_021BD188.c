/*
 * function: func_021BD188
 * address:  0x021BD188
 * packet:   pkt_ov088_021BD188
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020310C4  0x020310C4  arm
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */

typedef unsigned int u32;

extern void func_020310C4(void *);
extern void func_020286C4(void *, void *, void *);
extern int func_0201CE30(void *);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(void *);

int func_021BD188(char *p)
{
    func_020310C4(*(void **)(p + 0x18));
    func_020286C4(*(void **)(p + 0x24), *(void **)(p + 0x14), *(void **)(p + 0x1c));
    switch (func_0201CE30(*(void **)(p + 0x14))) {
    case 0:
        *(int *)(p + 0x28) = 0;
        break;
    case 1:
        if (*(int *)(p + 0x28) == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(*(void **)(p + 0x14));
                *(int *)(p + 0x28) = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(*(void **)(p + 0x14));
        *(int *)(p + 0x28) = 0;
        return 0;
    }
    return 1;
}
