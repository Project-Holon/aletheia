/*
 * unit: yes
 * function: func_02173FC0, func_02173FE4
 * address: 0x02173FC0
 * packet: pkt_ov011_02173FC0
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: Lead one run is EXACT*, followed by the root-claimed 02173FE4
 *       tail stub; tu verifies the complete 52-byte unit. func_021736D8's void forwarder
 *       leaves r0 live, tested at 02173FC8; func_0203D3A8's final send
 *       result is returned at 02173FE2. Follower loads a full word at
 *       02173FEA and forwards it without caller truncation.
 * symbols:
 *   func_021736D8 0x021736D8 thumb ov011
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021759F8 0x021759F8 thumb ov011
 */
typedef unsigned char u8;
typedef unsigned int u32;
int func_021736D8(void);
struct Entry;
struct Entry *func_020399A8(void);
int func_0203D3A8(int a, int b, int c, void *d);
void func_021759F8(u8 *a, int b);

int func_02173FC0(int a, u8 *b)
{
    if (func_021736D8() == 0) return 0;
    return func_0203D3A8((int)func_020399A8(), 0x214, 0x34, b + 0x78);
}

void func_02173FE4(int a, int b, int *c, u8 *d)
{
    func_021759F8(d + 0x1ac, *c);
}
