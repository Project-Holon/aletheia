/*
 * function: func_021BBFA8
 * address:  0x021BBFA8
 * packet:   pkt_ov088_021BBFA8
 * region:   ov088
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020286C4  0x020286C4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_0203630C  0x0203630C  arm
 *   func_0201CE5C  0x0201CE5C  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0201CE38  0x0201CE38  thumb
 *   func_0201CE48  0x0201CE48  thumb
 */

typedef unsigned int u32;

extern void func_020286C4(void *, void *, void *);
extern int func_0201CE30(void *);
extern u32 func_0203630C(void);
extern void func_0201CE5C(void *, int);
extern u32 func_020362DC(void);
extern void func_020061E4(u32);
extern void func_0201CE38(void *);
extern void func_0201CE48(void *);

int func_021BBFA8(char *p)
{
    if (*(void **)(p + 0x6c) == 0)
        return 0;
    func_020286C4(*(void **)(p + 0x74), *(void **)(p + 0x6c), *(void **)(p + 0xe8));
    switch (func_0201CE30(*(void **)(p + 0x6c))) {
    case 0:
        if (func_0203630C() & 3)
            func_0201CE5C(*(void **)(p + 0x6c), 0);
        *(int *)(p + 0x78) = 0;
        break;
    case 1:
        if (*(int *)(p + 0x78) == 0) {
            if (func_020362DC() & 3) {
                func_020061E4(0x547);
                func_0201CE38(*(void **)(p + 0x6c));
                *(int *)(p + 0x78) = 1;
            }
        }
        break;
    case 2:
        func_0201CE48(*(void **)(p + 0x6c));
        *(int *)(p + 0x6c) = 0;
        *(int *)(p + 0x78) = 0;
        return 0;
    }
    return 1;
}
