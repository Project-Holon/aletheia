/*
 * function: func_021F3D70
 * address: 0x021F3D70
 * packet: pkt_ov194_021F3D70
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_0201C6C4 0x0201C6C4 thumb
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_0201C6FC 0x0201C6FC thumb
 */
extern int func_02045770(int);
extern int func_0201C6C4(int,int);
extern void func_0201C4E4(int);
extern void func_02043B5C(int,unsigned char);
extern void func_02045CAC(unsigned,unsigned,unsigned);
extern void func_0201C6FC(int,int,int,int,int,int);
void func_021F3D70(char *p,int value) {
    int window;
    while (func_0201C6C4(*(int *)(p+16),func_02045770(*(int *)(p+20))))
        func_0201C4E4(*(int *)(p+16));
    func_02043B5C(func_02045770(*(int *)(p+20)),*(unsigned short *)(p+32));
    func_02045CAC(*(unsigned *)p,value,*(unsigned *)(p+28));
    window=*(int *)(p+16);
    func_0201C6FC(window,func_02045770(*(int *)(p+8)),0,0,*(int *)(p+28),*(int *)(p+4));
    *(unsigned char *)(p+12)=1;
}
