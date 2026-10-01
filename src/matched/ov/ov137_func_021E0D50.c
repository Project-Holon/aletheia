/*
 * function: func_021E0D50
 * address: 0x021E0D50
 * packet: pkt_ov137_021E0D50
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E0F64 0x021E0F64 thumb ov137
 *   func_021E1090 0x021E1090 thumb ov137
 *   func_02082BCC 0x02082BCC arm
 */
extern void func_021E0F64(char *,int *);
extern void func_021E1090(char *,int *);
extern void func_02082BCC(void *,int,unsigned);
void func_021E0D50(char *p,int *q)
{
    int *r=(int *)q[7];
    switch(q[1]) {
    case 0:
        func_021E0F64(p,r);
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
            func_021E1090(p,r);
            func_02082BCC(q,0,32);
        }
        break;
    }
}
