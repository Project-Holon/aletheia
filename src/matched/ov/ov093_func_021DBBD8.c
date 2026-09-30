/*
 * unit: yes
 * function: func_021DBBD8, func_021DBCE0
 * address: 0x021DBBD8
 * packet: pkt_ov093_021DBBD8
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021C7D00 0x021C7D00 thumb ov093
 *   func_021C8120 0x021C8120 thumb ov093
 *   func_021C7F68 0x021C7F68 thumb ov093
 *   func_021D5BB0 0x021D5BB0 thumb ov093
 *   func_021D6740 0x021D6740 thumb ov093
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021D78AC 0x021D78AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F06C0 0x021F06C0 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5B40(void *p);
extern u32 func_021C7D00(void *a, int b);
extern u8 *func_021C8120(void *a, int k);
extern u8 func_021C7F68(void *p, u16 b, u8 *out);
extern int func_021D5BB0(void *p, int k);
extern u16 func_021D6740(void *p);
extern u8 func_021D5440(void *p);
extern u32 func_021D78AC(u32 k);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern void func_021C88C8(void *a, void *b);
void func_021DBBD8(int a, void *b, u8 c)
{
    u8 *buf;
    void *m;
    u32 flag;
    u8 i;
    u8 n;
    u8 selected;
    u16 value;
    u8 *r;
    if (c == func_021D775C(2) && !func_021D5B40(func_021C7CF4(b, c))) {
        flag = func_021C7D00(b, c);
        buf = func_021C8120(b, 14);
        buf[12] = func_021C7F68(b, flag | 0x200, buf);
        n = 0;
        buf[13] = 0;
        for (i = 0; i < (u32)buf[12]; i++) {
            m = func_021C7CF4(b, buf[i]);
            if (func_021D5BB0(m, 8) && func_021D6740(m)) {
                buf[6 + n++] = func_021D5440(m);
            }
        }
        if (n) {
            selected = (buf + (u8)func_021D78AC(n))[6];
            value = func_021D6740(func_021C7CF4(b, selected));
            if (value) {
                r = (u8 *)func_021C88A4(b, 0x20, c);
                *(u32 *)r |= 0x800000;
                r[6] = c;
                *(u16 *)(r + 4) = value;
                r[8] = 1;
                r[9] = selected;
                func_021C8838(r + 12, 2, 0x1ea);
                func_021C8860(r + 12, c);
                func_021C8860(r + 12, value);
                func_021C88C8(b, r);
            }
        }
    }
}
extern u8 d_021F06C0[];
void *func_021DBCE0(int *p) { *p = 1; return d_021F06C0; }
