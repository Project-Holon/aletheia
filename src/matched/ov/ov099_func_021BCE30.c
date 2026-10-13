/*
 * function: func_021BCE30
 * address:  0x021BCE30
 * packet:   pkt_ov099_021BCE30
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 *   KEY_GetTrg  0x020362DC  arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 KEY_GetTrg(void);
extern void func_021BC06C(char *p);
extern void func_021BA8EC(char *p);

int func_021BCE30(char *p, int v)
{
    if (KEY_GetTrg() != 0) {
        func_021BC06C(p);
        func_021BA8EC(p);
        switch (*(int *)(p + 0x135C)) {
        case 3:
            *(int *)(p + 0x1CC) = 0x4E;
            break;
        case 2:
            *(u8 *)(p + 0x1353) = 0x97;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        case 4:
            *(u8 *)(p + 0x1353) = 0x90;
            *(int *)(p + 0x1CC) = 0x8A;
            break;
        default:
            *(int *)(p + 0x1CC) = 0x72;
            break;
        }
    }
    return v;
}
