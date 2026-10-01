/*
 * function: func_021BA38C
 * address: 0x021BA38C
 * packet: pkt_ov213_021BA38C
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9E50 0x021B9E50 thumb ov213
 *   func_021BA268 0x021BA268 thumb ov213
 */
typedef unsigned char u8;
typedef struct {char bytes[0x54];} Row;
typedef struct {int pad0;char *owner;char pad8[0x4834];Row rows[4];char pad498C[0x2C];int c;char pad49BC[12];u8 kind;char pad49C9[15];u8 flag;} Context;
extern int func_021B9E50(unsigned);
extern void func_021BA268(Row *,u8,u8,char *,void *,void *,int);
enum Count {CountZero,CountTwo=2,CountFour=4};
void func_021BA38C(Context *p)
{
    int i;
    enum Count count;
    if(func_021B9E50(p->kind)) count=CountTwo;
    else count=CountFour;
    for(i=0;i<count;i++)
        func_021BA268(&p->rows[i],p->kind,i,p->owner+i*16,(char *)p+0xC,(char *)p+0x24,p->c);
}
