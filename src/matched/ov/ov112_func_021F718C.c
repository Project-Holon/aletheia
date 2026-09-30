/*
 * function: func_021F718C
 * address: 0x021F718C
 * packet: pkt_ov112_021F718C
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding before 021F7204.
 * symbols:
 *   func_021F732C 0x021F732C thumb ov112
 *   func_021F9E44 0x021F9E44 thumb ov132
 *   func_021F4990 0x021F4990 thumb ov112
 */
extern void func_021F732C(char *, char *);
extern unsigned func_021F9E44(int);
extern void func_021F4990(int);
typedef struct { int pad[5]; int flag; } Record;
void func_021F718C(char *p) {
    int i;
    unsigned j;
    for (i = 0; i < 4; i++) {
        if (((Record *)(p + i * 0x108))->flag == 1) {
            func_021F732C(p, p + 0x14 + i * 0x108);
            if (*(int *)(p + 4) != 0) {
                for (j = 0; j < func_021F9E44(*(int *)(p + 4)); j++) {
                    if (*(void (**)(char *, char *))(p + i * 0x108 + 0x118) != 0)
                        (*(void (**)(char *, char *))(p + i * 0x108 + 0x118))(p, p + 0x14 + i * 0x108);
                }
            }
        }
    }
    func_021F4990(*(int *)(p + 0x10));
}
