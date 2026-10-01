/*
 * function: func_021BE51C
 * address: 0x021BE51C
 * packet: pkt_ov209_021BE51C
 * region: ov209
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Row expression assigned back to index keeps the entry register; 021BE586 is two zero alignment bytes.
 * symbols:
 *   func_021BD8F4 0x021BD8F4 thumb ov209
 *   func_021BD958 0x021BD958 thumb ov209
 *   func_021BD8B0 0x021BD8B0 thumb ov209
 *   func_021BD890 0x021BD890 thumb ov209
 */
typedef unsigned short u16;
extern int func_021BD8F4(int,int);
extern void func_021BD958(char *,int,short *,short *,u16);
extern int func_021BD8B0(char *,int);
extern void func_021BD890(char *,int,int);
void func_021BE51C(char *p,int index)
{
    unsigned i;
    short pos[2];
    index=index*24+8;
    for(i=10;i<26;i++){
        if(func_021BD8F4((int)p,i)==0)func_021BD890(p,i,0);
        else{
            func_021BD958(p,i,&pos[1],&pos[0],0);
            if(index==pos[0]){if(func_021BD8B0(p,i)!=1)func_021BD890(p,i,1);}
            else func_021BD890(p,i,0);
        }
    }
}
