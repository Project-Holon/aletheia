/*
 * function: func_021DE570
 * address: 0x021DE570
 * packet: pkt_ov121_021DE570
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0203CA98 0x0203CA98 arm
 *   func_0203CA04 0x0203CA04 arm
 *   func_02059F18 0x02059F18 arm
 *   func_0200FBB0 0x0200FBB0 thumb
 *   func_0200F83C 0x0200F83C thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 *   func_0200FA84 0x0200FA84 thumb
 */
extern int func_0200FB24(void);
extern char *func_0203CA98(void);
extern void func_0203CA04(void);
extern void func_02059F18(void);
extern void func_0200FBB0(void);
extern void func_0200F83C(void);
extern void func_0200FBA0(void);
extern void func_0200FA84(void);
int func_021DE570(char *p)
{
    int result=0;
    if (func_0200FB24()) {
        switch (*(unsigned *)(func_0203CA98()+4)) {
        case 1: case 2: case 3: case 4: case 5: case 6:
            if (*(int *)(p+0x790)==1) return result;
            func_0203CA04();
            func_02059F18();
            func_0200FBB0();
            func_0200F83C();
            func_0200FBA0();
            result=1; break;
        case 7:
            func_0203CA04();
            func_0200FA84();
            result=3; break;
        case 0: default: break;
        }
    }
    return result;
}
