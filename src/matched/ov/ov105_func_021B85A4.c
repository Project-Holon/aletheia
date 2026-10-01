/*
 * unit: yes
 * function: func_021B85A4, func_021B871C, func_021B8730
 * address: 0x021B85A4
 * packet: pkt_ov105_021B85A4
 * region: ov105
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * extent: 376-byte lead,20-byte reset871C,4-byte getter8730; no tail data.
 * lever: 3-byte table rows unify index array and count field relocations.
 * symbols:
 *   func_020061E4 0x020061E4 thumb
 *   func_021B8734 0x021B8734 thumb ov105
 *   d_021B8984 0x021B8984 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_020061E4(int);
extern void func_021B8734(u16 *,int,u8,u8,u8,u16,u16);
typedef struct { u8 index[2]; u8 count; } Row;
extern const Row d_021B8984[];
#define W(off) (*(unsigned *)(p+(off)))
#define H(off) (*(u16 *)(p+(off)))
void func_021B85A4(u8 *p)
{
    int i;
    if (!W(0x50)) return;
    switch(W(0x58)) {
    case 0:
        if(H(0x56)>H(0x54)) {
            if(W(0x5c)) W(0x58)=1;
            else { W(0x4c)=1; W(0x50)=0; }
            return;
        }
        if(!W(0x48)) func_020061E4(2000+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)].count;++i) {
            int index=d_021B8984[H(0x56)].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,0x7fff,((u16 *)(p+8))[index]);
        }
        if(W(0x48)++>=40) { W(0x48)=0; ++H(0x56); }
        break;
    case 1:
        if(W(0x48)++>=60) { W(0x48)=0; W(0x58)=2; }
        break;
    case 2:
        if(!W(0x48)) func_020061E4(1998+H(0x56));
        for(i=0;i<d_021B8984[H(0x56)-1].count;++i) {
            int index=d_021B8984[H(0x56)-1].index[i];
            func_021B8734((u16 *)(p+0x28)+index,(u16)W(0x48),40,8,index,((u16 *)(p+8))[index],0x7fff);
        }
        if(W(0x48)++>=40) { W(0x48)=0; W(0x4c)=1; W(0x50)=0; }
        break;
    }
}
void func_021B871C(u8 *p)
{
    W(0x50)=1; W(0x4c)=0; H(0x56)=1; W(0x58)=0; W(0x48)=0;
}
unsigned func_021B8730(u8 *p)
{
    return W(0x4c);
}
