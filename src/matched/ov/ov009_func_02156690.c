/*
 * function: func_02156690
 * address:  0x02156690
 * packet:   pkt_ov009_02156690
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   func_02155374  0x02155374  thumb  ov009
 *   func_021AF13C  0x021AF13C  thumb  ov013
 *   func_02059E38  0x02059E38  arm
 *   func_02059F18  0x02059F18  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021A8264;
extern void func_02155374(int v);
extern void func_021AF13C(void);
extern int func_02059E38(int *errorCode, int *errorType);
extern void func_02059F18(void);

int func_02156690(int a)
{
    u32 x, y;
    if (func_02059E38((int *)(&x), (int *)(&y)) != 0) {
        func_02059F18();
    }
    if (a == 0) {
        switch (*(u32 *)(g_021A8264 + 0x754)) {
        case 7:
        case 9:
        case 10:
            if (*(u32 *)(g_021A8264 + 0x76c) != 0) {
                func_021AF13C();
            }
            func_02155374(0x12);
            break;
        case 6:
        case 16:
        case 19:
        case 20:
            return 1;
        default:
            break;
        }
    } else {
        switch (*(u32 *)(g_021A8264 + 0x754)) {
        case 6:
        case 0x13:
        case 0x14:
            return 1;
        default:
            break;
        }
    }
    return 0;
}
