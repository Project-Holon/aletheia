/*
 * function: func_021DA994
 * address: 0x021DA994
 * packet: pkt_ov121_021DA994
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_02043B5C 0x02043B5C arm
 *   func_02045CAC 0x02045CAC arm
 *   func_021DAA28 0x021DAA28 thumb ov121
 */
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned char u8;
extern void func_02043B5C(int,int);
extern void func_02045CAC(int,int,void *);
extern void func_021DAA28(char *,int,int *);
extern void func_0201C724(void *,int,s16,s16,void *,int,u16);
void func_021DA994(char *p,int a,int b,int c)
{
    int xy[2];
    func_02043B5C(*(int *)p,(u8)(*(u16 *)(p+4)&31));
    func_02045CAC(a,b,*(void **)(p+24));
    func_021DAA28(p,c,xy);
    func_0201C724(*(void **)(p+32),*(int *)p,(s16)xy[0],(s16)xy[1],*(void **)(p+24),c,*(u16 *)(p+4));
    *(int *)(p+8)=1;
}
