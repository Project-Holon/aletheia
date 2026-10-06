/*
 * function: func_021F4F7C
 * address: 0x021F4F7C
 * packet: pkt_ov194_021F4F7C
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F4F68 0x021F4F68 thumb ov194
 *   func_021F4F6C 0x021F4F6C thumb ov194
 */
typedef unsigned short u16;
extern int func_021F4F68(const u16 *p);
extern unsigned short func_021F4F6C(char *base, int i, int j);
int func_021F4F7C(char *p, const unsigned short *key, unsigned short *out)
{
    int i, j;
    if (*key == 0x3000) return 0;
    for (i = 0; i < func_021F4F68((const u16 *)p); i++) {
        for (j = 0; j < 3; j++) {
            if (*key == func_021F4F6C(p, (unsigned short)i, (unsigned short)j)) {
                p += i * 6;
                do {
                    j = (j + 1) % 3;
                    *out = *(unsigned short *)(p + 2 + j * 2);
                } while (*out == 0x3000);
                return 1;
            }
        }
    }
    return 0;
}
