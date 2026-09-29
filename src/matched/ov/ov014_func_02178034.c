/*
 * function: func_02178034
 * address:  0x02178034
 * packet:   pkt_ov014_02178034
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   func_021780E4  0x021780E4  thumb  ov014
 *   func_0217758C  0x0217758C  thumb  ov014
 *   func_02177560  0x02177560  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_021775AC  0x021775AC  thumb  ov014
 *   func_02177FF0  0x02177FF0  thumb
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021797A4;
void func_021780E4(u32 a);
void func_0217758C(u8 *p);
void func_02177560(void);
void func_0217933C(void *fn);
void func_0217727C(u8 *p, void *fn);
void func_021775AC(void);
void func_02177FF0(void);

int func_02178034(void)
{
    u8 *p = g_021797A4;
    if (p == 0)
        return 0;
    func_021780E4(0);
    func_0217758C(p);
    func_02177560();
    func_0217933C(func_021775AC);
    p[0xCE8] = 1;
    func_0217727C(g_021797A4, func_02177FF0);
    return 1;
}
