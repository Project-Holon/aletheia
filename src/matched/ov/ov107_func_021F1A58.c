/*
 * function: func_021F1A58
 * address: 0x021F1A58
 * packet: pkt_ov107_021F1A58
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02028470 0x02028470 thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;
struct MsgBank;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
typedef unsigned char  u8;
struct CharBuf;
extern void func_0201CE48(void *);
extern void func_02045808(void *);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern void func_02045C04(void *);
extern void func_02028470(void *,int);
struct Descriptor;
extern void *func_02045770(struct Descriptor *),*func_02045EC0(void *,int),*func_0201CCE4(void *,int,int,void *,void *,int,void *,int,int,int);
#define P(k) (*(void **)(p+(k)))
#define I(k) (*(int *)(p+(k)))
void func_021F1A58(char *p,int a)
{
    void *s;
    s=func_02045B38(0,3,158,*(u16 *)p);
    if(P(0x18)){func_0201CE48(P(0x18));P(0x18)=0;}
    I(0x38)=0;I(0x58)=0;
    if(P(0x20)){func_02045808(P(0x20));P(0x20)=0;}
    func_02043B5C(func_02045770(P(0x10)),15);
    P(0x20)=func_02045EC0(s,22);
    P(0x18)=func_0201CCE4(P(0x10),0,0,P(0x20),P(0x14),a,P(12),2,*(u16 *)p,15);
    func_0201F73C(P(0x10),1,1,13);
    func_02045C04(s);
    if(I(8)==1)func_02028470(p+0x28,6);else func_02028470(p+0x28,4);
}
