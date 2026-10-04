/*
 * function: func_02177DB0
 * address:  0x02177DB0
 * packet:   pkt_ov014_02177DB0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   d_02179680     0x02179680  data  ov014  a2
 *   func_0203D798  0x0203D798  arm
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_02178524  0x02178524  thumb  ov014
 *   func_021795C0  0x021795C0  thumb  ov014
 *   func_0217933C  0x0217933C  thumb  ov014
 *   func_0217727C  0x0217727C  thumb
 *   func_0217771C  0x0217771C  thumb  ov014
 *   func_021775AC  0x021775AC  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *g_021797A4;
extern u16 d_02179680[2];
void *func_0203D798(void);
int func_02178E4C(void);
int func_02178524(u32 a, const u16 *b, u32 c);
void func_021795C0(unsigned v);
void func_0217933C(void *fn);
void func_0217727C(u8 *p, u32 v);
int func_0217771C(u8 *obj);
int func_021775AC(int a, int b, int c);

void func_02177DB0(void)
{
    u8 *st = func_0203D798();
    u16 tab[2];
    tab[0] = d_02179680[0];
    tab[1] = d_02179680[1];
    if (func_02178E4C() == 1 || func_02178E4C() == 2) {
        func_02178524(tab[st[0x64]], (const u16 *)(g_021797A4 + 0xCDE), 0);
        func_021795C0((unsigned int)func_0217771C);
        func_0217933C(func_021775AC);
        g_021797A4[0xCE8] = 1;
        func_0217727C(g_021797A4, 0);
    }
}
