/*
 * function: func_021FD22C
 * address: 0x021FD22C
 * packet: pkt_ov132_021FD22C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020173E8 0x020173E8 thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020173E8(void);
extern u32 func_02008468(void);
extern void func_02082D44(void *,void *,u32);
extern void *func_0203996C(int);
extern int func_0203D3F8(void *,int,int,u32,void *,int,int,int);
void func_021FD22C(char *p)
{
    u8 i;
    u32 n;
    u32 m;
    char *q;
    u32 k;
    void *h;
    for(i=0;i<4;i++) {
        m=func_02008468();
        n=func_020173E8();
        q=*(char **)(p+0x13c);
        k=i*(m+4+n);
        m=func_02008468();
        n=func_020173E8();
        func_02082D44(*(void **)(p+i*0x30+0x8c),q+k,m+4+n);
    }
    h=func_0203996C(0xff);
    m=func_02008468();
    n=func_020173E8();
    func_0203D3F8(h,0xff,0x1102,(m+4+n)*4,*(void **)(p+0x13c),1,0,1);
}
