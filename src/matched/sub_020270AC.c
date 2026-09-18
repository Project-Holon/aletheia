/*
 * function: func_020270AC
 * address:  0x020270AC
 * packet:   pkt_020266E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GX_GetBankForLCDC  0x02045A98  arm
 *   sub_02045A38       0x02045A38  arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 GX_GetBankForLCDC(void);
extern void sub_02045A38(void *vec, u16 *out, u32 n);

void func_020270AC(void *vec, u16 *dest)
{
    u16 buf[12];
    u16 stamp;
    int i;

    stamp = GX_GetBankForLCDC();
    sub_02045A38(vec, buf, 12);

    for (i = 0; i < 10; i++) {
        dest[i] = buf[i];
        if (stamp == buf[i]) {
            break;
        }
    }
}
