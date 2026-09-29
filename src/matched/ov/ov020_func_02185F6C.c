/*
 * function: func_02185F6C
 * address:  0x02185F6C
 * packet:   pkt_ov020_02185F6C
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045B38  0x02045B38  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045A38  0x02045A38  arm
 *   func_02008F08  0x02008F08  thumb
 *   func_02008F88  0x02008F88  thumb
 *   func_02008FA0  0x02008FA0  thumb
 *   func_02008FA8  0x02008FA8  thumb
 *   func_02008FB4  0x02008FB4  thumb
 *   func_02008FBC  0x02008FBC  thumb
 *   func_02008FD8  0x02008FD8  thumb
 *   func_02008FC4  0x02008FC4  thumb
 *   func_02008FEC  0x02008FEC  thumb
 *   func_0200903C  0x0200903C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045C04  0x02045C04  arm
 *   d_02187DA4  0x02187DA4  data  ov020  a4
 *   d_02187DAC  0x02187DAC  data  ov020  a4
 *   d_02187DB4  0x02187DB4  data  ov020  a4
 */

int func_02045B38(int a, int b, int c, int d);
int func_02045EC0(int a, int b);
void func_02045A38(int a, void *b, int c);
int func_02008F08(int a);
void func_02008F88(int a, void *b);
void func_02008FA0(int a, int b);
void func_02008FA8(int a, int b);
void func_02008FB4(int a, int b);
void func_02008FBC(int a, int b);
void func_02008FD8(int a, void *b, int c);
void func_02008FC4(int a, int b);
int func_02008FEC(int a);
void func_0200903C(int a, int b, int c, int d);
void func_020307B0(int a);
void func_02045808(int a);
void func_02045C04(int a);
extern char d_02187DA4[];
extern char d_02187DAC[];
extern char d_02187DB4[];

void func_02185F6C(int a)
{
    int r6 = func_02045B38(0, 2, 0xbe, 1);
    int r7 = func_02045EC0(r6, 0x3b);
    int r4;
    char buf[0x20];

    func_02045A38(r7, buf, 0x10);
    r4 = func_02008F08(1);
    func_02008F88(r4, buf);
    func_02008FA0(r4, 1);
    func_02008FA8(r4, 3);
    func_02008FB4(r4, 2);
    func_02008FBC(r4, 0x15);
    func_02008FD8(r4, d_02187DA4, 0);
    func_02008FD8(r4, d_02187DAC, 1);
    func_02008FD8(r4, d_02187DB4, 2);
    func_02008FC4(r4, 0x58F);
    func_0200903C(func_02008FEC(a), 0, 0, r4);
    func_020307B0(r4);
    func_02045808(r7);
    func_02045C04(r6);
}
