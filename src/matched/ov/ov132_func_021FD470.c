/*
 * function: func_021FD470
 * address: 0x021FD470
 * packet: pkt_ov132_021FD470
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: 2026-10-05 length kept in a local before the call (n = f()+0x7c; call(q+k, src, n)); the inline n+0x7c form swapped two adds (4 B). Older DIFF notes superseded.
 * symbols:
 *   func_020084BC 0x020084BC thumb
 *   func_020173EC 0x020173EC thumb
 *   func_02082D44 0x02082D44 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_020084BC(const u16 *);
extern u32 func_020173EC(void);
extern void func_02082D44(const void *,void *,u32);
/* The callback owner is the 0x1ac-byte allocation in 021FC644. */
typedef struct {u8 pad[0x128];char *buffer;u8 tail[0x80];} Owner;
void func_021FD470(int a,int b,int c,const Owner *p)
{
    u8 i;
    char *s;
    u32 k;
    char *q;
    u32 n;
    for(i=0;i<4;i++) {
        s=(char *)p+i*0x30;
        if(func_020084BC(*(u16 **)(s+0x84))==0) {
            n=func_020173EC()+0x7c;
            q=p->buffer;
            k=i*n;
            n=func_020173EC()+0x7c;
            func_02082D44(q+k,*(void **)(s+0x7c),n);
            q=*(char **)(s+0x7c);
            *(char **)(q+4)=q+0x7c;
            *(int *)(s+0x64)=1;
        } else *(int *)(s+0x64)=0;
    }
    *(int *)((char *)p+0x15c)=1;
}
