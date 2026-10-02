/*
 * function: func_021E5868
 * address:  0x021E5868
 * packet:   pkt_ov119_021E5868
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 */
extern void func_0204A8D4(int);
extern void func_0204ADA4(int);
extern void func_0204AFD8(int);
void func_021E5868(char *p)
{
    if (*(int *)(p + 0x898) != 0) {
        func_0204A8D4(*(int *)(p + 0x898));
        func_0204ADA4(*(int *)(p + 0x884));
        func_0204AFD8(*(int *)(p + 0x8b4));
        *(int *)(p + 0x898) = 0;
        *(int *)(p + 0x884) = 0;
        *(int *)(p + 0x8b4) = 0;
    }
}
