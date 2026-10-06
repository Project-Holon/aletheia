/*
 * function: func_021FF72C
 * address: 0x021FF72C
 * packet: pkt_ov186_021FF72C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: pass 4 2026-10-06 P4L01: EXACT (also with --lang c). Case 1 works on a block local copy of the
 *   result (`int r=result; ... r=1; ... result=r;`). The final `result=r` is a register copy that the
 *   allocator coalesces away, so the block after case 1's if is empty only after allocation; it is then
 *   merged into case 1's copy block, which gives that block a new (front of list) edge to the release
 *   join. The cross-jump keeps the first predecessor in the join's list, so case 1's `movs r5,#1` keeps
 *   and case 0's after-store copy and 22002's copy become hops onto it (the image's forward hop at +002E).
 *   Earlier forms (2 B off) kept case 0's copy, the earliest original edge.
 * symbols:
 *   func_021D72EC 0x021D72EC thumb ov125
 *   func_021D72F8 0x021D72F8 thumb ov125
 *   func_02006210 0x02006210 thumb
 *   func_0200FB4C 0x0200FB4C thumb
 */
extern int func_021D72EC(char *,int **);
extern void func_021D72F8(char *);
extern void func_02006210(void);
extern void func_0200FB4C(int);
int func_021FF72C(char *p,int *out)
{
    const int *event;
    int result;
    if(func_021D72EC(p,(int **)&event)){
        result=1;
        if(event[1]==0){
            if(event[3]){
                if(out)*out=event[3]+283;
                result=1;
            }
        }else if(event[1]==1){
            int r=result;
            if(event[3]==7){
                if(out)*out=event[3]+298;
                r=1;
            }
            result=r;
        }else if(event[1]==2){
            switch(event[2]){
            case 21000:
                if(event[3]){if(out)*out=event[3]+230;result=2;}
                break;
            case 21001:
                if(event[3]){if(out)*out=event[3]+237;result=2;}
                break;
            case 22000:
                if(event[3]){
                    switch(event[3]){
                    case 150:func_02006210();func_0200FB4C(65);result=3;break;
                    case 151:func_02006210();func_0200FB4C(66);result=3;break;
                    case 152:func_02006210();func_0200FB4C(68);result=3;break;
                    case 153:func_02006210();func_0200FB4C(67);result=3;break;
                    default:if(out)*out=event[3]+261;result=2;break;
                    }
                }
                break;
            case 22001:
                if(event[3]){if(out)*out=event[3]+269;result=2;}
                break;
            case 22002:
                if(event[3]){if(out)*out=event[3]+274;result=1;}
                break;
            case 22003:result=0;break;
            }
        }
        func_021D72F8(p);
        if(result==3)*(int *)(p+0x5DC)=1;
        return result;
    }
    return 0;
}
