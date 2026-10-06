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
typedef unsigned int   u32;
struct Link;
extern u32 func_0203D1A4(struct Link *p);
extern int func_0201A918(void);
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
int func_0217E258(int unused, int arg)
{
    int flag;
    int obj;
    unsigned n;
    int r;
    r = func_0203D1A4((struct Link *)((int)func_020399A8()));
    flag = 1;
    if (r != 0)
        flag = 0;
    obj = (int)func_020399A8();
    n = func_0201A918();
    return func_0203D3F8((int)obj, (unsigned char)flag, (int)0x1F01, n, (int)arg, (int)1, (int)1, (int)1);
}
