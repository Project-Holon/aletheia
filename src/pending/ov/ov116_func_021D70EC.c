/*
 * function: func_021D70EC
 * address: 0x021D70EC
 * packet: pkt_ov116_021D70EC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: MATCH
 * blocker: ov114 ARM 0x021C940C is SDK union code, owned by Ilias.
 * Also unresolved: ov114 ARM 0x021C93D0, unlabelled state query leaf.
 * No overlay leaves filed because the SDK blocker persists; parent requested park.
 * ISA evidence: show --region ov114 --arm reads state at 0x021D4084;
 * overlapping ov021 0x021C93D0 is different Thumb code.
 * symbols:
 *   func_021C93D0 0x021C93D0 arm ov114
 *   func_021C940C 0x021C940C arm ov114
 *   func_021C9634 0x021C9634 arm ov114
 *   func_0200F7B8 0x0200F7B8 thumb
 */
typedef unsigned char u8;
typedef short s16;
extern int func_021C93D0(void);
extern int func_021C940C(void);
extern void func_021C9634(void);
extern void func_0200F7B8(int);
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
        case -5: func_0200F7B8(1); break;
        default:
            if(result>=0) *q=result;
            else func_0200F7B8(1);
            break;
        }
    }
    return done;
}
