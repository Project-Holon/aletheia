/*
 * function: func_021D61FC
 * address: 0x021D61FC
 * packet: pkt_ov115_021D61FC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203CF04 0x0203CF04 arm
 *   func_0203D0D0 0x0203D0D0 arm
 *   func_0203C968 0x0203C968 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_0203CDBC 0x0203CDBC arm
 *   func_0203CEAC 0x0203CEAC arm
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6274 0x021D6274 thumb ov115
 *   func_021D625C 0x021D625C thumb ov115
 *   func_021D6328 0x021D6328 thumb ov115
 */
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern void func_0203CF04(void);
extern void func_0203D0D0(void);
extern void func_0203C968(void);
extern void func_0203CA04(void);
extern int func_0203CDBC(void);
extern int func_0203CEAC(int a0);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D6274(unsigned char *p);
extern void func_021D625C(unsigned char *p);
typedef unsigned char  u8;
extern void func_021D6328(u8 *p);
void func_021D61FC(void *p) {
    if (func_0200FB24()) {
        func_0203CF04(); func_0203D0D0(); func_0203C968(); func_0203CA04(); func_0200FBA0();
    }
    if (func_0203CDBC()) {
        func_021D6134(p,(int)((void (*)(void))func_021D6274),0x1bf);
        return;
    }
    if (func_0203CEAC((int)func_021D6328)) func_021D6134(p,(int)((void (*)(void))func_021D625C),0x1c7);
}
