/*
 * function: BR_NET_StartRequest
 * address: 0x021FF54C
 * packet: pkt_ov186_021FF54C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent: 252 bytes; the listing extent of 276 includes the separately filed BR_NET_IsIdle at +0xFC.
 * recoup 2026-10-05: the 8-byte payload copy as one struct assignment (W = two ints) gives the original r2/r1 load colours; two int stores gave r1/r1 (2 bytes off). Struct copy is a plausible human form. EXACT* only because of the 276 vs 252 listing extent.
 * symbols:
 *   func_02034714 0x02034714 arm
 *   MI_CpuFill8 0x02082BCC arm
 *   BR_NET_SetStep 0x021FFB68 thumb ov186
 *   gBrNetAssertString 0x02200D98 data a1
 *   BR_NET_StepUploadEntry 0x021FF900 thumb ov186
 *   BR_NET_StepDownloadEntries 0x021FF938 thumb ov186
 *   BR_NET_StepUploadVideo 0x021FF968 thumb ov186
 *   BR_NET_StepGetVideo 0x021FF99C thumb ov186
 *   BR_NET_StepSearchVideos 0x021FF9D0 thumb ov186
 *   BR_NET_StepSearchKind1 0x021FFA14 thumb ov186
 *   BR_NET_StepSearchKind3 0x021FFA40 thumb ov186
 *   BR_NET_StepSearchKind2 0x021FFA6C thumb ov186
 *   BR_NET_StepMarkVideo 0x021FFA98 thumb ov186
 */
typedef struct {int a,b;} W;
typedef unsigned int   u32;
extern void func_02034714(const char *expr, u32 line, const char *file);
extern void MI_CpuFill8(void *,unsigned,unsigned);
extern void BR_NET_SetStep(char *,int);
extern const char gBrNetAssertString[];
extern void BR_NET_StepUploadEntry(char *,int,char *);
extern void BR_NET_StepDownloadEntries(char *,int,char *);
extern void BR_NET_StepUploadVideo(char *,int,char *);
extern void BR_NET_StepGetVideo(char *,int,char *);
extern void BR_NET_StepSearchVideos(char *,int,char *);
extern void BR_NET_StepSearchKind1(char *,int,char *);
extern void BR_NET_StepSearchKind3(char *,int,char *);
extern void BR_NET_StepSearchKind2(char *,int,char *);
extern void BR_NET_StepMarkVideo(char *,int,char *);
void BR_NET_StartRequest(char *p,int kind,const int *values)
{
    if(kind>=9)func_02034714(gBrNetAssertString,0,gBrNetAssertString);
    if(values){
        *(W *)(p+0x5B0)=*(const W *)values;
    }
    MI_CpuFill8(p+0x5B8,0,0x24);
    switch(kind){
    case 0:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepUploadEntry);break;
    case 1:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepDownloadEntries);break;
    case 2:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepUploadVideo);break;
    case 3:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepGetVideo);break;
    case 4:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepSearchVideos);break;
    case 5:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepSearchKind1);break;
    case 6:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepSearchKind3);break;
    case 7:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepSearchKind2);break;
    case 8:BR_NET_SetStep(*(char **)(p+0x5AC),(int)BR_NET_StepMarkVideo);break;
    default:func_02034714(gBrNetAssertString,0,gBrNetAssertString);break;
    }
}
