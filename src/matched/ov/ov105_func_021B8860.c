/*
 * function: func_021B8860
 * address: 0x021B8860
 * packet: pkt_ov105_021B8860
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 248-byte function; 021B8958..021B8B20 is overlay rodata.
 * lever: one-case switch retains conditional-plus-unconditional dispatch.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200A8A0 0x0200A8A0 thumb
 *   func_02008530 0x02008530 thumb
 *   func_0200A9A4 0x0200A9A4 thumb
 *   func_0201292C 0x0201292C thumb
 *   func_02007FB8 0x02007FB8 thumb
 *   func_02007E50 0x02007E50 thumb
 *   func_020084F4 0x020084F4 thumb
 *   func_02008550 0x02008550 thumb
 *   func_0200AA68 0x0200AA68 thumb
 *   func_02012F2C 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 * abi: 084F4's full empty body preserves the input r0 consumed at8890;
 *   12F2C's full body forwards its live r0 result from071CC/319A4 to08DF0.
 *   The matched071CC tail-call and full319A4 body return that word;
 *   original8944..894A forwards it with r1=113. No callee source changed.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned u32;
struct Big;
struct BigObj;
struct Ctx;
struct Sub02008C20Obj;
struct T0200A9A4;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200A8A0(void *);
extern u32 func_02008530(void *);
extern int func_0200A9A4(struct T0200A9A4 *o, u32 v);
extern void *func_0201292C(const struct BigObj *p);
extern u32 func_02007FB8(u8 *,u16,u16);
extern u32 func_02007E50(u8 *,u16,u16,u16);
extern void *func_020084F4(void *);
extern u8 func_02008550(void *);
extern u8 func_0200AA68(void *,const void *,u16,u32,u8,u8,u32,u16,u8,u8,u8);
extern void *func_02012F2C(int *);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
#define ARG (*(u8 **)(p+0x1a4))
int func_021B8860(u8 *p)
{
    u8 *detail;
    void *record;
    u8 *key;
    u8 *bag;
    u32 quantity,request;
    void *src;
    int flag;
    int result=1;
    record=func_0200A8A0(func_02012EBC(func_020120F4(*(void **)ARG)));
    detail=*(u8 **)(ARG+8);
    key=detail+12;
    if(!func_0200A9A4(record,func_02008530(key)) && *(void **)ARG) {
        bag=func_0201292C(func_020120F4(*(void **)ARG));
        quantity=func_02007FB8(bag,134,60);
        switch(quantity) {
        case 999: result=2; break;
        default:
            request=*(u32 *)(p+0x1a0);
            if(999-quantity<request) request=999-quantity;
            result=func_02007E50(bag,134,(u16)request,60)?0:2;
            break;
        }
    }
    if(*(void **)(ARG+8)) {
        src=func_020084F4(key);
        flag=func_02008550(key)?0:1;
        func_0200AA68(record,src,ARG[12],(u8)flag,detail[4],detail[5],func_02008530(key),*(u16 *)(detail+6),detail[8],detail[9],detail[10]);
    }
    if(*(void **)ARG) func_02008DF0(func_02012F2C(func_020120F4(*(void **)ARG)),113);
    return result;
}
