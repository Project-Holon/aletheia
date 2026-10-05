/*
 * function: func_021FF72C
 * address: 0x021FF72C
 * packet: pkt_ov186_021FF72C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 wave P8 lane W7: 2 bytes differ, size 352/352. Case 0 sets result=1 before the store here (a dead assignment that the compiler drops) and case 1 sets it after the store, which leaves one surviving movs r5,#1 join in the case 1 arm (matches +0044). The image also has a join copy in case 0 (beq r4 at +0026 lands on a b to 0x021FF770, store path falls into it). With result=1 after the store in case 0 as well (b.c) the compiler keeps case 0's copy as the survivor and case 1 hops to it (28 bytes). Goto from case 0 into case 1's result=1 (c.c) threads the hop and merges the adds/str tails (281 bytes). Result copies for 2 keep the EARLIEST arm in the image, for 1 the LATER one. Twin search: grep func_021D72EC/func_0200FB4C/func_02006210 over src/matched/ov found no decoder twin.
 * residual: 2 concrete bytes (was 26); compiled352/352; first-arm result cross-jump differs; 6/7 relocations, ARM9 0200FB4C witness absent.
 * checks: 1 own ov125 reader/ack and ARM9 body confirm arity; 2 FF88C reread, no decoder twin; 3 Event struct, short/long result unchanged26; 4 named first-arm value34 and switch284, manual variants exhausted; 5 fresh unfiltered idioms and matched neighbours reread.
 * retry: Wave67 6 fixed one calls; previous once-only300 permuter already used, no repeated search.
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
                result=1;
                if(out)*out=event[3]+283;
            }
        }else if(event[1]==1){
            if(event[3]==7){
                if(out)*out=event[3]+298;
                result=1;
            }
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
