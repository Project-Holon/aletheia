/*
 * function: func_021DE728
 * address: 0x021DE728
 * packet: pkt_ov170_021DE728
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F1400 0x021F1400 data a1
 *   func_021DD2D0 0x021DD2D0 thumb ov170
 *   func_02017E88 0x02017E88 thumb
 *   func_021DE720 0x021DE720 thumb ov170
 */
#include "../include/Obj00000.h"
#include "../include/Obj23849.h"
#include "../include/Obj23850.h"
typedef struct {void *p;unsigned short f4;unsigned char flags;unsigned char pad[5];} State;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char d_021F1400[];
extern int func_021DD2D0(void ***p, int a, unsigned b);
extern unsigned func_02017E88(void *,unsigned,unsigned);
extern int func_021DE720(unsigned short);
void func_021DE728(unsigned char *p)
{
    State *s;
    void *m;
    unsigned i;
    int r;
    *(State * *)&((struct Obj23849 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190=func_02030734(0x804c,12,0,d_021F1400,0xa70);
    s=*(State * *)&((struct Obj23850 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->fA190;
    s->p=*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C+*(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C+p[0x16]+0x3dd2)*4+0x9e74);
    s->f4=0;
    s->flags=0;
    m=(void *)func_021DD2D0((void ***)p,p[0x14],p[0x16]);
    for(i=0;i<4;i++){
        r=func_021DE720((unsigned short)func_02017E88(m,i+0x36,0));
        if(r!=-1){s->flags|=(unsigned char)(1<<r);return;}
    }
}
