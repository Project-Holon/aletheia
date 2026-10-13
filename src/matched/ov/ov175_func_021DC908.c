/*
 * function: func_021DC908
 * address: 0x021DC908
 * packet: pkt_ov175_021DC908
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: two-case result switch sorts compares while preserving case body order; the equivalent if chain differed21 bytes.
 * blocker: ARM9 0x0200FB4C has no outside code-start witness; three own calls unresolved. TU --suggest-split leaves caller out.
 * blocker-C: copied verified32B Thumb EXACT from ov116_func_021D7200.c header, prior scratch blocker-1.log, dsi/1.1p1 -O4,p.
 * extern unsigned char gNetErrWork[],g_021461BC[];
 * void GFL_NET_ERR_RaiseFatal(int a) {
 *   if(*(int *)(gNetErrWork+44)!=2) {
 *     *(int *)(gNetErrWork+96)=a;
 *     g_021461BC[26]=1;g_021461BC[25]=1;
 *     *(int *)(gNetErrWork+44)=2;
 *   }
 * }
 * Blocker symbols: gNetErrWork 0x0214617C data; g_021461BC 0x021461BC data.
 * abi: CE58 retains visibly loaded third argument despite its two-argument setter body.
 * symbols:
 *   func_021B95D4 0x021B95D4 thumb ov114
 *   func_021B973C 0x021B973C thumb ov114
 *   func_021BE79C 0x021BE79C arm ov114
 *   func_021B9748 0x021B9748 thumb ov114
 *   func_021B9838 0x021B9838 thumb ov114
 *   func_021B99DC 0x021B99DC thumb ov114
 *   func_021B9790 0x021B9790 thumb ov114
 *   func_021B97F4 0x021B97F4 thumb ov114
 *   GFL_NET_ERR_RaiseFatal 0x0200FB4C thumb
 *   func_021DC610 0x021DC610 thumb ov175
 *   func_021DCE58 0x021DCE58 thumb ov175
 *   func_021B9774 0x021B9774 thumb ov114
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021B95D4(int,u8 *);
extern int func_021B973C(char *);
extern int func_021BE79C(void *handle, void *value_p, unsigned long length);
extern int func_021B9748(u8 *);
extern void func_021B9838(u8 *);
extern int func_021B99DC(u8 *);
extern int func_021B9790(u8 *);
extern u8 *func_021B97F4(u8 *p);
extern void GFL_NET_ERR_RaiseFatal(u32);
extern int func_021DC610(u32);
extern void func_021DCE58(char *,unsigned long,u32);
extern void func_021B9774(u8 *);
int func_021DC908(char *p)
{
    int result;
    int status;
    u32 *data;
    if(*(u8 **)(p+0x121c)==0) return 2;
    switch(*(u32 *)(p+0x12c)) {
    case 0:
        if(func_021B95D4(6,*(u8 **)(p+0x121c))) {
            func_021BE79C((void *)func_021B973C(*(char **)(p+0x121c)),(void *)((u32)(p+0x1228)),8);
            *(u32 *)(p+0x12c)=1;
        }
        break;
    case 1:
        if(!func_021B9748(*(u8 **)(p+0x121c))) *(u32 *)(p+0x12c)=2;
        else {
            if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 2:
        result=func_021B99DC(*(u8 **)(p+0x121c));
        status=func_021B9790(*(u8 **)(p+0x121c));
        if(status==0) {
            data=(u32 *)func_021B97F4(*(u8 **)(p+0x121c));
            switch(result) {
            case 0x1f7: *(u32 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3e);return 0;
            case 0x1f6: *(u32 *)(p+0x12c)=3;GFL_NET_ERR_RaiseFatal(0x3f);return 0;
            default:
                if(*data==0) *(u32 *)(p+0x12c)=4;
                else {GFL_NET_ERR_RaiseFatal(func_021DC610(*data));*(u32 *)(p+0x12c)=3;}
                break;
            }
        } else if(status!=15) {
            func_021DCE58(p+0x18,status,0x16a0);
            if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
            return 2;
        }
        break;
    case 3:
        if(*(u8 **)(p+0x121c)) {
            func_021B9774(*(u8 **)(p+0x121c));
            func_021B9838(*(u8 **)(p+0x121c));
            *(u8 **)(p+0x121c)=0;
        }
        return 3;
    case 4:
        if(*(u8 **)(p+0x121c)) {func_021B9838(*(u8 **)(p+0x121c));*(u8 **)(p+0x121c)=0;}
        return 1;
    }
    return 0;
}
