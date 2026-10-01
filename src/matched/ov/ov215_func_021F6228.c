/*
 * function: func_021F6228
 * address: 0x021F6228
 * packet: pkt_ov215_021F6228
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_0201CE30 0x0201CE30 thumb
 *   func_0203630C 0x0203630C arm
 *   func_02035C38 0x02035C38 arm
 *   func_0201CE5C 0x0201CE5C thumb
 *   func_020362DC 0x020362DC arm
 *   func_02035C60 0x02035C60 arm
 *   func_0201CE38 0x0201CE38 thumb
 */
extern unsigned func_0201CE30(void *);
extern unsigned func_0203630C(void);
extern unsigned func_02035C38(void);
extern void func_0201CE5C(void *,unsigned);
extern unsigned func_020362DC(void);
extern unsigned func_02035C60(void);
extern void func_0201CE38(void *);
int func_021F6228(void *unused,char *p)
{
    int result=0;
    switch(func_0201CE30(*(void **)(p+80))) {
    case 0:
        if((func_0203630C()&3)!=0 || func_02035C38()!=0)
            func_0201CE5C(*(void **)(p+80),0);
        break;
    case 1:
        if((func_020362DC()&3)!=0 || func_02035C60()!=0)
            func_0201CE38(*(void **)(p+80));
        break;
    case 2:
        result=1;
        break;
    }
    return result;
}
