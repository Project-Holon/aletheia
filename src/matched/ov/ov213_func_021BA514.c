/*
 * function: func_021BA514
 * address: 0x021BA514
 * packet: pkt_ov213_021BA514
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203D5D4 0x0203D5D4 arm
 *   func_021BA4BC 0x021BA4BC thumb ov213
 * prototype: caller loads r0 net object before D5D4; retained visible input despite callee's void parameter list.
 */
extern int func_0203D5D4(void *);
extern void func_021BA4BC(void *,int,int);
void func_021BA514(char *p)
{
    if(*(void **)(*(char **)(p+4)+0x54)) {
        switch(func_0203D5D4(*(void **)(*(char **)(p+4)+0x54))) {
        case 37:case 12:case 31:func_021BA4BC(*(void **)(*(char **)(p+4)+0x54),37,*(int *)(p+0x49CC));break;
        case 10:func_021BA4BC(*(void **)(*(char **)(p+4)+0x54),17,*(int *)(p+0x49CC));break;
        case 20:case 21:case 23:case 24:case 25:case 26:
            func_021BA4BC(*(void **)(*(char **)(p+4)+0x54),13,*(int *)(p+0x49CC));break;
        }
    }
}
