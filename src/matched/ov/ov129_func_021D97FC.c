/*
 * function: func_021D97FC
 * address: 0x021D97FC
 * packet: pkt_ov129_021D97FC
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: Two zero alignment bytes.
 * note: 2026-10-05 the count field is read in the loop condition and again at the return (as written by hand); this closed the count/flag register swap.
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
int func_021D97FC(u8 *p,int value) { int i; int flag=0; for(i=0;i<*(int *)(p+0x23C);i++) { if(value==*(int *)(p+i*28+4)) flag=1; else if(flag==1) return i-1; } return *(int *)(p+0x23C)-1; }
