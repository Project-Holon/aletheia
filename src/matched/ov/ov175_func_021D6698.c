/*
 * function: func_021D6698
 * address: 0x021D6698
 * packet: pkt_ov175_021D6698
 * region: ov175
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_02012944 0x02012944 thumb
 *   func_02008468 0x02008468 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0200E6E8 0x0200E6E8 thumb
 *   func_0200E6FC 0x0200E6FC thumb
 *   func_0200DFD8 0x0200DFD8 thumb
 *   func_0201283C 0x0201283C thumb
 *   func_02009CC0 0x02009CC0 thumb
 */
typedef unsigned int u32;
typedef unsigned char  u8;
struct Big;
struct BigObj;
struct Rec0200E6FC;
extern void *func_02012EBC(struct Big *p);
extern u8 *func_02012944(void *p);
extern int func_02008468(void);
extern void func_02082D44(const void *,void *,int);
extern void *func_0200E6E8(u32 a);
extern void func_0200E6FC(struct Rec0200E6FC *src, int idx, struct Rec0200E6FC *dst);
extern u32 func_0200DFD8(u32,u32,u32);
extern u32 func_0201283C(const struct BigObj *p);
extern u32 func_02009CC0(u32);
void func_021D6698(u32 *p,u32 *q)
{
    u32 save=((u32 *)((u32 *)q[16])[2])[0];
    u32 profile=(u32)func_02012EBC((struct Big *)save);
    u32 blob;
    u32 *ctx;
    p[17]=100;
    blob=(u32)func_02012944((void *)save);
    func_02082D44((void *)blob,p,func_02008468());
    func_0200E6FC(func_0200E6E8(profile),0,(struct Rec0200E6FC *)((char *)(p+14)));
    ctx=(u32 *)q[16];
    if(ctx[0]==0) {
        p[10]=func_0200DFD8(ctx[4],((u32 *)ctx[2])[1]+5,1);
        ctx=(u32 *)q[16];
        p[11]=func_0200DFD8(ctx[4],((u32 *)ctx[2])[1]+5,2);
    } else {
        p[10]=func_0200DFD8(ctx[4],((u32 *)ctx[2])[1],1);
        ctx=(u32 *)q[16];
        p[11]=func_0200DFD8(ctx[4],((u32 *)ctx[2])[1],2);
    }
    p[18]=func_02009CC0(func_0201283C((const struct BigObj *)save));
}
