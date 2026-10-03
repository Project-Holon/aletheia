/*
 * function: func_021BC1E8
 * address:  0x021BC1E8
 * packet:   pkt_ov099_021BC1E8
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201DD68  0x0201DD68  thumb
 *   func_021BA858  0x021BA858  thumb  ov099
 *   func_021BA8EC  0x021BA8EC  thumb  ov099
 */

typedef unsigned char u8;

extern void func_0201DD68(void);
typedef unsigned int   u32;
extern u32 func_021BA858(char *p);
extern void func_021BA8EC(char *p);

int func_021BC1E8(char *p, int r)
{
    int v;

    func_0201DD68();
    v = func_021BA858(p);
    if (v == -1)
        return r;
    if (v == 0)
        *(u8 *)(p + 0x1353) = 0x44;
    else
        *(u8 *)(p + 0x1353) = 0x4A;
    func_021BA8EC(p);
    *(int *)(p + 0x1CC) = 0x8A;
    return r;
}
