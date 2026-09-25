/*
 * function: func_0218441C
 * address:  0x0218441C
 * packet:   pkt_0218441C
 * region:   ov168
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02006D64   0x02006D64  thumb
 *   func_02006D94   0x02006D94  thumb
 *   func_0218448C   0x0218448C  thumb
 *   func_02184470   0x02184470  thumb
 *
 * Latch the polled flag into p[0x34], arming and disarming the p[0x2c]
 *   work item while p[0x30] tracks the busy state.
 */


extern void func_02006D64(int);
extern int func_02006D94(void);
extern void func_0218448C(int *);
extern void func_02184470(int *);

void func_0218441C(int *p)
{
    int x;
    int y;
    func_02006D64(1);
    x = func_02006D94();
    if (x != 0 && p[13] != 0)
        goto end;
    if (p[12] == 0) {
        if (p[10] != 0) {
            func_0218448C(p);
            p[11] = 1;
        }
        p[12] = 1;
    }
    if (x == 0)
        goto end;
    if (p[13] != 0)
        goto end;
    y = p[11];
    p[12] = 0;
    if (y != 0) {
        func_02184470(p);
        p[11] = 0;
    }
end:
    p[13] = x;
}
