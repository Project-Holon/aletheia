/*
 * unit: yes
 * function: func_021FCA38, func_021FCAA0
 * address: 0x021FCA38
 * packet: pkt_ov132_021FCA38
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
extern void func_020307B0(void *);
void func_021FCA38(char *p)
{
    u8 i;
    char *q;
    for(i=0;i<4;i++) {
        q=p+i*0x30;
        if(*(void **)(q+0x7c)) {
            func_020307B0(*(void **)(q+0x8c));
            func_020307B0(*(void **)(q+0x7c));
        }
    }
    if(*(void **)(p+0x124)) func_020307B0(*(void **)(p+0x124));
    if(*(void **)(p+0x138)) func_020307B0(*(void **)(p+0x138));
    if(*(void **)(p+0x128)) func_020307B0(*(void **)(p+0x128));
    if(*(void **)(p+0x13c)) func_020307B0(*(void **)(p+0x13c));
}
void func_021FCAA0(char *p)
{
    *(int *)(p+0x10)=1;
}
