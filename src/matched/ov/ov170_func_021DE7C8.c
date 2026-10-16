/*
 * function: BOX2_MAIN_StepScroll
 * address: 0x021DE7C8
 * packet: pkt_ov170_021DE7C8
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: Spell the byte-mask update as plain assignment; compound assignment inserts an extra truncation pair.
 * symbols:
 *   BOX2_MAIN_GetMonAt 0x021DD2D0 thumb ov170
 *   POKE_TOOL_GetBoxValue 0x02017E88 thumb
 *   BOX2_MAIN_GetMinusOne 0x021DE720 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23851.h"
typedef struct {void *p;unsigned short index;unsigned char flags;unsigned char pad[5];} State;
extern int BOX2_MAIN_GetMonAt(void ***p, int a, unsigned b);
extern unsigned POKE_TOOL_GetBoxValue(void *,unsigned,unsigned);
extern int BOX2_MAIN_GetMinusOne(unsigned short);
int BOX2_MAIN_StepScroll(unsigned char *p)
{
    State *s=*(State * *)&((struct Obj23851 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    unsigned short n=s->index;
    unsigned j,i;
    void *m;
    int box,r,slot;
    if(n==726)return 0;
    for(j=0;j<15;j++){
        if(n<720){
            box=n/30;
            slot=n%30;
            if(box==p[0x14]&&slot==p[0x16]) m=0;
            else m=(void *)BOX2_MAIN_GetMonAt((void ***)p,box,slot);
        }else{
            slot=n-720;
            if(slot==p[0x16]-30)m=0;
            else m=(void *)BOX2_MAIN_GetMonAt((void ***)p,255,slot);
        }
        if(m&&POKE_TOOL_GetBoxValue(m,0xa9,0)!=0){
            for(i=0;i<4;i++){
                r=BOX2_MAIN_GetMinusOne((unsigned short)POKE_TOOL_GetBoxValue(m,i+0x36,0));
                if(r!=-1)s->flags=s->flags & (255^(1<<r));
            }
        }
        ++s->index;
        n=s->index;
        if(n==726)return 0;
    }
    return 1;
}
