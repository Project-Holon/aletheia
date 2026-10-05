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
 * recoup 2026-10-05 R1: still DIFF 2 B. Original shape read from the listing: case 0 store path and no-out path both end at one join block that is only `b 0x021FF770` (hop onto case 1's `movs r5,#1`), so case 0 had its own result=1 copy that cross-jumping merged INTO case 1's copy (later survivor); 22002 hops to 770 too. Tried (352 B unless noted): case 0 before store/case 1 after (this file, 2 B, case 0 copy dropped as redundant after the top result=1); both after store (28 B, case 0 copy survives, case 1 hops to it); swapped before/after (26 B); both before (264 B, 348 B); if(out){..result=1}else result=1 in case 0 (2 B, copies dropped); `if(event[3]==0){}else{..}` (28 B); `int result=1` initialiser without top assignment (15 B); case 1 result=1 hoisted before its compare with case 0 after store (26 B); 22002 without result=1 (348 B, 76 B off); pragmas opt_dead_assignments, peephole, opt_propagation off on this form and on both-after form (no change: 2 B and 28 B), opt_common_subs off (163/186 B, worse). A before-store result=1 is always dropped, an after-store one always makes the EARLIEST copy survive; no source form found that keeps a case 0 join hopping onto case 1's copy.
 * final push 2026-10-05 G1L2: still DIFF 2 B (352/352), form unchanged. Research first (idioms a-conditional-branch-onto-an-unconditional-b..., a-dead-assignment-in-one-switch-arm-cross-jumps..., an-instruction-the-scheduler-will-not-hoist..., two-arms-write-the-tail-out..., a-branch-to-the-next-case-block..., a-shared-exit-block-is-written-out..., a-switch-return-flag..., switch-arms-tail-merge, a-goto-join-loses...; twin grep func_021D72EC/func_021D72F8 hits only ov125_func_021D71D8). Tried: switch(event[1]) with case 0/1/2, A after or before store (288 B each, layout differs); opt_lifetimes off and scheduling off on the current form (2 B) and on both-after (28 B); case 1 as if(event[3]!=7){}else{..} (2 B); case 0 result=(event[3]!=0) before or after store (302 and 293 B off, size changes); case 1 if(out){..result=1}else result=1 with case 0 after-store (26 B), with case 0 unchanged (282 B, 348 size), with case 0 if/else too (282 B); case 0 if(out){..result=1}else result=1 only (2 B); case 0 result=1 both before and after store (28 B); case 22002 result=1 before store (76 B, 348 size). Observation: a result=1 before the store is always dropped as redundant, one after the store is always kept; among kept copies the EARLIEST always survives, while the image keeps case 1's (middle) copy and hops case 0 and 22002 onto it. No human source form found that makes case 0's kept copy hop onto case 1's.
 * final push 2026-10-05 G1R2: still DIFF 2 B (352/352), form unchanged. Matched-assembly search for a conditional branch onto a `b` hop into a `movs rN,#1; b` found ov094 func_021FE594 (hop goes backward to the earlier copy, same as our compile), ov228 func_021DFC20 (hop from &&/||, n/a), ov172 func_021B9580 (hop from ||, n/a) and ov199 func_02212A90 (forward hop between two switches' case 0 calls, no if(out) join). New tries, none closer: goto from case 0 into case 1's result=1 (281 B off, stores merge), switch(event[1]) in two case orders (288/290), case 0 result as (event[3]!=0)/event[1]+1/!event[1] (size changes, 277-302), case 1 first in source (33, mirror: first-written copy survives), inline put(out,v) helper in case 0/1/both/22002 (28-44), store-shape matrix over case 0 x case 1 (28; 26 with if(out)/else form in case 1; 2 with it in case 0 only), label in case 1, else-switch nest (272), sequential ifs (289), switch(event[3]) arms, goto done in each arm, do-while(0) around the chain or arms, for(;;) and switch-default wrappers (all 28). Observation: the survivor is always the first-written copy among case 0, case 1, 22002; the image keeps case 1's. Research notes in the lane scratchpad wD9r/g1r2/research.md.
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
