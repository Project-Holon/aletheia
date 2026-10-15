/*
 * function: BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch
 * address: 0x0217B1BC
 * packet: pkt_ov176_0217B1BC
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   LIVEBATTLEMATCH_FLOW_Create 0x0217B984 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Release 0x0217BAF4 thumb ov176
 *   LIVEBATTLEMATCH_FLOW_GetResult 0x0217BB3C thumb ov176
 *   LIVEBATTLEMATCH_FLOW_Delete 0x0217BA9C thumb ov176
 *   WIFIBATTLEMATCH_UTIL_SetCallback 0x021E8AA0 thumb ov177
 *   BATTLE_CHAMPIONSHIP_FLOW_FadeOut 0x0217B064 thumb ov176
 *   BATTLE_CHAMPIONSHIP_FLOW_StartMenu 0x0217B0C8 thumb ov176
 */
typedef unsigned char u8;
typedef unsigned u32;
typedef struct {u32 w[10];} Init;
extern void MI_CpuFill8(void *,int,unsigned);
extern u8 *LIVEBATTLEMATCH_FLOW_Create(Init *,u32);
extern void LIVEBATTLEMATCH_FLOW_Release(int *);
extern int LIVEBATTLEMATCH_FLOW_GetResult(int *);
extern void LIVEBATTLEMATCH_FLOW_Delete(int *);
extern void WIFIBATTLEMATCH_UTIL_SetCallback(int *,int);
extern void BATTLE_CHAMPIONSHIP_FLOW_FadeOut(void *,int *,char *);
extern void BATTLE_CHAMPIONSHIP_FLOW_StartMenu(int *,int *,int *);
void BATTLE_CHAMPIONSHIP_FLOW_StartLiveMatch(int *a,int *state,int *p)
{
    Init config;
    switch(*state) {
    case 0:
        MI_CpuFill8(&config,0,40);
        config.w[1]=p[2];
        config.w[2]=p[3];
        config.w[3]=p[5];
        config.w[4]=p[8];
        config.w[5]=p[9];
        config.w[6]=((u32 *)p[10])[0];
        config.w[7]=((u32 *)p[10])[3];
        config.w[8]=((u32 *)p[10])[4];
        config.w[9]=((u32 *)p[10])[5];
        switch(((u32 *)p[10])[1]) {
        case 3: config.w[0]=0;break;
        case 4: config.w[0]=2;break;
        case 5: config.w[0]=3;break;
        case 6: config.w[0]=1;break;
        default: config.w[0]=0;break;
        }
        p[11]=(int)LIVEBATTLEMATCH_FLOW_Create(&config,78);
        (*state)++;
        break;
    case 1:
        LIVEBATTLEMATCH_FLOW_Release((int *)p[11]);
        switch(LIVEBATTLEMATCH_FLOW_GetResult((int *)p[11])) {
        case 1: *state=3;break;
        case 2: ((int *)p[10])[2]=2;*state=2;break;
        case 3: ((int *)p[10])[2]=3;*state=2;break;
        case 4: ((int *)p[10])[2]=4;*state=2;break;
        }
        break;
    case 2:
        LIVEBATTLEMATCH_FLOW_Delete((int *)p[11]);
        WIFIBATTLEMATCH_UTIL_SetCallback(a,(int)BATTLE_CHAMPIONSHIP_FLOW_FadeOut);
        break;
    case 3:
        p[12]=1;
        LIVEBATTLEMATCH_FLOW_Delete((int *)p[11]);
        WIFIBATTLEMATCH_UTIL_SetCallback(a,(int)BATTLE_CHAMPIONSHIP_FLOW_StartMenu);
        break;
    }
}
