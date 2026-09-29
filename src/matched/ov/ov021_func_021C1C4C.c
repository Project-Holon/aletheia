/*
 * function: func_021C1C4C
 * address:  0x021C1C4C
 * packet:   pkt_ov021_021C1C4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02048AD0  0x02048AD0  arm
 *   func_020489F4  0x020489F4  arm
 *   func_02048A00  0x02048A00  arm
 *   func_02048A18  0x02048A18  arm
 *   func_02047A60  0x02047A60  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

void func_02048AD0(int a);
int func_020489F4(int a, u16 b);
int func_02048A00(int a, u16 b);
int func_02048A18(int a, u16 b);
void func_02047A60(int a, char *b);

void func_021C1C4C(char *p)
{
    int a;
    int n;
    int i;
    u8 k;

    if (*(int *)(p + 0xc) == 0)
        func_02048AD0(*(int *)(p + 4));
    else
        func_02048AD0(*(int *)(p + 8));
    if (*(int *)(p + 0x18) != -1) {
        a = func_020489F4(*(int *)(p + 0x14), *(int *)(p + 0x18));
        n = func_02048A00(*(int *)(p + 0x14), *(int *)(p + 0x18));
        for (k = 0; k < n; k++) {
            i = func_02048A18(*(int *)(p + 0x14), a + k);
            func_02047A60(i, p + 0x1c);
        }
    }
}
