/*
 * function: func_021D4240
 * address: 0x021D4240
 * packet: pkt_ov124_021D4240
 * region: ov124
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D43F8 0x021D43F8 thumb ov124
 *   func_021D4558 0x021D4558 thumb ov124
 *   func_021D46BC 0x021D46BC thumb ov124
 *   func_021D43F0 0x021D43F0 thumb ov124
 *   func_021D4940 0x021D4940 thumb ov124
 *   func_0203D34C 0x0203D34C arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021D43F8(char *);
extern void func_021D4558(char *);
extern void func_021D46BC(char *);
extern void func_021D43F0(void);
extern void *func_020056A0(void *,void *,int);
extern void func_021D4940(char *,int);
extern void func_0203D34C(unsigned,unsigned);
void func_021D4240(char *p)
{
    *(int *)(p + 0x10) = 0;
    func_021D43F8(p);
    func_021D4558(p);
    func_021D46BC(p);
    *(void **)(p + 0x14) = func_020056A0(func_021D43F0,p,8);
    *(u8 *)(p + 0x18) = 0;
    *(int *)(p + 0xc) = 1;
    func_021D4940(p,*(u8 *)(p + 0x18));
    func_0203D34C(0,*(u16 *)p);
}
