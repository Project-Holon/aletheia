/*
 * function: func_021F3A50
 * address: 0x021F3A50
 * packet: pkt_ov048_021F3A50
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 */
typedef unsigned char u8;
void func_021F3A50(char *p,int a,int b) { char *q; int i; q=p+0x28; i=*(u8 *)(p+0x28); if(i<7) { *(int *)(q+i*4+4)=a; *(int *)(q+i*4+0x20)=b; *(u8 *)q=i+1; } }
