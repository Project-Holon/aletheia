/*
 * function: func_021FADF8
 * address: 0x021FADF8
 * packet: pkt_ov132_021FADF8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_020605B4 0x020605B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020307B0(void *);
extern void func_02030EAC(void *);
extern void func_020605B4(void *, void *);
void func_021FADF8(char *p, char *q)
{
    func_020307B0(*(void **)(q + 8));
    func_02030EAC(*(void **)(q + 0xc));
    func_020605B4(p + 0x38, q);
    func_020307B0(q);
}
