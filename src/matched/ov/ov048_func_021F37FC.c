/*
 * function: func_021F37FC
 * address: 0x021F37FC
 * packet: pkt_ov048_021F37FC
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021F37A4 0x021F37A4 thumb ov048
 */
typedef unsigned short u16;
extern char *func_021F37A4(int a);
void func_021F37FC(int *p) { char *q; q=func_021F37A4(p[1]); p[4]=*(int *)q; p[6]=*(int *)(q+4); *(u16 *)((char *)p+0x64)=*(u16 *)(q+8); }
