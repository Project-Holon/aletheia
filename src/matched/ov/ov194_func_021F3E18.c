/*
 * function: func_021F3E18
 * address: 0x021F3E18
 * packet: pkt_ov194_021F3E18
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201EE84 0x0201EE84 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201F250 0x0201F250 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 */
extern void func_0201EE84(int,int);
extern int func_02045770(int);
extern void func_02043B5C(int,unsigned char);
extern int func_02045EC0(unsigned,unsigned);
extern void func_0201F250(int,void *,int);
extern void func_0201C6FC(int,int,int,int,int,int);
extern void func_02045808(int);
void func_021F3E18(char *p,int value) {
    int text,window;
    func_0201EE84(*(int *)(p+24),0);
    func_02043B5C(func_02045770(*(int *)(p+20)),*(unsigned short *)(p+32));
    text=func_02045EC0(*(unsigned *)p,value);
    func_0201F250(*(int *)(p+24),*(void **)(p+28),text);
    window=*(int *)(p+16);
    func_0201C6FC(window,func_02045770(*(int *)(p+8)),0,0,*(int *)(p+28),*(int *)(p+4));
    *(unsigned char *)(p+12)=1;
    func_02045808(text);
}
