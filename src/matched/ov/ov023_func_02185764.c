/*
 * function: func_02185764
 * address:  0x02185764
 * packet:   pkt_ov023_02185764
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02186660  0x02186660  thumb  ov023
 *   func_02186164  0x02186164  thumb  ov023
 *   func_02186444  0x02186444  thumb  ov023
 *   func_02184114  0x02184114  thumb  ov022
 *   func_021852F4  0x021852F4  thumb  ov023
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02039338  0x02039338  arm
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02185354  0x02185354  thumb  ov023
 */

typedef unsigned int u32;

extern int func_02186660(char *p);
extern int func_02186164(char *p);
typedef unsigned short u16;
extern void func_02186444(char *p, u32 v);
extern int func_02184114(unsigned char *p);
extern void func_021852F4(void *p, int flag);
extern void func_0201F7A8(void *desc, u32 kind);
extern u16 func_02039338(void);
extern void func_02184560(char *p, int a);
extern void func_02185354(char *p);

int func_02185764(char *p, int x)
{
    int m;

    m = func_02186660(p);
    if (*(int *)(p + 0x1ac) != func_02186164(p) || *(int *)(p + 0x9280) != 0) {
        func_02185354(p);
        return x;
    }
    switch (m) {
    case 0:
        func_02186444(p, 0x11);
        func_02184114((unsigned char *)(*(u32 *)*(u32 **)(p + 4)));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(*(u32 *)(p + 0x100)), 0);
        func_0201F7A8((void *)(*(u32 *)(p + 0x11c)), 2);
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            *(int *)(p + 0x9e6c) = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}
