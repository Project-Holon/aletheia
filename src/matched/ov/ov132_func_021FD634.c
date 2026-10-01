/*
 * function: func_021FD634
 * address: 0x021FD634
 * packet: pkt_ov132_021FD634
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 */
typedef unsigned char u8;
typedef unsigned int u32;
void func_021FD634(int a,int b,int c,char *p)
{
    char *q;
    char *s;
    u32 v;
    (*(u8 *)(p+0x14c))++;
    *(int *)(p+0x154)=0;
    q=*(char **)(p+0x140);
    if((u32)(*(u8 *)(p+0x14c)*0x3800)>=*(u32 *)(q+0x2c)) {
        s=*(char **)(q+0x10);
        *(void **)(q+0x14)=s+0xc;
        q=*(char **)(p+0x140);
        *(void **)(q+0x18)=*(char **)(q+0x10)+0xc+*(u32 *)s;
        q=*(char **)(p+0x140);
        v=*(u32 *)(s+4);
        *(u32 *)(q+0x1c)=v+(*(u32 *)(q+0x10)+0xc+*(u32 *)s);
    }
}
