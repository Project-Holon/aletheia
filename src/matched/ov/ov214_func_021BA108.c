/*
 * function: func_021BA108
 * address: 0x021BA108
 * packet: pkt_ov214_021BA108
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: 0201CCE4's r0 remains live and is stored at +5c after the call;
 * its caller declaration returns that word despite the own source's void.
 * extent-tail: 021BA16A alignment padding (two zero bytes).
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045808 0x02045808 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void*func_02045770(void*);
extern void func_02043B5C(void*,u8);
extern void func_0201CE48(void*);
extern void func_02045808(void*);
extern void*func_02045EC0(void*,unsigned);
extern signed char func_02012FFC(void);
extern void*func_0201CCE4(unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,unsigned,u16,u16);
void func_021BA108(int unused,char*p,unsigned entry,int v)
{
    int x;
    func_02043B5C(func_02045770(*(void**)(p+0x6c)),15);
    if(*(void**)(p+0x5c))func_0201CE48(*(void**)(p+0x5c));
    if(*(void**)(p+0x78))func_02045808(*(void**)(p+0x78));
    *(void**)(p+0x78)=func_02045EC0(*(void**)(p+0x58),entry);
    x=func_02012FFC();
    *(void**)(p+0x5c)=func_0201CCE4(*(unsigned*)(p+0x6c),0,0,*(unsigned*)(p+0x78),*(unsigned*)(p+8),x,*(unsigned*)(p+0x68),2,*(u16*)p,15);
    *(int*)(p+0x60)=v;
}
