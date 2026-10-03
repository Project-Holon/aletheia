/*
 * function: func_02155C8C
 * address:  0x02155C8C
 * packet:   pkt_ov009_02155C8C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021A8264     0x021A8264  data  ov009  a4
 *   d_021A1C5C     0x021A1C5C  data  ov009  a1
 *   func_02177270  0x02177270  arm
 *   func_0216B838  0x0216B838  arm
 *   func_0216B908  0x0216B908  arm
 *   func_02034714  0x02034714  arm
 *   func_02155C70  0x02155C70  thumb  ov009
 */

typedef unsigned char u8;

typedef struct {
    char pad[0x764];
    int n;
    char pad2[0x7a8 - 0x768];
    u8 flag;
} G;

extern G *d_021A8264;
extern char d_021A1C5C[];
int func_02177270(u8 a, int b);
typedef unsigned int   u32;
unsigned char func_0216B838(void);
int func_0216B908(void);
void func_02034714(const char *expr, u32 line, const char *file);
void func_02155C70(void);

void func_02155C8C(void)
{
    int i, j;

    for (i = 0; i < 2; i++)
        func_02177270(i, 0);
    if (func_0216B838() == 0) {
        for (j = 0; j < d_021A8264->n; j++) {
            if (j != func_0216B838() && (func_0216B908() & (1 << j)) != 0) {
                if (func_02177270(j, 10000) == 0)
                    func_02034714(d_021A1C5C, 0, d_021A1C5C);
            }
        }
    } else {
        if (func_02177270(0, 10000) == 0)
            func_02034714(d_021A1C5C, 0, d_021A1C5C);
    }
    d_021A8264->flag = 1;
    func_02155C70();
}
