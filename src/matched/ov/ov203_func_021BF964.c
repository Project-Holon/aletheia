/*
 * function: func_021BF964
 * address: 0x021BF964
 * packet: pkt_ov203_021BF964
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE990 0x021BE990 thumb ov203
 *   func_021BF9B8 0x021BF9B8 thumb ov203
 */
typedef struct { int kind;unsigned limit;int values[8]; } Record;
extern Record *func_021BE990(int);
extern void func_021BF9B8(char *,char *,Record *);
int func_021BF964(char *p,char *owner,int *index)
{
    Record *r;
    int i;
    r=func_021BE990(*(int *)(owner+0x78));
    for(i=0;i<9999;i++) {
        if(r[i].kind==18) return 1;
        if(r[i].limit==-1) func_021BF9B8(p,owner,&r[i]);
        else if(r[i].limit>=*(unsigned *)(owner+0x7C)) {*index=i;return 0;}
    }
    return 0;
}
