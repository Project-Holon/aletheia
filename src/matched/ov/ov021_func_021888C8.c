/*
 * function: func_021888C8
 * address:  0x021888C8
 * packet:   pkt_ov021_021888C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02047CE4  0x02047CE4  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0218E104  0x0218E104  thumb  ov021
 *   func_02189A80  0x02189A80  thumb  ov021
 *   func_02189084  0x02189084  thumb  ov021
 */

typedef unsigned short u16;

void func_02047CE4(void);
unsigned int func_0203630C(void);
void func_0218E104(int a, u16 b);
int func_02189A80(void *o);
void func_02189084(void *o);

void func_021888C8(char *o)
{
    volatile u16 *r = (volatile u16 *)0x04000204;

    func_02047CE4();
    func_0218E104(*(int *)(o + 0x10), func_0203630C());
    *(int *)(o + 0x100) = func_02189A80(o);
    *r = *r & 0xFFFF7FFF;
    func_02189084(o);
    *r = *r | 0x8000;
}
