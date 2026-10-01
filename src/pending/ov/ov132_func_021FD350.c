/*
 * function: func_021FD350
 * address: 0x021FD350
 * packet: pkt_ov132_021FD350
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * unfiled: larger followers 021FD3D8 and 021FD3F0 remain DIFF notes.
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_02030734 0x02030734 arm
 *   func_02082D44 0x02082D44 arm
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3F8 0x0203D3F8 arm
 *   d_021FDE5C 0x021FDE5C data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
extern void func_020307B0(void *);
extern void *func_02030734(u32,u32,int,const void *,u16);
extern u32 func_020173EC(void);
extern void func_02082D44(void *,void *,u32);
extern void *func_020399A8(void);
extern int func_0203D3F8(void *,int,int,u32,void *,int,int,int);
extern const char d_021FDE5C[];
void func_021FD350(char *p,char *src)
{
    char *q;
    void *h;
    u32 n;
    int zero;
    if(*(void **)(p+0x124)) func_020307B0(*(void **)(p+0x124));
    n=func_020173EC();
    q=func_02030734(*(u16 *)p,n+0x7c,0,d_021FDE5C,0x5be);
    zero=0;
    *(void **)(p+0x124)=q;
    func_02082D44(src,q,0x7c);
    n=func_020173EC();
    q+=0x7c;
    func_02082D44(*(void **)(src+4),q,n);
    h=func_020399A8();
    n=func_020173EC();
    func_0203D3F8(h,0xff,0x1103,n+0x7c,*(void **)(p+0x124),1,zero,1);
}
