/*
 * function: BR_FADE_StepPalette
 * address: 0x021FEB1C
 * packet: pkt_ov186_021FEB1C
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 the older draft used 0x3fff for both calls of the first pair and 0xbfff for both of the second. The listing pairs them as (2,0x3fff) (0,0xbfff) (3,0x3fff) (1,0xbfff). Variable value is read uninitialised when field 8 is not 0 or 1 (original behaviour, kept).
 * symbols:
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   func_0209C0A4 0x0209C0A4 arm
 *   _u32_div_f 0x0209C2B0 arm
 *   PALANM_RequestFullTransfer 0x02021F08 thumb
 *   PALANM_BlendChannelMask 0x02022004 thumb
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj02021F08;
struct S02021D50;
extern int FADE_GetSpeed(void);
extern int func_0209C0A4(int,int);
extern u32 _u32_div_f(u32,u32);
extern void PALANM_RequestFullTransfer(struct Obj02021F08 *,int);
extern void PALANM_BlendChannelMask(u32,u32,u16,u32,u32);
extern void PALANM_TransferPalettes(struct S02021D50 *);
int BR_FADE_StepPalette(char *p,int *state)
{
    switch(*state) {
    case 0: {
        int duration;
        *(u32 *)(p+0x10)=0;
        duration=*(int *)(p+0x18);
        if(duration==0)duration=func_0209C0A4(16,FADE_GetSpeed());
        *(u32 *)(p+0x14)=duration;
        PALANM_RequestFullTransfer(*(struct Obj02021F08 **)(p+0x20),1);
        *state=1;
        break;
    }
    case 1: {
        int value;
        if(*(int *)(p+8)==0)value=(u8)(16-_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14)));
        else if(*(int *)(p+8)==1)value=(u8)_u32_div_f(*(u32 *)(p+0x10)<<4,*(u32 *)(p+0x14));
        if(*(int *)(p+4)==15) {
            PALANM_BlendChannelMask(*(u32 *)(p+0x20),1,0x3000,value,0xffff);
        } else {
            if(*(int *)(p+4)&1) {
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),2,0x3fff,value,*(u16 *)(p+0x24));
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),0,0xbfff,value,*(u16 *)(p+0x24));
            }
            if(*(int *)(p+4)&2) {
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),3,0x3fff,value,*(u16 *)(p+0x24));
                PALANM_BlendChannelMask(*(u32 *)(p+0x20),1,0xbfff,value,*(u16 *)(p+0x24));
            }
        }
        PALANM_TransferPalettes(*(struct S02021D50 **)(p+0x20));
        if((*(u32 *)(p+0x10))++ >= *(u32 *)(p+0x14))*state=2;
        break;
    }
    case 2:return 1;
    }
    return 0;
}

