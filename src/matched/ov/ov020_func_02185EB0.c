/*
 * function: func_02185EB0
 * address:  0x02185EB0
 * packet:   pkt_ov020_02185EB0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02012870  0x02012870  thumb
 *   func_0201284C  0x0201284C  thumb
 *   func_02014068  0x02014068  thumb
 *   func_020128C0  0x020128C0  thumb
 *   func_02014204  0x02014204  thumb
 *   func_02013C50  0x02013C50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;

int func_02012870(int a);
short *func_0201284C(int a);
typedef unsigned int   u32;
u32 func_02014068(u32 id);
void func_020128C0(int a, void *b);
void func_02014204(void *buf, int n);
u32 func_02013C50(u32 id);

void func_02185EB0(int a, u16 *p)
{
    int r7 = func_02012870(a);
    short *r6 = func_0201284C(a);
    u8 buf[0x1c];

    if (func_02014068(p[2])) {
        if (r6[2] == 0x88) {
            func_020128C0(a, (void *)r7);
        } else if (!func_02014068((u16)r6[2])) {
            func_02014204(buf, 0xd6);
            func_020128C0(a, buf);
        }
    }
    if (r6[2] == 0x9e) {
        if (func_02013C50(p[2]))
            func_020128C0(a, (void *)r7);
    }
}
