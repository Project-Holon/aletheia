/*
 * function: func_021BA5C8
 * address: 0x021BA5C8
 * packet: pkt_ov214_021BA5C8
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_021BA4E8 0x021BA4E8 thumb ov214
 */
typedef unsigned short u16;
extern void*func_02045EC0(void*,unsigned);
extern void*func_02045770(void*);
extern void func_02045808(void*);
extern void func_0201C724(void*,unsigned,unsigned,unsigned,unsigned,unsigned,u16);
extern void func_021BA4E8(void*,char*);
void func_021BA5C8(void*obj,char*p)
{
    void*h;
    h=func_02045EC0(*(void**)(p+0x58),19);
    func_0201C724(*(void**)(p+0x10),(unsigned)func_02045770(*(void**)(p+0x8c)),4,1,(unsigned)h,*(unsigned*)(p+8),0x440);
    func_02045808(h);
    *(int*)(p+0x9c)=0;
    h=func_02045EC0(*(void**)(p+0x58),*(unsigned*)(p+0x2a4));
    func_0201C724(*(void**)(p+0x10),(unsigned)func_02045770(*(void**)(p+0x90)),4,1,(unsigned)h,*(unsigned*)(p+8),0x440);
    func_02045808(h);
    *(int*)(p+0xa0)=0;
    func_021BA4E8(obj,p);
}
