/*
 * function: func_021DACE4
 * address: 0x021DACE4
 * packet: pkt_ov119_021DACE4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02039338 0x02039338 arm
 *   func_021E36D8 0x021E36D8 thumb ov119
 *   func_021DD1B8 0x021DD1B8 thumb ov119
 *   func_021D8AA8 0x021D8AA8 thumb ov119
 *   func_020173EC 0x020173EC thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021E1098 0x021E1098 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DAC60 0x021DAC60 thumb ov119
 */
extern void func_02039338(void),func_021E36D8(void *,int),func_021DD1B8(void *);
extern int func_021D8AA8(void *),func_020173EC(void);
struct Obj;
extern void func_02082BCC(void *,int,int),func_0204B3DC(struct Obj *,unsigned int),func_021E1098(void *);
extern void func_021D8E84(void *,int),func_021DAC60(void *);
void func_021DACE4(char *p) {
 int i;
 func_02039338();*(int *)(p+0xf88)=-1;*(int *)(p+0xf84)=-1;*(int *)(p+0x800)=0;*(int *)(p+0xf60)=0;*(int *)(p+0x1060)=0;
 func_021E36D8(p,0);func_021E36D8(p,1);if(func_021D8AA8(p))func_021DD1B8(p);
 func_02082BCC(*(void **)(p+0x5dc),0,func_020173EC());func_02082BCC(*(void **)(p+0x5e0),0,func_020173EC());
 for(i=0;i<10;i++) {if(*(int *)(p+0xefc+4*i))func_0204B3DC((struct Obj *)*(int *)(p+0xefc+4*i),1);}
 func_021E1098(p);func_021D8E84(p,(int)func_021DAC60);
}
