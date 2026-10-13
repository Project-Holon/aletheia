/*
 * unit: yes
 * function: COMPATIBLE_IRC_SYS_StepShareValue,COMPATIBLE_IRC_SYS_ResetStep,COMPATIBLE_IRC_SYS_ClearValues,COMPATIBLE_IRC_SYS_SetOwnValue
 * address: 0x021B630C
 * packet: pkt_ov101_021B630C
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   COMPATIBLE_IRC_SYS_SendToHandle 0x021B6494 thumb ov101
 *   GFL_NET_IsParentAid 0x0203D378 arm
 */
extern int COMPATIBLE_IRC_SYS_SendToHandle(unsigned int p, unsigned int a, unsigned int b, unsigned int c);
typedef unsigned int   u32;
extern u32 GFL_NET_IsParentAid(void);
int COMPATIBLE_IRC_SYS_StepShareValue(int *p,int value)
{
    int i;
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        p[28]=0;
        if(COMPATIBLE_IRC_SYS_SendToHandle((unsigned int)p,0xD00,4,(unsigned int)(&value))) p[17]=1;
        break;
    case 1:
        if(GFL_NET_IsParentAid()) {
            for(i=0;i<2;i++) { if(value != p[26+i]) break; }
            if(i == 2) p[17]=2;
        } else p[17]=3;
        break;
    case 2:
        if(COMPATIBLE_IRC_SYS_SendToHandle((unsigned int)p,0xD01,4,(unsigned int)(&value))) p[17]=4;
        break;
    case 3:
        if(p[28]) p[17]=4;
        break;
    case 4:
        p[17]=0;
        return 1;
    }
    return 0;
}
void COMPATIBLE_IRC_SYS_ResetStep(int *p) { p[17]=0; }
void COMPATIBLE_IRC_SYS_ClearValues(int *p) { p[15]=0; p[14]=0; }
void COMPATIBLE_IRC_SYS_SetOwnValue(int *p,int n) { p[14]=n; }
