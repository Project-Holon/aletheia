/*
 * function: func_021BA4BC
 * address: 0x021BA4BC
 * packet: pkt_ov213_021BA4BC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02008DF0 0x02008DF0 thumb
 */
typedef unsigned int   u32;
struct Sub02008C20Obj;
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
void func_021BA4BC(void *p,int kind,int variant)
{
    switch(kind) {
    case 13:
        if(variant==0) func_02008DF0(p,14);
        else if(variant==1) func_02008DF0(p,15);
        break;
    case 37:
        if(variant==0) func_02008DF0(p,38);
        else if(variant==1) func_02008DF0(p,39);
        break;
    case 17:
        if(variant==0) func_02008DF0(p,18);
        else if(variant==1) func_02008DF0(p,19);
        else if(variant==2) func_02008DF0(p,20);
        break;
    }
    func_02008DF0(p,kind);
}
