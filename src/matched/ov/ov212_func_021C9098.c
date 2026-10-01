/*
 * function: func_021C9098
 * address: 0x021C9098
 * packet: pkt_ov212_021C9098
 * region: ov212
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: spell the empty-result arm first in the nested if/else;
 * shared failure exit remains after the switch.
 * symbols:
 *   func_021C8F7C 0x021C8F7C thumb ov212
 *   func_021C9288 0x021C9288 thumb ov212
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
struct Blk37;
extern void func_021C8F7C(char *);
extern u16 func_021C9288(struct Blk37 *,u16 **,unsigned);
extern void func_020307B0(void *);
int func_021C9098(char *p)
{
    int result;
    switch(*(unsigned *)(*(char **)(p+40)+16)){
    case 0:
        if(*(u16 *)(p+18)==0){
            *(u16 *)(*(char **)p+14)=0;result=9;
        }else{
            func_021C8F7C(p);
            *(u16 *)(p+16)=func_021C9288(*(struct Blk37 **)(*(char **)p+4),(u16 **)(p+12),105);
            *(u16 *)(p+18)=0;result=3;
        }
        goto done;
    case 1:*(u16 *)(*(char **)p+14)=1;result=9;goto done;
    case 2:
        func_021C8F7C(p);
        *(u16 *)(p+16)=func_021C9288(*(struct Blk37 **)(*(char **)p+4),(u16 **)(p+12),105);
        result=3;goto done;
    case 3:result=5;*(unsigned *)(p+36)=1;goto done;
    case 4:
        if(*(u16 *)(p+18)==1){
            func_021C8F7C(p);
            *(u16 *)(p+16)=func_021C9288(*(struct Blk37 **)(*(char **)p+4),(u16 **)(p+12),105);
        }
        result=7;goto done;
    default:break;
    }
    *(u16 *)(*(char **)p+14)=0;result=9;
done:
    func_020307B0(*(void **)(p+40));
    return result;
}
