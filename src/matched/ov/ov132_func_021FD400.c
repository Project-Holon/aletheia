/*
 * function: func_021FD400
 * address: 0x021FD400
 * packet: pkt_ov132_021FD400
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 recoup: the copy length is a plain call result plus 0x7c, written the same way as the
 *   first call's n (n=f()+0x7c) and passed as n. The older draft passed n+0x7c inline and left adds r2/r1 swapped.
 * symbols:
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 *   func_0203996C 0x0203996C arm
 *   func_0203D3F8 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern u32 func_020173EC(void);
extern void func_02082D44(const void *,void *,u32);
typedef signed int     s32;
struct Entry;
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_0203D3F8(u32,u32,u32,u32,u32,u32,u32,u32);
int func_021FD400(const char *p)
{
    u8 i;
    u32 n;
    u32 k;
    u32 q;
    void *h;
    for(i=0;i<4;i++) {
        n=func_020173EC()+0x7c;
        q=*(u32 *)(p+0x128);
        k=i*n;
        n=func_020173EC()+0x7c;
        func_02082D44(*(void **)(p+i*0x30+0x7c),(void *)(q+k),n);
    }
    h=func_0203996C(0xff);
    n=func_020173EC();
    return func_0203D3F8((u32)h,0xff,0x1104,(n+0x7c)*4,*(u32 *)(p+0x128),1,0,1);
}
