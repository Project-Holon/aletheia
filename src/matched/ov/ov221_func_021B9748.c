/*
 * function: func_021B9748
 * address: 0x021B9748
 * packet: pkt_ov221_021B9748
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9770 hardware DISPCNT sub masked read.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_021B9CCC 0x021B9CCC thumb ov221
 *   func_021B9AEC 0x021B9AEC thumb ov221
 *   func_021B9960 0x021B9960 thumb ov221
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_021B9F20 0x021B9F20 thumb ov221
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   d_021BA148 0x021BA148 data a4
 */
struct Node; struct PrintSys;
typedef enum { LAYER_FIRST=0,LAYER_LIMIT=1 } Layer;
extern const unsigned d_021BA148[][11];
extern void func_020403F4(unsigned char);
extern void func_021B9CCC(char *);
extern void func_021B9AEC(char *);
extern void func_021B9960(char *);
extern void func_02030EAC(struct Node *);
extern void func_0201C6EC(struct PrintSys *);
extern void func_0201C4C0(void *);
extern void func_0201D83C(void *);
extern void func_021B9F20(char *);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *);
extern void func_020306F0(void *);
int func_021B9748(void *owner,void *unused1,void *unused2,char *p)
{
    Layer i=LAYER_FIRST;
    do {
        func_020403F4(d_021BA148[i][0]);
        i++;
    } while((unsigned)i<1);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &= 0xFFFF1FFF;
    func_021B9CCC(p);
    func_021B9AEC(p);
    func_021B9960(p);
    func_02030EAC(*(struct Node **)(p+0x14));
    func_0201C6EC(*(struct PrintSys **)(p+0x10));
    func_0201C4C0(*(void **)(p+0x10));
    func_0201D83C(*(void **)(p+0xC));
    func_021B9F20(*(char **)(p+8));
    func_020315D4((struct S020315D4 *)owner);
    func_020306F0((void *)0x83);
    return 1;
}
