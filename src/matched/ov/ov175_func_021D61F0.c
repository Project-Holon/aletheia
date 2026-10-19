/*
 * function: WIFIBATTLEMATCH_NET_TaskStepPostPartyData
 * address: 0x021D61F0
 * packet: pkt_ov175_021D61F0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   MI_CpuCopy8 0x02082D44 arm
 *   WIFIBATTLEMATCH_NET_SetupPostData 0x021DCB58 thumb ov175
 *   WIFIBATTLEMATCH_NET_HttpRapPost 0x021DCC28 thumb ov175
 *   WIFIBATTLEMATCH_UTIL_ClearCallback 0x021E8AA8 thumb ov177
 */
#include "../include/Obj03317.h"
#include "../include/Obj24227.h"
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,int);
extern void MI_CpuCopy8(const void *,void *,int);
extern void WIFIBATTLEMATCH_NET_SetupPostData(char *p, void *q, int mode);
typedef unsigned char  u8;
extern int WIFIBATTLEMATCH_NET_HttpRapPost(char *p, u8 *out);
extern void WIFIBATTLEMATCH_UTIL_ClearCallback(int a);
void WIFIBATTLEMATCH_NET_TaskStepPostPartyData(u32 sys,int *state,char *p)
{
    char *base=*(char * *)&((struct Obj24227 *)(*(char * *)&((struct Obj03317 *)p)->f40))->f14;
    int result;
    switch(*state) {
    case 0:
        ((struct Obj03317 *)p)->fE0=0;
        MI_CpuFill8(p+0x44,0,0x9c);
        (*state)++;
        break;
    case 1:
        WIFIBATTLEMATCH_NET_SetupPostData(((struct Obj03317 *)p)->f30,base+0xd4,1);
        (*state)++;
        break;
    case 2:
        result=WIFIBATTLEMATCH_NET_HttpRapPost(((struct Obj03317 *)p)->f30,(u8 *)(p+0x44));
        if(result==1) *state=3;
        else if(result==2) { ((struct Obj03317 *)p)->f3C=2; *state=4; }
        else if(result==3) { ((struct Obj03317 *)p)->f3C=3; *state=4; }
        break;
    case 3:
        if(((struct Obj03317 *)p)->f44==0) {
            MI_CpuCopy8(p+0x60,base+0x54,0x80);
            ((struct Obj03317 *)p)->f3C=0; *state=4;
        } else { ((struct Obj03317 *)p)->f3C=1; *state=4; }
        break;
    case 4: WIFIBATTLEMATCH_UTIL_ClearCallback(sys); break;
    }
}
