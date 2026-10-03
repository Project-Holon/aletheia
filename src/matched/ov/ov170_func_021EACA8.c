/*
 * function: func_021EACA8
 * address: 0x021EACA8
 * packet: pkt_ov170_021EACA8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_021EAC98 0x021EAC98 thumb ov170
 *   func_021EABD0 0x021EABD0 thumb ov170
 *   func_02045C04 0x02045C04 arm
 *   func_021EABA0 0x021EABA0 thumb ov170
 */
#define WORK(p) (*(char **)((p)+0x2C))
typedef unsigned char  u8;
struct CharBuf;
struct Descriptor;
struct Rec;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_021EAC98(void);
extern void func_021EABD0(unsigned char *,int,void *,unsigned,int,int,unsigned,unsigned short);
extern void func_02045C04(struct Rec *rec);
extern void func_021EABA0(void **);
void func_021EACA8(unsigned char *p) {
 unsigned char *w; void *bank;
 w=(unsigned char *)WORK(p);
 func_02043B5C(func_02045770(*(void **)(w+0x94)),0);
 bank=func_021EAC98();
 func_021EABD0(w,0,bank,*(unsigned *)(*(char **)p+0x24)+0x25,0,8,*(unsigned *)(w+0x78),0x440);
 func_02045C04(bank);
 func_021EABA0((void **)(WORK(p)+0x94));
}
