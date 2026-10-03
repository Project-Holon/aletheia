/*
 * function: func_021F6A24
 * address: 0x021F6A24
 * packet: pkt_ov112_021F6A24
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: Two-byte zero alignment padding follows the compiled body.
 * lever: Load adds the index before offset eight; the call adds offset eight before the index.
 * symbols:
 *   func_021F6B80 0x021F6B80 thumb ov112
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F6B80(u32 *,u32 *);extern void func_020307B0(void *);
void func_021F6A24(char *p) {u8 i;for(i=0;i<5;i++)if(*(u32 *)(p+i*28+8)==1)func_021F6B80((u32 *)p,(u32 *)(p+8+i*28));func_020307B0(p);}
