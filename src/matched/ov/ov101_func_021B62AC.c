/*
 * unit: yes
 * function: func_021B62AC,func_021B62FC
 * address: 0x021B62AC
 * packet: pkt_ov101_021B62AC
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02039CB4 0x02039CB4 arm
 */
struct Entry;
struct Link;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
int func_021B62AC(int *p)
{
    if(p[30]) return 1;
    switch(p[17]) {
    case 0:
        func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13);
        p[17]=1;
        break;
    case 1:
        if(func_02039CB4((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),14,13)) p[17]=2;
        break;
    case 2:
        p[17]=0;
        return 1;
    }
    return 0;
}
int func_021B62FC(int *p) { if(p[30]) return 1; return p[20]; }
