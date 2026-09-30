/*
 * function: func_021B838C
 * address: 0x021B838C
 * packet: pkt_ov102_021B838C
 * region: ov102
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B63C4 0x021B63C4 thumb ov101
 *   func_021B63BC 0x021B63BC thumb ov101
 *   func_021B61E8 0x021B61E8 thumb ov101
 *   func_021B7F18 0x021B7F18 thumb ov102
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021B63C4(int *);
extern void func_021B63BC(int *);
extern int func_021B61E8(int *);
extern void func_021B7F18(u8 *);
void func_021B838C(u8 *p, u16 *state)
{
    switch (*state) {
    case 0:
        *state = 1;
        func_021B63C4(*(int **)(*(u8 **)(p + 0x48c) + 4));
        func_021B63BC(*(int **)(*(u8 **)(p + 0x48c) + 4));
        break;
    case 1:
        if (func_021B61E8(*(int **)(*(u8 **)(p + 0x48c) + 4)))
            *state = 2;
        break;
    case 2:
        *(u32 *)(*(u8 **)(p + 0x48c) + 12) = 2;
        func_021B7F18(p);
        break;
    }
}
