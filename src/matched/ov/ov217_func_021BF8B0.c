/*
 * function: func_021BF8B0
 * address: 0x021BF8B0
 * packet: pkt_ov217_021BF8B0
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: pointer-typed lookup base keeps the original r4/r5 allocation; E44C full body reads only r0/r1 and forwards neither legacy trailing input.
 * F740 tail-forwards to C09B4's pointer getter; E394 tail-forwards to 071CC's returned save block.
 * E44C's full body reads only r0/r1 and has no forwarding calls; legacy two trailing inputs omitted.
 * symbols:
 *   func_021BF740 0x021BF740 thumb ov217
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200E394 0x0200E394 thumb
 *   func_0200E44C 0x0200E44C thumb
 *   d_021C363C 0x021C363C data ov217 a1
 *   d_021C3646 0x021C3646 data ov217 a1
 *   d_021C3632 0x021C3632 data ov217 a1
 */
typedef unsigned char u8;
struct Big;
extern struct Big *func_021BF740(u8 *);
extern void *func_02012EBC(struct Big *);
extern void *func_0200E394(int);
extern int func_0200E44C(int,int);
extern const u8 d_021C363C[];
extern const u8 d_021C3646[];
extern const u8 d_021C3632[];
u8 func_021BF8B0(u8 *p)
{
    u8 bytes[3];
    u8 a,b,c,j;
    void *base;
    int i;
    base=func_0200E394((int)func_02012EBC(func_021BF740(p)));
    for (i=0;i<3;i++) bytes[i]=func_0200E44C((int)base,i);
    b=bytes[1];
    c=bytes[2];
    a=bytes[0];
    for (j=0;j<10;j++) {
        if (a==d_021C363C[j] && b==d_021C3646[j] && c==d_021C3632[j]) return j;
    }
    return 0;
}
