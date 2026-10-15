/*
 * function: WIFIBATTLEMATCH_NET_SetupSprite
 * address: 0x021D6550
 * packet: pkt_ov175_021D6550
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   WIFIBATTLEMATCH_UTIL_ShowMenu 0x021E888C thumb ov177
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void MI_CpuFill8(void *,int,u32);
extern u32 WIFIBATTLEMATCH_UTIL_ShowMenu(void *,u32);
void WIFIBATTLEMATCH_NET_SetupSprite(u32 *p,int mode)
{
    struct { u32 x0,x1,x2,x3,x4,x5,x6,x7; u16 a,b,c,d; int enabled; u16 kind,pad; } desc;
    if (p[10]==0) {
        MI_CpuFill8(&desc,0,48);
        desc.x0=p[4]; desc.x1=p[2]; desc.x2=p[3];
        desc.a=0; desc.b=15; desc.c=13; desc.d=1;
        switch(mode) {
        case 0:
            desc.x3=31; desc.x4=32; desc.x7=2;
            desc.enabled=1; desc.kind=1;
            break;
        case 1:
            desc.x3=27; desc.x4=28; desc.x5=29;
            desc.x7=3; desc.enabled=1; desc.kind=2;
            break;
        }
        p[11]=mode;
        p[10]=WIFIBATTLEMATCH_UTIL_ShowMenu(&desc,87);
    }
}
