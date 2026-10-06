/*
 * function: func_021DA578
 * address: 0x021DA578
 * packet: pkt_ov129_021DA578
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201EC64 0x0201EC64 thumb
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_020457B0 0x020457B0 arm
 *   func_0201EFA4 0x0201EFA4 thumb
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201C7A4 0x0201C7A4 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045C04 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   func_02045334 0x02045334 arm
 *   func_020409B4 0x020409B4 arm
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef short s16;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec;
struct U16Vec;
struct WordSet;
extern struct WordSet *func_0201EC64(u32 heap);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02045C04(struct Rec *rec);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_02045334(struct Descriptor *d);
extern void func_020409B4(u32);
void func_021DA578(void *p,int a,void *b,u32 c)
{
    void *ws=func_0201EC64(50);
    void *bank=func_02045B38(0,2,25,50);
    void *msg=func_02045EC0(bank,a);
    void *out=func_020457B0(88,50);
    func_0201EFA4(ws,0,c,2,2,1);
    func_0201F250(ws,out,msg);
    func_02043B5C(func_02045770(p),15);
    func_0201C7A4(func_02045770(p),0,0,out,b);
    func_02045808(out);
    func_02045808(msg);
    func_02045C04(bank);
    func_0201ED04(ws);
    func_02045334(p);
    func_020409B4(4);
}
