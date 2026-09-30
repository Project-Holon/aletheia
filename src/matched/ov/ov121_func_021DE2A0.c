/*
 * function: func_021DE2A0
 * address: 0x021DE2A0
 * packet: pkt_ov121_021DE2A0
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   func_02082BCC 0x02082BCC arm
 *   func_021DEE68 0x021DEE68 thumb ov121
 *   func_021DE618 0x021DE618 thumb ov121
 *   d_021DFBC0 0x021DFBC0 data ov121 a1
 */
typedef unsigned short u16;
extern void *func_02030734(unsigned,unsigned,int,const char *,unsigned);
extern void func_02082BCC(void *,int,int);
extern void func_021DEE68(void *,int,void *);
extern void func_021DE618(void);
extern const char d_021DFBC0[];
void *func_021DE2A0(void *arg,int heap)
{
    char *p;
    p=func_02030734(heap,0x17a8,0,d_021DFBC0,315);
    func_02082BCC(p,0,0x17a8);
    *(u16 *)(p+0x58)=heap;
    *(void **)(p+0x794)=arg;
    func_021DEE68(p,(int)p,func_021DE618);
    return p;
}
