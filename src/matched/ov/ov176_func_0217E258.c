/*
 * function: func_0217E258
 * address: 0x0217E258
 * packet: pkt_ov176_0217E258
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_0203D1A4 0x0203D1A4 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 */
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_0203D1A4(int);
extern int func_0201A918(void);
extern void func_0203D3F8(int, unsigned char, int, unsigned, int, int, int, int);
void func_0217E258(int unused, int arg)
{
    int flag;
    int obj;
    unsigned n;
    int r;
    r = func_0203D1A4((int)func_020399A8());
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = (int)func_020399A8();
    n = func_0201A918();
    func_0203D3F8(obj, flag, 0x1F01, n, arg, 1, 1, 1);
}
