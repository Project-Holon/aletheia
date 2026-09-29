/*
 * function: func_021CC0F8
 * address:  0x021CC0F8
 * packet:   pkt_ov093_021CC0F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D5BDC  0x021D5BDC  thumb  ov093
 *   func_021D5FE4  0x021D5FE4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021CD4B0  0x021CD4B0  thumb  ov093
 *   func_021D5F38  0x021D5F38  thumb  ov093
 *   func_021CD64C  0x021CD64C  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D5BDC(void *m, u32 n);
extern void func_021D5FE4(void *m, u32 n);
extern int func_021D5440(void *m);
extern void func_021CD4B0(void *w, u32 id, ...);
extern int func_021D5F38(void *m, u32 n);
extern void func_021CD64C(void *w, u8 id, ...);

int func_021CC0F8(char *p, void *m, int c, int n)
{
    int flag;

    flag = 0;
    if (func_021D5BDC(m, 9) == 0) {
        func_021D5FE4(m, 9);
        func_021CD4B0(*(void **)(p + 0xc), 0x19, func_021D5440(m), 9);
        flag = 1;
    }
    if (n > 1) {
        if (func_021D5F38(m, n - 1) != 0) {
            func_021CD4B0(*(void **)(p + 0xc), 0xe, func_021D5440(m), n - 1);
            flag = 1;
        }
    }
    if (flag) {
        func_021CD64C(*(void **)(p + 0xc), 0x5b, 0x411, func_021D5440(m), 0xffff0000);
        return 1;
    }
    return 0;
}
