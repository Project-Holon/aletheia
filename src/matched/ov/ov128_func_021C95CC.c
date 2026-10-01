/*
 * function: func_021C95CC
 * address: 0x021C95CC
 * packet: pkt_ov128_021C95CC
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte zero padding at 021C9626 before next label 021C9628.
 * symbols:
 *   func_021C9BEC 0x021C9BEC thumb ov128
 *   func_021C6DF8 0x021C6DF8 thumb ov128
 *   func_021C9BF8 0x021C9BF8 thumb ov128
 *   func_02040618 0x02040618 arm
 */
typedef unsigned char u8;
typedef signed short s16;
extern void func_021C9BEC(u8 *,void *,void *,int,s16,int);
extern void func_021C6DF8(void *,int);
extern void func_021C9BF8(void *,void *,int);
extern void func_02040618(int,int,int);
int func_021C95CC(u8 *p,void *a,void *b,int c)
{
    int value=*(int *)(p+4);
    int offset;
    if(value>8) {
        func_021C9BEC(p,a,b,0,*(s16 *)p,c);
        func_021C6DF8(b,1);
        func_021C9BF8(p,b,255);
        return 1;
    }
    offset=(value*256)/8;
    if(*(int *)(p+8)==2) offset=-offset;
    func_02040618(3,0,offset);
    *(int *)(p+4)=*(int *)(p+4)+1;
    return 0;
}
