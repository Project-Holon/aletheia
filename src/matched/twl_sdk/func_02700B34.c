/*
 * function: func_02700B34
 * address:  0x02700B34
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC0  0x02732FC0  data twl a2
 *   data_02732FF8  0x02732FF8  data twl a2
 *   data_02733008  0x02733008  data twl a2
 *   data_0273302C  0x0273302C  data twl a2
 *   func_0208C86C  0x0208C86C  arm twl a2
 *   func_02731590  0x02731590  arm twl a2
 *   func_02700DB8  0x02700DB8  arm twl a2
 *   func_02702080  0x02702080  arm twl a2
 *   func_0270212C  0x0270212C  arm twl a2
 *   func_027021E4  0x027021E4  arm twl a2
 *   func_020885A0  0x020885A0  arm twl a2
 *   func_0270223C  0x0270223C  arm twl a2
 *   func_02702268  0x02702268  arm twl a2
 *   func_02702208  0x02702208  arm twl a2
 *   func_02084774  0x02084774  arm twl a2
 *   func_02084998  0x02084998  arm twl a2
 *   func_02085638  0x02085638  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02732FC0[];
extern u32 data_02732FF8[];
extern u32 data_02733008[];
extern u32 data_0273302C[];

extern void func_0208C86C(u32*);
extern void func_02731590(u32*);
extern void func_02700DB8(u32);
extern void func_02702080(void);
extern void func_0270212C(void);
extern void func_027021E4(void);
extern void func_020885A0(u32, u32);
extern void func_0270223C(u32);
extern void func_02702268(u32);
extern void func_02702208(u32);
extern void func_02084774(u32, u32);
extern void func_02084998(u32);
extern void func_02085638(u32*, u32);

void func_02700B34(void) {
    if (data_02732FC0[0] == 0) return;
    data_02732FC0[0] = 0;
    func_0208C86C(data_02732FF8);
    func_02731590(data_02733008);
    func_02700DB8(0);
    func_02702080();
    func_0270212C();
    func_027021E4();
    func_020885A0(0x15, 0);
    func_0270223C(0);
    func_02702268(0);
    func_02702208(0);
    func_02084774(0x02000000, 0);
    func_02084998(0x02000000);
    func_02085638(data_0273302C, 0);
}
