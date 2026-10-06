/*
 * function: func_021BCDB0
 * address:  0x021BCDB0
 * packet:   pkt_ov099_021BCDB0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BC06C  0x021BC06C  thumb  ov099
 *   func_020362DC  0x020362DC  arm
 *   func_021BCBBC  0x021BCBBC  thumb  ov099
 *   func_021BBEB4  0x021BBEB4  thumb  ov099
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020362DC(void);
extern void func_021BC06C(char *p);
extern int func_021BCBBC(int a, int b, int *out);
struct O;
extern void func_021BBEB4(struct O *p, int mask, u32 a, int mode);

int func_021BCDB0(char *p, int v)
{
    if (func_020362DC() != 0) {
        func_021BC06C(p);
        if (*(int *)(p + 0xCC) != 0) {
            int out;
            func_021BCBBC(*(int *)(p + 0x1348), *(int *)(p + 0xCC), &out);
            func_021BBEB4((struct O *)p, out, *(u8 *)(*(char **)(p + 0x248) + 0x48), 3);
            *(int *)(p + 0x1CC) = 0x78;
        } else {
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
    }
    return v;
}
