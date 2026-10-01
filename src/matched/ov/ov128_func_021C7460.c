/*
 * function: func_021C7460
 * address: 0x021C7460
 * packet: pkt_ov128_021C7460
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021CA58A 0x021CA58A data a1
 *   func_02035C08 0x02035C08 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021CA154 0x021CA154 thumb ov128
 *   func_021CA184 0x021CA184 thumb ov128
 *   func_020355D8 0x020355D8 arm
 */
typedef unsigned char u8;
extern const char d_021CA58A[];
extern int func_02035C08(const char *);
extern void func_020061E4(int);
extern void func_021CA154(u8 *,int);
extern void func_021CA184(u8 *,int,int);
extern void func_020355D8(int);
int func_021C7460(int *p,int *q,u8 *ctx)
{
    int v;
    v=func_02035C08(d_021CA58A);
    if(v!=-1) {
        if(v==3) {
            func_020061E4(1361);
            func_021CA154(ctx,*p);
        } else if(v==4) {
            func_020061E4(1366);
            func_021CA154(ctx,*p);
        } else {
            func_020061E4(1356);
            func_021CA184(ctx,v,*p);
        }
        *p=v;
        func_020355D8(1);
        *q=1;
    }
    return v;
}
