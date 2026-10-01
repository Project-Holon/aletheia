/*
 * function: func_021D60D4
 * address: 0x021D60D4
 * packet: pkt_ov131_021D60D4
 * region: ov131
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6064 0x021D6064 thumb ov131
 *   func_021D60D4 0x021D60D4 thumb ov131
 */
extern void *func_021D6064(void *);
extern void *func_0201AB28(void *,int);
extern int func_02017D30(void *);
extern void func_02017D70(void *,int);
extern int func_02017DBC(void *);
extern void func_02017DE4(void *,int);
void func_021D60D4(unsigned char *p,int a) {
 void *m;
 switch((*(unsigned char **)(p+8))[12]) {
 case 0:
 m=**(void ***)(p+8);
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 1:
 m=func_0201AB28(**(void ***)(p+8),*(unsigned short *)(p+24));
 if(a==1) func_02017D30(m); else func_02017D70(m,1);
 break;
 case 2:
 m=func_021D6064(p);
 if(a==1) {func_02017D30(*(void **)(p+600));func_02017DBC(m);}
 else {func_02017D70(*(void **)(p+600),1);func_02017DE4(m,1);}
 break;
 }
}
