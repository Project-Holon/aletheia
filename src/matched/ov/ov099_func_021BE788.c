/*
 * function: func_021BE788
 * address: 0x021BE788
 * packet: pkt_ov099_021BE788
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C23C0 0x021C23C0 thumb ov099
 *   func_021C23B8 0x021C23B8 thumb ov099
 *   func_021BDD48 0x021BDD48 thumb ov099
 *   func_021C2050 0x021C2050 thumb ov099
 *   func_021C203C 0x021C203C thumb ov099
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021C23C0(int index);
extern void *func_021C23B8(int index);
extern u8 func_021BDD48(int unused, void *s);
extern u8 func_021C2050(char *p, int i);
extern void func_021C203C(char *p, int i);
int func_021BE788(char *p)
{
    int count = 0;
    int i;
    unsigned value;
    for (i = 0; i < 32; i++) {
        *(u8 *)(p + i + 0x10) = 0;
        if (*(u16 *)(p + 0x132a) > i && func_021C23C0(i)) {
            value = func_021BDD48((int)p, func_021C23B8(i));
            if (value != 0 && value < 6) {
                *(u8 *)(p + count + 0x10) = i + 1;
                count++;
            } else if (func_021C2050(p, i + 1)) {
                func_021C203C(p, i + 1);
            }
        }
    }
    return count;
}
