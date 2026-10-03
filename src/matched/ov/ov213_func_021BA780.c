/*
 * function: func_021BA780
 * address: 0x021BA780
 * packet: pkt_ov213_021BA780
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207D63C 0x0207D63C arm
 *   func_02047CFC 0x02047CFC arm
 *   func_02050B80 0x02050B80 arm
 */
extern void func_0207D63C(void *,int,int,int,int),func_02050B80(unsigned);extern void *func_02047CFC(unsigned,unsigned,unsigned);
void func_021BA780(char *p,void *state,short heap){func_0207D63C((void *)0x04000050,1,31,0,0);*(void **)p=state;*(unsigned short *)(p+4)=heap;*(void **)(p+8)=func_02047CFC(16,20,heap);func_02050B80(heap);}
