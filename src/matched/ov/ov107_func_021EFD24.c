/*
 * function: func_021EFD24
 * address: 0x021EFD24
 * packet: pkt_ov107_021EFD24
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of alignment padding after the return.
 * symbols:
 *   func_021F11C4 0x021F11C4 thumb ov107
 *   func_021F17E0 0x021F17E0 thumb ov107
 *   func_021F1B38 0x021F1B38 thumb ov107
 *   func_021EFD98 0x021EFD98 thumb ov107
 *   func_0200C184 0x0200C184 thumb
 *   func_021F11E0 0x021F11E0 thumb ov107
 *   func_0200C18C 0x0200C18C thumb
 *   func_021EFC1C 0x021EFC1C thumb ov107
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Blk34;
extern u8 func_021F11C4(u8 *p);
extern void func_021F17E0(void *,int);
extern void func_021F1B38(u8 *p, u32 v);
extern void func_021EFD98(void *);
extern u32 func_0200C184(struct Blk34 *p);
extern int func_021F11E0(unsigned char *a);
extern void func_0200C18C(struct Blk34 *p, u32 v);
extern void func_021EFC1C(u8 *p, int mode);
void func_021EFD24(u8 *p) {
 unsigned v=func_021F11C4(*(void **)(p+12));
 unsigned old,cur;
 func_021F17E0(*(void **)(p+104),6);func_021F1B38(*(void **)(p+104),1);func_021EFD98(p);
 if(p[40]==0) {
 old=(u16)func_0200C184(*(void **)(p+76));cur=func_021F11E0(*(void **)(p+12));
 if(old<cur) {func_0200C18C(*(void **)(p+76),cur);func_021EFC1C(p,1);}
 else if(v==0) func_021EFC1C(p,2);else func_021EFC1C(p,0);
 if(*(u16 *)(p+56)<cur) *(u16 *)(p+56)=cur;
 *(u16 *)(p+60)=*(u16 *)(p+60)+v;
 }
}
