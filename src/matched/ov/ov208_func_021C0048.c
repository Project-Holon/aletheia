/*
 * function: func_021C0048
 * address: 0x021C0048
 * packet: pkt_ov208_021C0048
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BBB3C 0x021BBB3C thumb ov072
 *   d_021C8670 0x021C8670 data a2
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u16 func_021BBB3C(char *, int, int);
extern const u16 d_021C8670[];
void func_021C0048(void *unused, char *p)
{
    u8 i;
    for (i = 0; i < 61; i++) {
        u16 value = func_021BBB3C(*(char **)(p + 0x3c8), i, 0);
        u8 j;
        for (j = 0; j < 61; j++) {
            if (value == d_021C8670[j]) {
                *(u8 *)(p + i + 0x3cc) = j;
                break;
            }
        }
    }
}
