/*
 * function: GURU2_MAIN_UpdateBounceEffect
 * address: 0x021E0D50
 * packet: pkt_ov137_021E0D50
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_AddSettleEffect 0x021E0F64 thumb ov137
 *   GURU2_MAIN_AddWobbleEffect 0x021E1090 thumb ov137
 *   MI_CpuFill8 0x02082BCC arm
 */
extern void GURU2_MAIN_AddSettleEffect(char *p, int key);
extern void GURU2_MAIN_AddWobbleEffect(char *p, int key);
extern void MI_CpuFill8(void *,int,unsigned);
void GURU2_MAIN_UpdateBounceEffect(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        GURU2_MAIN_AddSettleEffect(p,(int)r);
        q[4]=0x4000;
        q[5]=-1092;
        q[1]++;
    case 1:
        r[23]+=q[4];
        q[4]+=q[5];
        q[2]++;
        if(q[2]>=15) {
            q[2]=0;
            q[4]=0;
            if(q[3]==0) { q[3]=1; return; }
            r[23]=0;
            GURU2_MAIN_AddWobbleEffect(p,(int)r);
            MI_CpuFill8(q,0,32);
        }
        break;
    }
}
