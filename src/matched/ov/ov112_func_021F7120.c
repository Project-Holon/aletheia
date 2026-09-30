/*
 * function: func_021F7120
 * address: 0x021F7120
 * packet: pkt_ov112_021F7120
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F77A0 0x021F77A0 thumb ov112
 *   func_0204F150 0x0204F150 arm
 *   func_020307B0 0x020307B0 arm
 */
extern void func_021F77A0(int, int);
extern void func_0204F150(int, int);
extern void func_020307B0(int);
typedef struct { int pad[5]; int flag; } Record;
void func_021F7120(char *p) {
    int i;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1)
            func_021F77A0((int)p, (int)(p + 0x14 + i * 0x108));
    }
    func_0204F150(*(int *)(p + 8), *(int *)(p + 0x438));
    func_020307B0((int)p);
}
