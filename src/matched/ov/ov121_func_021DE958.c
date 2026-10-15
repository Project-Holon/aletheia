/*
 * function: MYSTERY_NET_RunNdDownload
 * address: 0x021DE958
 * packet: pkt_ov121_021DE958
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DWC_RAP_SetErrorHookCallback 0x02156DE0 thumb ov009
 *   MI_CpuFill8 0x02082BCC arm
 *   DWC_NdInitAsync 0x021C5928 arm ov114
 *   DWC_NdSetAttr 0x021C5C04 arm ov114
 *   DWC_NdGetFileListAsync 0x021C5C38 arm ov114
 *   DWC_NdGetFileAsync 0x021C5CFC arm ov114
 *   DWC_NdProcess 0x021C5AB8 arm ov114
 *   DWC_NdGetProgress 0x021C5E14 arm ov114
 *   DWC_NdCancelAsync 0x021C5DB4 arm ov114
 *   MYSTERY_NET_GetErrorHookState 0x021DEF54 thumb ov121
 *   MYSTERY_NET_OnNdAsyncDone 0x021DEED8 thumb ov121
 *   MYSTERY_NET_SetNdState 0x021DEE14 thumb ov121
 *   MYSTERY_NET_AbortNd 0x021DEE38 thumb ov121
 *   MYSTERY_NET_SetHandler 0x021DEEA4 thumb ov121
 *   MYSTERY_NET_EndDownload 0x021DEDC8 thumb ov121
 *   MYSTERY_NET_IsZeroBlock 0x021DEF38 thumb ov121
 *   MYSTERY_NET_ParseHexValue 0x021DEEF8 thumb ov121
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   GFL_NET_STATE_SetError 0x0203C9AC arm
 *   _ull_mul 0x0209C054 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   d_021DFBD8 0x021DFBD8 data a4
 *   d_021DFBD0 0x021DFBD0 data a4
 *   d_021DFBF8 0x021DFBF8 data a4
 *   d_021DFBEC 0x021DFBEC data a4
 *   d_021DFC00 0x021DFC00 data a4
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef struct { char pad[0x6e0];u32 flag; } Flag;
extern void DWC_RAP_SetErrorHookCallback(int,int);
extern void MI_CpuFill8(void *,int,u32);
extern int DWC_NdInitAsync(void (*callback)(int, int, int), char *gamecd, char *passwd);
extern int DWC_NdSetAttr(char *,char *,char *);
extern int DWC_NdGetFileListAsync(void *,u32,u32);
extern int DWC_NdGetFileAsync(void *,char *,u32);
extern void DWC_NdProcess(void);
extern int DWC_NdGetProgress(u32 *,u32 *);
extern int DWC_NdCancelAsync(void);
extern int MYSTERY_NET_GetErrorHookState(char *,int,int);
extern void MYSTERY_NET_OnNdAsyncDone(int,int);
extern void MYSTERY_NET_SetNdState(char *,int *,int);
extern void MYSTERY_NET_AbortNd(u32 p, int a, int *state, int b, int c);
extern void MYSTERY_NET_SetHandler(u32 *p, void *f);
extern void MYSTERY_NET_EndDownload(void *a, int *state, char *p);
extern int MYSTERY_NET_IsZeroBlock(const unsigned *,unsigned);
extern int MYSTERY_NET_ParseHexValue(const signed char *);
extern u32 GF_STANDARD_Rand(void);
extern void GFL_NET_STATE_SetError(int,u32,u32,u32);
extern char d_021DFBD8[],d_021DFBD0[],d_021DFBF8[],d_021DFBEC[];
extern int d_021DFC00[];
#define Q(k) (*(u32 *)(q+(k)))
#define W(k) (*(u32 *)(p+(k)))
void MYSTERY_NET_RunNdDownload(void *task,int *state,char *p)
{
    char *q=p+0x60;
    int i,n,j,valid;
    u32 rnd,t,ratio;
    switch(*state) {
    case 0:
        DWC_RAP_SetErrorHookCallback((int)MYSTERY_NET_GetErrorHookState,(int)q);
        MI_CpuFill8(q,0,0x734);
        Q(0x70c)=0;Q(0x710)=0;Q(0x724)=0;Q(0x728)=(u32)(p+0x7a4);
        W(0x17a4)=0;
        if(!DWC_NdInitAsync((void (*)(int,int,int))MYSTERY_NET_OnNdAsyncDone,d_021DFBD0,d_021DFBD8)) {
            W(0x17a4)=2;*state=9;
        } else {Q(0x730)=1;MYSTERY_NET_SetNdState(q,state,1);}
        break;
    case 1:
        if(Q(0x710)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);}
        else if(!DWC_NdSetAttr(d_021DFBEC,d_021DFBF8,d_021DFBF8)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);
        } else *state=3;
        break;
    case 3:
        if(!DWC_NdGetFileListAsync(q,0,10)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);}
        else MYSTERY_NET_SetNdState(q,state,2);
        break;
    case 2:
        for(i=0;i<10;i++) {
            if(!MYSTERY_NET_IsZeroBlock((const unsigned *)(q+0xb0*i),0xb0)) {
                if(MYSTERY_NET_ParseHexValue((const signed char *)(q+0xb0*i+0x93))&0x200000)
                    ((Flag *)((u32)q+(u32)i*4))->flag=1;
                else ((Flag *)((u32)q+(u32)i*4))->flag=0;
            } else ((Flag *)((u32)q+(u32)i*4))->flag=0;
        }
        Q(0x714)=0;
        for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) Q(0x714)++;
        *state=4;break;
    case 4:
        n=Q(0x714);
        if(n==1) {
            for(i=0;i<10;i++) if(((Flag *)((u32)q+(u32)i*4))->flag) {Q(0x724)=i;break;}
        } else if(n>1) {
            j=0;rnd=GF_STANDARD_Rand();
            if(n) rnd=(u32)(((u64)rnd*(u32)n)>>32);
            for(i=0;i<10;i++) {
                if(((Flag *)((u32)q+(u32)i*4))->flag) {
                    if(j==rnd) {Q(0x724)=i;break;}
                    j++;
                }
            }
            Q(0x724)=i;
        } else {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,1,state,8,8);break;}
        *state=5;break;
    case 5:
        if(!DWC_NdGetFileAsync(q+Q(0x724)*0xb0,(char *)Q(0x728),0x1000)) {
            W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);
        } else {
            Q(0x718)=0;d_021DFC00[1]=0;d_021DFC00[3]=0;Q(0x72c)=0;*state=6;
        }break;
    case 6:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);
        }
        if(!d_021DFC00[1]) {
            if(Q(0x70c)) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,7,7);break;}
            if(DWC_NdGetProgress((u32 *)(q+0x71c),(u32 *)(q+0x720))==1) {
                ratio=Q(0x71c)*100/Q(0x720);
                if(Q(0x718)!=ratio) Q(0x718)=ratio;
            }
        } else if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,4,state,9,9);}
        else if(!Q(0x710)) {W(0x17a4)=1;MYSTERY_NET_AbortNd((u32)q,1,state,8,8);}
        else {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,8,8);}
        break;
    case 7:DWC_NdCancelAsync();*state=8;break;
    case 8:*state=9;break;
    case 9:Q(0x730)=0;DWC_RAP_SetErrorHookCallback(0,0);MYSTERY_NET_SetHandler(task,MYSTERY_NET_EndDownload);break;
    case 100:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {
            GFL_NET_STATE_SetError(0,0,0,0x3f5);W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,9,9);
        }
        if(d_021DFC00[1]) {
            d_021DFC00[1]=0;
            if(d_021DFC00[3]) {W(0x17a4)=2;MYSTERY_NET_AbortNd((u32)q,3,state,9,9);}
            else *state=Q(0x708);
        } else if(Q(0x70c)) Q(0x710)=1;
        break;
    case 200:
        DWC_NdProcess();
        if(Q(0x72c)++>7200) {GFL_NET_STATE_SetError(0,0,0,0x3f5);*state=Q(0x708);}
        if(d_021DFC00[0]) {d_021DFC00[0]=0;*state=Q(0x708);}
        else if(Q(0x70c)) Q(0x710)=1;
        break;
    }
}
