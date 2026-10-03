/*
 * function: func_021CC668
 * address: 0x021CC668
 * packet: pkt_ov093_021CC668
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B8B9C 0x021B8B9C thumb ov093
 *   func_021B9AEC 0x021B9AEC thumb ov093
 *   func_021B9B94 0x021B9B94 thumb ov093
 *   func_021B9B98 0x021B9B98 thumb ov093
 *   func_021B8BC4 0x021B8BC4 thumb ov093
 *   func_021B8FF4 0x021B8FF4 thumb ov093
 *   func_021BA534 0x021BA534 thumb ov093
 *   func_021CC758 0x021CC758 thumb ov093
 *   func_021B9A40 0x021B9A40 thumb ov093
 *   func_021CC768 0x021CC768 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021B8B9C(unsigned char *p, unsigned char k);
extern char *func_021B9AEC(char *,int);
extern u8 func_021B9B94(void *);
extern u8 func_021B9B98(char *);
extern u8 func_021B8BC4(void *,u8);
extern u8 func_021B8FF4(u8 *p);
extern int func_021BA534(void ***p);
extern int func_021CC758(void *);
extern unsigned char func_021B9A40(unsigned int x);
extern int func_021CC768(void *,u8 *,u8 *,int);
int func_021CC668(u8 *p)
{
    u8 live[2];
    u8 counts[2];
    u32 i;
    char *list;
    u8 side;
    u8 other;
    int k;
    live[0] = live[1] = 0;
    counts[0] = counts[1] = 0;
    for (i = 0; i < 4; i++) {
        if (func_021B8B9C(*(void **)(p+4), i)) {
            list = func_021B9AEC(*(char **)(p+8),i);
            if (func_021B9B94(list)) {
                side = func_021B8BC4(*(void **)(p+4),i);
                live[side] += func_021B9B98(list);
                counts[side] += func_021B9B94(list);
            }
        }
    }
    side = func_021B8BC4(*(void **)(p+4),func_021B8FF4(*(void **)(p+4)));
    other = side ^ 1;
    if (live[side] == 0 && live[other] != 0) return 0;
    if (live[other] == 0 && live[side] != 0) return 1;
    if (!func_021BA534(*(void **)(p+4))) return 2;
    if (live[0] == 0) {
        k = func_021CC758(p+0x3e0);
        if (k != 31) {
            k = func_021B9A40(k);
            if (k == side) return 1;
            return 0;
        }
        return 2;
    }
    return func_021CC768(p, live, counts, side);
}
