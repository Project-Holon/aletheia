/*
 * function: func_021E82BC
 * address: 0x021E82BC
 * packet: pkt_ov177_021E82BC
 * region: ov177
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware write 021E82C4.
 * symbols:
 *   func_020456F8 0x020456F8 arm
 *   func_020452E8 0x020452E8 arm
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_020307B0 0x020307B0 arm
 */
struct Descriptor;
struct Obj;
extern void func_020456F8(struct Descriptor *d);
extern void func_020452E8(struct Descriptor *d);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204A8D4(void *);
extern void func_0204AFD8(void *);
extern void func_0204ADA4(void *);
extern void func_020307B0(void *);
void func_021E82BC(char *p)
{
 int i;
 *(volatile unsigned short *)0x04000050 = 0;
 for(i=0;i<6;i++) {if(*(void **)(p+i*4+0x68)!=0){func_020456F8(*(void **)(p+i*4+0x68));func_020452E8(*(void **)(p+i*4+0x68));}}
 for(i=0;i<14;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204B3B4(*(void **)(p+i*4+0x30));
 func_0204A8D4(*(void **)(p+0x28));func_0204AFD8(*(void **)(p+0x2C));func_0204ADA4(*(void **)(p+0x24));
 for(i=0;i<6;i++)if(*(void **)(p+i*4+0x30)!=0)func_0204A8D4(*(void **)(p+i*4+4));
 func_0204AFD8(*(void **)(p+0x20));func_0204ADA4(*(void **)p);func_020307B0(p);
}
