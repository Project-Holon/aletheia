/*
 * unit: yes
 * function: func_021DC32C, func_021DC498
 * address: 0x021DC32C
 * packet: pkt_ov093_021DC32C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021D5D14 0x021D5D14 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88B4 0x021C88B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F0658 0x021F0658 data a4
 * Pointer-sum grouping preserves both candidate-list load sequences.
 * Signed byte storage of -1 preserves the subtraction from the live one.
 */
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern u8 *func_021C8120(void *a, int k);
extern int func_021D5D14(void *m, u32 e, int d);
extern u32 func_021D78AC(u32 k);
extern void func_021C88B4(void *a, int k, int b);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
void func_021DC32C(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u8 n1;
    u8 n2;
    u32 i;
    u8 n;
    u32 j;
    u8 first;
    u8 second;
    u16 pair;
    u8 *r;
    if (c == func_021D775C(2)) {
        buf = func_021C8120(b, 0xb6);
        m = func_021C7CF4(b, c);
        n2 = 0;
        n1 = 0;
        for (i = 0; i < 7; i++) {
            if (func_021D5D14(m, i + 1, 1)) buf[0xa8 + n1++] = i + 1;
            if (func_021D5D14(m, i + 1, -1)) buf[0xaf + n2++] = i + 1;
        }
        second = 0;
        first = 0;
        if (n1 == 0 && n2 != 0) {
            second = (buf + func_021D78AC(n2))[0xaf];
        } else if (n1 != 0 && n2 == 0) {
            first = (buf + func_021D78AC(n1))[0xa8];
        } else if (n1 != 0 && n2 != 0) {
            n = 0;
            for (i = 0; i < n1; i++) {
                for (j = 0; j < n2; j++) {
                    if (buf[0xa8 + i] != buf[0xaf + j]) {
                        ((u16 *)buf)[n++] = (buf[0xa8 + i] << 8) | buf[0xaf + j];
                        if (n >= 0x54) break;
                    }
                }
            }
            pair = ((u16 *)buf)[func_021D78AC(n)];
            first = pair >> 8;
            second = pair;
        }
        func_021C88B4(b, 2, c);
        if (first) {
            r = (u8 *)func_021C88A4(b, 14, c);
            r[15] = 1;
            r[16] = c;
            *(u32 *)(r + 4) = first;
            r[12] = 2;
            func_021C88C8(b, r);
        }
        if (second) {
            r = (u8 *)func_021C88A4(b, 14, c);
            r[15] = 1;
            r[16] = c;
            *(u32 *)(r + 4) = second;
            *(s8 *)(r + 12) = -1;
            func_021C88C8(b, r);
        }
        func_021C88B4(b, 3, c);
    }
}
extern u8 d_021F0658[];
void *func_021DC498(int *p) { *p = 1; return d_021F0658; }
