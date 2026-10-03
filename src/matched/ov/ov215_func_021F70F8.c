/*
 * unit: yes
 * function: func_021F70F8,func_021F7100,func_021F7110
 * address: 0x021F70F8
 * packet: pkt_ov215_021F70F8
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: three contiguous unlabelled blockers of 021F67E0; only code through
 *   021F7116 included, then two-byte padding and rodata beginning 021F7118.
 * function_starts: 0x021F70F8,0x021F7100,0x021F7110
 */
void func_021F70F8(char *p){*(int *)(p+92)=1;}
int func_021F7100(char *p){return *(int *)(p+92)==2;}
void func_021F7110(char *p){*(int *)(p+92)=3;}
