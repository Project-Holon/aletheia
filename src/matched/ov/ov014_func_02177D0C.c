/*
 * function: func_02177D0C
 * address:  0x02177D0C
 * packet:   pkt_ov014_02177D0C
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_02177CE4  0x02177CE4  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021797A4;
void func_0217933C(void *fn);
void func_0217727C(u32 *p, u32 v);
int func_021775AC(int a, int b, int c);
void func_02177CE4(void);

int func_02177D0C(int a)
{
    u8 *p = g_021797A4;
    if (*(u32 *)p != 0)
        return 0;
    if (a != 0)
        p[0xCE6] = 0xff;
    func_0217933C(func_021775AC);
    g_021797A4[0xCE8] = 1;
    func_0217727C((u32 *)g_021797A4, (u32)func_02177CE4);
    return 1;
}
