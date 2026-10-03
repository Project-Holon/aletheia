/*
 * function: func_021B7750
 * address: 0x021B7750
 * packet: pkt_ov180_021B7750
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049F78 0x02049F78 arm
 *   func_0204ADEC 0x0204ADEC arm
 *   func_020307B0 0x020307B0 arm
 *   func_02049238 0x02049238 arm
 *   d_021B82D4 0x021B82D4 data a4
 */
typedef unsigned short u16;

typedef unsigned int   u32;
extern void *func_020490F4(u32 id, u16 heap);
extern void *func_02049F78(unsigned char *,unsigned,void **,int);
extern void func_0204ADEC(int,void *,int);
extern void func_020307B0(void *);
extern void func_02049238(unsigned char *);
extern unsigned d_021B82D4[];
void func_021B7750(char *p) {
    void *out;
    unsigned char *bank;
    void *buffer;
    bank=func_020490F4(216,0x808d);
    buffer=func_02049F78(bank,d_021B82D4[*(unsigned short *)(p+0x915a)],&out,141);
    func_0204ADEC(*(int *)(p+0x90ec),out,1);
    func_020307B0(buffer);
    func_02049238(bank);
}
