/*
 * function: func_0220B164
 * address: 0x0220B164
 * packet: pkt_ov187_0220B164
 * region: ov187
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 0200BA58 (Thumb); scratch one EXACT, blocker-0200BA58-2.log.
 *   symbols: func_02034AC4 0x02034AC4 arm; overlay188 0x000000BC data a4.
 *   extern int func_02034AC4(int); extern char overlay188[];
 *   int func_0200BA58(void) { return func_02034AC4((int)overlay188); }
 * blocker: ARM9 0200BA68 (Thumb); scratch one EXACT, blocker-0200BA68-2.log.
 *   symbols: func_02034A5C 0x02034A5C arm; overlay188 0x000000BC data a4.
 *   extern void func_02034A5C(int); extern char overlay188[];
 *   void func_0200BA68(void) { func_02034A5C((int)overlay188); }
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_020138C4 0x020138C4 thumb
 *   func_0200BA58 0x0200BA58 thumb
 *   func_0200BA68 0x0200BA68 thumb
 *   func_021EEEA8 0x021EEEA8 thumb ov188
 *   func_02005DE4 0x02005DE4 thumb
 *   func_02005E64 0x02005E64 thumb
 *   func_0220B240 0x0220B240 thumb ov187
 *   func_02005D90 0x02005D90 thumb
 *   d_0220B2E4 0x0220B2E4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16);
extern void func_02082BCC(void *,int,int);
extern void func_020138C4(void *,int,void *);
extern void func_0200BA58(void);
extern void func_0200BA68(void);
extern void func_021EEEA8(void *,u32);
extern void func_02005DE4(u32);
extern void func_02005E64(void);
extern void func_0220B240(u16 *,u16 *);
extern void func_02005D90(u32,u32);
extern char d_0220B2E4[];
void *func_0220B164(u32 a,u8 *b)
{
    u8 *p = func_02030734(a,240,0,d_0220B2E4,542);
    func_02082BCC(p,0,240);
    func_020138C4(p,*(int *)(*(u8 **)(b+0x17F0)+4),(void *)a);
    func_0200BA58();
    func_021EEEA8(p,a);
    func_0200BA68();
    func_02005DE4(1);
    func_02005E64();
    func_0220B240((u16 *)(p+24),(u16 *)(p+26));
    func_02005D90(*(u16 *)(p+24),65535);
    return p;
}
