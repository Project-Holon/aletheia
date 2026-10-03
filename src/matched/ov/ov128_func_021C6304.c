/*
 * function: func_021C6304, func_021C6354
 * unit: yes
 * address: 0x021C6304
 * packet: pkt_ov128_021C6304
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030EAC 0x02030EAC arm
 *   func_021C6664 0x021C6664 thumb ov128
 *   func_021C6420 0x021C6420 thumb ov128
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_02034A5C 0x02034A5C arm
 *   func_021C665C 0x021C665C thumb ov128
 *   id43 0x00000043 data
 *   id127 0x0000007F data
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int     s32;
struct Node;
struct S020315D4;
extern void func_02030EAC(struct Node *n);
extern void func_021C6664(void *);
extern void func_021C6420(void *,void *);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(int);
extern void func_02034A5C(s32 handle);
extern void func_021C665C(void *);
extern char id43[],id127[];
int func_021C6304(void *p,int a,int b,char *q)
{
    func_02030EAC(*(void **)(q+0x5a8)); *(void **)(q+0x5a8)=0;
    func_021C6664(q+4);
    func_021C6420(q+0x190,*(void **)(q+0x1f8));
    func_020315D4(p); func_020306F0(52);
    func_02034A5C((u32)id43); func_02034A5C((u32)id127);
    return 1;
}
void func_021C6354(void *p,char *q) { func_021C665C(q+4); }
