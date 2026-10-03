/*
 * function: func_02177FF0
 * address:  0x02177FF0
 * packet:   pkt_ov014_02177FF0
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   g_021797A4     0x021797A4  data  ov014  a4
 *   func_02178E4C  0x02178E4C  thumb  ov014
 *   func_021785B4  0x021785B4  thumb
 *   func_020056EC  0x020056EC  thumb
 *   func_0217727C  0x0217727C  thumb
 *   func_021773E0  0x021773E0  thumb  ov014
 *   func_02177FC4  0x02177FC4  thumb  ov014
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *g_021797A4;
int func_02178E4C(void);
int func_021785B4(void *fn, u32 b, u32 c);
u32 func_020056EC(u32 n);
void func_0217727C(u8 *p, void *fn);
int func_021773E0(u8 *p);
void func_02177FC4(unsigned char *p);

void func_02177FF0(u8 *a)
{
    if (func_02178E4C() == 1) {
        if (func_021785B4(func_021773E0, 0, 0) != 0) {
            a[0xCF2] = func_020056EC(0x28) + 0x3C;
            func_0217727C(g_021797A4, func_02177FC4);
        }
    }
}
