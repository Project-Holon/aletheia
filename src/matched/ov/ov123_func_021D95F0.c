/*
 * function: func_021D95F0
 * address: 0x021D95F0
 * packet: pkt_ov123_021D95F0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   func_020362DC 0x020362DC arm
 */

typedef unsigned int u32;
extern int func_0201CE30(void *);
extern void func_0201CE48(void *);
extern void func_0201CE38(void *);
extern u32 func_020362DC(void);
int func_021D95F0(char *p)
{
    if (*(void **)(p+0x80)) {
        switch (func_0201CE30(*(void **)(p+0x80))) {
        case 2:
            func_0201CE48(*(void **)(p+0x80));
            *(void **)(p+0x80)=0;
            break;
        case 1:
            if (func_020362DC()==1) func_0201CE38(*(void **)(p+0x80));
            break;
        }
        return 0;
    }
    return 1;
}
