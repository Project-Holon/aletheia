/*
 * function: func_021BA984
 * address: 0x021BA984
 * packet: pkt_ov223_021BA984
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_02049238 0x02049238 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021BC520 0x021BC520 thumb
 *   func_0204B294 0x0204B294 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_021BAA5C 0x021BAA5C thumb
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct Request {u16 x,y,z;u8 a,b;};
extern void *func_020490F4(unsigned,unsigned);
extern int func_0204AC18(void *,unsigned,unsigned,unsigned,u16,u16,u16);
extern int func_0204A6C8(void *,unsigned,unsigned,unsigned,u16);
extern int func_0204AF28(void *,unsigned,unsigned,unsigned);
extern void func_02049238(void *);
extern void func_02082BCC(void *,int,unsigned);
extern void *func_021BC520(void *);
extern void *func_0204B294(void *,int,int,int,void *,u16,u16);
extern void func_0204B92C(void *,unsigned);
extern void func_021BAA5C(void *,int);
void func_021BA984(char *p)
{
    void *object;
    struct Request request;
    object=func_020490F4(205,*(u16 *)p);
    *(int *)(p+540)=func_0204AC18(object,11,0,0,0,1,*(u16 *)p);
    *(int *)(p+536)=func_0204A6C8(object,17,0,0,*(u16 *)p);
    *(int *)(p+544)=func_0204AF28(object,24,28,*(u16 *)p);
    func_02049238(object);
    func_02082BCC(&request,0,8);
    request.x=66;request.y=39;request.z=0;request.a=0;request.b=2;
    *(void **)(p+548)=func_0204B294(func_021BC520(*(void **)(p+20)),*(int *)(p+536),*(int *)(p+540),*(int *)(p+544),&request,0,*(u16 *)p);
    func_0204B92C(*(void **)(p+548),1);
    func_021BAA5C(p,0);
}
