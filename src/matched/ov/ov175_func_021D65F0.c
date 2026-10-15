/*
 * function: WIFIBATTLEMATCH_NET_CopyBoxRecord
 * address: 0x021D65F0
 * packet: pkt_ov175_021D65F0
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 */
typedef unsigned int u32;
extern void MI_CpuFill8(void *,int,u32);
void WIFIBATTLEMATCH_NET_CopyBoxRecord(u32 *p,u32 *q)
{
    u32 *ctx,*s;
    MI_CpuFill8(p,0,16);
    ctx=(u32 *)q[16]; s=(u32 *)ctx[14];
    p[1]=s[8]; p[2]=0;
    s=(u32 *)ctx[14];
    p[3]=s[13]+(s[14]+(s[11]+(s[12]+(s[17]+(s[18]+(s[9]+(s[10]+(s[16]+s[15]))))))));
    switch(((u32 *)ctx[2])[1]) {
    case 0: p[0]=((u32 *)ctx[14])[3]; break;
    case 1: p[0]=((u32 *)ctx[14])[0]; break;
    case 2: p[0]=((u32 *)ctx[14])[4]; break;
    case 3: p[0]=((u32 *)ctx[14])[1]; break;
    case 4: p[0]=((u32 *)ctx[14])[2]; break;
    }
}
