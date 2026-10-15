/*
 * function: WIFIBATTLEMATCH_NET_ReportAddRecord
 * address: 0x021DAFB8
 * packet: pkt_ov175_021DAFB8
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_ScReportAddByteValue 0x021DF420 arm ov175
 *   DWC_ScReportAddIntValue 0x021DF3E8 arm ov175
 *   func_02034714 0x02034714 arm
 *   d_021E2EF8 0x021E2EF8 data a4
 */
typedef unsigned int u32;
extern int DWC_ScReportAddByteValue(int,int,int);
extern int DWC_ScReportAddIntValue(int,int,int);
extern void func_02034714(const char *expr, u32 line, const char *file);
extern const char d_021E2EF8[];
void WIFIBATTLEMATCH_NET_ReportAddRecord(int *ctx,const u32 *record,int invert) {
    int first,second,flip=0,skip=0,present;
    present=record[2]!=0 || record[3]!=0;
    switch(record[1]) {
    case 0: case 3: first=0; second=1; flip=1; break;
    case 1: case 4: first=1; second=0; flip=1; break;
    case 2: first=0; second=0; skip=1; break;
    case 5: case 6: default: first=0; second=0; break;
    }
    if(!invert && flip) { first^=1; second^=1; }
    switch(record[0]) {
    case 0:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],15,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],5,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],6,second)) return;
        break;
    case 1:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],16,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],8,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],7,second)) return;
        break;
    case 2:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],18,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],11,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],12,second)) return;
        break;
    case 3:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],17,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],9,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],10,second)) return;
        break;
    case 4:
        if(!skip && DWC_ScReportAddByteValue(ctx[1],19,1)) return;
        if(DWC_ScReportAddIntValue(ctx[1],13,first)) return;
        if(DWC_ScReportAddIntValue(ctx[1],14,second)) return;
        break;
    default: func_02034714(d_021E2EF8,0,d_021E2EF8); break;
    }
    if(DWC_ScReportAddIntValue(ctx[1],20,present!=0)) return;
    DWC_ScReportAddIntValue(ctx[1],27,-1);
}
