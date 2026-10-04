/*
 * function: func_021DB304
 * address: 0x021DB304
 * packet: pkt_ov119_021DB304
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: non-const table keeps reads after the p+0x800 store (const: 16 bytes differ).
 * volatile: hardware read/write at 021DB358/021DB35C and 021DB3C6/021DB3CA.
 * prototype: 02035C08 returns the live r0 result of 02035BBC (full original
 * 02035BBC and matched forwarder read); caller uses it despite void header.
 * symbols:
 *   func_020435F4 0x020435F4 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_02035C08 0x02035C08 arm
 *   d_021E8044 0x021E8044 data a1
 *   func_021E6FD4 0x021E6FD4 thumb ov119
 *   func_021DB1BC 0x021DB1BC thumb ov119
 *   func_020061E4 0x020061E4 thumb
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DB2E8 0x021DB2E8 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_021E0EF4 0x021E0EF4 thumb ov119
 *   func_021B63D0 0x021B63D0 thumb ov067
 *   func_021B6448 0x021B6448 thumb ov067
 *   func_021E5D84 0x021E5D84 thumb ov119
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021DF7AC 0x021DF7AC thumb ov119
 *   func_021E71E0 0x021E71E0 thumb ov119
 *   func_021DBB6C 0x021DBB6C thumb ov119
 *   func_021E6700 0x021E6700 thumb ov119
 *   func_021E7058 0x021E7058 thumb ov119
 *   func_021DB290 0x021DB290 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u8 a,b,c,d; } Rect;
extern Rect d_021E8044[];
extern void func_020435F4(u32);
extern int func_021E12AC(char *),func_02035C08(const void *);
extern void func_021E6FD4(char *,int,int);
extern int func_021DB1BC(char *,int);
extern void func_020061E4(int),func_021D8E84(void *,int),func_021DB2E8(void *);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021E0EF4(void *,int,int,int,int,int);
struct S;
extern void func_021B63D0(struct S *p);
extern int func_021B6448(u8 *);
extern void func_021E5D84(char *),func_021E1098(char *),func_021DF7AC(void *,int);
extern void func_021E71E0(void *,int),func_021DBB6C(char *),func_021E6700(void *),func_021E7058(void *),func_021DB290(void *);
void func_021DB304(char *p)
{
    int index;
    func_020435F4(31);
    if(func_021E12AC(p)) {
        index=func_02035C08(d_021E8044);
        if(index!=-1) {
            *(u32 *)(p+0x800)=(u32)index+1u;
            func_021E6FD4(p,d_021E8044[index].c,d_021E8044[index].a);
            if(func_021DB1BC(p,index)) {
                func_020061E4(0x548);
                *(volatile u32 *)0x04001000 &= 0xffff1fff;
                func_021D8E84(p,(int)func_021DB2E8);
                return;
            }
            func_02045CAC((struct MsgBank *)(*(int *)(p+0x720)),0x34,(void *)(*(int *)(p+0x738)));
            func_021E0EF4(p,1,1,1,0x1d,4);
            func_020061E4(0x557);
        }
        func_021B63D0(*(void **)(p+0x9c0));
        if(func_021B6448(*(u8 **)(p+0x9c0))==1) {
            func_020435F4(0x1a);
            *(int *)(p+0x800)=0;
            func_021E5D84(p);
            func_021E1098(p);
            *(volatile u32 *)0x04001000 &= 0xffff1fff;
            func_021DF7AC(p,1);
            func_021E71E0(p,0);
            func_021DBB6C(p);
            func_021E6700(p);
            func_021E7058(p);
            func_021D8E84(p,(int)func_021DB290);
        }
    }
}
