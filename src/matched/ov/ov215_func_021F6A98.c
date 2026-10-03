/*
 * unit: yes
 * function: func_021F6A98,func_021F6AA4
 * address: 0x021F6A98
 * packet: pkt_ov215_021F6A98
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * leaf: two unlabelled leaves blocking concrete MATCH900 ov215021F5884.
 * extent: setter and predicate, each followed by two zero alignment bytes.
 */
void func_021F6A98(char *p){*(int *)(p+12)=6;*(int *)(p+24)=0;}
int func_021F6AA4(char *p){if(*(int *)(p+12)>=9)return 1;return 0;}
