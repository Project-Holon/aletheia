/*
 * function: func_021EFC1C
 * address:  0x021EFC1C
 * packet:   pkt_ov093_021EFC1C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-02 (wB2 lane08): DIFF, 3 bytes: original spills r3 (sp+4) before r1 (sp+0) around the first call; ours stores r1 then r3. Locals, decl order, types, && fold and y/x copies tried; everything else matches.
 *
 * symbols:
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021B9A24  0x021B9A24  thumb  ov093
 *   func_021B9940  0x021B9940  thumb  ov093
 *   func_021D5750  0x021D5750  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern int func_021D5440(void *m);
extern int func_021B9A24(int a, int b);
extern int func_021B9940(char *p, int i);
extern int func_021D5750(int, int);

typedef struct {
    u8 pad00[0xB0];
    u32 id[0x4D - 0x2C];    /* 0x0B0 */
    u32 count;              /* 0x134 */
} S;

int func_021EFC1C(S *a, char *x, void *m, int y)
{
    int mon;
    int c;
    u32 i;
    u32 n;

    mon = func_021D5440(m);
    n = a->count;
    for (i = 0; i < n; i++) {
        c = (u8)a->id[i];
        if (func_021B9A24(mon, c) == 0) {
            if (func_021D5750(func_021B9940(x, c), y) != 0)
                return 1;
        }
    }
    return 0;
}
