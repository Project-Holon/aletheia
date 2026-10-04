/*
 * function: func_021B6C70
 * address: 0x021B6C70
 * packet: pkt_ov174_021B6C70
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02005728 0x02005728 thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008550 0x02008550 thumb
 *   func_021B7004 0x021B7004 thumb ov174
 *   func_021B6F3C 0x021B6F3C thumb ov174
 *   func_021B71B8 0x021B71B8 thumb ov174
 *   d_021B74BC 0x021B74BC data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_02005728(u32 range);
extern u8 *func_02012944(void *p);
struct Sub0200852CObj;
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern void func_021B7004(char *,char *);
extern void func_021B6F3C(char *,char *);
extern void func_021B71B8(char *,char *);
extern char d_021B74BC[];
char *func_021B6C70(char *p,int index)
{
    char *q;
    if((*(u8 **)(p+0x3c))[index]==0xff) return 0;
    q=func_02030734(*(u16 *)p,0x3c,0,d_021B74BC,0x7a);
    *(u8 *)q=index;
    *(u8 *)(q+2)=(*(u8 **)(p+0x3c))[index];
    *(u8 *)(q+3)=(*(u8 **)(p+0x3c)+index)[4];
    *(u8 *)(q+4)=0;
    *(u8 *)(q+5)=0;
    *(int *)(q+0x14)=0;
    *(int *)(q+0x34)=0;
    *(u16 *)(q+0x30)=func_02005728(0x4b);
    if(*(u8 *)(q+2)==0 && func_02008550((const struct Sub0200852CObj *)func_02012944(*(void **)(*(char **)(p+0x30)+4)))==1) *(u8 *)(q+2)=5;
    func_021B7004(p,q);
    func_021B6F3C(p,q);
    func_021B71B8(p,q);
    *(int *)(q+8)=0;
    *(int *)(q+0x10)=0;
    *(u8 *)(q+6)=func_02005728(40);
    *(u16 *)(q+0x38)=0;
    return q;
}
