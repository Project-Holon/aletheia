/*
 * function: func_021C060C
 * address: 0x021C060C
 * packet: pkt_ov110_021C060C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Own callee bodies fix arity and full word payloads; caller0490 loads heap
 *   with ldrh. The original narrows only 49990's fifth argument to u16.
 * No local arrays; p+14/+16/+18/+1a halfwords initialized before queued
 *   two-byte reads. Callback/context pointers retain their full32 bits.
 * First one EXACT476; final text freshly verified after literal move.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049B40 0x02049B40 arm
 *   func_02061CA4 0x02061CA4 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_020413B0 0x020413B0 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201C724 0x0201C724 thumb
 *   func_02045808 0x02045808 arm
 *   func_02049238 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_020490F4(unsigned int id, u16 heap);
extern void func_02049B68(u32,u32,u32,u32,u32,u16);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern int func_02061CA4(void *,u32,u32,int);
extern void func_02049658(u32,u32,u32,u32,u32,u32,u16);
extern void func_020498F4(u32,u32,u32,u32,u32,u32,u16);
extern u32 func_02049740(u32,u32,u32,u32,u32,u16);
extern u32 func_02049990(u32,u32,u32,u32,u16,u32,u32,u16);
extern void *func_02049EF4(u32,u32,u32,u32,u16);
extern void func_02049BDC(u32,u32,u32,u32,u32,u32,u16);
extern void func_020413B0(u32,u8,u8,u8,u8,u8);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
extern void *func_02045770(void *);
extern void func_02043B5C(void *,u8);
extern void *func_02045EC0(void *,u32);
extern void func_0201C724(void *,u32,u32,u32,u32,u32,u16);
extern void func_02045808(void *);
extern void func_02049238(void *);
void func_021C060C(u8 *p,u16 heap,u32 font,void *print,void *bank)
{
    void *h;
    void *str;
    h=func_020490F4((unsigned int)43,heap);
    func_02049B68((u32)h,0,0,0,288,heap);
    func_02049B68((u32)h,0,4,0,256,heap);
    func_02049B40(23,5,0,288,32,heap);
    *(u16 *)(p+0x14)=0x7fff;
    func_02061CA4((void *)15,316,(u32)(p+0x14),2);
    *(u16 *)(p+0x16)=0x7fff;
    func_02061CA4((void *)15,314,(u32)(p+0x16),2);
    func_02049658((u32)h,10,4,0,0,0,heap);
    func_020498F4((u32)h,21,4,0,0,0,heap);
    *(u32 *)p=func_02049740((u32)h,10,3,0,0,heap);
    func_02049990((u32)h,22,3,0,*(u32 *)p,0,0,heap);
    func_02049658((u32)h,11,2,0,0,0,heap);
    *(void **)(p+4)=func_02049EF4((u32)h,23,0,(u32)(p+8),heap);
    func_02049BDC((u32)h,4,4,128,256,32,heap);
    *(u16 *)(p+0x18)=0x294b;
    func_02061CA4((void *)31,284,(u32)(p+0x18),2);
    *(u16 *)(p+0x1a)=0x5694;
    func_02061CA4((void *)31,286,(u32)(p+0x1a),2);
    func_02049658((u32)h,18,5,0,0,0,heap);
    func_020498F4((u32)h,24,5,0,0,0,heap);
    func_020413B0(5,0,0,32,32,8);
    *(u32 *)(p+0x24)=func_020450F0(5,3,5,26,7,8,1);
    func_02043B5C(func_02045770(*(void **)(p+0x24)),7);
    str=func_02045EC0(bank,21);
    func_0201C724(print,(u32)func_02045770(*(void **)(p+0x24)),2,4,(u32)str,font,0x39e7);
    *(u32 *)(p+0x28)=1;
    func_02045808(str);
    func_02049238(h);
}
