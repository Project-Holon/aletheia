/*
 * function: func_021B9D48
 * address: 0x021B9D48
 * packet: pkt_ov218_021B9D48
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021BB060 0x021BB060 data ov218 a4
 *   template_021BB060 0x021BB060 data ov218 a4
 *   tbl_021BAC80 0x021BAC80 data ov218 a4
 *   func_021B7754 0x021B7754 thumb ov067
 *   func_021B7A10 0x021B7A10 thumb ov067
 *   func_021B7A4C 0x021B7A4C thumb ov067
 *   func_021B79E4 0x021B79E4 thumb ov067
 *   func_020490F4 0x020490F4 arm
 *   func_02049238 0x02049238 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045C04 0x02045C04 arm
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct Template {u8 pad[0x18];u8 page;u8 pad19;u16 start;u8 pad1c[8];void *owner;} Template;
extern Template d_021BB060;
extern Template template_021BB060;
extern int tbl_021BAC80[];
extern void *func_021B7754(Template *,u32);
extern void func_021B7A10(void *,void *,u32,u32,u32);
struct MsgBank;
struct Rec;
extern void func_021B7A4C(u8 *p, u8 *a, u32 b, u32 c, u32 d);
extern void func_021B79E4(char *ctx, unsigned first, unsigned second);
extern void *func_020490F4(u32,u16);
extern void func_02049238(void *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02045C04(struct Rec *rec);
void func_021B9D48(char *p)
{
    int i,value;
    u32 offset;
    int disabled;
    void *archive,*bank;
    d_021BB060.owner=p;
    value=**(u8 **)(p+0x20);
    if(value<=1)value=2;
    for(i=0;i<130;i++) {
        if(131-i==value) {
            if(i>126) {
                d_021BB060.page=i-126;
                d_021BB060.start=i-d_021BB060.page;
            } else d_021BB060.start=i;
        }
    }
    *(void **)(p+0x2c)=func_021B7754(&template_021BB060,*(u16 *)p);
    archive=func_020490F4(193,*(u16 *)p);
    func_021B7A10(*(void **)(p+0x2c),archive,3,0,0);
    func_021B7A10(*(void **)(p+0x2c),archive,4,0,1);
    func_021B7A4C(*(void **)(p+0x2c),archive,1,2,3);
    func_02049238(archive);
    bank=func_02045B38(0,2,229,*(u16 *)p);
    for(i=0;i<130;i++) {
        offset=i*4;
        disabled=1;
        if(*(u32 *)(p+0x34+offset)==1)disabled=0;
        func_021B79E4(*(void **)(p+0x2c),disabled,i);
        if(disabled==0)
            *(void **)(*(char **)(p+0x28)+0x2c+offset)=func_02045EC0(bank,*(int *)((char *)tbl_021BAC80+offset));
        else
            *(void **)(*(char **)(p+0x28)+0x2c+offset)=func_02045EC0(bank,238);
    }
    func_02045C04(bank);
}
