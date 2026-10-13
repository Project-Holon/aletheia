/*
 * function: func_021BC490
 * address: 0x021BC490
 * packet: pkt_ov110_021BC490
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: Full ARM9 Strbuf copy and message-tag unit prototypes copied.
 *   Cursor contains the observed word04 pointer, word08 state and halfword0c.
 *   Tag scan preserves the original sentinel/advance loop and same-buffer
 *   signed halfword pointer difference; results 0/1/2/3 preserve all states.
 *   No temporary array, narrowed pointer/index or uninitialized read added.
 * symbols:
 *   STRBUF_SetStringN 0x02045994 arm
 *   func_0201D670 0x0201D670 thumb
 *   func_0201D688 0x0201D688 thumb
 */
typedef unsigned short u16;
typedef unsigned int u32;
struct Strbuf;
typedef struct Cursor {
    u32 f00;
    u16 *f04;
    u32 f08;
    u16 f0c;
} Cursor;
extern void STRBUF_SetStringN(struct Strbuf *,const u16 *,u32);
extern u32 func_0201D670(const u16 *,u32);
extern u16 *func_0201D688(u16 *);
int func_021BC490(Cursor *p,struct Strbuf *out)
{
    u16 *start;
    int result;
    start=p->f04;
    switch(p->f08) {
    case 0:
        while(p->f08==0) {
            switch(*p->f04) {
            case 0xfffe: p->f08=2; break;
            case 0xffff: p->f08=3; break;
            case 0xf000: p->f08=1; break;
            default: p->f04+=1; break;
            }
        }
        STRBUF_SetStringN(out,start,(p->f04-start)+1);
        return 0;
    case 1:
        p->f0c=func_0201D670(start,0);
        p->f04=func_0201D688(p->f04);
        result=1;
        break;
    case 2:
        p->f04=start+1;
        result=2;
        break;
    case 3:
    default:
        return 3;
    }
    switch(*p->f04) {
    case 0xfffe: p->f08=2; break;
    case 0xffff: p->f08=3; break;
    case 0xf000: p->f08=1; break;
    default: p->f08=0; break;
    }
    return result;
}
