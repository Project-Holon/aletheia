/*
 * function: func_021FD2B8
 * address: 0x021FD2B8
 * packet: pkt_ov132_021FD2B8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: loop leaf filed as ov132_func_021FD328.c.
 * symbols:
 *   func_020173E8 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020173E8(void);
extern u32 func_02008468(void);
extern int func_020084BC(void *);
extern void func_02082D44(void *,void *,u32);
void func_021FD2B8(int a,int b,int c,char *p)
{
    u8 i;
    int n;
    u32 m,k;
    char *q,*s;
    int flag;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char **)(p+0x13c);
        k=i*(m+4+n);
        m=func_02008468();
        n=m+4+func_020173E8();
        s=p+i*0x30;
        func_02082D44(q+k,*(void **)(s+0x8c),n);
        flag=func_020084BC(*(void **)(s+0x84))==0 ? 1 : 0;
        *(int *)(s+0x60)=flag;
        *(int *)(s+0x68)=flag;
    }
    *(int *)(p+0x158)=1;
}
