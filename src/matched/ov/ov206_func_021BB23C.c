/*
 * function: func_021BB23C
 * address: 0x021BB23C
 * packet: pkt_ov206_021BB23C
 * region: ov206
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B800 0x0204B800 arm
 *   func_0204B688 0x0204B688 arm
 *   func_0201AE1C 0x0201AE1C thumb
 *   func_0204B604 0x0204B604 arm
 */
typedef struct { short x,y,z,w; } Pos;
extern void func_02082BCC(void *,int,int);
extern int func_0204B294(int,int,int,int,Pos *,unsigned short,unsigned short);
extern void func_0204B800(int,int);
extern void func_0204B688(int,int);
extern int func_0201AE1C(int,int);
extern void func_0204B604(int,int,int);
void func_021BB23C(char *p,int x,int y,int index)
{
    int flag=0;
    Pos pos;
    if (*(int *)(p+0x1c)) flag=1;
    func_02082BCC(&pos,0,8);
    pos.x=x;
    pos.y=y;
    *(int *)(p+0xac+index*4)=func_0204B294(*(int *)(p+0x24),*(int *)(p+0x94+index*4),*(int *)(p+0x9c+index*4),*(int *)(p+0xa4+index*4),&pos,flag,*(unsigned short *)p);
    func_0204B800(*(int *)(p+0xac+index*4),0);
    if(*(int *)(p+0x18)==2) func_0204B688(*(int *)(p+0xac+index*4),1);
    if(func_0201AE1C(*(int *)(p+0x26c),34)==0) func_0204B604(*(int *)(p+0xac+index*4),1,1);
}
