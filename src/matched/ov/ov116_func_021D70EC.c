/*
 * function: func_021D70EC
 * address: 0x021D70EC
 * packet: pkt_ov116_021D70EC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * 2026-10-05 (wD4 lane19): still MATCH. Blocked by ov114 ARM 0x021C93D0 and 0x021C940C (pengy overlay, no witness).
 * blocker: ov114 ARM 0x021C940C is SDK union code, owned by the integrator.
 * Also unresolved: ov114 ARM 0x021C93D0, unlabelled state query leaf.
 * No overlay leaves filed because the SDK blocker persists; parent requested park.
 * ISA evidence: show --region ov114 --arm reads state at 0x021D4084;
 * overlapping ov021 0x021C93D0 is different Thumb code.
 * 2026-10-05 (wD8 lane09): re-run, still MATCH. Open relocations: func_021C93D0 and func_021C940C (ov114
 *   ARM, SDK-side, no witness). Nothing source-side to change.
 * symbols:
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C940C 0x021C940C arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   GFL_NET_ERR_ShowScreen 0x0200F7B8 thumb
 */

/*
 * 2026-10-04 (wave D2 lane05): MATCH, rechecked: two relocations unresolved, func_021C93D0 and func_021C940C, both ov114 ARM code at 0x021C93D0/0x021C940C. Neither has a matched witness in ov114 (matched files at those addresses belong to ov021/ov212 and are different Thumb code). ov114 is pengy's overlay, so no leaf was filed. The ARM state query at 0x021C93D0 (64 bytes incl. data, reads 0x021D4084) is a tiny leaf that would unblock this file and func_021D7AA8.
 */

typedef unsigned char u8;
typedef short s16;
extern int func_021C93D0(void);
extern int func_021C940C(void);
extern void func_021C9634(void);
typedef unsigned int   u32;
extern u32 GFL_NET_ERR_ShowScreen(u32 a0);
int func_021D70EC(u8 *p,int *q) {
    int done=0;
    if(func_021C93D0()==0) {
        (*(s16 *)(p+10))++;
        if(*(s16 *)(p+10)==3600) {
            func_021C9634();
            *(s16 *)(p+8)=1;
        }
    } else {
        int result=func_021C940C();
        done=1;
        switch(result) {
        case -7: case -6: case -4: case -3: case -2: case -1:
            *(int *)p=result; break;
        case -5: GFL_NET_ERR_ShowScreen(1); break;
        default:
            if(result>=0) *q=result;
            else GFL_NET_ERR_ShowScreen(1);
            break;
        }
    }
    return done;
}
