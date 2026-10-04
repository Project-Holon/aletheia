/*
 * function: func_021E1A44
 * address: 0x021E1A44
 * packet: pkt_ov119_021E1A44
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045B38 0x02045B38 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02045770 0x02045770 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef signed short s16;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct MsgBank;
struct Rec;
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u8 func_02018598(void *p);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_0201C7A4(void *,s16,s16,void *,void *);
extern void func_02045C04(struct Rec *rec);
void func_021E1A44(int a,int b,int x,int y,char *p)
{
    int s;
    s=(int)func_02045B38(0,2,24,*(u16 *)(p+0x5f4));
    func_02045CAC((struct MsgBank *)s,func_02018598((void *)a),(void *)(*(int *)(p+0x730)));
    func_0201C7A4(func_02045770((struct Descriptor *)b),x,y,*(void **)(p+0x730),*(void **)(p+0x728));
    func_02045C04((struct Rec *)s);
}
